#ifndef __VreemdStoryCinematicScene_H__
#define __VreemdStoryCinematicScene_H__

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

class VreemdStoryCinematicScene : public CScene
{
public :
    VreemdStoryCinematicScene(int);

    virtual ~VreemdStoryCinematicScene();

    virtual void render();
    
    int number;


};



#endif
