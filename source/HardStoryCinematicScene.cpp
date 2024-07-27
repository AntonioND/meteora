/*

    Sprite class for player ship

*/

#include "HardStoryCinematicScene.h"

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
#include "story_duplicate_png.h"
#include "story_thedig_png.h"
#include "story_thebrain_png.h"

#include "story_final_png.h"

#include "cinematic_sound_raw.h"



HardStoryCinematicScene::HardStoryCinematicScene(int i): CScene()  {
    //CScene::CScene();

    number = i;
}

HardStoryCinematicScene::~HardStoryCinematicScene() {

}

void HardStoryCinematicScene::render() {

    GameCtrl * gc = GameCtrl::getSharedObject();
    CSprite::flushTex();
    gc->flushSprites();


    string description = "";
    string description2 = "";

    PA_StopSound(12);
    PA_PlaySoundRepeat(12, cinematic_sound_raw);

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
    toptitle << "hard mode"<< (int)number;
    gc->drawPersistentOnScreen(160, 20, toptitle.str().c_str());




    if (number ==1 ) {
        loadTex(scrapper,story_1_png);
        description = "planet of evil toudouxmous,";
        description2= "Now they have weapons";

        ulSetImageTint(scrapper->spriteTex, RGB15(31,12,12));
    }
    if (number ==2 ) {
        loadTex(scrapper,story_duplicate_png);
        description = "Duplicate that's that ?";
    }
    if (number ==3 ) {
        loadTex(scrapper,story_thedig_png);
        description = "A portal to an other world ?";
        description2= "seems to be cool ;)";
    }
    if (number ==4 ) {
        loadTex(scrapper,story_duplicate_png);
        description = "Him ? Again ? Is it a mirror ?";
        description2 = "What the hell ?";
        ulSetImageTint(scrapper->spriteTex, RGB15(12,31,12));
    }
    if (number ==5 ) {
        loadTex(scrapper,story_4_png);
        ulSetImageTint(scrapper->spriteTex, RGB15(31,31,8));
        description = "Dark energy generator...";
        description2 = "Destroy the origin of evil energy";
    }

        if (number ==6 ) {
        loadTex(scrapper,story_thebrain_png);
        description = "I think...";
        description2 = "He's not so stupid...";
    }

        if (number ==7 ) {
        loadTex(scrapper,story_duplicate_png);
        description = "AAARHHHH...";
        description2 = "Finish him...";
        ulSetImageTint(scrapper->spriteTex, RGB15(31,12,12));
    }

        if (number ==8 ) {
        loadTex(scrapper,story_final_png);
        description = "The source of all evil";
        description2 = "BEWARE !!!!";
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
