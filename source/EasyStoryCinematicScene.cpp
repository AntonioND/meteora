/*

    Sprite class for player ship

*/

#include "EasyStoryCinematicScene.h"

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
#include "HelpScene.h"
#include "StoryScene.h"
#include "MarathonScene.h"

#include "story_1_png.h"
#include "story_2_png.h"
#include "story_3_png.h"
#include "story_4_png.h"
#include "story_5_png.h"
#include "story_7_png.h"

#include "story_final_png.h"

#include "story_duplicate_png.h"
#include "story_thedig_png.h"
#include "story_thebrain_png.h"

#include "cinematic_sound_raw.h"



EasyStoryCinematicScene::EasyStoryCinematicScene(int i): CScene()  {
    //CScene::CScene();

    number = i;
}

EasyStoryCinematicScene::~EasyStoryCinematicScene() {

}

void EasyStoryCinematicScene::render() {

    GameCtrl * gc = GameCtrl::getSharedObject();
    CSprite::flushTex();
    gc->flushSprites();


    string description = "";
    string description2 = "";

    soundKill(gc->curr_channel_loop_1);
    gc->curr_channel_loop_1 = GC_playSoundLoop(cinematic_sound_raw);

    /*CSprite * background_haut = new CSprite(128,96,0);
    //loadTex16col(background_haut,menu_haut);
    loadTex(background_haut,title);

    CSprite * background_bas = new CSprite(128,192+32+96,0);
    loadTex(background_bas,menu_bas)
    */

    CSprite * scrapper = new CSprite(80,106,0);

    scrapper->setVelX(CFixed(0)+CFixed(0.2));

    loadTex(scrapper,story_final_png);

    gc->addDecoSprite(scrapper);

    ostringstream toptitle;
    toptitle << "easy mode"<< (int)number;
    gc->drawPersistentOnScreen(160, 20, toptitle.str().c_str());




    if (number ==1 ) {
        loadTex(scrapper,story_1_png);
        description = "planet of toudouxmous,";
        description2= "They sleep, atttack and destroy";
    }
    if (number ==2 ) {
        loadTex(scrapper,story_duplicate_png);
        description = "Hmm this planet seems to be down";
        description2= "Just a piece of cake...";
    }
    if (number ==3 ) {
        loadTex(scrapper,story_1_png);
        description = "Revange of toudouxmous";
        description2= "be carefull they attack with sweets";
        ulSetImageTint(scrapper->spriteTex, RGB15(31,12,12));
    }
    if (number ==4 ) {
        loadTex(scrapper,story_4_png);
        description = "Do you think it's a problem ?";
        ulSetImageTint(scrapper->spriteTex, RGB15(12,31,12));
    }
    if (number ==5 ) {
        loadTex(scrapper,story_2_png);
        description = "Cool man !!";
        ulSetImageTint(scrapper->spriteTex, RGB15(12,31,12));
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
                    GC_playSound(error_sound_raw);
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

	soundKill(gc->curr_channel_loop_1);
	//delete(bg_haut);

}
