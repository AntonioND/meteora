/*

    Sprite class for player ship

*/

#include "ModifierDie.h"
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


ModifierDie::ModifierDie(CSprite * _parent) :Modifier(_parent) {
    nextThink = 1;


    nextThink = 1;
    par = dynamic_cast<CBullet*>(_parent);

    duration = 0;

}

ModifierDie::~ModifierDie() {
}

void ModifierDie::thinking()
{
    if (par) {
        par->weight = par->weight -4;

        if (gc->getSpriteCount()> 40) {
            par->weight = par->weight -5;
        }

        if (gc->getSpriteCount()> 50) {
            par->weight = par->weight -10;
        }

        if (gc->getSpriteCount()> 70) {
            par->weight = par->weight -15;
        }

        if (gc->getSpriteCount()> 100) {
            par->weight = par->weight -15;
        }

        if (gc->getSpriteCount()> 120) {
            par->weight = par->weight -35;
        }

        if (gc->getSpriteCount()> 150) {
            par->weight = par->weight -35;
        }

        if (par->weight < 1) {
            par->weight = 1;
            this->dead();
        }


        duration++;

        if (duration == 60) { //become mergeable after 60 frames
            par->type = par->type | MERGEABLE;
        }
    }



}


void ModifierDie::duplicateAndAttachTo(CSprite * s) {
    //new ModifierDie(s);

    //DO NOT DUPLICATE DYING EFFECT ON MERGE
}

