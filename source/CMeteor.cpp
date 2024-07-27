/*

    Sprite class for player ship

*/

#include "CMeteor.h"
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

#include "GameScene.h"

CMeteor::CMeteor(): CBullet() {
    if (PA_Rand()%10==1) {
        weight =  int(1000+PA_Rand()%90);
    } else {
        weight =  int(PA_Rand()%90);
    }
    this->size = sqrt(this->weight)*0.1; //pow(weight,1);
    mType = 2;
    loadTex(this,meteor_png)

    //color = RGB15(31,31,31);

    type = 2 | MERGEABLE; //owner
}

CMeteor::~CMeteor() {
}
/*
void CMeteor::thinking()
{
        /*if((x>255-32)) {
            setVel(-getVelX(),getVelY());
        }*/
/*
        CDecal * bulletS;

        bulletS = new CDecal();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);

        bulletS->setX(this->x);
        bulletS->setY(this->y);
        bulletS->setVel(CFixed((int)PA_Rand()%16-8)/CFixed(8),CFixed((int)PA_Rand()%16-8)/CFixed(8));

        loadTex16col(bulletS,bullet_small)
        bulletS->size=0.4;
        bulletS->nextThink = 2;
        gc->addDecoSprite(bulletS);
*/

/*
        if((int)y > 416) {
            //setVel(getVelX(),-getVelY());
            this->dead();
            if ((int) x > 0&&(int) x < 192) { //if in range
                GameScene::life = GameScene::life - CFixed(this->weight);
            }
        }

        if ((int)y< -100) {
            this->dead();
        }

        //this->spriteTex->angle+=1;
}*/

/*void CMeteor::draw(int offset) {
    this->spriteTex->stretchX = size*(this->spriteTex->sizeX);
    this->spriteTex->stretchY = size*(this->spriteTex->sizeY);
    this->spriteTex->angle = this->angle;
    //this->spriteTex->stretchX = 400;
        CSprite::draw(offset);
       /* if (!((offset-192)<(int)x<offset)) {
        ulDrawString((int)x, (int)y, "meteor");
        }
    //this->spriteTex->stretchX = this->spriteTex->sizeX;
    //this->spriteTex->stretchY = this->spriteTex->sizeY;

    this->angle +=1;

}*/

void CMeteor::dead() {

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




    //add residual bullet;
/*
    CBullet * bulletLet;
    bulletLet = new CBullet();
    bulletLet->setX(this->x);
    bulletLet->setY(this->y);
    bulletLet->weight = this->weight/2;
    bulletLet->setSize (sqrt(bulletLet->weight)*0.1); //pow(weight,1);
    gc->addSprite(bulletLet);
    */

}
