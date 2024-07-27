/*

    Sprite class for player ship

*/

#include "CChargesShotSpell2.h"
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

#include "ModifierGrow.h"



CChargesShotSpell2::CChargesShotSpell2(): CSpriteCollidable(0,0,0) {
    lifetime = 0;
    alpha = 31;
    nextThink = 4;
    layer = 5;

    nbclicked = 0;
    x = CFixed(88);
    y = CFixed(192+32+92);

    loadTex16col(this,bullet_lumi_png);


}

CChargesShotSpell2::~CChargesShotSpell2() {
}

void CChargesShotSpell2::thinking()
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

void CChargesShotSpell2::draw(int offset) {
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

void CChargesShotSpell2::clicked(int px, int py){
    nbclicked++;

    if (nbclicked ==1) {
        CLineDecal * bulletS; //add a blank flash
        bulletS = new CLineDecal();
        bulletS->x1 = (int)x;
        bulletS->y1 = (int)y;
        bulletS->x2 = x+CFixed(40);
        bulletS->y2 = y-CFixed(40);
        bulletS->color = RGB15(31,31,25);
        GameCtrl::getSharedObject()->addDecoSprite(bulletS);


        y = y - CFixed(40);
        x = x + CFixed(40);
        GC_playSound(invoc_sound_raw);


    }

    if (nbclicked ==2) {
        CLineDecal * bulletS; //add a blank flash
        bulletS = new CLineDecal();
        bulletS->x1 = x;
        bulletS->y1 = y;
        bulletS->x2 = x+CFixed(40);
        bulletS->y2 = y+CFixed(40);
        bulletS->color = RGB15(31,31,25);
        GameCtrl::getSharedObject()->addDecoSprite(bulletS);


        y = y + CFixed(40);
        x = x + CFixed(40);
        GC_playSound(invoc_sound_raw);


    }

    if (nbclicked ==3) {
        CLineDecal * bulletS; //add a blank flash
        bulletS = new CLineDecal();
        bulletS->x1 = x;
        bulletS->y1 = y;
        bulletS->x2 = x-CFixed(40);
        bulletS->y2 = y+CFixed(40);
        bulletS->color = RGB15(31,31,25);
        GameCtrl::getSharedObject()->addDecoSprite(bulletS);


        y = y + CFixed(40);
        x = x - CFixed(40);
        GC_playSound(invoc_sound_raw);


    }

    if (nbclicked ==4) {
        CLineDecal * bulletS; //add a blank flash
        bulletS = new CLineDecal();
        bulletS->x1 = x;
        bulletS->y1 = y;
        bulletS->x2 = x-CFixed(40);
        bulletS->y2 = y-CFixed(40);
        bulletS->color = RGB15(31,31,25);
        GameCtrl::getSharedObject()->addDecoSprite(bulletS);


        y = y - CFixed(40);
        x = x - CFixed(40);
        GC_playSound(invoc_sound_raw);


    }


    //x = x + CFixed(40);
    alpha = 31;




    if (nbclicked >= 5) {
        GameCtrl * gc = GameCtrl::getSharedObject();

        CBullet * bulletS;
        bulletS = new CBullet();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
        bulletS->setX((int)(128));
        bulletS->setY((int)(192+32+96));
        bulletS->setVel(0,0);
        bulletS->weight = 30;
        bulletS->setSize (sqrt(bulletS->weight)*0.1);

        new ModifierGrow(bulletS,15,20);
        GameCtrl::getSharedObject()->addSprite(bulletS);


        alpha = 1;
        GameCtrl::getSharedObject()->drawOnScreen(128,192+32+96+30,"charged shot spell");
        this->dead();

        GC_playSound(invoc_final_sound_raw);


        CFlashDecal * bulletS2; //add a blank flash
        bulletS2 = new CFlashDecal();
        GameCtrl::getSharedObject()->addDecoSprite(bulletS2);
    }
}
