/*

    Sprite class for player ship

*/

#include "CNetworkAI.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "CMeteor.h"

#include <cstdlib>
#include <time.h>

#include "GameScene.h"

//math
#include "math.h"

//modifier
#include "ModifierAddTrailer.h"

//sound
#include "launch_raw.h"

#include "ennemyIA/EnnemyMultipleShotsManager.h"

#include "GameCtrl.h"
#include "GameScene.h"

#include "FadingDecal.h"

#include "invoc_final_sound_raw.h"

#include "CFlashDecal.h"

#include <vector>

using namespace std;







extern const unsigned short scrBottomOption_map[58][32];

// for some odd reason I can't seem to find vcount in ndslib -sigh- (I mean, in a place it doesn't conflict with other things)
#define		VCOUNT		(*((u16 volatile *) 0x04000006))

char szPersName[20];

//---------------------------------------------------------------------------------
// Dswifi stub functions
//void * sgIP_malloc(int size) { return malloc(size); }
//void sgIP_free(void * ptr) { free(ptr); }

// sgIP_dbgprint only needed in debug version
//void sgIP_dbgprint(char * txt, ...) {
//}

// wifi timer function, to update internals of sgIP
//void Timer_50ms(void) {
//   Wifi_Timer(50);
//}

// notification function to send fifo message to arm7
//void arm9_synctoarm7() { // send fifo message
//   REG_IPC_FIFO_TX=0x87654321;
//}

// interrupt handler to receive fifo messages from arm7
//void arm9_fifo() { // check incoming fifo messages
//   u32 value = REG_IPC_FIFO_RX;
//   if(value == 0x87654321) Wifi_Sync();
//}

//******************************************************************************
//  Init wifi communication
//******************************************************************************
void wifiInit() {
  // send fifo message to initialize the arm7 wifi
  REG_IPC_FIFO_CR = IPC_FIFO_ENABLE | IPC_FIFO_SEND_CLEAR; // enable & clear FIFO

  u32 Wifi_pass= Wifi_Init(WIFIINIT_OPTION_USELED);
  REG_IPC_FIFO_TX=0x12345678;
  REG_IPC_FIFO_TX=Wifi_pass;

  *((volatile u16 *)0x0400010E) = 0; // disable timer3

#if 0
  // TODO: Re-enable
  irqSet(IRQ_TIMER3, Timer_50ms); // setup timer IRQ
  irqEnable(IRQ_TIMER3);
  irqSet(IRQ_FIFO_NOT_EMPTY, arm9_fifo); // setup fifo IRQ
  irqEnable(IRQ_FIFO_NOT_EMPTY);

  REG_IPC_FIFO_CR = IPC_FIFO_ENABLE | IPC_FIFO_RECV_IRQ; // enable FIFO IRQ

  Wifi_SetSyncHandler(arm9_synctoarm7); // tell wifi lib to use our handler to notify arm7
#endif
  // set timer3
  *((volatile u16 *)0x0400010C) = -6553; // 6553.1 * 256 cycles = ~50ms;
  *((volatile u16 *)0x0400010E) = 0x00C2; // enable, irq, 1/256 clock

  while(Wifi_CheckInit()==0) { // wait for arm7 to be initted successfully
    while(VCOUNT>192); // wait for vblank
    while(VCOUNT<192);
  }
} // wifi init complete - wifi lib can now be used!

//******************************************************************************
//  Init wifi communication via WFC
//******************************************************************************
u8 wifiConnect(void) {
  int i;
  u8 uOK=0x00;

#ifdef DEBUG
  iprintf("Connecting via WFC data\n");
#endif
  // simple WFC connect:
  Wifi_AutoConnect(); // request connect
  while(1) {
    i=Wifi_AssocStatus(); // check status
    if(i==ASSOCSTATUS_ASSOCIATED) {
#ifdef DEBUG
      iprintf("Connected successfully!\n");
#endif
      uOK = 0x01;
      break;
    }
    if(i==ASSOCSTATUS_CANNOTCONNECT) {
#ifdef DEBUG
      iprintf("Could not connect!\n");
#endif
      uOK = 0x00;
      break;
    }
  }
  return(uOK);
} // if connected, you can now use the berkley sockets interface to connect to the internet!

int StrToInt(string text) {
       int number;
       std::istringstream ss( text );
       ss >> number;

       return number;
}


vector<string> explode(string s, string e) {
 vector<string> ret;
 int iPos = s.find(e, 0);
 int iPit = e.length();
 while(iPos>-1) {
   if(iPos!=0)
     ret.push_back(s.substr(0,iPos));
   s.erase(0,iPos+iPit);   // poistetaan stringistä ylimääräiset scheißet
   iPos = s.find(e, 0);    // haetaan erottimen sijainti
 } // end while
 if(s!="")
   ret.push_back(s);
 return ret;
}

CNetworkAI::CNetworkAI() :CSimpleAI() {
            lastPassedTime = GameCtrl::getSharedObject()->getPassedTime();
    GameScene::ennemy_life = CFixed(500);
    nextThink = 1;

    //GameCtrl::getSharedObject()->drawPersistentOnScreen(128,110,"wifi connection started");

    //PA_InitWifi(); //Initializes the wifi

    //while (!PA_ConnectWifiWFC()) {
    //}

    connected = 0;

    GameScene::getInstance()->started = 0;
}

CNetworkAI::~CNetworkAI() {
    //wifiDisable();
    if (sock)
      close(sock);

    Wifi_DisconnectAP();
    Wifi_DisableWifi();
}

