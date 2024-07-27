/*

    Sprite class for player ship

*/

#include "MultipleShotLvl2.h"

#include <cstdlib>
#include <time.h>
#include "explosion.h"
#include "small_explosion.h"
#include "trapattack.h"
#include "multpleshotimg.h"

#include "explode.h"
#include "big_boom.h"

#include "../GameCtrl.h"
#include "../GameScene.h"
#include "../CMultipleShotsManager.h"

MultipleShotLvl2::MultipleShotLvl2() : SpellItem() {
    //ulDisableTransparentColor();
    //#loadTex16col(this,trapattack)
    loadTex16col(this,multpleshotimg)
    //ulSetTransparentColor(RGB15(31, 0, 31));
    //loadTex16col(this,small_explosion)
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



