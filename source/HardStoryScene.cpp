/*

    Sprite class for player ship

*/

#include "HardStoryScene.h"

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

#include "HardStoryCinematicScene.h"

#include "CSimpleAI.h"

#include "SplashScreenScene.h"

#include "congrat_img.h"

#include "SaveManager.h"

CSimpleAI * HardStoryScene::generateAI(int level) {
    CSimpleAI * ennemy_ai = NULL;
     if (level == 1) {
        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 0;
        ennemy_ai->probaPartialDmg = 70;
        ennemy_ai->reactivity= 1;
        ennemy_ai->extraPower = 2;
        ennemy_ai->probaAbsorb = 30;
        ennemy_ai->mana_gain = CFixed(1.5);


        //ennemy_ai->probaShrapnelAttack = 1;

        GameScene::player_id = 3;
        GameScene::ennemy_id = 2;


    }

     if (level == 2) {
        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 0;
        ennemy_ai->probaPartialDmg = 75;
        ennemy_ai->reactivity= 0.5;
        ennemy_ai->extraPower = 1;
        ennemy_ai->probaAbsorb = 10;
        ennemy_ai->mana_gain = CFixed(2.5);


        ennemy_ai->probaShrapnelAttack = 1;

        GameScene::player_id = 1;
        GameScene::ennemy_id = 2;


    }

         if (level == 3) {
        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 15;
        ennemy_ai->probaPartialDmg = 50;
        ennemy_ai->reactivity= 1;
        ennemy_ai->extraPower = 3;
        ennemy_ai->probaAbsorb = 30;
        ennemy_ai->mana_gain = CFixed(2);


        //ennemy_ai->probaShrapnelAttack = 1;

        GameScene::player_id = 1;
        GameScene::ennemy_id = 2;


    }     if (level == 4) {
        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 10;
        ennemy_ai->probaPartialDmg = 55;
        ennemy_ai->reactivity= 0.4;
        ennemy_ai->extraPower = 2;
        ennemy_ai->probaAbsorb = 20;
        ennemy_ai->mana_gain = CFixed(2.5);


        ennemy_ai->probaMassiveAttack = 100;

        GameScene::player_id = 3;
        GameScene::ennemy_id = 5;


    }     if (level == 5) {
        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 10;
        ennemy_ai->probaPartialDmg = 55;
        ennemy_ai->reactivity= 0.2;
        ennemy_ai->extraPower = 3;
        ennemy_ai->probaAbsorb = 20;
        ennemy_ai->mana_gain = CFixed(3);


        ennemy_ai->probaMassiveAttack = 50;

        GameScene::player_id = 4;
        GameScene::ennemy_id = 5;


    }     if (level == 6) {
        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 10;
        ennemy_ai->probaPartialDmg = 55;
        ennemy_ai->reactivity= 0.2;
        ennemy_ai->extraPower = 4;
        ennemy_ai->probaAbsorb = 20;
        ennemy_ai->mana_gain = CFixed(2.5);


        ennemy_ai->probaShrapnelAttack = 10;

        GameScene::player_id = 2;
        GameScene::ennemy_id = 3;


    }     if (level == 7) {
        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 15;
        ennemy_ai->probaPartialDmg = 55;
        ennemy_ai->reactivity= 0.2;
        ennemy_ai->extraPower = 5;
        ennemy_ai->probaAbsorb = 25;
        ennemy_ai->mana_gain = CFixed(3);


        ennemy_ai->probaShrapnelAttack = 1;

        GameScene::player_id = 1;
        GameScene::ennemy_id = 5;


    }



     if (level == 8) {
        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 15;
        ennemy_ai->probaPartialDmg = 55;
        ennemy_ai->reactivity= 0.001;
        ennemy_ai->extraPower = 4;
        ennemy_ai->probaAbsorb = 30;
        ennemy_ai->mana_gain = CFixed(4);


        ennemy_ai->probaShrapnelAttack = 1;

        GameScene::player_id = 1;
        GameScene::ennemy_id = 2;


    }


    if (ennemy_ai == NULL) {
        //error unkown level
        ennemy_ai = new CSimpleAI();
    }

    return ennemy_ai;

}

HardStoryScene::HardStoryScene(): StoryScene()  {
    //CScene::CScene();
    mode = "Hard";
    step = 8;
}

HardStoryScene::~HardStoryScene() {

}


void HardStoryScene::renderCinematic(int i ) {
        HardStoryCinematicScene * cinematic = new HardStoryCinematicScene(i);
        cinematic->render();

        delete (cinematic);
}


void HardStoryScene::displayCongrat() {
            //SHOW CONGRAT

        CScene::resetScene();
        SplashScreenScene * splash = new SplashScreenScene();

        CSprite * background_haut = new CSprite(128,96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,congrat_img);

        splash->addSprite(background_haut);

        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 90, "congratulation");

        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 100+32+128, "you have finished");
        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 118+32+128, "the hard mode");

        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 150+32+128, "you are eleet");
        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 150+32+138, "now try the insane mode");

        splash->render();

        delete (splash);
}




