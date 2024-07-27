/*

    Sprite class for player ship

*/

#include "SacrificeSpell.h"

#include <cstdlib>
#include <time.h>
#include "explosion_png.h"
#include "small_explosion_png.h"
#include "menu_absorb_png.h"
#include "scream_raw.h"
#include "multpleshotimg_png.h"

#include "explode_raw.h"
#include "big_boom_raw.h"

#include "../GameCtrl.h"
#include "../GameScene.h"


#include "../ModifierBlast.h"


SacrificeSpell::SacrificeSpell() : SpellItem() {
    //ulDisableTransparentColor();
    //#loadTex16col(this,trapattack_png)
    loadTex16col(this,menu_absorb_png)
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
    
    GC_playSound(scream_raw);
    
    GameCtrl * gc = GameCtrl::getSharedObject();    
    
    GameScene::mana = GameScene::mana + CFixed(200);
    GameScene::life = GameScene::life - CFixed(75);
     
}



