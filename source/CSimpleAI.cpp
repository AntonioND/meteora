/*

    Sprite class for player ship

*/

#include "CSimpleAI.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "CMeteor.h"

#include <cstdlib>
#include <time.h>

#include "GameScene.h"

//math
#include "math.h"

//modifier
#include "ModifierAddTrailer.h"
#include "ModifierShrapnel.h"

//sound
#include "launch.h"

#include "ennemyIA/EnnemyMultipleShotsManager.h"


CSimpleAI::CSimpleAI() :CSprite() {
    size =0;
    mType = 0;
    nextThink=30;

    probaTotalStop = 5;
    probaDeviation = 45;
    probaPartialDmg = 30;

    reactivity = 1;

    //GameScene::ennemy_life = CFixed(500);
    GameScene::ennemy_life = CFixed(500);

    extraPower = 1;
    probaAbsorb = 0;

    mana_gain = CFixed(0.4);


    probaSimpleAttack = 75;
    probaMassiveAttack = 5;
    probaMeteorAttack = 5;
    //probaShrapnelAttack = 0;
    probaShrapnelAttack = 0;
    probaBigAttack = 10;
}

CSimpleAI::~CSimpleAI() {
}

void CSimpleAI::thinking()
{
    /*CExplosion * exp = new CExplosion();
    exp->x = 50;
    exp->y = 50;
    exp->setVel(0,7);
    GameCtrl::getSharedObject()->addDecoSprite(exp);*/
    int order = PA_Rand()%100;


    if ((int)GameScene::ennemy_mana < (PA_Rand()%100)+50) {
        nextThink = reactivity * 10;
        return;
    }

     if ((int)GameScene::ennemy_mana > 1500) {
        CBullet * bulletS;
        bulletS = new CBullet(GameScene::ennemy_id);//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
        bulletS->setX((int)(128+PA_Rand()%180-90));
        bulletS->setY(-12);
        //bulletS->setVel(0,3);
        bulletS->setVel(0,CFixed(4)+CFixed((int)PA_Rand()%(extraPower/2)));
        bulletS->weight = 1501;
        bulletS->setSize (sqrt(bulletS->weight)*0.1);

        GameScene::ennemy_mana = GameScene::ennemy_mana - CFixed(1500);

        GameCtrl::getSharedObject()->addSprite(bulletS);

        GC_playSound(launch);
        nextThink = (15+PA_Rand()%40)* reactivity;
     }

    if (order < probaShrapnelAttack) {

            if ((int)GameScene::ennemy_mana > 50) {
            CBullet * bulletS;
            bulletS = new CBullet(GameScene::ennemy_id);//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
            bulletS->setX((int)(128+PA_Rand()%180-90));
            bulletS->setY(-12);
            //bulletS->setVel(0,3);
            bulletS->setVel(0,2);
            bulletS->weight = 50;
            bulletS->setSize (sqrt(bulletS->weight)*0.1);

            GameScene::ennemy_mana = GameScene::ennemy_mana - CFixed(50);

            new ModifierShrapnel(bulletS);

            GameCtrl::getSharedObject()->addSprite(bulletS);

             GC_playSound(launch);
             nextThink = (15+PA_Rand()%40)* reactivity;
            } else {
                    nextThink = 0;
            }
            return;

    } else if (order < (probaShrapnelAttack+probaBigAttack)) {
        if ((int)GameScene::ennemy_mana > 30) {
        CBullet * bulletS;
        bulletS = new CBullet(GameScene::ennemy_id);//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
        bulletS->setX((int)(128+PA_Rand()%180-90));
        bulletS->setY(-6);
        //bulletS->setVel(0,3);
        bulletS->setVel(0,4);
        bulletS->weight = 100+PA_Rand()%40;
        bulletS->setSize (sqrt(bulletS->weight)*0.1);

        GameScene::ennemy_mana = GameScene::ennemy_mana - CFixed(30);

        GameCtrl::getSharedObject()->addSprite(bulletS);

        ModifierAddTrailer * mat;

        mat = new ModifierAddTrailer(bulletS);

         GC_playSound(launch);
         nextThink = (15+PA_Rand()%40)* reactivity;
        } else {
                nextThink = 0;
        }
        return;

    }

    else if (order < (probaMeteorAttack+probaShrapnelAttack+probaBigAttack)) {


        if ((int)GameScene::ennemy_mana > 10) {
            if (GameCtrl::getSharedObject()->getSpriteCount() < 300) {
                CMeteor * meteor = new CMeteor();
                meteor->setX((int)(128+PA_Rand()%90-45));
                meteor->setY(-30);
                meteor->setVel(((float)(PA_Rand()%5))/4+PA_Rand()%extraPower,1);

                GameCtrl::getSharedObject()->addSprite(meteor);

                GameScene::ennemy_mana = GameScene::ennemy_mana - CFixed(10);
            }
        }

        nextThink = reactivity * 30;
        return;

    } else if (order < (probaSimpleAttack + probaMeteorAttack+probaShrapnelAttack+probaBigAttack)) {
        if ((int)GameScene::ennemy_mana > 10) {
        CBullet * bulletS;
        bulletS = new CBullet(GameScene::ennemy_id);//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
        bulletS->setX((int)(128+PA_Rand()%180-90));
        bulletS->setY(-12);
        //bulletS->setVel(0,3);
        bulletS->setVel(0,CFixed(4)+CFixed((int)PA_Rand()%extraPower));
        bulletS->weight = 12;
        bulletS->setSize (sqrt(bulletS->weight)*0.1);

        GameScene::ennemy_mana = GameScene::ennemy_mana - CFixed(10);

        GameCtrl::getSharedObject()->addSprite(bulletS);

        ModifierAddTrailer * mat;

        mat = new ModifierAddTrailer(bulletS);

         GC_playSound(launch);
         nextThink = (15+PA_Rand()%40)* reactivity;
        } else {
                nextThink = 0;
        }
        return;
    } else if (order < (probaMassiveAttack + probaMeteorAttack+probaSimpleAttack+probaShrapnelAttack+probaBigAttack)) {
        EnnemyMultipleShotsManager * ems = new EnnemyMultipleShotsManager(extraPower);
        GameCtrl::getSharedObject()->addSprite(ems);
    }


    //CSprite::dead();


}

