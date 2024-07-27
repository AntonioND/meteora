/*

    Sprite class for player ship

*/

#include "ChangeSideSpell.h"

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

#include "menu_heal_png.h"

ChangeSideSpell::ChangeSideSpell() : SpellItem() {
    //ulDisableTransparentColor();
    //#loadTex16col(this,trapattack)
    loadTex16col(this,menu_heal_png)
    //ulSetTransparentColor(RGB15(31, 0, 31));
    //loadTex16col(this,small_explosion)
    status = -1;



    mana = 80;

    interval = 60;
}

ChangeSideSpell::~ChangeSideSpell() {

}

void ChangeSideSpell::isPressed() {



    CSprite * bulletS;
    bulletS = new CAlchemySpell();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);

    GameCtrl::getSharedObject()->addDecoSprite(bulletS);
}



