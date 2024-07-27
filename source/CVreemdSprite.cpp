/*

    Sprite class for player ship

*/

#include "CVreemdSprite.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "meteor_png.h"

#include <cstdlib>
#include <time.h>
#include "math.h"
#include "bullet_png.h"

#include "small_pix_png.h"
#include "crap_small_png.h"
#include "CPixelDecal.h"

#include "vreemd_metroid_png.h"
#include "vreemd_supermario_png.h"
#include "vreemd_yoshi_png.h"

#include "GameScene.h"

CVreemdSprite::CVreemdSprite(): CBullet() {
/*    if (PA_Rand()%10==1) {
        weight =  int(1000+PA_Rand()%90);
    } else {
        weight =  int(PA_Rand()%90);
    }*/
    //this->size = sqrt(this->weight)*0.1; //pow(weight,1);
    weight =  int(PA_Rand()%180)+40;
    
    this->size = sqrt(this->weight)*0.1; //pow(weight,1);
    
    mType = 2;
    
    int rnd = (int)PA_Rand()%3;
    
    if (rnd==0) {
        loadTex(this,vreemd_metroid_png)
    }
    if (rnd==1) {
        loadTex(this,vreemd_supermario_png)
    }
    if (rnd==2) {
        loadTex(this,vreemd_yoshi_png)
    }

    //color = RGB15(255,255,255);

    type = GameScene::ennemy_id; //owner
}


CVreemdSprite::~CVreemdSprite() {
}

void CVreemdSprite::dead() {

    CBullet::dead();

    int sprite_size = (int)(size*(this->spriteTex->sizeX));

    //add Decals
    for (int i = 0; i < sprite_size; i++) {

        CPixelDecal * bulletS;

        bulletS = new CPixelDecal();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);

        bulletS->setX(this->x);
        bulletS->setY(this->y);
        bulletS->setVel(CFixed((int)PA_Rand()%64-32)/CFixed(32),CFixed((int)PA_Rand()%64-32)/CFixed(32));

        //loadTex16col(bulletS,crap_small)
                bulletS->size=0.4;
        bulletS->nextThink = 2;

        gc->addDecoSprite(bulletS);

    }

    //add explosion
    CExplosion * exp = new CExplosion(size*(this->spriteTex->sizeX));
    exp->x = this->x;
    exp->y = this->y;
    //exp->setVel(0,0);
    //exp->size = 1;
    GameCtrl::getSharedObject()->addDecoSprite(exp);

}
