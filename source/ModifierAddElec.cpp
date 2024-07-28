/*

    Sprite class for player ship

*/

#include "ModifierAddElec.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "CMeteor.h"

#include <cstdlib>
#include <time.h>
#include "math.h"

#include "CElecDecal.h"

#include "GameScene.h"


ModifierAddElec::ModifierAddElec(CSprite * _parent) :Modifier(_parent) {
    oldx = -1; oldy= -1;
    nextThink = 10;
}

ModifierAddElec::~ModifierAddElec() {
}

void ModifierAddElec::thinking()
{



    CElecDecal * s;
    s = new CElecDecal();
    s->setX(_parent->x-CFixed(20)+CFixed((int)rand()%40));
    s->setY(_parent->y-CFixed(20)+CFixed((int)rand()%40));
    //s->setX(_parent->x+CFixed(size*this->spriteTex->sizeX*PA_Sin(rand()%512)));
    //s->setY(_parent->y+CFixed(size*this->spriteTex->sizeX*PA_Cos(rand()%512)));

    GameCtrl::getSharedObject()->addDecoSprite(s);




}


