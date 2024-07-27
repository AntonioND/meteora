/*

    Sprite class for player ship

*/

#include "MarathonScene.h"

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

#include "CMarathonAI.h"

#include "SaveManager.h"

MarathonScene::MarathonScene(): CScene()  {
    //CScene::CScene();
}

MarathonScene::~MarathonScene() {

}




void MarathonScene::render() {
    GameScene * game;
    ScoreScene * score;
    /*
        int probaTotalStop;
    int probaDeviation;
    int probaPartialDmg;
    */

        CScene::resetScene();
        game = new GameScene();

        game->isMarathon = 1;

        GameCtrl::getSharedObject()->resetPassedTime();

        game->ennemy_ai = new CMarathonAI();

        game->ennemy_ai->probaShrapnelAttack = 5;
        //game->ennemy_ai->probaShrapnelAttack = 0;

        game->preInit();
        game->render();

        score = (ScoreScene *)game->nextScene;
        delete(game);

        CScene::resetScene();
        score->render();

        //MarathonTimeRecord

        if (SaveManager::ent()->getInt("MarathonTimeRecord") < (int)score->totalTime) {
            SaveManager::ent()->set("MarathonTimeRecord",(int)score->totalTime);
        }


        delete(score); //else you continue and delete score Scene

        nextScene = new MenuScene(); //you finished the game ;)
}
