/*

    Sprite class for player ship

*/

#include "Modifier.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "meteor.h"

#include <cstdlib>
#include <time.h>
#include "math.h"
#include "bullet.h"


Modifier::Modifier(CSprite * parent): CSprite() {
    _parent = parent;
    parent->addModifier(this);
}

Modifier::~Modifier() {
}

void Modifier::thinking()
{

}

void Modifier::draw(int offset) {

}

void Modifier::duplicateAndAttachTo(CSprite *) {

}
