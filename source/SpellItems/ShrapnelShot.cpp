/*

    Sprite class for player ship

*/

#include "ShrapnelShot.h"

#include <cstdlib>
#include <time.h>
#include "explosion.h"
#include "small_explosion.h"
#include "trapattack.h"

#include "explode.h"
#include "big_boom.h"

#include "../GameCtrl.h"

ShrapnelShot::ShrapnelShot() : SpellItem() {
    loadTex16col(this,trapattack)
    //loadTex16col(this,small_explosion)
    status = -1;
    mana = 50;
    interval = 40;
}

ShrapnelShot::~ShrapnelShot() {

}



