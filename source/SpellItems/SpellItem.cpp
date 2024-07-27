/*

    Sprite class for player ship

*/

#include "SpellItem.h"

#include <cstdlib>

#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include "explosion_png.h"
#include "small_explosion_png.h"

#include "explode_raw.h"
#include "big_boom_raw.h"

#include "error_sound_raw.h"

#include "../GameCtrl.h"

#include "../GameScene.h"

SpellItem::SpellItem() :CDecal() {
    lastPressed= 0;
    interval = 1;
    mana = 0;
}

SpellItem::~SpellItem() {

}

void SpellItem::draw(int offset) {
        CDecal::draw(offset);

        if ((lastPressed != 0)||((int)GameScene::mana <(int) mana)) {
                    ulSetAlpha(UL_FX_ALPHA, 16, 1);
                    ulDrawFillRect((int)x-16, (int)y-offset-16, (int)x+16, (int)y-offset+16, RGB15(255, 0, 0));
                    ulSetAlpha(UL_FX_DEFAULT, 0, 0);
                    
                    if (lastPressed != 0) {
                        ulDrawFillRect((int)x+17, (int)y-offset-16, (int)x+19, (int)y-offset-16+(32*lastPressed/interval), RGB15(0, 100, 155));
                    }
        }

        ostringstream spellshow;
        spellshow << (int)mana;
        ulDrawString((int)x-6, (int)y-202, spellshow.str().c_str());
}

void SpellItem::thinking()
{
    if (status ==1) {
        if (alpha<30) {
            alpha +=6;
        } else {
            alpha = 31;
            nextThink = 4000;
        }
    } else {
        if (alpha>1) {
            alpha -=6;
        } else {
            alpha = 1;
            nextThink = 4000;
        }
    }
    size = 5-((float)alpha/31)*4;


    if (lastPressed >0) {
        lastPressed--;
    }
}

short int SpellItem::testCollision(int styletX, int styletY) {
     if (lastPressed != 0) {
        return false;
     }


     if (styletX < (int)x-16) {
            return false;
     }
     if (styletX > (int)x+16) {
            return false;
     }

     if (styletY < (int)y-16) {
            return false;
     }

     if (styletY > (int)y+16) {
            return false;
     }

     if ((int)GameScene::mana < (int) this->mana) {
         GC_playSound(error_sound_raw);
         lastPressed += 5;
         return false;
     }

     lastPressed = interval;

     GameScene::mana = GameScene::mana - this->mana;

     return true;

 }
