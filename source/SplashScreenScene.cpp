/*

    Sprite class for player ship

*/

#include "SplashScreenScene.h"

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

#include "cinematic_sound_raw.h"

#include "FadingDecal.h"

#include "CFlashDecal.h"


SplashScreenScene::SplashScreenScene(): CScene()  {
    GameCtrl * gc = GameCtrl::getSharedObject();
    CSprite::flushTex();
    gc->flushSprites();
}

SplashScreenScene::~SplashScreenScene() {

}

void SplashScreenScene::render() {



    GameCtrl * gc = GameCtrl::getSharedObject();

    CFlashDecal * flash = new CFlashDecal();
    flash->color = RGB15(0,0,0);

    gc->addDecoSprite(flash);


    fading = 0;

    int i = 0;

	while(_run)
	{
	   //Update only one time of two, else the game will run too fast!
	   if (!ulGetMainLcd())			{
             gc->update();
		   //Read keys
		   ulReadKeys(0);
           //if (ul_keys.touch.doubleClick) {
           i++;
           if (ul_keys.held.touch&&(i>20)) {

                       if (!fading) {
                            GameCtrl::getSharedObject()->addDecoSprite(new FadingDecal());
                            fading = 1;
                            GC_playSound(error_sound_raw);
                        }
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

		}

		//End the drawing
		ulEndDrawing();

		//Wait the VBlank (synchronize at 60 fps)

		ulSyncFrame();
	}
}
