#ifndef __ChargeShot_H__
#define __ChargeShot_H__

#include "SpellItem.h"
#include "math.h"

#include "../GameCtrl.h"
#include "../GameScene.h"
#include "../CChargesShotManager.h"
#include "../ModifierGrow.h"

class ChargeShot : public SpellItem {
public :


    
    ChargeShot();

    virtual ~ChargeShot();
   // virtual void thinking();
   
   virtual void isPressed() {
                    
                        CBullet * bulletS;
                        bulletS = new CBullet();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
                        bulletS->setX((int)(128));
                        bulletS->setY((int)(192+32+96));
                        bulletS->setVel(0,0);
                        bulletS->weight = 20;
                        bulletS->setSize (sqrt(bulletS->weight)*0.1);
                        
                        new ModifierGrow(bulletS,10,10);

                        GameCtrl::getSharedObject()->addSprite(bulletS);

                        //GameCtrl::getSharedObject()->addSprite(bulletS);
   }
    


};



#endif
