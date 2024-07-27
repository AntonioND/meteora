/*

    Sprite class for player ship

*/

#include "ModifierShrapnel.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "CMeteor.h"

#include "CBullet.h"

#include <cstdlib>
#include <time.h>
#include "math.h"

#include "CTrailDecal.h"

#include "GameScene.h"

#include "CConcentrate.h"
#include "launch_raw.h"

#include "CExplosion.h"

#include "ModifierAddTrailer.h"
#include "ModifierDie.h"


ModifierShrapnel::ModifierShrapnel(CSprite * _parent) :Modifier(_parent) {
    oldx = -1; oldy= -1;
    nextThink = 1;


    nextThink = 2;

    CBullet * par = dynamic_cast<CBullet*>(_parent);

    if (par) {
        parent_bul = par;
        pa_weight = (int)par->weight;

        par->color = par->color & RGB15(255,255,180);
    }
}

ModifierShrapnel::~ModifierShrapnel() {

//CBullet * par = dynamic_cast<CBullet*>(_parent);

            if (pa_weight < 7) {
                    return;
            }

            int we = pa_weight;

            CExplosion * exp = new CExplosion((int)(size*(_parent->spriteTex->sizeX)));
            exp->x = _parent->x;
            exp->y = _parent->y;
                //exp->setVel(0,0);
                //exp->size = 1;
            GameCtrl::getSharedObject()->addDecoSprite(exp);

            int number = 4;

            if (gc->getSpriteCount()> 70) {
                number -= ((gc->getSpriteCount()-70)/20);
            }




            for (int z = 0; z< number; z++) {

                we = we - 7;
                CBullet * bulletS;
                bulletS = new CBullet((_parent->type&OWNER_MASK));//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
                bulletS->setX(_parent->x);
                bulletS->setY(_parent->y);
                bulletS->setVel(_parent->getVelX()-CFixed(1)+CFixed(z)/CFixed(2),_parent->getVelY()*CFixed(1.5)-(CFixed((int)PA_Rand()%8)/CFixed(8)));
                bulletS->weight = pa_weight/5;
                bulletS->setSize(parent_bul->size/4);

                bulletS->type = _parent->type&OWNER_MASK;

                //bulletS->color = RGB15(150,100,150);
                //bulletS->setSize (_parent->size);

                GameCtrl::getSharedObject()->addSprite(bulletS);

                if (gc->getTotalSpriteCount() < 600) {
                    new ModifierAddTrailer(bulletS);
                }

                new ModifierDie(bulletS);

                if ((z ==3)||(z==4)) {
                new ModifierShrapnel(bulletS);
                }
            }

}

void ModifierShrapnel::thinking()
{

    if (gc->getSpriteCount() < 80) {
        if ((int)pa_weight > parent_bul->weight) {
            _parent->dead();
        } else {
            pa_weight = (int)parent_bul->weight;
        }
    }
}


void ModifierShrapnel::duplicateAndAttachTo(CSprite * s) {
    new ModifierShrapnel(s);
}

