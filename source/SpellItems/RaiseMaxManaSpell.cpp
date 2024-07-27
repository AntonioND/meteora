/*

    Sprite class for player ship

*/

#include "RaiseMaxManaSpell.h"

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

#include "menu_raise_maxmana.h"

RaiseMaxManaSpell::RaiseMaxManaSpell() : SpellItem() {
    //ulDisableTransparentColor();
    //#loadTex16col(this,trapattack)
    loadTex16col(this,menu_raise_maxmana)
    //ulSetTransparentColor(RGB15(31, 0, 31));
    //loadTex16col(this,small_explosion)
    status = -1;



    mana = 100;

    interval = 20;
}

RaiseMaxManaSpell::~RaiseMaxManaSpell() {

}

void RaiseMaxManaSpell::isPressed() {
    GameScene::getInstance()->max_mana = GameScene::getInstance()->max_mana + CFixed(1000);
     GameCtrl::getSharedObject()->drawOnScreen(128,192+32+96+30,"max mana raised");

     mana = mana * CFixed(1.2);
}



