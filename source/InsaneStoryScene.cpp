/*

    Sprite class for player ship

*/

#include "InsaneStoryScene.h"

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

#include "InsaneStoryCinematicScene.h"

#include "CSimpleAI.h"

#include "CVreemdAI.h"

#include "SplashScreenScene.h"

#include "congrat_img_png.h"

#include "SaveManager.h"


#include "vreemd_haut_reppa_png.h"
#include "vreemd_haut_schyzo_png.h"

#include "vreemd_haut_evilspoon_png.h"
#include "vreemd_bas_evilspoon_png.h"

#include "vreemd_haut_kuku_png.h"
#include "vreemd_bas_kuku_png.h"

#include "vreemd_haut_t4ils_png.h"
#include "vreemd_bas_t4ils_png.h"

#include "vreemd_haut_xb_png.h"
#include "vreemd_bas_xb_png.h"

#include "splash_haut_png.h"
#include "splash_bas_png.h"

#include "vreemd_bas_momo_png.h"

CSimpleAI * InsaneStoryScene::generateAI(int level) {
    CSimpleAI * ennemy_ai = NULL;
     if (level == 1) {



        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 15;
        ennemy_ai->probaPartialDmg = 55;
        ennemy_ai->reactivity= 0.001;
        ennemy_ai->extraPower = 6;
        ennemy_ai->probaAbsorb = 30;
        ennemy_ai->mana_gain = CFixed(4);

        //ennemy_ai->probaShrapnelAttack = 1;

        GameScene::player_id = 3;
        GameScene::ennemy_id = 2;


    }

     if (level == 2) {

        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 15;
        ennemy_ai->probaPartialDmg = 55;
        ennemy_ai->reactivity= 0.001;
        ennemy_ai->extraPower = 6;
        ennemy_ai->probaAbsorb = 32;
        ennemy_ai->mana_gain = CFixed(4.2);


        ennemy_ai->probaShrapnelAttack = 1;

        GameScene::player_id = 1;
        GameScene::ennemy_id = 2;


    }

         if (level == 3) {

        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 15;
        ennemy_ai->probaPartialDmg = 55;
        ennemy_ai->reactivity= 0.001;
        ennemy_ai->extraPower = 6;
        ennemy_ai->probaAbsorb = 34;
        ennemy_ai->mana_gain = CFixed(4.4);



        //ennemy_ai->probaShrapnelAttack = 1;

        GameScene::player_id = 1;
        GameScene::ennemy_id = 2;


    }     if (level == 4) {

        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 15;
        ennemy_ai->probaPartialDmg = 55;
        ennemy_ai->reactivity= 0.001;
        ennemy_ai->extraPower = 7;
        ennemy_ai->probaAbsorb = 36;
        ennemy_ai->mana_gain = CFixed(4.4);



        ennemy_ai->probaMassiveAttack = 100;

        GameScene::player_id = 3;
        GameScene::ennemy_id = 5;


    }     if (level == 5) {
ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 15;
        ennemy_ai->probaPartialDmg = 55;
        ennemy_ai->reactivity= 0.001;
        ennemy_ai->extraPower = 7;
        ennemy_ai->probaAbsorb = 38;
        ennemy_ai->mana_gain = CFixed(4.6);


        ennemy_ai->probaMassiveAttack = 50;

        GameScene::player_id = 4;
        GameScene::ennemy_id = 5;


    }     if (level == 6) {


        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 15;
        ennemy_ai->probaPartialDmg = 55;
        ennemy_ai->reactivity= 0.001;
        ennemy_ai->extraPower = 8;
        ennemy_ai->probaAbsorb = 40;
        ennemy_ai->mana_gain = CFixed(4.8);


        ennemy_ai->probaShrapnelAttack = 10;

        GameScene::player_id = 2;
        GameScene::ennemy_id = 3;


    }     if (level == 7) {


        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 15;
        ennemy_ai->probaPartialDmg = 55;
        ennemy_ai->reactivity= 0.001;
        ennemy_ai->extraPower = 9;
        ennemy_ai->probaAbsorb = 40;
        ennemy_ai->mana_gain = CFixed(5);


        ennemy_ai->probaShrapnelAttack = 1;

        GameScene::player_id = 1;
        GameScene::ennemy_id = 5;


    }



     if (level == 8) {
                 game->background_haut = new CSprite(128,96,0);
        loadTex(game->background_haut,vreemd_haut_xb_png)

         game->background_bas = new CSprite(128,192+32+96,0);
         loadTex(game->background_bas,vreemd_bas_xb_png)

        ennemy_ai = new CSimpleAI();
        ennemy_ai->probaTotalStop = 15;
        ennemy_ai->probaPartialDmg = 55;
        ennemy_ai->reactivity= 0.001;
        ennemy_ai->extraPower = 9;
        ennemy_ai->probaAbsorb = 45;
        ennemy_ai->mana_gain = CFixed(5);


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

InsaneStoryScene::InsaneStoryScene(): StoryScene()  {
    //CScene::CScene();
    mode = "Insane";
    step = 8;
}

InsaneStoryScene::~InsaneStoryScene() {

}


void InsaneStoryScene::renderCinematic(int i ) {
        InsaneStoryCinematicScene * cinematic = new InsaneStoryCinematicScene(i);
        cinematic->render();

        delete (cinematic);
}


void InsaneStoryScene::displayCongrat() {
            //SHOW CONGRAT

        CScene::resetScene();
        SplashScreenScene * splash = new SplashScreenScene();

        CSprite * background_haut = new CSprite(128,96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,congrat_img_png);

        splash->addSprite(background_haut);

        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 90, "congratulation");

        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 100+32+128, "you have finished");
        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 118+32+128, "the insane mode");

        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 150+32+128, "i respect you");

        splash->render();

        delete (splash);


        SplashScreenScene * splash2 = new SplashScreenScene();

        //CSprite * background_haut2 = new CSprite(128,96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,congrat_img_png);

        splash2->addSprite(background_haut);

        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 90, "congratulation");

        GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 100+32+128, "thanks for playing");

        splash->render();

        delete (splash2);
}




