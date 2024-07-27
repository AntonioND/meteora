/*

    Sprite class for player ship

*/

#include "CExplosion.h"

#include <cstdlib>
#include <time.h>
#include "explosion.h"
#include "small_explosion.h"

#include "explode.h"
#include "big_boom.h"

#include "GameCtrl.h"

CExplosion::CExplosion(int pSize) :CSprite(0,0,0,7) {
    size =pSize;
    nextThink = 3;

    if (this->size>8) {
         loadTex16col(this,explosion)
         GC_playSound(big_boom);
         size = pSize * 2;

    } else {
        loadTex16col(this,small_explosion)
        GC_playSound(explode);
    }


}

CExplosion::~CExplosion() {

}

void CExplosion::draw(int offset) {
    //angle = angle+10;
    //this->spriteTex->stretchX =  0.1*this->spriteTex->sizeX;
    //this->spriteTex->stretchY =  0.1*this->spriteTex->sizeY;
    //this->spriteTex->angle = angle;
    //this->spriteTex->stretchX = 400;
        CSprite::draw(offset);
    //this->spriteTex->stretchX = this->spriteTex->sizeX;
    //this->spriteTex->stretchY = this->spriteTex->sizeY;
}

void CExplosion::thinking()
{
        this->frame+=1;

        if (frame > 6) {
            frame = 6;
            dead();
        }
}

