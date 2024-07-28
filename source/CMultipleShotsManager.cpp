/*

    Sprite class for player ship

*/

#include "CMultipleShotsManager.h"

#include "ModifierAddTrailer.h"

#include "GameCtrl.h"
#include "CExplosion.h"

#include "GameScene.h"

#include "CMeteor.h"

#include "launch_raw.h"

#include <cstdlib>
#include <time.h>
#include "math.h"


CMultipleShotsManager::CMultipleShotsManager() :CSprite() {
    size =0;
    mType = 0;
    nextThink=1;

    bulletNumber = 0;
    _bulletSize = 8;
}

CMultipleShotsManager::~CMultipleShotsManager() {
}

void CMultipleShotsManager::thinking()
{

    CBullet * bulletS;
    bulletS = new CBullet();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
    bulletS->setX((int)(128+rand()%180-90));
    bulletS->setY(192+32+192);
    bulletS->setVel(0,-6);
    bulletS->weight = _bulletSize;
    bulletS->setSize (sqrt(bulletS->weight)*0.1);

    //GameScene::mana = GameScene::mana - CFixed(5);

    GameCtrl::getSharedObject()->addSprite(bulletS);
#if 0
    ModifierAddTrailer * mat;

    mat = new ModifierAddTrailer(bulletS);
#endif
    GC_playSound(launch_raw);

   /* bulletNumber++;

    bulletS = new CBullet();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
    bulletS->setX((int)(128+rand()%180-90));
    bulletS->setY(192+32+192);
    bulletS->setVel(0,-15);
    bulletS->weight = 3;
    bulletS->setSize (sqrt(bulletS->weight)*0.1);

    GameCtrl::getSharedObject()->addSprite(bulletS);

    bulletNumber++;

    bulletS = new CBullet();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
    bulletS->setX((int)(128+rand()%180-90));
    bulletS->setY(192+32+192);
    bulletS->setVel(0,-15);
    bulletS->weight = 3;
    bulletS->setSize (sqrt(bulletS->weight)*0.1);

    GameCtrl::getSharedObject()->addSprite(bulletS);



*/
    bulletNumber++;

        if (bulletNumber % 10 ==1) {
             GC_playSound(launch_raw);
        }


    if (bulletNumber > 15) {

        dead();
        //nextThink = 10000;
    }


}

void CMultipleShotsManager::draw(int offset) {
}
