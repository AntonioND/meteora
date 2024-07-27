/*

    Sprite class for player ship

*/

#include "ChargeShot.h"

#include <cstdlib>
#include <time.h>
#include "explosion.h"
#include "small_explosion.h"
#include "frostflame_0.h"

#include "explode.h"
#include "big_boom.h"

//#include "tutorial_bas_1.h"

#include "../GameCtrl.h"

ChargeShot::ChargeShot() : SpellItem() {
    //loadTex(this,tutorial_bas_1)
    loadTex16col(this,frostflame_0)
    //loadTex16col(this,small_explosion)
    status = -1;
    mana = 60;
    interval = 40;
}

ChargeShot::~ChargeShot() {

}



