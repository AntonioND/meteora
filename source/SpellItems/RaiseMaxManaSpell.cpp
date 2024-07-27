/*

    Sprite class for player ship

*/

#include "RaiseMaxManaSpell.h"

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

#include "menu_raise_maxmana_png.h"

RaiseMaxManaSpell::RaiseMaxManaSpell() : SpellItem() {
    //ulDisableTransparentColor();
    //#loadTex16col(this,trapattack_png)
    loadTex16col(this,menu_raise_maxmana_png)
    //ulSetTransparentColor(RGB15(31, 0, 31));
    //loadTex16col(this,small_explosion_png)
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



