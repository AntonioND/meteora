/*

    Sprite class for player ship

*/

#include "ModifierGrow.h"
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


ModifierGrow::ModifierGrow(CSprite * _parent,int groMax , int groInc) :Modifier(_parent) {
    oldx = -1; oldy= -1;
    nextThink = 1;

    growing_max = groMax;
    growing_inc = groInc;
    growing_count = 0;

    nextThink = 30;

    CBullet * par = dynamic_cast<CBullet*>(_parent);

    if (par) {
        par->color = par->color & RGB15(150,150,255);
    }
}

ModifierGrow::~ModifierGrow() {
}

void ModifierGrow::thinking()
{

    if (growing_count <= growing_max ) {

         GC_playSound(launch_raw);

         CConcentrate * cc;
         cc = new CConcentrate();
         cc->setX(_parent->x);
         cc->setY(_parent->y);
         GameCtrl::getSharedObject()->addDecoSprite(cc);

         growing_count++;


             CBullet * bulletS;
            bulletS = new CBullet();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
            bulletS->setX(_parent->x);
            bulletS->setY(_parent->y);
            bulletS->setVel(0,0);
            bulletS->weight = growing_inc;
            bulletS->setSize (sqrt(bulletS->weight)*0.1);


            GameCtrl::getSharedObject()->addSprite(bulletS);

     } else {
        nextThink = 20000;
     }
}


void ModifierGrow::duplicateAndAttachTo(CSprite * s) {
    new ModifierGrow(s,growing_max - growing_count, growing_inc);
}

