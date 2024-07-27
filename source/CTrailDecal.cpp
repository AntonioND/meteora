/*

    Sprite class for player ship

*/

#include "CTrailDecal.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "meteor.h"

#include <cstdlib>
#include <time.h>
#include "math.h"
#include "bullet.h"


CTrailDecal::CTrailDecal(): CSprite() {
    lifetime = 4;
    alpha = 14;
    nextThink = 1;
    layer = 1;
    border = 5;
    height = 50;
    color = RGB15(200,200,255);
}

CTrailDecal::~CTrailDecal() {
}

void CTrailDecal::thinking()
{

/*        if (lifetime !=0) {
            lifetime--;
            return;
        }*/

        alpha-=3;

         if (gc->getTotalSpriteCount() > 600) {
                border -=1;
                alpha -=3;
         }

        border -=1;

        if (border <1) {
                this->dead();
        }


}

void CTrailDecal::draw(int offset) {
        if ((int)x<0) {
            return;
        }

        if (((int)y-offset+height)> 192) {
            return;
        }




        ulSetAlpha(UL_FX_ALPHA, alpha, layer);

        drawFillRect((int)x-(border/2), (int)y-offset, (int)x+(border/2), (int)y-offset+height, color);

        ulSetAlpha(UL_FX_DEFAULT, 0, 0);

}
