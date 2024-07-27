/*

    Sprite class for player ship

*/

#include "CSuperNovaDecal.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "GameScene.h"

#include "meteor_png.h"

#include <cstdlib>
#include <time.h>
#include "math.h"
#include "bullet_png.h"

#include "invoc_final_sound_raw.h"

#include "DSIO.h"


CSuperNovaDecal::CSuperNovaDecal(int weight): CSprite() {
    lifetime = 5;
    alpha = 31;
    nextThink = 10;
    layer = 5;
    //border = 220;
    border = sqrt(weight)*0.1*32;
    //height = 50;
    color = RGB15(255,255,255);

    GC_playSound(invoc_final_sound_raw);

    GameScene::getInstance()->setEarthQuake(5);
    DSIO::ent()->rumbleOn();
}

CSuperNovaDecal::~CSuperNovaDecal() {
    DSIO::ent()->rumbleOff();
}

void CSuperNovaDecal::thinking()
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

void CSuperNovaDecal::draw(int offset) {
        /*if ((int)y<0) {
            return;
        }*/

        /*if (((int)y-offset+height)> 192) {
            return;
        }*/




        ulSetAlpha(UL_FX_ALPHA, alpha, layer);

        drawFillRect(0, (int)y-offset-(border/2), 255, (int)y-offset+(border/2), color);

        ulSetAlpha(UL_FX_DEFAULT, 0, 0);

}
