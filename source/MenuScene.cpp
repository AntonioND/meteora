/*

    Sprite class for player ship

*/

#include "MenuScene.h"

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
#include "CTextDecal.h"
#include "SaveManager.h"

#include "img_evolution_tag_png.h"

#include "menu_ambiant_raw.h"

#include "menu_haut_png.h"
#include "menu_bas_png.h"

#include "error_sound_raw.h"

#include "GameScene.h"
#include "HelpScene.h"
#include "StoryScene.h"
#include "StoryMenuScene.h"
#include "MarathonScene.h"

#include "FadingDecal.h"

#include "TutorialScene.h"
#include "NetworkScene.h"

#include "DSIO.h"
#include "DSIO_tag_png.h"

MenuScene::MenuScene(): CScene()  {
    //CScene::CScene();
}

MenuScene::~MenuScene() {

}

void MenuScene::render() {

    //DEBUG
    DebugLogger::write("begin render menu scene");
    //END DEBUG

    int fading = 0;

    GameCtrl * gc = GameCtrl::getSharedObject();
    CSprite::flushTex();
    gc->flushSprites();


    PA_PlaySoundRepeat(15, menu_ambiant_raw);

    CSprite * background_haut = new CSprite(128,96,0);
    //loadTex16col(background_haut,menu_haut);
    loadTex(background_haut,title_png);

    CSprite * background_bas = new CSprite(128,192+32+96,0);
    loadTex(background_bas,menu_bas_png)

    CPulseDecal * evo = new CPulseDecal();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
    evo->setX(191);
    evo->setY(89);
    evo->setVel(0,0);
    loadTex16col(evo,img_evolution_tag_png)

    gc->addDecoSprite(evo);


    if (DSIO::ent()->hasDSIO) {
        CPulseDecal * dsioim = new CPulseDecal();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
        dsioim->setX(128);
        dsioim->setY(125);
        dsioim->setVel(0,0);
        loadTex16col(dsioim,DSIO_tag_png)

        gc->addDecoSprite(dsioim);


    }



    /**
 ****************** MARATHON MODE
 */

                ostringstream oss;
                oss << "Record "<<	timeToString(SaveManager::ent()->getInt("MarathonTimeRecord")) << "s";

                CTextDecal * txt = new CTextDecal(oss.str());
                txt->x = 149;
                txt->y = 192+32+68;

                gc->addSprite(txt);


	while(_run)
	{
	   //Update only one time of two, else the game will run too fast!
	   if (!ulGetMainLcd())			{
             gc->update();


             //ADD DECALS

             if (!fading) {

                    CDecal * bulletS = new CDecal();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
                    bulletS->setX(CFixed(-10));
                    bulletS->setY((int)rand()%60+110);
                    bulletS->setVel(5,0);
                    bulletS->size=((double)(rand()%8))/8;
                    loadTex16col(bulletS,crap_small_png)

                    gc->addDecoSprite(bulletS);

                    bulletS = new CDecal();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
                    bulletS->setX(CFixed(-10));
                    bulletS->setY((int)rand()%60+110);
                    bulletS->setVel(3,0);
                    bulletS->size=((double)(rand()%8))/8;
                    loadTex16col(bulletS,crap_small_png)

                    gc->addDecoSprite(bulletS);

                    CPixelDecal * bulletS2;
                    bulletS2 = new CPixelDecal();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
                    bulletS->setX(CFixed(-10));
                    bulletS->setY((int)rand()%60+110);
                    bulletS->setVel(2,0);
                    bulletS->size=((double)(rand()%8))/16;

                    //loadTex16col(bulletS,crap_small)

                    gc->addDecoSprite(bulletS2);

                    bulletS2 = new CPixelDecal();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
                    bulletS->setX(CFixed(-10));
                    bulletS->setY((int)rand()%60+110);
                    bulletS->setVel(3,0);
                    bulletS->size=((double)(rand()%8))/16;

                    //loadTex16col(bulletS,crap_small)

                    gc->addDecoSprite(bulletS2);
             }


             //END ADD DECALS
















		   //Read keys
		   ulReadKeys(0);
           //if (ul_keys.touch.doubleClick) {
           if (ul_keys.held.touch) {
             if (ul_keys.touch.y>25&&ul_keys.touch.y<105) {
                if (ul_keys.touch.x<126) {
                        if (!fading) {
                            GameCtrl::getSharedObject()->addDecoSprite(new FadingDecal());
                            fading = 1;
                            GC_playSound(error_sound_raw);
                            this->nextScene = new StoryMenuScene();
                        }



                    //this->nextScene = new GameScene();
                } else {

                        if (!fading) {
                            GameCtrl::getSharedObject()->addDecoSprite(new FadingDecal());
                            fading = 1;
                            GC_playSound(error_sound_raw);
                            this->nextScene = new MarathonScene();
                        }



                }
             }

                 if (ul_keys.touch.y>=105&&ul_keys.touch.y<186) {

                  if (ul_keys.touch.x<126) {
                                if (!fading) {
                                GameCtrl::getSharedObject()->addDecoSprite(new FadingDecal());
                                fading = 1;
                                GC_playSound(error_sound_raw);
                                this->nextScene = new NetworkScene();

                                }
                  } else {
                                if (!fading) {
                                GameCtrl::getSharedObject()->addDecoSprite(new FadingDecal());
                                fading = 1;
                                GC_playSound(error_sound_raw);
                                this->nextScene = new TutorialScene();
                                }
                    //this->nextScene = new GameScene();
                  }

                }
             }




        }


	   //Start our drawing

		ulStartDrawing2D();

		if (!ulGetMainLcd())		{
		    //bg_haut->draw(0);
            background_haut->draw(0);
            gc->draw(0);

		}
		else			{
            background_bas->draw(SCREEN_HEIGHT + BORDER_HEIGHT);
            gc->draw(SCREEN_HEIGHT + BORDER_HEIGHT);
		}

		//End the drawing
		ulEndDrawing();

		//Wait the VBlank (synchronize at 60 fps)

		ulSyncFrame();
	}

/*


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

*/


	delete(background_haut);
	delete(background_bas);
	//delete(black_screen_sprite);

	PA_StopSound(15);
	//delete(bg_haut);

    CSprite::flushTex();
    gc->flushSprites();

}
