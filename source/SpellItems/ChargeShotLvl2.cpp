/*

    Sprite class for player ship

*/

#include "ChargeShotLvl2.h"

#include <cstdlib>
#include <time.h>
#include "explosion.h"
#include "small_explosion.h"
#include "frostflame_1.h"

#include "explode.h"
#include "big_boom.h"

#include "../GameCtrl.h"

ChargeShotLvl2::ChargeShotLvl2() : SpellItem() {
    loadTex16col(this,frostflame_1)
    //loadTex16col(this,small_explosion)
    status = -1;
    mana = 100;
    interval = 40;
}

ChargeShotLvl2::~ChargeShotLvl2() {

}



