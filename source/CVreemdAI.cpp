/*

    Sprite class for player ship

*/

#include "CVreemdAI.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "CMeteor.h"

#include <cstdlib>
#include <time.h>

#include "GameScene.h"

//math
#include "math.h"

//modifier
#include "ModifierAddTrailer.h"

//sound
#include "launch.h"

#include "ennemyIA/EnnemyMultipleShotsManager.h"

#include "GameCtrl.h"
#include "GameScene.h"

#include "CVreemdSprite.h"


CVreemdAI::CVreemdAI() :CSimpleAI() {
    lastPassedTime = GameCtrl::getSharedObject()->getPassedTime();
    //GameScene::ennemy_life = CFixed(1);
}

CVreemdAI::~CVreemdAI() {
}

void CVreemdAI::thinking()
{

    if ((int)PA_Rand()%8==3) {
        CVreemdSprite * bulletS;
        bulletS = new CVreemdSprite();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
        bulletS->setX((int)(128+PA_Rand()%180-90));
        bulletS->setY(-12);
        //bulletS->setVel(0,3);
        bulletS->setVel(0,2);
        //bulletS->weight = 50;
        //bulletS->setSize (sqrt(bulletS->weight)*0.1);

        GameCtrl::getSharedObject()->addSprite(bulletS);
    }
    


    if ((GameCtrl::getSharedObject()->getPassedTime() - lastPassedTime) > 120 ) {
            GameScene::ennemy_id = GameScene::player_id;
            while (GameScene::ennemy_id == GameScene::player_id) {
                            GameScene::ennemy_id =PA_Rand()%5+1;
            }
            lastPassedTime = GameCtrl::getSharedObject()->getPassedTime();
    }

    CSimpleAI::thinking();

    //GameScene::ennemy_mana = GameScene::ennemy_mana + (CFixed((int)GameCtrl::getSharedObject()->getPassedTime()-lastPassedTime )/CFixed(30))*CFixed((int)GameCtrl::getSharedObject()->getPassedTime())/CFixed(500);

    //reactivity = 1-((GameCtrl::getSharedObject()->getPassedTime()-lastPassedTime )/30)*(GameCtrl::getSharedObject()->getPassedTime())/3600;

    //lastPassedTime = GameCtrl::getSharedObject()->getPassedTime();

}