void CNetworkAI::connect() {
    if (connected == 0) {
        GameCtrl::getSharedObject()->drawOnScreen(128,110,"wifi connection started");
        connected=1;

        textDecal = new CTextDecal("connecting...");
        textDecal->setX(128);
        textDecal->setY(128);

        GameCtrl::getSharedObject()->addDecoSprite(textDecal);

        return;
    }

    wifiInit();
    if(!wifiConnect()) {
        GameCtrl::getSharedObject()->drawOnScreen(128,130,"error during wfc connection");
        GameCtrl::getSharedObject()->addDecoSprite(new FadingDecal());
        return;
    }

    connected = 2;

    PA_InitSocket(&sock,"srv.lo2k.net",7000,PA_NONBLOCKING_TCP);
    int i = 1;
    ioctl(sock, FIONBIO, &i);

    if ((sock == -1)||(sock == 0)) {
        GameCtrl::getSharedObject()->drawOnScreen(128,130,"could not connect to the server");
        GameCtrl::getSharedObject()->addDecoSprite(new FadingDecal());
        return;
    }


    ostringstream oss;
    oss << "connect " << string((char *)PA_UserInfo.Name) << + "\n\r";

    string msg = oss.str();

    send(sock,msg.c_str(),msg.size(),0);

    memset(_tmp_buffer,0,sizeof(_tmp_buffer));

    iter = 0;
    userid = 0;
    gameid = 0;
    start = 0;

    textDecal->text = "Searching an opponent";


    //GameScene::getInstance()->paused = 1;
}

void CNetworkAI::thinking()
{

    if (connected!=2) {
        connect();
        return;
    }


    if (recv(sock,_tmp_buffer,32,0)) {
        buffer = buffer + string(_tmp_buffer);

         string e = "\n\r";
         vector<string> ret;
         int iPos = buffer.find(e, 0);
         int iPit = e.length();
         while(iPos>-1) {
           if(iPos!=0)
             interpret(buffer.substr(0,iPos));
             //ret.push_back(s.substr(0,iPos));
           buffer.erase(0,iPos+iPit);   // poistetaan stringistä ylimääräiset scheißet
           iPos = buffer.find(e, 0);    // haetaan erottimen sijainti
         } // end while
         //if(s!="")
           //ret.push_back(s);
           memset(_tmp_buffer,0,sizeof(_tmp_buffer));
        }


      iter ++;

      if (iter >= 5) {
        iter = 0;
             if (start == 1) {
                   ostringstream oss;
                   oss << "update "<< (int) gameid <<" " << (int)userid<<  " " << (int)GameScene::life <<" "<< (int)GameScene::shield <<" "<< (int)GameScene::mana <<" " <<"\n\r";

                   send(sock,oss.str().c_str(),oss.str().size(),0);
             } else {
                   ostringstream oss;
                   oss << "still "<< (int)userid<<  "\n\r";

                   send(sock,oss.str().c_str(),oss.str().size(),0);

             }
         }




}

void CNetworkAI::interpret(string s) {
    DebugLogger::write("Network :"+s);

    vector<string> args = explode(s," ");

    string command = args[0];



    if (command=="id") {
        userid = StrToInt(args[1]);
        DebugLogger::write("Identification OK");
    }
    else if (command == "start") {
        gameid = StrToInt(args[1]);
        GameScene::getInstance()->enemy_name = args[2];
        GameScene::getInstance()->player_id = StrToInt(args[3]);
        GameScene::getInstance()->ennemy_id = StrToInt(args[4]);
        start =1;
        GameScene::getInstance()->started = 1;

        textDecal->dead();

        GC_playSound(invoc_final_sound_raw);


        GameCtrl::getSharedObject()->addDecoSprite(new CFlashDecal());
    }
    else if (command == "meteor") {
            CBullet * s = new CBullet(StrToInt(args[6]));
            s->setX(StrToInt(args[1]));
            s->setY(StrToInt(args[2]));
            s->setVel(((float)StrToInt(args[3]))/10, ((float)StrToInt(args[4]))/15);
            s->weight = StrToInt(args[5]);
            s->setSize (sqrt(s->weight)*0.1);

            if (rand()%2==1) {
                s->type = s->type^MERGEABLE;
            }

            new ModifierAddTrailer(s);

            GameCtrl::getSharedObject()->addSprite(s);
            GC_playSound(launch_raw);
    } else if (command=="update") {
            GameScene::ennemy_life = CFixed(StrToInt(args[1]));
            GameScene::ennemy_shield = CFixed(StrToInt(args[2]));
            GameScene::ennemy_mana = CFixed(StrToInt(args[3]));

    }
    else if (command == "quit") {
            GameCtrl::getSharedObject()->addDecoSprite(new FadingDecal());
    }
}


void CNetworkAI::manageBullet(int bulletSize, CBullet * meteor) {
   //do nothing, you are in marathon
   //GameScene::ennemy_life = GameScene::ennemy_life+ CFixed(bulletSize);
   ostringstream oss;
   oss << "meteor " << (int)meteor->x << " "
   << (int)meteor->y << " " << (int)(meteor->velX*CFixed(10)) << " " <<
   (int)(meteor->velY*CFixed(10)) << " " << (int)meteor->weight << " " << (int)(meteor->type & OWNER_MASK) << " " << userid << "\n\r";

   send(sock,oss.str().c_str(),oss.str().size(),0);
}
