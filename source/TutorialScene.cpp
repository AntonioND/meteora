/*

    Sprite class for player ship

*/

#include "TutorialScene.h"

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

#include "TutorialCinematicScene.h"

#include "CSimpleAI.h"

#include "SplashScreenScene.h"


#include "tutorial_haut_1_png.h"
#include "tutorial_bas_1_png.h"

#include "tutorial_haut_2_png.h"
#include "tutorial_bas_2_png.h"


#include "tutorial_haut_2_3_png.h"
#include "tutorial_bas_2_3_png.h"

#include "tutorial_haut_3_png.h"
#include "tutorial_bas_3_png.h"

#include "tutorial_haut_4_png.h"
#include "tutorial_bas_4_png.h"

#include "tutorial_haut_5_png.h"
#include "tutorial_bas_5_png.h"


#include "tutorial_haut_6_png.h"
#include "tutorial_bas_6_png.h"

#include "tutorial_haut_7_png.h"
#include "tutorial_bas_7_png.h"

#include "tutorial_haut_8_png.h"
#include "tutorial_bas_8_png.h"

#include "congrat_img_png.h"



CSimpleAI * generateAI2(int level) {
    CSimpleAI * ennemy_ai = NULL;
    if (level ==1) {
        ennemy_ai = new CSimpleAI();

        ennemy_ai->mana_gain = CFixed(0);

        ennemy_ai->probaAbsorb = 0;
        ennemy_ai->probaTotalStop = 0;
        ennemy_ai->probaPartialDmg = 0;
        ennemy_ai->reactivity = 2000;
        ennemy_ai->probaBigAttack = 0;

        ennemy_ai->probaSimpleAttack = 0;
        ennemy_ai->probaMassiveAttack = 0;
        ennemy_ai->probaMeteorAttack = 0;
        ennemy_ai->probaShrapnelAttack = 0;

        GameScene::ennemy_life = CFixed(10);
        GameScene::ennemy_shield = CFixed(0);
        GameScene::ennemy_mana = CFixed(0);

    }

    if (level == 2) {
        ennemy_ai = new CSimpleAI();

        ennemy_ai->mana_gain = CFixed(0);

        ennemy_ai->probaAbsorb = 0;
        ennemy_ai->probaTotalStop = 0;
        ennemy_ai->probaPartialDmg = 0;
        ennemy_ai->reactivity = 2000;
        ennemy_ai->probaBigAttack = 0;


        ennemy_ai->probaSimpleAttack = 0;
        ennemy_ai->probaMassiveAttack = 0;
        ennemy_ai->probaMeteorAttack = 0;
        ennemy_ai->probaShrapnelAttack = 0;

        GameScene::ennemy_life = CFixed(100);
        GameScene::ennemy_shield = CFixed(0);
        GameScene::ennemy_mana = CFixed(0);

    }

   if (level == 3) {
        ennemy_ai = new CSimpleAI();

        ennemy_ai->mana_gain = CFixed(0.1);

        ennemy_ai->probaAbsorb = 0;
        ennemy_ai->probaTotalStop = 0;
        ennemy_ai->probaPartialDmg = 0;
        ennemy_ai->reactivity = 8;
        ennemy_ai->probaBigAttack = 0;


        ennemy_ai->probaSimpleAttack = 50;
        ennemy_ai->probaMassiveAttack = 0;
        ennemy_ai->probaMeteorAttack = 0;
        ennemy_ai->probaShrapnelAttack = 0;
        GameScene::ennemy_shield = CFixed(0);
        GameScene::ennemy_mana = CFixed(0);


    }

   if (level == 4) {
        ennemy_ai = new CSimpleAI();

        ennemy_ai->mana_gain = CFixed(0.1);

        ennemy_ai->probaAbsorb = 0;
        ennemy_ai->probaTotalStop = 0;
        ennemy_ai->probaPartialDmg = 0;
        ennemy_ai->reactivity = 8;
        ennemy_ai->probaBigAttack = 0;


        ennemy_ai->probaSimpleAttack = 50;
        ennemy_ai->probaMassiveAttack = 10;
        ennemy_ai->probaMeteorAttack = 0;
        ennemy_ai->probaShrapnelAttack = 0;
        GameScene::ennemy_shield = CFixed(0);
        GameScene::ennemy_mana = CFixed(0);


    }

   if (level == 5) {
        ennemy_ai = new CSimpleAI();

        ennemy_ai->mana_gain = CFixed(0.1);

        ennemy_ai->probaAbsorb = 0;
        ennemy_ai->probaTotalStop = 0;
        ennemy_ai->probaPartialDmg = 0;
        ennemy_ai->reactivity = 4;
        ennemy_ai->probaBigAttack = 0;


        ennemy_ai->probaSimpleAttack = 0;
        ennemy_ai->probaMassiveAttack = 80;
        ennemy_ai->probaMeteorAttack = 0;
        ennemy_ai->probaShrapnelAttack = 0;

    }

       if (level == 6) {
        ennemy_ai = new CSimpleAI();


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

    }


    if (ennemy_ai == NULL) {
        //error unkown level
        ennemy_ai = new CSimpleAI();
    }

    return ennemy_ai;

}

