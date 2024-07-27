/*

    Sprite class for player ship

*/

#include "SacrificeSpell.h"

#include <cstdlib>
#include <time.h>
#include "explosion.h"
#include "small_explosion.h"
#include "menu_absorb.h"
#include "scream.h"
#include "multpleshotimg.h"

#include "explode.h"
#include "big_boom.h"

#include "../GameCtrl.h"
#include "../GameScene.h"


#include "../ModifierBlast.h"


SacrificeSpell::SacrificeSpell() : SpellItem() {
    //ulDisableTransparentColor();
    //#loadTex16col(this,trapattack)
    loadTex16col(this,menu_absorb)
    //ulSetTransparentColor(RGB15(31, 0, 31));
    //loadTex16col(this,small_explosion)
    status = -1;
    
    mana = 5;
    
    interval = 60;
}

SacrificeSpell::~SacrificeSpell() {

}

void SacrificeSpell::isPressed() {
    /*GameCtrl * gc = GameCtrl::getSharedObject();
    for (int i =0; i < gc->_spriteNumber; i++) {
        CSprite * tmpSprite = gc->_spriteList[i];
        new ModifierBlast(tmpSprite); //add blast effect on all sprites.
    }*/
    
    GC_playSound(scream);
    
    GameCtrl * gc = GameCtrl::getSharedObject();    
    
    GameScene::mana = GameScene::mana + CFixed(200);
    GameScene::life = GameScene::life - CFixed(75);
     
}



