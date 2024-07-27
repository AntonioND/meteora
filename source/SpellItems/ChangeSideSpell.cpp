/*

    Sprite class for player ship

*/

#include "ChangeSideSpell.h"

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

#include "menu_heal.h"

ChangeSideSpell::ChangeSideSpell() : SpellItem() {
    //ulDisableTransparentColor();
    //#loadTex16col(this,trapattack)
    loadTex16col(this,menu_heal)
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