TutorialScene::TutorialScene(): CScene()  {
    //CScene::CScene();
}

TutorialScene::~TutorialScene() {

}



void launchTest(int i) {
            GameScene * game;
        ScoreScene * score;
        TutorialCinematicScene * cinematic;

        CScene::resetScene();
        cinematic = new TutorialCinematicScene(i);
        cinematic->render();

        delete (cinematic);


        CScene::resetScene();
        game = new GameScene();

        game->ennemy_ai = generateAI2(i);


        game->render();

        score = (ScoreScene *)game->nextScene;
        delete(game);

        CScene::resetScene();
        score->render();

        delete(score); //else you continue and delete score Scene
}

void tut1() {
#if 0
        GameScene * game;
        ScoreScene * score;
        TutorialCinematicScene * cinematic;
#endif
        SplashScreenScene * splash;
        /*
            int probaTotalStop;
        int probaDeviation;
        int probaPartialDmg;
        */

        /////SPLASH !!!!
        //first splash
        CScene::resetScene();
        splash = new SplashScreenScene();

        CSprite * background_haut = new CSprite(128,96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,tutorial_haut_1_png);

        splash->addSprite(background_haut);


        background_haut = new CSprite(128,192+32+96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,tutorial_bas_1_png);

        splash->addSprite(background_haut);


        splash->render();

        delete (splash);


        //first splash
        CScene::resetScene();
        splash = new SplashScreenScene();

        background_haut = new CSprite(128,96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,tutorial_haut_2_png);

        splash->addSprite(background_haut);


        background_haut = new CSprite(128,192+32+96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,tutorial_bas_2_png);

        splash->addSprite(background_haut);


        splash->render();

        delete (splash);

                //first splash
        CScene::resetScene();
        splash = new SplashScreenScene();

        background_haut = new CSprite(128,96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,tutorial_haut_3_png);

        splash->addSprite(background_haut);


        background_haut = new CSprite(128,192+32+96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,tutorial_bas_3_png);

        splash->addSprite(background_haut);


        splash->render();

        delete (splash);


        CScene::resetScene();
        splash = new SplashScreenScene();

        background_haut = new CSprite(128,96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,tutorial_haut_2_3_png);

        splash->addSprite(background_haut);


        background_haut = new CSprite(128,192+32+96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,tutorial_bas_2_3_png);

        splash->addSprite(background_haut);


        splash->render();

        delete (splash);

        //END SPLASH
                launchTest(1);


}

void tut2() {
#if 0
        GameScene * game;
        ScoreScene * score;
        TutorialCinematicScene * cinematic;
#endif
        SplashScreenScene * splash;
        /*
            int probaTotalStop;
        int probaDeviation;
        int probaPartialDmg;
        */

        /////SPLASH !!!!
        //first splash
        CScene::resetScene();
        splash = new SplashScreenScene();

        CSprite * background_haut = new CSprite(128,96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,tutorial_haut_4_png);

        splash->addSprite(background_haut);


        background_haut = new CSprite(128,192+32+96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,tutorial_bas_4_png);

        splash->addSprite(background_haut);


        splash->render();

        delete (splash);

        //END SPLASH

        launchTest(2);


}

