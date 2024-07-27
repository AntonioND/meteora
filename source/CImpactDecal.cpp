/*

    Sprite class for player ship

*/

#include "CImpactDecal.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "GameScene.h"

#include "meteor.h"

#include <cstdlib>
#include <time.h>
#include "math.h"
#include "bullet.h"

#include "invoc_final_sound.h"

#include "DSIO.h"


CImpactDecal::CImpactDecal(int weight): CSprite() {
    lifetime = 1;
    alpha = 16;
    nextThink = 4;
    layer = 5;
    //border = 220;
    border = sqrt(weight)*0.1*32;
    //height = 50;
    color = RGB15(255,255,255);

    GC_playSound(invoc_final_sound);

    GameScene::getInstance()->setEarthQuake(2);

    DSIO::ent()->rumbleOn();
}

CImpactDecal::~CImpactDecal() {
    DSIO::ent()->rumbleOff();
}

void CImpactDecal::thinking()
{

        if (lifetime !=0) {
            lifetime--;
            return;
        }

        alpha-=2;

         if (gc->getTotalSpriteCount() > 600) {
                border -=1;
                alpha -=3;
        }

        border = (border * 0.7);

        if ((border <1)||(alpha <= 2)) {
                this->dead();
        }


}

void CImpactDecal::draw(int offset) {
        /*if ((int)y<0) {
            return;
        }*/

        /*if (((int)y-offset+height)> 192) {
            return;
        }*/




        ulSetAlpha(UL_FX_ALPHA, (alpha/3), layer);
        drawFillRect((int)x-(border/2), 0, (int)x+(border/2), 192, color);

        ulSetAlpha(UL_FX_ALPHA, (alpha*2/3), layer+1);
        drawFillRect((int)x-(border/2*2/3), 0, (int)x+(border/2*2/3), 192, color);

        ulSetAlpha(UL_FX_ALPHA, alpha, (layer+2));
        drawFillRect((int)x-(border/2/3), 0, (int)x+(border/2/3), 192, color);

        ulSetAlpha(UL_FX_DEFAULT, 0, 0);

}
