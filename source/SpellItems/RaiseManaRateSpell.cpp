/*

    Sprite class for player ship

*/

#include "RaiseManaRateSpell.h"

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
#include "../CAlchemySpell.h"

#include "menu_raise_mana_png.h"

RaiseManaRateSpell::RaiseManaRateSpell() : SpellItem() {
    //ulDisableTransparentColor();
    //#loadTex16col(this,trapattack_png)
    loadTex16col(this,menu_raise_mana_png)
    //ulSetTransparentColor(RGB15(31, 0, 31));
    //loadTex16col(this,small_explosion_png)
    status = -1;



    mana = 100;

    interval = 20;
}

RaiseManaRateSpell::~RaiseManaRateSpell() {

}

void RaiseManaRateSpell::isPressed() {
    GameScene::getInstance()->mana_gain = GameScene::getInstance()->mana_gain + CFixed(0.2);
     GameCtrl::getSharedObject()->drawOnScreen(128,192+32+96+30,"mana rate raised");

     mana = mana * CFixed(1.5);
}



