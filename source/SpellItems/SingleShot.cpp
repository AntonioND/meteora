/*

    Sprite class for player ship

*/

#include "SingleShot.h"

#include <cstdlib>
#include <time.h>
#include "explosion.h"
#include "multpleshotimg_0.h"

#include "explode.h"
#include "big_boom.h"

#include "launch.h"

#include "../GameCtrl.h"
#include "../GameScene.h"
#include "../CBullet.h"
#include "../ModifierAddTrailer.h"

#include "Math.h"

SingleShot::SingleShot() : SpellItem() {
    //ulDisableTransparentColor();
    //#loadTex16col(this,trapattack)
    loadTex16col(this,multpleshotimg_0)
    //ulSetTransparentColor(RGB15(31, 0, 31));
    //loadTex16col(this,small_explosion)
    status = -1;
    interval = 5;
    mana = 10;
}

SingleShot::~SingleShot() {

}

void SingleShot::isPressed() {
        if ((int)GameScene::mana>0) {
            CBullet * bulletS;
            bulletS = new CBullet();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
            bulletS->setX((int)(128+PA_Rand()%180-90));
            bulletS->setY(192+32+192);
            bulletS->setVel(0,-8);
            bulletS->weight = 14;
            bulletS->setSize (sqrt(bulletS->weight)*0.1);

            GameScene::mana = GameScene::mana - CFixed(5);

            GameCtrl::getSharedObject()->addSprite(bulletS);

            ModifierAddTrailer * mat;

            mat = new ModifierAddTrailer(bulletS);

             GC_playSound(launch);

        }
}



