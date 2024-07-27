/*

    Sprite class for player ship

*/

#include "CAlchemySpell.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "meteor_png.h"

#include <cstdlib>
#include <time.h>
#include "math.h"
#include "bullet_png.h"

#include "CBullet.h"

#include "GameScene.h"

#include "bullet_lumi_png.h"




#include "invoc_sound_raw.h"
#include "invoc_final_sound_raw.h"

#include "CFlashDecal.h"
#include "CPixelDecal.h"
#include "CLineDecal.h"



CAlchemySpell::CAlchemySpell(): CSpriteCollidable(0,0,0) {
    lifetime = 0;
    alpha = 31;
    nextThink = 4;
    layer = 5;

    nbclicked = 0;
    x = CFixed(80);
    y = CFixed(192+32+120);

    loadTex16col(this,bullet_lumi_png);


}

CAlchemySpell::~CAlchemySpell() {
}

void CAlchemySpell::thinking()
{

        if (lifetime !=0) {
            lifetime--;
            return;
        }

        alpha --;

        if (alpha <1) {
                this->dead();
        }


}

void CAlchemySpell::draw(int offset) {
        //ulSetAlpha(UL_FX_DEFAULT, 0, 0);
    //Draw a blue sky background
        //ulDrawFillRect(0, 0, 256, 192, RGB15(0, 16, 31));
        ulSetAlpha(UL_FX_ALPHA, alpha, layer);

/*
        this->spriteTex->angle += 1;

        if (this->spriteTex->angle > 360) {
                this->spriteTex->angle = 0;
        }*/

        this->spriteTex->stretchX =  size*this->spriteTex->sizeX;
        this->spriteTex->stretchY =  size*(this->spriteTex->sizeY)/mFrameNumber;

            //this->spriteTex->stretchY =  size*this->spriteTex->sizeY;
    //this->spriteTex->angle = angle;
    //this->spriteTex->stretchX = 400;
        CSprite::draw(offset);
        //CSprite::draw(offset);
        ulSetAlpha(UL_FX_DEFAULT, 0, 0);

       if (angle%6==0) { //only each 3 frames

            CPixelDecal * bulletS;

            bulletS = new CPixelDecal();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);

            bulletS->setX(this->x);
            bulletS->setY(this->y);
            bulletS->setVel(CFixed((int)PA_Rand()%64-32)/CFixed(32),CFixed((int)PA_Rand()%64-32)/CFixed(32));


            GameCtrl::getSharedObject()->addDecoSprite(bulletS);
        }

}

void CAlchemySpell::clicked(int px, int py){
    nbclicked++;

    if (nbclicked ==1) {
        y = CFixed(192+32+40);
        GC_playSound(invoc_sound_raw);
        CLineDecal * bulletS; //add a blank flash
        bulletS = new CLineDecal();
        bulletS->x1 = 80;
        bulletS->y1 = 192+32+120;
        bulletS->x2 = 80+40;
        bulletS->y2 = 192+32+40;
        bulletS->color = RGB15(255,255,200);
        GameCtrl::getSharedObject()->addDecoSprite(bulletS);

    }

    if (nbclicked ==2) {
        y = CFixed(192+32+120);
        GC_playSound(invoc_sound_raw);

        CLineDecal * bulletS; //add a blank flash
        bulletS = new CLineDecal();
        bulletS->x1 = 80+40;
        bulletS->y1 = 192+32+40;
        bulletS->x2 = 80+40+40;
        bulletS->y2 = 192+32+120;
        bulletS->color = RGB15(255,255,200);


        GameCtrl::getSharedObject()->addDecoSprite(bulletS);
    }

    x = x + CFixed(40);
    alpha = 31;




    if (nbclicked >= 3) {
        GameCtrl * gc = GameCtrl::getSharedObject();
        for (int i =0; i < gc->_spriteNumber; i++) {

            CBullet * tmpSprite = dynamic_cast<CBullet*>(gc->_spriteList[i]);

            //CSprite * tmpSprite = gc->_spriteList[i];

            if (tmpSprite) {
                tmpSprite->changeOwner(GameScene::player_id);
            }
        }
        alpha = 1;
        GameCtrl::getSharedObject()->drawOnScreen(128,96,"change side spell");
        this->dead();

        GC_playSound(invoc_final_sound_raw);


        CFlashDecal * bulletS; //add a blank flash
        bulletS = new CFlashDecal();
        GameCtrl::getSharedObject()->addDecoSprite(bulletS);
    }
}
