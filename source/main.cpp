#include <ulib/ulib.h>
#include <PA9.h>

#include <ulib/glWrapper.h>

#include "GameCtrl.h"

#include "main.h"



#include "GameScene.h"
#include "IntroScene.h"
#include "MenuScene.h"
#include "StoryMenuScene.h"

#include "GameCtrl.h"

#include "ScoreScene.h"


// TODO: This header is missing
//#include "modfile.h"

#include <sstream>

#include "SaveManager.h"

#include "FastMath.h"
#include "fat.h"

#include "invoc_final_sound_raw.h"

#include "splash_haut_png.h"
#include "splash_bas_png.h"

#include "pre_title_bas_png.h"
#include "pre_title_haut_png.h"

#include "SplashScreenScene.h"




using namespace std;

#define MAX_BALLS 120

//flush screens with black rectangles
void flushScreen() {

    //DEBUG
    DebugLogger::write("flush screen");
    //END DEBUG


    ulDrawFillRect(0, 0, 256, 192, RGB15(0,0,0));

    //End the drawing
    ulEndDrawing();

    //Wait the VBlank (synchronize at 60 fps)

    ulSyncFrame();

    ulDrawFillRect(0, 0, 256, 192, RGB15(0,0,0));

    //End the drawing
    ulEndDrawing();

    //Wait the VBlank (synchronize at 60 fps)

    ulSyncFrame();

}


int main()
{
    FastMath::init();

    //fatInitDefault();

   	PA_Init();    // PA Init...

	PA_InitVBL();	// VBL Init...
	PA_InitSound(); 	// Sound Init, for the mod player...



	//Initialize µLibrary
	ulInit(UL_INIT_ALL);
	//Initialize the graphical part
	ulInitGfx();
	//Initialize the text part
	ulInitText();

    //WARNING: If you have an error during compilation just below, you need a small hack and add UL_BANK_A_B in ulib header
    //if you want a quick compile without hack just put "UL_BANK_A" but you will very quickly low in memory
    if (!ulSetTexVramParameters(UL_BANK_A | UL_BANK_B, VRAM_A, 256 << 10)) { 
        return 0;
    }


	ulInitDualScreenMode();

if (SaveManager::ent()->isDLDI) {

    if (SaveManager::ent()->get("save?")=="") {
            GC_playSound(invoc_final_sound_raw);

               UL_MSGBOX_BUTTON buttons[2] = {
			    {UL_KEY_A, "A: Yes"},
			    {UL_KEY_B, "B: Yeesss !"}
			   };
		   	int res = GameCtrl::getSharedObject()->messageBox("It seems your savefile does not exist or is corrupted. Create a new one ?", "Savefile does not exist", 2, buttons);
		   	(void)res;

            SaveManager::ent()->data.clear();

		   	SaveManager::ent()->set("save?","DONE");
    }

    SaveManager::ent()->set("boot",SaveManager::ent()->getInt("boot")+1); //increment boot counter

    SaveManager::ent()->save();
} else {

            GC_playSound(invoc_final_sound_raw);

               UL_MSGBOX_BUTTON buttons[2] = {
			    {UL_KEY_A, "A: Oops"},
			    {UL_KEY_B, "B: It's bad"}
			   };
		   	int res = GameCtrl::getSharedObject()->messageBox("Your rom in not compatible with DLDI, please patch it. Save function desactivated.", "NOT DLDI PATCHED", 2, buttons);
		   	(void)res;

            SaveManager::ent()->data.clear();

		   	SaveManager::ent()->set("save?","DONE"); 
    }





    flushScreen();


    ulSetTransparentColor(RGB15(31, 0, 31));



    SplashScreenScene * splash;
    CSprite * spr;

    //first splash
    CScene::resetScene();
    

    spr = new CSprite(128,96,0);
    //loadTex16col(background_haut,menu_haut);
    loadTex(spr,pre_title_haut_png);

    splash->addSprite(spr);


    spr = new CSprite(128,192+32+96,0);
    //loadTex16col(background_haut,menu_haut);
    loadTex(spr,pre_title_bas_png);

    splash->addSprite(spr);


    splash->render();

    delete (splash);


    //second splash
    //NO COMPO SPLASH SCREEN FOR SOURCE RELEASE ;)
    //splash = new SplashScreenScene();
    /*

    CScene::resetScene();
    splash = new SplashScreenScene();

    spr = new CSprite(128,96,0);
    loadTex(spr,splash_haut);

    splash->addSprite(spr);


    spr = new CSprite(128,192+32+96,0);
    loadTex(spr,splash_bas);

    splash->addSprite(spr);


    splash->render();

    delete (splash);




*/


    CScene * currScene;







    currScene = new IntroScene();
    //currScene = new StoryMenuScene();
    //currScene = new GameScene();
    //currScene = new MenuScene();
    //currScene = new ScoreScene();

    while (1) { //render scene, check next scene and render nextscene

            flushScreen();
            CScene::resetScene();

            currScene->render(); //render scene

            CScene * nextScene2 = currScene->nextScene;

            delete currScene;
            currScene = nextScene2;
    }




	//Program end - should never get there
	return 0;
}
