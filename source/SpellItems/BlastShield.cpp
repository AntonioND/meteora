/*

    Sprite class for player ship

*/

#include "BlastShield.h"

#include <cstdlib>
#include <time.h>
#include "explosion_png.h"
#include "small_explosion_png.h"
#include "repell_png.h"
#include "multpleshotimg_png.h"

#include "explode_raw.h"
#include "big_boom_raw.h"

#include "../GameCtrl.h"
#include "../GameScene.h"


#include "../ModifierBlast.h"
#include "../CWindPowerManager.h"

BlastShield::BlastShield() : SpellItem() {
    ulDisableTransparentColor();
    //#loadTex16col(this,trapattack_png)
    loadTex16col(this,repell_png)
    ulSetTransparentColor(RGB15(31, 0, 31));
    //loadTex16col(this,small_explosion_png)
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



