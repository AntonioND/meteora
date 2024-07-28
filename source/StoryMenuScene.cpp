/*

    Sprite class for player ship

*/

#include "StoryMenuScene.h"

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

#include "touch_the_screen_png.h"

#include "menu_ambiant_raw.h"

#include "menu_haut_png.h"
#include "menu_bas_story_png.h"

#include "error_sound_raw.h"

#include "GameScene.h"
#include "HelpScene.h"
#include "MenuScene.h"
#include "StoryScene.h"
#include "EasyStoryScene.h"
#include "HardStoryScene.h"
#include "VreemdStoryScene.h"
#include "InsaneStoryScene.h"
#include "MarathonScene.h"

#include "menu_locked_png.h"

#include "FadingDecal.h"

#include "TutorialScene.h"

#include "SaveManager.h"

StoryMenuScene::StoryMenuScene(): CScene()  {
    //CScene::CScene();
}

StoryMenuScene::~StoryMenuScene() {

}

void StoryMenuScene::render() {

    //DEBUG
    DebugLogger::write("begin render story menu scene");
    //END DEBUG


    int fading = 0;

    GameCtrl * gc = GameCtrl::getSharedObject();
    CSprite::flushTex();
    gc->flushSprites();


    gc->curr_channel_loop_2 = GC_playSoundLoop(menu_ambiant_raw);

    CSprite * background_haut = new CSprite(128,96,0);
    //loadTex16col(background_haut,menu_haut_png);
    loadTex(background_haut,title_png);

    CSprite * background_bas = new CSprite(128,192+32+96,0);
    loadTex(background_bas,menu_bas_story_png)

    /*gc->drawPersistentOnScreen(64,196+32+20,"easy");
    gc->drawPersistentOnScreen(64,196+32+90,"normal");
    gc->drawPersistentOnScreen(64,196+32+155,"hard");

    gc->drawPersistentOnScreen(64+128,196+32+20,"locked");
    gc->drawPersistentOnScreen(64+128,196+32+90,"locked");
    gc->drawPersistentOnScreen(64+128,196+32+155,"return");*/
    CSprite * locked;

    if (SaveManager::ent()->getInt("StoryNormalFinish")==0) {

         locked = new CSprite(64+128,196+32+30);
        loadTex16col(locked,menu_locked_png)

        gc->addDecoSprite(locked);
    }

    if (SaveManager::ent()->getInt("StoryHardFinish")==0) {

        locked = new CSprite(64+128,196+32+97);
        loadTex16col(locked,menu_locked_png)

        gc->addDecoSprite(locked);
    }

/**
 ****************** NORMAL MODE
 */
    if (SaveManager::ent()->getInt("StoryNormalFinish")==1) {
                ostringstream oss;
                oss << "Record "<<	timeToString(SaveManager::ent()->getInt("StoryNormalTimeAttackRecord")) << "s";

                CTextDecal * txt = new CTextDecal(oss.str());
                txt->x = 10;
                txt->y = 192+32+99;

                gc->addSprite(txt);
    } else {
        int StoryNormalProgress = SaveManager::ent()->getInt("StoryNormalProgress"); //get normalStory

        if (!((StoryNormalProgress==0)||(StoryNormalProgress==1))) {

                ostringstream oss;
                oss << ">> level "<<	StoryNormalProgress;
                CTextDecal * txt = new CTextDecal(oss.str().c_str());
                txt->x = 10;
                txt->y = 192+32+99;

                gc->addSprite(txt);
        } else {
                CTextDecal * txt = new CTextDecal("Unfinished");
                txt->x = 20;
                txt->y = 192+32+99;

                gc->addSprite(txt);

        }

    }

/**
 ****************** EASY MODE
 */
    if (SaveManager::ent()->getInt("StoryEasyFinish")==1) {
                ostringstream oss;
                oss << "Record "<<	timeToString(SaveManager::ent()->getInt("StoryEasyTimeAttackRecord")) << "s";

                CTextDecal * txt = new CTextDecal(oss.str());
                txt->x = 10;
                txt->y = 192+32+35;

                gc->addSprite(txt);
    } else {
        int StoryNormalProgress = SaveManager::ent()->getInt("StoryEasyProgress"); //get normalStory

        if (!((StoryNormalProgress==0)||(StoryNormalProgress==1))) {

                ostringstream oss;
                oss << ">> to level "<<	StoryNormalProgress;
                CTextDecal * txt = new CTextDecal(oss.str().c_str());
                txt->x = 10;
                txt->y = 192+32+35;

                gc->addSprite(txt);
        } else {
                CTextDecal * txt = new CTextDecal("Unfinished");
                txt->x = 20;
                txt->y = 192+32+35;

                gc->addSprite(txt);

        }
    }


 /**
 ****************** HARD MODE
 */

    if (SaveManager::ent()->getInt("StoryHardFinish")==1) {
                ostringstream oss;
                oss << "Record "<<	timeToString(SaveManager::ent()->getInt("StoryHardTimeAttackRecord")) << "s";

                CTextDecal * txt = new CTextDecal(oss.str());
                txt->x = 10;
                txt->y = 192+32+163;

                gc->addSprite(txt);
    } else {
        int StoryNormalProgress = SaveManager::ent()->getInt("StoryHardProgress"); //get normalStory

        if (!((StoryNormalProgress==0)||(StoryNormalProgress==1))) {

                ostringstream oss;
                oss << ">> level "<<	StoryNormalProgress;
                CTextDecal * txt = new CTextDecal(oss.str().c_str());
                txt->x = 10;
                txt->y = 192+32+163;

                gc->addSprite(txt);
        } else {
                CTextDecal * txt = new CTextDecal("Unfinished");
                txt->x = 20;
                txt->y = 192+32+163;

                gc->addSprite(txt);

        }
    }

 /**
 ****************** Vreemd MODE
 */

    if (SaveManager::ent()->getInt("StoryVreemdFinish")==1) {
                ostringstream oss;
                oss << "Record "<<	timeToString(SaveManager::ent()->getInt("StoryVreemdTimeAttackRecord")) << "s";

                CTextDecal * txt = new CTextDecal(oss.str());
                txt->x = 145;
                txt->y = 192+32+35;

                gc->addSprite(txt);
    } else {
        int StoryNormalProgress = SaveManager::ent()->getInt("StoryVreemdProgress"); //get normalStory

        if (!((StoryNormalProgress==0)||(StoryNormalProgress==1))) {

                ostringstream oss;
                oss << ">> level "<<	StoryNormalProgress;
                CTextDecal * txt = new CTextDecal(oss.str().c_str());
                txt->x = 145;
                txt->y = 192+32+35;

                gc->addSprite(txt);
        } else {
                CTextDecal * txt = new CTextDecal("Unfinished");
                txt->x = 145;
                txt->y = 192+32+35;

                gc->addSprite(txt);

        }
    }


 /**
 ****************** Insane MODE
 */

    if (SaveManager::ent()->getInt("StoryInsaneFinish")==1) {
                ostringstream oss;
                oss << "Record "<<	timeToString(SaveManager::ent()->getInt("StoryInsaneTimeAttackRecord")) << "s";

                CTextDecal * txt = new CTextDecal(oss.str());
                txt->x = 145;
                txt->y = 192+32+99;

                gc->addSprite(txt);
    } else {
        int StoryNormalProgress = SaveManager::ent()->getInt("StoryInsaneProgress"); //get normalStory

        if (!((StoryNormalProgress==0)||(StoryNormalProgress==1))) {

                ostringstream oss;
                oss << ">> level "<<	StoryNormalProgress;
                CTextDecal * txt = new CTextDecal(oss.str().c_str());
                txt->x = 145;
                txt->y = 192+32+99;

                gc->addSprite(txt);
        } else {
                CTextDecal * txt = new CTextDecal("Unfinished");
                txt->x = 145;
                txt->y = 192+32+99;

                gc->addSprite(txt);

        }
    }



/**
 ************************ MAIN LOOP
 */


	while(_run)
	{
	   //Update only one time of two, else the game will run too fast!
	   if (!ulGetMainLcd())			{
             gc->update();
		   //Read keys
		   ulReadKeys(0);
           //if (ul_keys.touch.doubleClick) {
           if (ul_keys.held.touch) {
             if (ul_keys.touch.y>10&&ul_keys.touch.y<53) {
                if (ul_keys.touch.x<126) {
                        if (!fading) {
                            GameCtrl::getSharedObject()->addDecoSprite(new FadingDecal());
                            fading = 1;
                            GC_playSound(error_sound_raw);
                            this->nextScene = new EasyStoryScene();
                        }



                    //this->nextScene = new GameScene();
                } else {

                        if (SaveManager::ent()->getInt("StoryNormalFinish")==1) {

                            if (!fading) {
                                GameCtrl::getSharedObject()->addDecoSprite(new FadingDecal());
                                fading = 1;
                                GC_playSound(error_sound_raw);
                                this->nextScene = new VreemdStoryScene();
                            }
                        }



                }
             }



          if (ul_keys.touch.y>80&&ul_keys.touch.y<119) {
                if (ul_keys.touch.x<126) {
                        if (!fading) {
                            GameCtrl::getSharedObject()->addDecoSprite(new FadingDecal());
                            fading = 1;
                            GC_playSound(error_sound_raw);
                            this->nextScene = new StoryScene();
                        }



                    //this->nextScene = new GameScene();
                } else {

                    if (SaveManager::ent()->getInt("StoryHardFinish")==1) {
                        if (!fading) {
                            GameCtrl::getSharedObject()->addDecoSprite(new FadingDecal());
                            fading = 1;
                            GC_playSound(error_sound_raw);
                            this->nextScene = new InsaneStoryScene();
                        }
                    }



                }
             }



           if (ul_keys.touch.y>144&&ul_keys.touch.y<183) {
                if (ul_keys.touch.x<126) {
                        if (!fading) {
                            GameCtrl::getSharedObject()->addDecoSprite(new FadingDecal());
                            fading = 1;
                            GC_playSound(error_sound_raw);
                            this->nextScene = new HardStoryScene();
                        }



                    //this->nextScene = new GameScene();
                } else {

                        if (!fading) {
                            GameCtrl::getSharedObject()->addDecoSprite(new FadingDecal());
                            fading = 1;
                            GC_playSound(error_sound_raw);
                            this->nextScene = new MenuScene();
                        }



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

	soundKill(gc->curr_channel_loop_2);
	//delete(bg_haut);

}
