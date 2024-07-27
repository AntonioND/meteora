/*

    Sprite class for player ship

*/

#include "TutorialScene.h"

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

#include "TutorialCinematicScene.h"

#include "CSimpleAI.h"

#include "SplashScreenScene.h"


#include "tutorial_haut_1.h"
#include "tutorial_bas_1.h"

#include "tutorial_haut_2.h"
#include "tutorial_bas_2.h"


#include "tutorial_haut_2_3.h"
#include "tutorial_bas_2_3.h"

#include "tutorial_haut_3.h"
#include "tutorial_bas_3.h"

#include "tutorial_haut_4.h"
#include "tutorial_bas_4.h"

#include "tutorial_haut_5.h"
#include "tutorial_bas_5.h"


#include "tutorial_haut_6.h"
#include "tutorial_bas_6.h"

#include "tutorial_haut_7.h"
#include "tutorial_bas_7.h"

#include "tutorial_haut_8.h"
#include "tutorial_bas_8.h"

#include "congrat_img.h"



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
        GameScene * game;
        ScoreScene * score;
        TutorialCinematicScene * cinematic;
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
        loadTex(background_haut,tutorial_haut_1);

        splash->addSprite(background_haut);


        background_haut = new CSprite(128,192+32+96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,tutorial_bas_1);

        splash->addSprite(background_haut);


        splash->render();

        delete (splash);


        //first splash
        CScene::resetScene();
        splash = new SplashScreenScene();

        background_haut = new CSprite(128,96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,tutorial_haut_2);

        splash->addSprite(background_haut);


        background_haut = new CSprite(128,192+32+96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,tutorial_bas_2);

        splash->addSprite(background_haut);


        splash->render();

        delete (splash);

                //first splash
        CScene::resetScene();
        splash = new SplashScreenScene();

        background_haut = new CSprite(128,96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,tutorial_haut_3);

        splash->addSprite(background_haut);


        background_haut = new CSprite(128,192+32+96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,tutorial_bas_3);

        splash->addSprite(background_haut);


        splash->render();

        delete (splash);


        CScene::resetScene();
        splash = new SplashScreenScene();

        background_haut = new CSprite(128,96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,tutorial_haut_2_3);

        splash->addSprite(background_haut);


        background_haut = new CSprite(128,192+32+96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,tutorial_bas_2_3);

        splash->addSprite(background_haut);


        splash->render();

        delete (splash);

        //END SPLASH
                launchTest(1);


}

void tut2() {
        GameScene * game;
        ScoreScene * score;
        TutorialCinematicScene * cinematic;
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
        loadTex(background_haut,tutorial_haut_4);

        splash->addSprite(background_haut);


        background_haut = new CSprite(128,192+32+96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,tutorial_bas_4);

        splash->addSprite(background_haut);


        splash->render();

        delete (splash);

        //END SPLASH

        launchTest(2);


}

void tut3() {
        GameScene * game;
        ScoreScene * score;
        TutorialCinematicScene * cinematic;
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
        loadTex16col(background_haut,tutorial_haut_5);

        splash->addSprite(background_haut);


        background_haut = new CSprite(128,192+32+96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex(background_haut,tutorial_bas_5);

        splash->addSprite(background_haut);


        splash->render();

        delete (splash);

        //END SPLASH

        launchTest(3);


}


void tut4() {
        GameScene * game;
        ScoreScene * score;
        TutorialCinematicScene * cinematic;
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
        loadTex16col(background_haut,tutorial_haut_6);

        splash->addSprite(background_haut);


        background_haut = new CSprite(128,192+32+96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex16col(background_haut,tutorial_bas_6);

        splash->addSprite(background_haut);


        splash->render();

        delete (splash);

        //END SPLASH

        launchTest(4);


}


void tut5() {
        GameScene * game;
        ScoreScene * score;
        TutorialCinematicScene * cinematic;
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
        loadTex16col(background_haut,tutorial_haut_7);

        splash->addSprite(background_haut);


        background_haut = new CSprite(128,192+32+96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex16col(background_haut,tutorial_bas_7);

        splash->addSprite(background_haut);


        splash->render();

        delete (splash);

        //END SPLASH

        launchTest(5);


}


void tut6() {
        GameScene * game;
        ScoreScene * score;
        TutorialCinematicScene * cinematic;
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
        loadTex16col(background_haut,tutorial_haut_8);

        splash->addSprite(background_haut);


        background_haut = new CSprite(128,192+32+96,0);
        //loadTex16col(background_haut,menu_haut);
        loadTex16col(background_haut,tutorial_bas_8);

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
    loadTex(background_haut,congrat_img);

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
