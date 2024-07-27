/*

    Sprite class for player ship

*/

#include "NetworkScene.h"

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

#include "CNetworkAI.h"

#include "SaveManager.h"

NetworkScene::NetworkScene(): CScene()  {
    //CScene::CScene();

}

NetworkScene::~NetworkScene() {

}




void NetworkScene::render() {
    GameScene * game;
    ScoreScene * score;
    /*
        int probaTotalStop;
    int probaDeviation;
    int probaPartialDmg;
    */

        CScene::resetScene();
        game = new GameScene();
        game->ennemy_ai = new CNetworkAI();


        //game->isMarathon = 1;

        GameCtrl::getSharedObject()->resetPassedTime();



        //game->ennemy_ai->probaShrapnelAttack = 5;
        //game->ennemy_ai->probaShrapnelAttack = 0;

        game->preInit();
        game->render();

        score = (ScoreScene *)game->nextScene;
        delete(game);

        CScene::resetScene();
        score->render();

        delete(score); //else you continue and delete score Scene

        nextScene = new MenuScene(); //you finished the game ;)
}