void tut3() {
#if 0
        GameScene * game;
        ScoreScene * score;
        TutorialCinematicScene * cinematic;
#endif
        SplashScreenScene * splash;
        /*
            int probaTotalStop;
        int probaDeviation;
        int probaPartialDmg;
        */

        /////SPLASH !!!!
        //first splash
        CScene::resetScene();
        splash = new SplashScreenScene();

        CSprite * background_haut = new CSprite(128,96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex16col(background_haut,tutorial_haut_5_png);

        splash->addSprite(background_haut);


        background_haut = new CSprite(128,192+32+96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,tutorial_bas_5_png);

        splash->addSprite(background_haut);


        splash->render();

        delete (splash);

        //END SPLASH

        launchTest(3);


}


void tut4() {
#if 0
        GameScene * game;
        ScoreScene * score;
        TutorialCinematicScene * cinematic;
#endif
        SplashScreenScene * splash;
        /*
            int probaTotalStop;
        int probaDeviation;
        int probaPartialDmg;
        */

        /////SPLASH !!!!
        //first splash
        CScene::resetScene();
        splash = new SplashScreenScene();

        CSprite * background_haut = new CSprite(128,96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex16col(background_haut,tutorial_haut_6_png);

        splash->addSprite(background_haut);


        background_haut = new CSprite(128,192+32+96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex16col(background_haut,tutorial_bas_6_png);

        splash->addSprite(background_haut);


        splash->render();

        delete (splash);

        //END SPLASH

        launchTest(4);


}


void tut5() {
#if 0
        GameScene * game;
        ScoreScene * score;
        TutorialCinematicScene * cinematic;
#endif
        SplashScreenScene * splash;
        /*
            int probaTotalStop;
        int probaDeviation;
        int probaPartialDmg;
        */

        /////SPLASH !!!!
        //first splash
        CScene::resetScene();
        splash = new SplashScreenScene();

        CSprite * background_haut = new CSprite(128,96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex16col(background_haut,tutorial_haut_7_png);

        splash->addSprite(background_haut);


        background_haut = new CSprite(128,192+32+96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex16col(background_haut,tutorial_bas_7_png);

        splash->addSprite(background_haut);


        splash->render();

        delete (splash);

        //END SPLASH

        launchTest(5);


}


void tut6() {
#if 0
        GameScene * game;
        ScoreScene * score;
        TutorialCinematicScene * cinematic;
#endif
        SplashScreenScene * splash;
        /*
            int probaTotalStop;
        int probaDeviation;
        int probaPartialDmg;
        */

        /////SPLASH !!!!
        //first splash
        CScene::resetScene();
        splash = new SplashScreenScene();

        CSprite * background_haut = new CSprite(128,96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex16col(background_haut,tutorial_haut_8_png);

        splash->addSprite(background_haut);


        background_haut = new CSprite(128,192+32+96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex16col(background_haut,tutorial_bas_8_png);

        splash->addSprite(background_haut);


        splash->render();

        delete (splash);

        //END SPLASH

        launchTest(6);


}




void TutorialScene::render() {
    tut1();

    tut2();

    tut3();

    tut4();

    tut5();

    tut6();


    //SHOW CONGRAT

    CScene::resetScene();
    SplashScreenScene * splash = new SplashScreenScene();

    CSprite * background_haut = new CSprite(128,96,0);
    //loadTex16col(background_haut,menu_haut);
    loadTex(background_haut,congrat_img_png);

    splash->addSprite(background_haut);

    GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 90, "congratulation");

    GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 100+32+128, "you have finished");
    GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 118+32+128, "the tutorial");

    GameCtrl::getSharedObject()->drawPersistentOnScreen(128, 150+32+128, "now try the story mode");

    splash->render();

    delete (splash);

    //END SHOW CONGRAT


    nextScene = new MenuScene(); //you finished the game ;)
}
