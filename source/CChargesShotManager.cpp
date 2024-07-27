/*

    Sprite class for player ship

*/

#include "CChargesShotManager.h"

#include "ModifierAddTrailer.h"

#include "GameCtrl.h"
#include "CExplosion.h"

#include "GameScene.h"

#include "CMeteor.h"

#include "launch.h"

#include <cstdlib>
#include <time.h>
#include "math.h"

#include "CConcentrate.h"


CChargesShotManager::CChargesShotManager() :CSprite() {
    size =0;
    mType = 0;
    nextThink=20;

    bulletNumber = 1;

    _bulletSize = 20;
}

CChargesShotManager::~CChargesShotManager() {
}

void CChargesShotManager::thinking()
{



    CBullet * bulletS;
    bulletS = new CBullet();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
    bulletS->setX((int)(128));
    bulletS->setY((int)(192+32+96));
    bulletS->setVel(0,0);
    bulletS->weight = _bulletSize;
    bulletS->setSize (sqrt(bulletS->weight)*0.1);

    GameScene::mana = GameScene::mana - CFixed(5);

    GameCtrl::getSharedObject()->addSprite(bulletS);

    //ModifierAddTrailer * mat;

    //mat = new ModifierAddTrailer(bulletS);

     GC_playSound(launch);

     CConcentrate * cc;
     cc = new CConcentrate();
     cc->setX((int)(128));
     cc->setY((int)(192+32+96));
     GameCtrl::getSharedObject()->addDecoSprite(cc);

   /* bulletNumber++;

    bulletS = new CBullet();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
    bulletS->setX((int)(128+PA_Rand()%180-90));
    bulletS->setY(192+32+192);
    bulletS->setVel(0,-15);
    bulletS->weight = 3;
    bulletS->setSize (sqrt(bulletS->weight)*0.1);

    GameCtrl::getSharedObject()->addSprite(bulletS);

    bulletNumber++;

    bulletS = new CBullet();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
    bulletS->setX((int)(128+PA_Rand()%180-90));
    bulletS->setY(192+32+192);
    bulletS->setVel(0,-15);
    bulletS->weight = 3;
    bulletS->setSize (sqrt(bulletS->weight)*0.1);

    GameCtrl::getSharedObject()->addSprite(bulletS);



*/
    bulletNumber++;

        if (bulletNumber % 10 ==1) {
             GC_playSound(launch);
        }


    if (bulletNumber > 15) {

        dead();
        //nextThink = 10000;
    }


}

void CChargesShotManager::draw(int offset) {
}
