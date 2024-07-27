/*

    Sprite class for player ship

*/

#include "EasyStoryScene.h"

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

#include "HelpScene.h"
#include "GameScene.h"
#include "ScoreScene.h"
#include "MenuScene.h"

#include "EasyStoryCinematicScene.h"

#include "CSimpleAI.h"

#include "SplashScreenScene.h"

#include "congrat_img_png.h"

#include "SaveManager.h"

CSimpleAI * EasyStoryScene::generateAI(int level) {
    CSimpleAI * ennemy_ai = NULL;
    if (level ==1) {
        
        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 0;
        ennemy_ai->probaPartialDmg = 0;
        ennemy_ai->reactivity = 4;
        ennemy_ai->probaAbsorb = 5;
        ennemy_ai->mana_gain = CFixed(0.1);

        GameScene::player_id = 5;
        GameScene::ennemy_id = 3;


    }

    if (level == 2) {
        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 10;
        ennemy_ai->probaPartialDmg = 0;
        ennemy_ai->reactivity = 2;
        ennemy_ai->probaAbsorb = 5;
        ennemy_ai->mana_gain = CFixed(0.3);
        
        ennemy_ai->probaSimpleAttack = 50;
        ennemy_ai->probaMassiveAttack = 10;
        ennemy_ai->probaMeteorAttack = 10;
        //ennemy_ai->probaShrapnelAttack = 50;
        

        GameScene::player_id = 5;
        GameScene::ennemy_id = 1;
        
        
    }

   if (level == 3) {
        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 10;
        ennemy_ai->probaPartialDmg = 80;
        ennemy_ai->mana_gain = CFixed(0.5);
        ennemy_ai->probaSimpleAttack = 100;
        
        ennemy_ai->extraPower = 3;

        GameScene::player_id = 1;
        GameScene::ennemy_id = 2;

    }

   if (level == 4) {
        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 10;
        ennemy_ai->probaPartialDmg = 80;
        ennemy_ai->mana_gain = CFixed(0.4);
        ennemy_ai->probaMassiveAttack = 100;
        

        GameScene::player_id = 1;
        GameScene::ennemy_id = 4;


    }

       if (level == 5) {
        ennemy_ai = new CSimpleAI();

        GameScene::player_id = 3;
        GameScene::ennemy_id = 2;
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

EasyStoryScene::EasyStoryScene(): StoryScene()  {
    //CScene::CScene();
    mode = "Easy";
    step = 5;
}

EasyStoryScene::~EasyStoryScene() {

}


void EasyStoryScene::renderCinematic(int i ) {
        EasyStoryCinematicScene * cinematic = new EasyStoryCinematicScene(i);
        cinematic->render();

        delete (cinematic);
}


void EasyStoryScene::displayCongrat() {
            //SHOW CONGRAT

        CScene::resetScene();
        SplashScreenScene * splash = new SplashScreenScene();

        CSprite * background_haut = new CSprite(128,96,0);
        //loadTex16col(background_haut,menu_haut_png);
        loadTex(background_haut,congrat_img_png);

        splash->addSprite(background_haut);

        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 90, "congratulation");

        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 100+32+128, "you have finished");
        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 118+32+128, "the easy mode");

        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 150+32+128, "now try the normal mode");

        splash->render();

        delete (splash);
}




