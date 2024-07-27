/*

    Sprite class for player ship

*/

#include "EnnemyMultipleShotsManager.h"

#include "../ModifierAddTrailer.h"

#include "../GameCtrl.h"
#include "../CExplosion.h"

#include "../GameScene.h"

#include "../CMeteor.h"

#include "launch_raw.h"

#include <cstdlib>
#include <time.h>
#include "math.h"


EnnemyMultipleShotsManager::EnnemyMultipleShotsManager(int ppower) :CSprite() {
    size =0;
    mType = 0;
    nextThink=1;

    bulletNumber = 0;

    pow = ppower;
}

EnnemyMultipleShotsManager::~EnnemyMultipleShotsManager() {
}

void EnnemyMultipleShotsManager::thinking()
{

    if ((int)GameScene::ennemy_mana > 8) {
        CBullet * bulletS;
        bulletS = new CBullet(GameScene::ennemy_id);//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
        bulletS->setX((int)(128+PA_Rand()%180-90));
        bulletS->setY(-12);
        //bulletS->setVel(0,3);
        bulletS->setVel(0,(4+pow));
        bulletS->weight = 12;
        bulletS->setSize (sqrt(bulletS->weight)*0.1);
        //bulletS->type = GameScene::ennemy_id;

    GameScene::ennemy_mana = GameScene::ennemy_mana - CFixed(7);

    GameCtrl::getSharedObject()->addSprite(bulletS);

    ModifierAddTrailer * mat;

    mat = new ModifierAddTrailer(bulletS);

     GC_playSound(launch_raw);

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
             GC_playSound(launch_raw);
        }
    } else {
        dead();
    }

    if (bulletNumber > 15) {

        dead();
        //nextThink = 10000;
    }


}

void EnnemyMultipleShotsManager::draw(int offset) {
}
