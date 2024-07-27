/*

    Sprite class for player ship

*/

#include "CWindPowerManager.h"

#include "ModifierAddTrailer.h"

#include "GameCtrl.h"
#include "CExplosion.h"

#include "GameScene.h"


#include "CMeteor.h"

#include "launch_raw.h"

#include <cstdlib>
#include <time.h>
#include "math.h"

#include "CConcentrate.h"

#include "GameCtrl.h"
#include "CDecal.h"

#include "repell_png.h"

#include "DSIO.h"


CWindPowerManager::CWindPowerManager() :CSprite() {

    GameCtrl::getSharedObject()->drawOnScreen(128,96,"wind of god");

    GameCtrl::getSharedObject()->drawOnScreen(128,96+30,"blow on your screen");

    size =0;
    mType = 0;
    nextThink=2;

    usageTime = 0;


    CDecal * decal = new CDecal();
    loadTex16col(decal,repell_png)

    decal->nextThink = 2;
    decal->lifetime = 210;
    decal->x = 256-16;
    decal->y = 192+32+16;
    decal->size = 0.5;

    GameCtrl::getSharedObject()->addDecoSprite(decal);

    DSIO::ent()->ledOn();
}

CWindPowerManager::~CWindPowerManager() {
    DSIO::ent()->ledOff();
}

void CWindPowerManager::thinking()
{

    usageTime++;

    if (usageTime > 240) {
        this->dead();
    }

    GameCtrl * gc = GameCtrl::getSharedObject();
    for (int i =0; i < gc->_spriteNumber; i++) {

        CBullet * tmpSprite = dynamic_cast<CBullet*>(gc->_spriteList[i]);

        if (tmpSprite) {

            if (!(tmpSprite->type&STICKY_SPRT)) {


                CFixed velY = (CFixed(0)-(CFixed(70)*CFixed(tmpSprite->y)/CFixed(492)))*(CFixed(gc->getMicVolume())/(CFixed(250)))/CFixed(tmpSprite->getRealSize());

                tmpSprite->y = tmpSprite->y + velY/CFixed(5);
                tmpSprite->setVelY(tmpSprite->getVelY()+(velY/CFixed(2)));
            }
        }
    }
}

void CWindPowerManager::draw(int offset) {
}
