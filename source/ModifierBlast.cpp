/*

    Sprite class for player ship

*/

#include "ModifierBlast.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "CMeteor.h"

#include <cstdlib>
#include <time.h>
#include "math.h"

#include "CTrailDecal.h"

#include "GameScene.h"


ModifierBlast::ModifierBlast(CSprite * _parent) :Modifier(_parent) {
    velY = CFixed(0)-(CFixed(70)*CFixed(_parent->y)/CFixed(492));
    nextThink = 1;
}

ModifierBlast::~ModifierBlast() {
}

void ModifierBlast::thinking()
{
    //CBullet * p = (CBullet *) _parent;
    _parent->y = _parent->y + velY/CFixed(5);
    _parent->setVelY(_parent->getVelY()+(velY/CFixed(2)));
    velY = velY * CFixed(0.9);

    if ((int)velY > 0) {
        nextThink = 50000;
    }
}


