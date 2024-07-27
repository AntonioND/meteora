/*

    Sprite class for player ship

*/

#include "ModifierAddTrailer.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "CMeteor.h"

#include <cstdlib>
#include <time.h>
#include "math.h"

#include "CTrailDecal.h"

#include "GameScene.h"


ModifierAddTrailer::ModifierAddTrailer(CSprite * _parent) :Modifier(_parent) {
    oldx = -1; oldy= -1;
    nextThink = 1;
}

ModifierAddTrailer::~ModifierAddTrailer() {
}

void ModifierAddTrailer::thinking()
{

    if ((_parent->type&OWNER_MASK) == 1) {
        trailerColor = RGB15(25,25,31);
    } else if ((_parent->type&OWNER_MASK) == 2) {
        trailerColor = RGB15(31,25,25);
    } else if ((_parent->type&OWNER_MASK) == 3) {
        trailerColor = RGB15(25,31,25);
    } else if ((_parent->type&OWNER_MASK) == 4) {
        trailerColor = RGB15(31,31,25);
    } else if ((_parent->type&OWNER_MASK) == 5) {
        trailerColor = RGB15(31,25,31);
    }else {
        trailerColor = RGB15(7,7,7);
    }

    int cury = (int)_parent->y + (int)_parent->getVelY();

    if (oldy != -1) {

    CTrailDecal * s;
    s = new CTrailDecal();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
    s->setX(_parent->x);
    s->setY(_parent->y);
    //s->setVel(0,0);
    s->color = trailerColor;
    //bulletS->weight = 2;
    //bulletS->setSize (sqrt(bulletS->weight)*0.1);



    if (oldy > cury) {
        s->height = (oldy - cury);
    } else {
        s->height = (cury - oldy);
    }
        GameCtrl::getSharedObject()->addDecoSprite(s);
    }

    oldy = cury;


}


