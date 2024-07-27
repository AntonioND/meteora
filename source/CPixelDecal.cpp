/*

    Sprite class for player ship

*/

#include "CPixelDecal.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "meteor_png.h"

#include <cstdlib>
#include <time.h>
#include "math.h"
#include "bullet_png.h"


CPixelDecal::CPixelDecal(): CSprite() {
    lifetime = 0;
    alpha = 32;
    nextThink = 4;
    layer = 1;
}

CPixelDecal::~CPixelDecal() {
}

void CPixelDecal::thinking()
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

void CPixelDecal::draw(int offset) {
        ulSetAlpha(UL_FX_ALPHA, alpha, layer);

        ulDrawFillRect((int)x, (int)y-offset, (int)x+1, (int)y-offset+1, RGB15(31, 31, 31));

        ulSetAlpha(UL_FX_DEFAULT, 0, 0);

}
