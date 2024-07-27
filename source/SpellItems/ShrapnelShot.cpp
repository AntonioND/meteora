/*

    Sprite class for player ship

*/

#include "ShrapnelShot.h"

#include <cstdlib>
#include <time.h>
#include "explosion_png.h"
#include "small_explosion_png.h"
#include "trapattack_png.h"

#include "explode_raw.h"
#include "big_boom_raw.h"

#include "../GameCtrl.h"

ShrapnelShot::ShrapnelShot() : SpellItem() {
    loadTex16col(this,trapattack_png)
    //loadTex16col(this,small_explosion_png)
    status = -1;
    mana = 50;
    interval = 40;
}

ShrapnelShot::~ShrapnelShot() {

}



