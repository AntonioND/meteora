/*

    Sprite class for player ship

*/

#include "ChargeShotLvl3.h"

#include <cstdlib>
#include <time.h>
#include "explosion.h"
#include "small_explosion.h"
#include "frostflame.h"

#include "explode.h"
#include "big_boom.h"

#include "../GameCtrl.h"

ChargeShotLvl3::ChargeShotLvl3() : SpellItem() {
    loadTex16col(this,frostflame)
    //loadTex16col(this,small_explosion)
    status = -1;
    mana = 1200;
    interval = 80;
}

ChargeShotLvl3::~ChargeShotLvl3() {

}



