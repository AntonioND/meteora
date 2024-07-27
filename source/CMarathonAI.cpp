/*

    Sprite class for player ship

*/

#include "CMarathonAI.h"
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
#include "launch_raw.h"

#include "ennemyIA/EnnemyMultipleShotsManager.h"

#include "GameCtrl.h"
#include "GameScene.h"


CMarathonAI::CMarathonAI() :CSimpleAI() {
    lastPassedTime = GameCtrl::getSharedObject()->getPassedTime();
    GameScene::ennemy_life = CFixed(1);
}

CMarathonAI::~CMarathonAI() {
}

void CMarathonAI::thinking()
{
    CSimpleAI::thinking();

    //GameScene::ennemy_mana = GameScene::ennemy_mana + (CFixed((int)GameCtrl::getSharedObject()->getPassedTime()-lastPassedTime )/CFixed(30))*CFixed((int)GameCtrl::getSharedObject()->getPassedTime())/CFixed(500);

    //reactivity = 1-((GameCtrl::getSharedObject()->getPassedTime()-lastPassedTime )/30)*(GameCtrl::getSharedObject()->getPassedTime())/3600;

    //lastPassedTime = GameCtrl::getSharedObject()->getPassedTime();

}


void CMarathonAI::manageBullet(int bulletSize, CBullet *) {
   //do nothing, you are in marathon
   //GameScene::ennemy_life = GameScene::ennemy_life+ CFixed(bulletSize);
}
