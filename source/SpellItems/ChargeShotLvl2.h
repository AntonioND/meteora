#ifndef __ChargeShotLvl2_H__
#define __ChargeShotLvl2_H__

#include "SpellItem.h"
#include "math.h"

#include "../GameCtrl.h"
#include "../GameScene.h"
#include "../CChargesShotSpell2.h"

class ChargeShotLvl2 : public SpellItem {
public :


    
    ChargeShotLvl2();

    virtual ~ChargeShotLvl2();
   // virtual void thinking();
   
   virtual void isPressed() {
                    CSprite * bulletS;  
                    bulletS = new CChargesShotSpell2();//(ul_keys.touch.x,ul_keys.touch.y+192+32,0);

                    GameCtrl::getSharedObject()->addDecoSprite(bulletS);
   }
    


};



#endif