void CSimpleAI::draw(int offset) {
}

void CSimpleAI::manageBullet(int bulletTotal, CBullet * s) {

/*    if (bulletSize > 30) {
        manageBullet(bulletSize-30);
        bulletSize = 30;
    }*/

if (bulletTotal < 3) {
    return;
}

int bulletSize;

while (bulletTotal > 0) {
    if (bulletTotal >= 30) {
        bulletSize = 30;
        bulletTotal-=30;
    } else {
        bulletSize = bulletTotal;
        bulletTotal = -1;
    }
    bulletSize = 30;
        int percent = PA_Rand()%100;
    /*
        probaTotalStop = 5;
        probaDeviation = 45;
        probaPartialDmg = 30;
    */

        if (percent < probaAbsorb) {
            GameScene::ennemy_mana = GameScene::ennemy_mana + CFixed(bulletSize); //simulate absorbtion
            return;
        }

        if (percent < probaTotalStop + probaAbsorb) {
                return; //simulate block with stylis
        }

        if (percent < (probaTotalStop+ probaDeviation+ probaAbsorb)) {
                if ((int)GameScene::ennemy_mana > 15 ) {
                        GameScene::ennemy_mana = GameScene::ennemy_mana - CFixed(15);
                } else {
                        GameScene::getInstance()->damage_ennemy(CFixed(bulletSize));
                }
                return; //simulate deviation
        }

        if (percent < (probaTotalStop + probaDeviation + probaPartialDmg+ probaAbsorb)) {
                GameScene::getInstance()->damage_ennemy(CFixed(bulletSize/3));
                return;
        } else {
                if ((int)GameScene::ennemy_mana > bulletSize ) {
                    //GameScene::getInstance()->damage_ennemy((CFixed(bulletSize/2))); //compensate by mana
                    GameScene::ennemy_mana = GameScene::ennemy_mana - CFixed(bulletSize/2);
                    return;
                } else {
                    GameScene::getInstance()->damage_ennemy(CFixed(bulletSize));
                }
        }
    }
}

void CSimpleAI::dead() {

}