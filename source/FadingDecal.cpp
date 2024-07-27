/*

    Sprite class for player ship

*/

#include "FadingDecal.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "meteor_png.h"

#include <cstdlib>
#include <time.h>
#include "math.h"
#include "bullet_png.h"

#include "CScene.h"

FadingDecal::FadingDecal(): CSprite() {
    lifetime = 4;
    alpha = 1;
    nextThink = 1;
    layer = 8;
    border = 5;
    height = 50;
    color = RGB15(0,0,0);
}

FadingDecal::~FadingDecal() {
}

void FadingDecal::thinking()
{

/*        if (lifetime !=0) {
            lifetime--;
            return;
        }*/

        alpha+=3;
        //border -=1;

        if (alpha >31) {
            alpha = 31;
                //this->dead();
                CScene::stopScene();
        }


}

void FadingDecal::draw(int offset) {
        ulSetAlpha(UL_FX_ALPHA, alpha, layer);

        ulDrawFillRect(0, 0, 256, 192, color);

        ulSetAlpha(UL_FX_DEFAULT, 0, 0);

}
