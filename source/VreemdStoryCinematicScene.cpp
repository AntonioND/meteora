/*

    Sprite class for player ship

*/

#include "VreemdStoryCinematicScene.h"

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
#include "story_vreemd_png.h"
#include "story_duplicate_png.h"
#include "story_thedig_png.h"
#include "story_thebrain_png.h"

#include "story_final_png.h"

#include "cinematic_sound_raw.h"



VreemdStoryCinematicScene::VreemdStoryCinematicScene(int i): CScene()  {
    //CScene::CScene();

    number = i;
}

VreemdStoryCinematicScene::~VreemdStoryCinematicScene() {

}

void VreemdStoryCinematicScene::render() {

    GameCtrl * gc = GameCtrl::getSharedObject();
    CSprite::flushTex();
    gc->flushSprites();


    string description = "";
    string description2 = "";

    PA_StopSound(12);
    PA_PlaySoundRepeat(12, cinematic_sound_raw);

    /*CSprite * background_haut = new CSprite(128,96,0);
    //loadTex16col(background_haut,menu_haut_png);
    loadTex(background_haut,title);

    CSprite * background_bas = new CSprite(128,192+32+96,0);
    loadTex(background_bas,menu_bas_png)
    */

    CSprite * scrapper = new CSprite(80,106,0);

    scrapper->setVelX(CFixed(0)+CFixed(0.2));

    loadTex(scrapper,story_final_png);

    gc->addDecoSprite(scrapper);

    ostringstream toptitle;
    toptitle << "vreemd mode"<< (int)number;
    gc->drawPersistentOnScreen(160, 20, toptitle.str().c_str());




    if (number ==1 ) {
        loadTex(scrapper,story_vreemd_png);
        description = "This homebrew was sponsored";
        description2 = "by http://www.dev-fr.org ;)";
        ulSetImageTint(scrapper->spriteTex, RGB15(12,31,12));
    }
    if (number ==2 ) {
        loadTex(scrapper,story_vreemd_png);
        ulSetImageTint(scrapper->spriteTex, RGB15(31,31,8));
        description = "Evil spoon";
        description2 = "Ahhhh a demoniac spoon !!";
    }

        if (number ==3 ) {
        loadTex(scrapper,story_vreemd_png);
        description = "Schyzo";
        description2 = "Psychic power !!!";
    }

        if (number ==4 ) {
        loadTex(scrapper,story_vreemd_png);
        description = "Reppa: go on";
        description2 = "http://reppa.ds-blog.com :D";
    }

    if (number ==5 ) {
        loadTex(scrapper,story_vreemd_png);
        description = "Kukulcan,";
        description2= "master of quizz";

    }
    if (number ==6 ) {
        loadTex(scrapper,story_vreemd_png);
        description = "T4ils";
        description2= "The honorable coder";
    }
    if (number ==7 ) {
        loadTex(scrapper,story_vreemd_png);
        description = "Dr Mollusk";
        description2= "PALib Master";
    }


        if (number ==8 ) {
        loadTex(scrapper,story_vreemd_png);
        description = "Do you think you can beat me ?";
        description2 = "http://scrutator.lo2k.net";
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

	PA_StopSound(12);
	//delete(bg_haut);

}
