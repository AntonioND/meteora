/*

    Sprite class for player ship

*/

#include "MultipleShotLvl2.h"

#include <cstdlib>
#include <time.h>
#include "explosion_png.h"
#include "small_explosion_png.h"
#include "trapattack_png.h"
#include "multpleshotimg_png.h"

#include "explode_raw.h"
#include "big_boom_raw.h"

#include "../GameCtrl.h"
#include "../GameScene.h"
#include "../CMultipleShotsManager.h"

MultipleShotLvl2::MultipleShotLvl2() : SpellItem() {
    //ulDisableTransparentColor();
    //#loadTex16col(this,trapattack_png)
    loadTex16col(this,multpleshotimg_png)
    //ulSetTransparentColor(RGB15(31, 0, 31));
    //loadTex16col(this,small_explosion_png)
    status = -1;
    interval = 20;
    mana = 160;
}

MultipleShotLvl2::~MultipleShotLvl2() {

}

void MultipleShotLvl2::isPressed() {
        if ((int)GameScene::mana>0) {
                    CMultipleShotsManager * bulletS;
                    bulletS = new CMultipleShotsManager();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
                    
                    bulletS->_bulletSize = 20;

                    GameCtrl::getSharedObject()->addSprite(bulletS);

                    if ((int) mana > 120 ) {
                         mana = mana - CFixed(0.2);
                    }


                    if ((int)interval > 10) {
                            interval = interval - 1;
                    }

        }
}



