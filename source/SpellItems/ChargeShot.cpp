/*

    Sprite class for player ship

*/

#include "ChargeShot.h"

#include <cstdlib>
#include <time.h>
#include "explosion_png.h"
#include "small_explosion_png.h"
#include "frostflame_0_png.h"

#include "explode_raw.h"
#include "big_boom_raw.h"

//#include "tutorial_bas_1_png.h"

#include "../GameCtrl.h"

ChargeShot::ChargeShot() : SpellItem() {
    //loadTex(this,tutorial_bas_1)
    loadTex16col(this,frostflame_0_png)
    //loadTex16col(this,small_explosion_png)
    status = -1;
    mana = 60;
    interval = 40;
}

ChargeShot::~ChargeShot() {

}



