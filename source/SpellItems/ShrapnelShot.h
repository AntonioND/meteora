#ifndef __ShrapnelShot_H__
#define __ShrapnelShot_H__

#include "SpellItem.h"
#include "math.h"

#include "../GameCtrl.h"
#include "../GameScene.h"
#include "../CChargesShotManager.h"
#include "../ModifierShrapnel.h"

class ShrapnelShot : public SpellItem {
public :


    
    ShrapnelShot();

    virtual ~ShrapnelShot();
   // virtual void thinking();
   
   virtual void isPressed() {
                    
                        CBullet * bulletS;
                        bulletS = new CBullet();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);
                        bulletS->setX((int)(128));
                        bulletS->setY((int)(192+32+96));
                        bulletS->setVel(0,0);
                        bulletS->weight = 50;
                        bulletS->setSize (sqrt(bulletS->weight)*0.1);
                        
                        new ModifierShrapnel(bulletS);

                        GameCtrl::getSharedObject()->addSprite(bulletS);

                        //GameCtrl::getSharedObject()->addSprite(bulletS);
   }
    


};



#endif
