/*

    Sprite class for player ship

*/

#include "CFlashDecal.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "meteor_png.h"

#include <cstdlib>
#include <time.h>
#include "math.h"
#include "bullet_png.h"


CFlashDecal::CFlashDecal(): CSprite() {
    lifetime = 4;
    alpha = 30;
    nextThink = 1;
    layer = 1;
    border = 5;
    height = 50;
    color = RGB15(31,31,31);
}

CFlashDecal::~CFlashDecal() {
}

void CFlashDecal::thinking()
{

/*        if (lifetime !=0) {
            lifetime--;
            return;
        }*/

        alpha-=3;
        //border -=1;

        if (alpha <1) {
                this->dead();
        }


}

void CFlashDecal::draw(int offset) {
        ulSetAlpha(UL_FX_ALPHA, alpha, layer);

        ulDrawFillRect(0, 0, 256, 192, color);

        ulSetAlpha(UL_FX_DEFAULT, 0, 0);

}
