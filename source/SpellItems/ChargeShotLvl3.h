#ifndef __ChargeShotLvl3_H__
#define __ChargeShotLvl3_H__

#include "SpellItem.h"
#include "math.h"

#include "../GameCtrl.h"
#include "../GameScene.h"
#include "../CChargesShotSpell2.h"

#include "../CBullet.h"
#include "../ModifierGrow.h"

class ChargeShotLvl3 : public SpellItem {
public :


    
    ChargeShotLvl3();

    virtual ~ChargeShotLvl3();
   // virtual void thinking();
   
   virtual void isPressed() {
                        CBullet * bulletS;
                        bulletS = new CBullet();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
                        bulletS->setX((int)(128));
                        bulletS->setY((int)(192+32+96));
                        bulletS->setVel(0,0);
                        bulletS->weight = 1000;
                        bulletS->setSize (sqrt(bulletS->weight)*0.1);
                        
                        new ModifierGrow(bulletS,10,100);

                        GameCtrl::getSharedObject()->addSprite(bulletS);

                        //GameCtrl::getSharedObject()->addSprite(bulletS);
   }
    


};



#endif
