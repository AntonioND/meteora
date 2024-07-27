/*

    Sprite class for player ship

*/

#include "MultipleShot.h"

#include <cstdlib>
#include <time.h>
#include "explosion.h"
#include "small_explosion.h"
#include "trapattack.h"
#include "multpleshotimg_1.h"

#include "explode.h"
#include "big_boom.h"

#include "../GameCtrl.h"
#include "../GameScene.h"
#include "../CMultipleShotsManager.h"

MultipleShot::MultipleShot() : SpellItem() {
    //ulDisableTransparentColor();
    //#loadTex16col(this,trapattack)
    loadTex16col(this,multpleshotimg_1)
    //ulSetTransparentColor(RGB15(31, 0, 31));
    //loadTex16col(this,small_explosion)
    status = -1;
    interval = 15;
    mana = 80;
}

MultipleShot::~MultipleShot() {

}

void MultipleShot::isPressed() {
        if ((int)GameScene::mana>0) {
                    CSprite * bulletS;
                    bulletS = new CMultipleShotsManager();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);

                    GameCtrl::getSharedObject()->addSprite(bulletS);

                    if ((int) mana > 60 ) {
                         mana = mana - CFixed(0.2);
                    }


                    if ((int)interval > 10) {
                            interval = interval - 1;
                    }

        }
}



