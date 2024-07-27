/*

    Sprite class for player ship

*/

#include "StoryScene.h"

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

#include "HelpScene.h"
#include "GameScene.h"
#include "ScoreScene.h"
#include "MenuScene.h"

#include "StoryCinematicScene.h"

#include "CSimpleAI.h"

#include "SplashScreenScene.h"

#include "congrat_img.h"

#include "SaveManager.h"

CSimpleAI * StoryScene::generateAI(int level) {
    CSimpleAI * ennemy_ai = NULL;
    if (level ==1) {
        ennemy_ai = new CSimpleAI();
        //ennemy_ai->extraPower = 0;

        GameScene::player_id = 2;
        GameScene::ennemy_id = 3;


    }

    if (level == 2) {
        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 10;
        ennemy_ai->probaAbsorb = 20;

        GameScene::player_id = 2;
        GameScene::ennemy_id = 1;

    }

   if (level == 3) {
        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 10;
        ennemy_ai->probaPartialDmg = 80;
        ennemy_ai->mana_gain = CFixed(1);

        ennemy_ai->probaSimpleAttack = 0;
        ennemy_ai->probaMassiveAttack = 50;
        ennemy_ai->probaMeteorAttack = 0;
        ennemy_ai->probaShrapnelAttack = 50;

        GameScene::player_id = 1;
        GameScene::ennemy_id = 5;

    }

   if (level == 4) {
        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaAbsorb = 10;
        ennemy_ai->probaTotalStop = 15;
        ennemy_ai->probaPartialDmg = 75;
         ennemy_ai->reactivity = 0.8;
         ennemy_ai->extraPower = 4;

        GameScene::player_id = 5;
        GameScene::ennemy_id = 4;


    }

       if (level == 5) {
        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 20;
        ennemy_ai->probaPartialDmg = 100;
        ennemy_ai->reactivity = 0.5;
        ennemy_ai->probaAbsorb = 10;
        ennemy_ai->extraPower = 3;
        ennemy_ai->mana_gain = CFixed(0.6);

        ennemy_ai->probaShrapnelAttack = 10;

        GameScene::player_id = 4;
        GameScene::ennemy_id = 5;


    }

       if (level == 6) {
        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 25;
        ennemy_ai->probaPartialDmg = 75;
        ennemy_ai->reactivity= 0.2;
        ennemy_ai->extraPower = 4;
        ennemy_ai->probaAbsorb = 30;
        ennemy_ai->mana_gain = CFixed(0.8);

        ennemy_ai->probaShrapnelAttack = 15;

        GameScene::player_id = 3;
        GameScene::ennemy_id = 2;


    }

     if (level == 7) {
        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 25;
        ennemy_ai->probaPartialDmg = 75;
        ennemy_ai->reactivity= 0.1;
        ennemy_ai->extraPower = 1;
        ennemy_ai->probaAbsorb = 30;
        ennemy_ai->mana_gain = CFixed(3);


        ennemy_ai->probaShrapnelAttack = 20;

        GameScene::player_id = 1;
        GameScene::ennemy_id = 2;


    }


    if (ennemy_ai == NULL) {
        //error unkown level
        ennemy_ai = new CSimpleAI();
    }

    return ennemy_ai;

}

StoryScene::StoryScene(): CScene()  {
    //CScene::CScene();
    mode = "Normal";
    step = 6;
}

StoryScene::~StoryScene() {

}


void StoryScene::renderCinematic(int i ) {
        StoryCinematicScene * cinematic = new StoryCinematicScene(i);
        cinematic->render();

        delete (cinematic);
}




void StoryScene::render() {

    ScoreScene * score;
    StoryCinematicScene * cinematic;
    /*
        int probaTotalStop;
    int probaDeviation;
    int probaPartialDmg;
    */

    int i = 1;

    int StoryNormalProgress = SaveManager::ent()->getInt("Story"+mode+"Progress"); //get normalStory

    if (!((StoryNormalProgress==0)||(StoryNormalProgress==1))) {
           UL_MSGBOX_BUTTON buttons[2] = {
			    {UL_KEY_A, "A: Resume"},
			    {UL_KEY_B, "B: Start a new game"},
			   };
            //Note the Render argument: this function will be called from within ulMessageBoxEx to render the background image!
		   	int res = GameCtrl::getSharedObject()->messageBox("You have a previous progression, do you want to start from your last save point ?", "Save already exist", 2, buttons);

		   	if (res == 0) {
		   	    i = StoryNormalProgress;
		   	} else {
		   	    SaveManager::ent()->set("Story"+mode+"TimeAttack",0); //reset save progression
		   	}
    } else {
        SaveManager::ent()->set("Story"+mode+"TimeAttack",0); //reset save progression
    }

    for (; i<=step; i++) {

        SaveManager::ent()->set("Story"+mode+"Progress",i); //save progression
        SaveManager::ent()->save();

        CScene::resetScene();

        renderCinematic(i);

        CScene::resetScene();
        game = new GameScene();

        game->preInit();

        game->ennemy_ai = generateAI(i);


        game->render();

        if (game->exitcode == 27) {
            exitcode = 27;
            delete(game);
            nextScene = new MenuScene();
            return;
        } else {

            score = (ScoreScene *)game->nextScene;
            delete(game);

            CScene::resetScene();
            score->render();

            if (!score->win) { //if you loose return to the menu
                delete(score);


                   UL_MSGBOX_BUTTON buttons[2] = {
                        {UL_KEY_A, "A: Yes"},
                        {UL_KEY_B, "B: No"},
                       };
                    //Note the Render argument: this function will be called from within ulMessageBoxEx to render the background image!
                    int res = GameCtrl::getSharedObject()->messageBox("Retry ?", "You loose", 2, buttons);

                    if (res == 0) {
                        i--;
                    } else {
                        nextScene = new MenuScene();
                        return;
                    }
            } else {

                int newtime = SaveManager::ent()->getInt("Story"+mode+"TimeAttack") +(int)score->totalTime;
                SaveManager::ent()->set("Story"+mode+"TimeAttack",newtime); //reset save progression
                SaveManager::ent()->save();
                delete(score);
            }
        }

        //delete(score); //else you continue and delete score Scene
    }

         //you finished the story mode
        SaveManager::ent()->set("Story"+mode+"Progress",0); //reset save progression
        SaveManager::ent()->set("Story"+mode+"Finish",1); //reset save progression


        if (SaveManager::ent()->getInt("Story"+mode+"TimeAttackRecord")==0) {
            SaveManager::ent()->set(("Story"+mode+"TimeAttackRecord"),9999999);
        }

        if (SaveManager::ent()->getInt("Story"+mode+"TimeAttack") < SaveManager::ent()->getInt("Story"+mode+"TimeAttackRecord")) {
            SaveManager::ent()->set("Story"+mode+"TimeAttackRecord",SaveManager::ent()->get("Story"+mode+"TimeAttack"));
        }

        SaveManager::ent()->save();

        displayCongrat();


    //END SHOW CONGRAT

    nextScene = new MenuScene(); //you finished the game ;)

}


void StoryScene::displayCongrat() {
            //SHOW CONGRAT

        CScene::resetScene();
        SplashScreenScene * splash = new SplashScreenScene();

        CSprite * background_haut = new CSprite(128,96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,congrat_img);

        splash->addSprite(background_haut);

        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 90, "congratulation");

        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 100+32+128, "you have finished");
        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 118+32+128, "the normal mode");

        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 150+32+128, "now try the hard mode");
        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 150+32+148, "or maybe the vreemd mode...");

        splash->render();

        delete (splash);
}