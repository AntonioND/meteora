/*

    Sprite class for player ship

*/

#include "RaiseManaRateSpell.h"

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
#include "../CAlchemySpell.h"

#include "menu_raise_mana.h"

RaiseManaRateSpell::RaiseManaRateSpell() : SpellItem() {
    //ulDisableTransparentColor();
    //#loadTex16col(this,trapattack)
    loadTex16col(this,menu_raise_mana)
    //ulSetTransparentColor(RGB15(31, 0, 31));
    //loadTex16col(this,small_explosion)
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



