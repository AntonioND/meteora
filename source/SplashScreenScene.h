#ifndef __SplashScreenScene_H__
#define __SplashScreenScene_H__

#include "CScene.h"
#include "GameCtrl.h"


#include "CBullet.h"
#include "CExplosion.h"

#include "bullet.h"
#include "meteor.h"
#include "spacebas.h"
#include "spacehaut.h"

#include "CSimpleAI.h"

#include <sstream>

class SplashScreenScene : public CScene
{
public :
    SplashScreenScene();

    virtual ~SplashScreenScene();

    virtual void render();
    
    int fading ;
    
    void addSprite(CSprite *c) {
        GameCtrl::getSharedObject()->addDecoSprite(c);
    }


};



#endif
