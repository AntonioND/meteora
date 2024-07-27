/*

    Sprite class for player ship

*/

#include "CConcentrate.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "meteor.h"

#include <cstdlib>
#include <time.h>
#include "math.h"
#include "bullet.h"

#include "concentrate.h"


CConcentrate::CConcentrate(): CSprite() {
    lifetime = 12;
    alpha = 8;
    nextThink = 1;
    layer = 1;
    loadTex16col(this,concentrate);
    decSize = 0.5;
    size = 4;
}

CConcentrate::~CConcentrate() {
}

void CConcentrate::thinking()
{

        /*if (lifetime !=0) {
            lifetime--;
            return;
        }*/

        //alpha --;

        size = size - decSize;

        if (size < 0.01) {
                this->dead();
        }


}

void CConcentrate::draw(int offset) {
        //ulSetAlpha(UL_FX_DEFAULT, 0, 0);
    //Draw a blue sky background
        //ulDrawFillRect(0, 0, 256, 192, RGB15(0, 16, 31));
        ulSetAlpha(UL_FX_ALPHA, alpha, layer);

        this->spriteTex->stretchX =  size*this->spriteTex->sizeX;
        this->spriteTex->stretchY =  size*this->spriteTex->sizeX;

            //this->spriteTex->stretchY =  size*this->spriteTex->sizeY;
    //this->spriteTex->angle = angle;
    //this->spriteTex->stretchX = 400;
        CSprite::draw(offset);
        //CSprite::draw(offset);
        ulSetAlpha(UL_FX_DEFAULT, 0, 0);

}
