/*

    Sprite class for player ship

*/

#include "HelpScene.h"

#include <cstdlib>
#include <time.h>
#include "explosion.h"
#include "small_explosion.h"
#include "CDecal.h"
#include "CPixelDecal.h"

#include "title.h"

#include "crap_small.h"

#include "spacebas_title.h"

#include "explode.h"
#include "CPulseDecal.h"

#include "touch_the_screen.h"

#include "menu_ambiant.h"

#include "error_sound.h"

#include "MenuScene.h"

HelpScene::HelpScene(): CScene()  {
    //CScene::CScene();
}

HelpScene::~HelpScene() {

}

void HelpScene::render() {

    GameCtrl * gc = GameCtrl::getSharedObject();
    CSprite::flushTex();
    gc->flushSprites();


    PA_PlaySoundRepeat(12, menu_ambiant);

    CSprite * background_haut = new CSprite(128,96,0);
//    loadTex(background_haut,tutorial_haut);

    CSprite * background_bas = new CSprite(128,192+32+96,0);
//    loadTex(background_bas,tutorial_bas)

    int i = 0;

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
                    if (i>30) {
                        CScene::stopScene();
                        nextScene = new MenuScene();
                        GC_playSound(error_sound);
                    }
                    //this->nextScene = new GameScene();
                }




		}

	   //Start our drawing
		ulStartDrawing2D();

		if (!ulGetMainLcd())		{
		    //bg_haut->draw(0);
            background_haut->draw(0);
            //gc->draw(0);

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

	//this->nextScene = new GameScene();


    int offset = 0;
	while(offset <=200) {
	    gc->update();

	    ulStartDrawing2D();

	    if (!ulGetMainLcd())		{
		    //bg_haut->draw(0);
            background_haut->draw(0);
            gc->draw(0);
            //black_screen_sprite->draw(0);
            ulSetAlpha(UL_FX_ALPHA, 31, 2);
            ulDrawFillRect(0, 0, 256, offset, RGB15(0, 0, 0));
            ulSetAlpha(UL_FX_DEFAULT, 0, 0);

		}
		else			{
            background_bas->draw(SCREEN_HEIGHT + BORDER_HEIGHT);
            gc->draw(SCREEN_HEIGHT + BORDER_HEIGHT);
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

	PA_StopSound(12);
	//delete(bg_haut);

}
