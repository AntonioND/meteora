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

#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#include <dswifi9.h>

#include <vector>

using namespace std;







extern const unsigned short scrBottomOption_map[58][32];

char szPersName[20];

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

void CNetworkAI::connect_() {
    if (connected == 0) {
        GameCtrl::getSharedObject()->drawOnScreen(128,110,"wifi connection started");
        connected=1;

        textDecal = new CTextDecal("connecting...");
        textDecal->setX(128);
        textDecal->setY(128);

        GameCtrl::getSharedObject()->addDecoSprite(textDecal);

        return;
    }

    if(!Wifi_InitDefault(WFC_CONNECT)) {
        GameCtrl::getSharedObject()->drawOnScreen(128,130,"error during wifi connection");
        GameCtrl::getSharedObject()->addDecoSprite(new FadingDecal());
        return;
    }

    connected = 2;

    int port = 7000;
    const char *host = "srv.lo2k.net";

    sock = socket(AF_INET, SOCK_STREAM, 0);
    unsigned long ip = *(unsigned long *)gethostbyname(host)->h_addr_list[0];

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = ip;

    // Non-blocking TCP
    if (connect(sock, (struct sockaddr *) &servaddr, sizeof(servaddr)) != 0) {
        GameCtrl::getSharedObject()->drawOnScreen(128,130,"could not connect to the server");
        GameCtrl::getSharedObject()->addDecoSprite(new FadingDecal());
        return;
    }

    int i = 1;
    ioctl(sock, FIONBIO, &i);

    if ((sock == -1)||(sock == 0)) {
        GameCtrl::getSharedObject()->drawOnScreen(128,130,"could not ioctl() to the server");
        GameCtrl::getSharedObject()->addDecoSprite(new FadingDecal());
        return;
    }

    // Clamp from UTF-16 to ASCII (we can't display non-ASCII chars anyway...)
    char name[10 + 1];
    for (i = 0; i < PersonalData->nameLen; i++)
        name[i] = PersonalData->name[i];
    name[i] = '\0';

    ostringstream oss;
    oss << "connect " << string(name) << + "\n\r";

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
        connect_();
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
