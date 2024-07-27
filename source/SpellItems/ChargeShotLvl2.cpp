/*

    Sprite class for player ship

*/

#include "ChargeShotLvl2.h"

#include <cstdlib>
#include <time.h>
#include "explosion_png.h"
#include "small_explosion_png.h"
#include "frostflame_1_png.h"

#include "explode_raw.h"
#include "big_boom_raw.h"

#include "../GameCtrl.h"

ChargeShotLvl2::ChargeShotLvl2() : SpellItem() {
    loadTex16col(this,frostflame_1_png)
    //loadTex16col(this,small_explosion_png)
    status = -1;
    mana = 100;
    interval = 40;
}

ChargeShotLvl2::~ChargeShotLvl2() {

}



