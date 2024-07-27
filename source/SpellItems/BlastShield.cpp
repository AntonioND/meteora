/*

    Sprite class for player ship

*/

#include "BlastShield.h"

#include <cstdlib>
#include <time.h>
#include "explosion.h"
#include "small_explosion.h"
#include "repell.h"
#include "multpleshotimg.h"

#include "explode.h"
#include "big_boom.h"

#include "../GameCtrl.h"
#include "../GameScene.h"


#include "../ModifierBlast.h"
#include "../CWindPowerManager.h"

BlastShield::BlastShield() : SpellItem() {
    ulDisableTransparentColor();
    //#loadTex16col(this,trapattack)
    loadTex16col(this,repell)
    ulSetTransparentColor(RGB15(31, 0, 31));
    //loadTex16col(this,small_explosion)
    status = -1;

    mana = 90;

    interval = 90;
}

BlastShield::~BlastShield() {

}

void BlastShield::isPressed() {



    CSprite * bulletS;
    bulletS = new CWindPowerManager();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);

    GameCtrl::getSharedObject()->addSprite(bulletS);

    interval +=20;
}



