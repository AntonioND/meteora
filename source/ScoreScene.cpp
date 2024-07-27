/*

    Sprite class for player ship

*/

#include "ScoreScene.h"

#include <cstdlib>
#include <time.h>
#include "explosion_png.h"
#include "small_explosion_png.h"
#include "CDecal.h"
#include "CPixelDecal.h"

#include "title_png.h"

#include "crap_small_png.h"

#include "spacebas_title_png.h"

#include "explode_raw.h"
#include "CPulseDecal.h"

#include "touch_the_screen_png.h"

#include "menu_ambiant_raw.h"

#include "menu_haut_png.h"
#include "menu_bas_png.h"

#include "error_sound_raw.h"

#include "GameScene.h"
#include "MenuScene.h"

#include "winner_sound_raw.h"

#include "score_haut_png.h"

#include "title_png.h"

ScoreScene::ScoreScene(): CScene()  {
    //CScene::CScene();
}

ScoreScene::~ScoreScene() {

}

void ScoreScene::render() {
    //DEBUG
    DebugLogger::write("begin render score scene");
    //END DEBUG


    GameCtrl * gc = GameCtrl::getSharedObject();
    CSprite::flushTex();
    gc->flushSprites();


    PA_PlaySoundRepeat(15, winner_sound_raw);

    CSprite * background_haut = new CSprite(128,96,0);
    loadTex(background_haut,score_haut_png);

    CSprite * background_bas = new CSprite(128,192+32+96,0);
    loadTex(background_bas,title_png)

    int i = 0;

    if (win) {
        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 50, "You win");
    } else {
        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 50, "You loose");
    }



	while(_run)
	{
	   //Update only one time of two, else the game will run too fast!
	   if (!ulGetMainLcd())			{
        i++;
             gc->update();
		   //Read keys
		   ulReadKeys(0);
           //if (ul_keys.touch.doubleClick) {
           if (ul_keys.held.touch) {
                    if (i>40) {
                        CScene::stopScene();
                        GC_playSound(error_sound_raw);
                    }
                    //this->nextScene = new GameScene();

           }

		}

	   //Start our drawing
		ulStartDrawing2D();

		if (!ulGetMainLcd())		{
		    //bg_haut->draw(0);
            background_haut->draw(0);
            gc->draw(0);
            //ulDrawGradientRect(0,0,256,192,RGB15(0,0,255),RGB15(0,0,255),RGB15(0,0,120),RGB15(100,0,120));
            //ulDrawString(90, 50, "Game OVER");

            ostringstream manashow;
            manashow << "Total mana earned:  "<< (int)totalMana;
            ulDrawString(60, 70, manashow.str().c_str());

            ostringstream timeshow;
            timeshow << "Total time:         "<< timeToString(totalTime)<< "s";
            ulDrawString(60, 90, timeshow.str().c_str());




		}
		else			{
            background_bas->draw(SCREEN_HEIGHT + BORDER_HEIGHT);
            //gc->draw(SCREEN_HEIGHT + BORDER_HEIGHT);
		}

		//End the drawing
		ulEndDrawing();

		//Wait the VBlank (synchronize at 60 fps)

		ulSyncFrame();
	}

	this->nextScene = new MenuScene();


    int offset = 0;
	while(offset <=200) {
	    //gc->update();

	    ulStartDrawing2D();

	    if (!ulGetMainLcd())		{
		    //bg_haut->draw(0);
            background_haut->draw(0);
            gc->draw(0);
            //black_screen_sprite->draw(0);
/*
            ulDrawString(90, 50, "Game OVER");
            if (win) {
                ulDrawString(90, 60, "You win");
            } else {
                ulDrawString(90, 60, "You loose");
            }
*/
            ostringstream manashow;
            manashow << "Total mana earned:  "<< (int)totalMana;
            ulDrawString(60, 70, manashow.str().c_str());

            ostringstream timeshow;
            timeshow << "Total time:         "<< timeToString(totalTime) << "s";
            ulDrawString(60, 90, timeshow.str().c_str());




            ulSetAlpha(UL_FX_ALPHA, 31, 2);
            ulDrawFillRect(0, 0, 256, offset, RGB15(0, 0, 0));
            ulSetAlpha(UL_FX_DEFAULT, 0, 0);

		}
		else {
            background_bas->draw(SCREEN_HEIGHT + BORDER_HEIGHT);
            //gc->draw(SCREEN_HEIGHT + BORDER_HEIGHT);
            //black_screen_sprite->draw(0);
            ulSetAlpha(UL_FX_ALPHA, 31, 2);
            ulDrawFillRect(0, 192-offset, 256, 192, RGB15(0, 0, 0));
            ulSetAlpha(UL_FX_DEFAULT, 0, 0);
		}
		//black_screen_sprite->alpha++;

        ulEndDrawing();
		ulSyncFrame();
        offset+=4;
	}




	delete(background_haut);
	delete(background_bas);
	//delete(black_screen_sprite);

	PA_StopSound(15);
	//delete(bg_haut);

}
