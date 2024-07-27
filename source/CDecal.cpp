/*

    Sprite class for player ship

*/

#include "CDecal.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "meteor_png.h"

#include <cstdlib>
#include <time.h>
#include "math.h"
#include "bullet_png.h"


CDecal::CDecal(): CSprite() {
    lifetime = 0;
    alpha = 31;
    nextThink = 4;
    layer = 1;
}

CDecal::~CDecal() {
}

void CDecal::thinking()
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

void CDecal::draw(int offset) {
        //ulSetAlpha(UL_FX_DEFAULT, 0, 0);
    //Draw a blue sky background
        //ulDrawFillRect(0, 0, 256, 192, RGB15(0, 16, 31));
        ulSetAlpha(UL_FX_ALPHA, alpha, layer);

        this->spriteTex->stretchX =  size*this->spriteTex->sizeX;
        this->spriteTex->stretchY =  size*(this->spriteTex->sizeY)/mFrameNumber;

            //this->spriteTex->stretchY =  size*this->spriteTex->sizeY;
    //this->spriteTex->angle = angle;
    //this->spriteTex->stretchX = 400;
        CSprite::draw(offset);
        //CSprite::draw(offset);
        ulSetAlpha(UL_FX_DEFAULT, 0, 0);

}
