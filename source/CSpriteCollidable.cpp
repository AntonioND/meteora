/*

    Sprite class for player ship

*/

#include "CSpriteCollidable.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "meteor_png.h"

#include <cstdlib>
#include <time.h>
#include "math.h"


CSpriteCollidable::CSpriteCollidable(int x, int y, int angle, int frameNumber): CSprite(x,y,angle,frameNumber) {
   gc->addCollisionMap(this,this->rangeDown);
}

CSpriteCollidable::~CSpriteCollidable() {
   gc->delCollisionMap(this,this->rangeDown);
}

void CSpriteCollidable::updatePos()
{
  gc->delCollisionMap(this,rangeDown);

   CSprite::updatePos();

   rangeDown =  (int)y - size*0.5*getRadius();
   //rangeDown = (int)y + 50;
   if (rangeDown < 0) {
        rangeDown = 0;
   } else if (rangeDown >=599) {
        rangeDown = 599;
   }

   rangeUp = (int)y + size*getRadius()*0.5;
   if (rangeUp < 0) {
        rangeUp = 0;
   } else if (rangeUp >=599) {
        rangeUp = 599;
   }

   gc->addCollisionMap(this,rangeDown);
}