/*

    Sprite class for player ship

*/

#include "ChargeShotLvl3.h"

#include <cstdlib>
#include <time.h>
#include "explosion_png.h"
#include "small_explosion_png.h"
#include "frostflame_png.h"

#include "explode_raw.h"
#include "big_boom_raw.h"

#include "../GameCtrl.h"

ChargeShotLvl3::ChargeShotLvl3() : SpellItem() {
    loadTex16col(this,frostflame_png)
    //loadTex16col(this,small_explosion)
    status = -1;
    mana = 1200;
    interval = 80;
}

ChargeShotLvl3::~ChargeShotLvl3() {

}



