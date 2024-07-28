/*

    Sprite class for player ship

*/

#include "CElecDecal.h"

#include <cstdlib>
#include <time.h>
#include "explosion_png.h"
#include "small_explosion_png.h"

#include "explode_raw.h"
#include "big_boom_raw.h"

#include "GameCtrl.h"

#include "elec_effect_png.h"

CElecDecal::CElecDecal() :CSprite(0,0,0,10) {
    nextThink = 5;

    loadTex16col(this,elec_effect_png)
    //GC_playSound(explode);

    count = 0;

    this->frame= (int)rand()%10;


}

CElecDecal::~CElecDecal() {

}

void CElecDecal::draw(int offset) {
    //angle = angle+10;
    //this->spriteTex->stretchX =  0.1*this->spriteTex->sizeX;
    //this->spriteTex->stretchY =  0.1*this->spriteTex->sizeY;
    //this->spriteTex->angle = angle;
    //this->spriteTex->stretchX = 400;
        CSprite::draw(offset);
    //this->spriteTex->stretchX = this->spriteTex->sizeX;
    //this->spriteTex->stretchY = this->spriteTex->sizeY;
}

void CElecDecal::thinking()
{
        count ++;
        this->frame= (int)rand()%10;

        if (count > 3) {
            //frame = 6;
            dead();
        }
}

