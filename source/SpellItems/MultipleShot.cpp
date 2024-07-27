/*

    Sprite class for player ship

*/

#include "MultipleShot.h"

#include <cstdlib>
#include <time.h>
#include "explosion_png.h"
#include "small_explosion_png.h"
#include "trapattack_png.h"
#include "multpleshotimg_1_png.h"

#include "explode_raw.h"
#include "big_boom_raw.h"

#include "../GameCtrl.h"
#include "../GameScene.h"
#include "../CMultipleShotsManager.h"

MultipleShot::MultipleShot() : SpellItem() {
    //ulDisableTransparentColor();
    //#loadTex16col(this,trapattack_png)
    loadTex16col(this,multpleshotimg_1_png)
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



