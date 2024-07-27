/*

    Sprite class for player ship

*/

#include "CPulseDecal.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "meteor.h"

#include <cstdlib>
#include <time.h>
#include "math.h"
#include "bullet.h"


CPulseDecal::CPulseDecal(): CDecal() {
    lifetime = 0;
    alpha = 31;
    nextThink = 1;
    layer = 1;
    alphaPulse = -2;
}

CPulseDecal::~CPulseDecal() {
}

void CPulseDecal::thinking()
{


        alpha += alphaPulse;
        if (alpha <10) {
            alphaPulse = 1;
        }

        if (alpha >29) {
            alphaPulse = -1;
        }
}

void CPulseDecal::draw(int offset) {
        //ulSetAlpha(UL_FX_DEFAULT, 0, 0);
    //Draw a blue sky background
        //ulDrawFillRect(0, 0, 256, 192, RGB15(0, 16, 31));
        ulSetAlpha(UL_FX_ALPHA, alpha, layer);

        this->spriteTex->stretchX =  size*this->spriteTex->sizeX;
        this->spriteTex->stretchY =  size*this->spriteTex->sizeY;

            //this->spriteTex->stretchY =  size*this->spriteTex->sizeY;
    //this->spriteTex->angle = angle;
    //this->spriteTex->stretchX = 400;
        CSprite::draw(offset);
        CSprite::draw(offset);
        ulSetAlpha(UL_FX_DEFAULT, 0, 0);

}
