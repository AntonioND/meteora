/*

    Sprite class for player ship

*/

#include "StoryCinematicScene.h"

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

#include "menu_haut.h"
#include "menu_bas.h"

#include "error_sound.h"

#include "GameScene.h"
#include "HelpScene.h"
#include "StoryScene.h"
#include "MarathonScene.h"

#include "story_1.h"
#include "story_2.h"
#include "story_3.h"
#include "story_4.h"
#include "story_5.h"
#include "story_7.h"

#include "story_final.h"

#include "cinematic_sound.h"



StoryCinematicScene::StoryCinematicScene(int i): CScene()  {
    //CScene::CScene();

    number = i;
}

StoryCinematicScene::~StoryCinematicScene() {

}

void StoryCinematicScene::render() {

    GameCtrl * gc = GameCtrl::getSharedObject();
    CSprite::flushTex();
    gc->flushSprites();


    string description = "";
    string description2 = "";

    PA_StopSound(12);
    PA_PlaySoundRepeat(12, cinematic_sound);

    /*CSprite * background_haut = new CSprite(128,96,0);
    //loadTex16col(background_haut,menu_haut);
    loadTex(background_haut,title);

    CSprite * background_bas = new CSprite(128,192+32+96,0);
    loadTex(background_bas,menu_bas)
    */

    CSprite * scrapper = new CSprite(80,106,0);

    scrapper->setVelX(CFixed(0)+CFixed(0.2));

    loadTex(scrapper,story_final);

    gc->addDecoSprite(scrapper);

    ostringstream toptitle;
    toptitle << "Story mode Level "<< (int)number;
    gc->drawPersistentOnScreen(160, 20, toptitle.str().c_str());




    if (number ==1 ) {
        loadTex(scrapper,story_1);
        description = "planet of toudouxmous,";
        description2= "peace and love for all";
    }
    if (number ==2 ) {
        loadTex(scrapper,story_2);
        description = "cold and ice... like";
        description2= "humour of people on it";
    }
    if (number ==3 ) {
        loadTex(scrapper,story_3);
        description = "gigantic ressources,";
        description2= "be carefull";
    }
    if (number ==4 ) {
        loadTex(scrapper,story_4);
        description = "thin but powerfull";
    }
    if (number ==5 ) {
        loadTex(scrapper,story_5);
        description = "@#\"( ^^$�";
        description2 = "NO DATA AVAILABLE";
    }
    if (number ==6 ) {
        loadTex(scrapper,story_7);
        description = "it can see all things";
        description2 = "quick and agressive";
    }

    if (number ==7 ) {
        loadTex(scrapper,story_final);
        description = "source of all evil";
        description2 = "this is your final destination";
    }




    int i=0;

	while(_run)
	{
	   //Update only one time of two, else the game will run too fast!
	   if (!ulGetMainLcd())			{
             gc->update();
		   //Read keys
		   ulReadKeys(0);
           //if (ul_keys.touch.doubleClick) {
           i++;
           if (ul_keys.held.touch&&(i>60)) {

                    CScene::stopScene();
                    GC_playSound(error_sound);
            }


            if ((int)scrapper->x >  170) {
             scrapper->setVelX(CFixed(0)-CFixed(0.2));
            }

            if ((int)scrapper->x <  80) {
             scrapper->setVelX(CFixed(0)+CFixed(0.2));
            }




        }


	   //Start our drawing
		ulStartDrawing2D();

		if (!ulGetMainLcd())		{
		    //bg_haut->draw(0);
            //background_haut->draw(0);
            gc->draw(0);

		}
		else			{
            //background_bas->draw(SCREEN_HEIGHT + BORDER_HEIGHT);
            gc->draw(SCREEN_HEIGHT + BORDER_HEIGHT);


            ostringstream lifeshow;
            lifeshow << description;
            ulDrawString(20, 94, lifeshow.str().c_str());

            ostringstream lifeshow2;
            lifeshow2 << description2;

            ulDrawString(20, 109, lifeshow2.str().c_str());
		}

		//End the drawing
		ulEndDrawing();

		//Wait the VBlank (synchronize at 60 fps)

		ulSyncFrame();
	}




    int offset = 0;
	while(offset <=200) {
	    gc->update();

	    ulStartDrawing2D();

	    if (!ulGetMainLcd())		{
		    //bg_haut->draw(0);
            //background_haut->draw(0);
            gc->draw(0);
            //black_screen_sprite->draw(0);
            ulSetAlpha(UL_FX_ALPHA, 31, 2);
            ulDrawFillRect(0, 0, 256, offset, RGB15(0, 0, 0));
            ulSetAlpha(UL_FX_DEFAULT, 0, 0);

		}
		else			{
            //background_bas->draw(SCREEN_HEIGHT + BORDER_HEIGHT);
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




	//delete(background_haut);
	//delete(background_bas);
	//delete(black_screen_sprite);

	PA_StopSound(12);
	//delete(bg_haut);

}