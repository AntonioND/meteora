#ifndef __HardStoryCinematicScene_H__
#define __HardStoryCinematicScene_H__

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

class HardStoryCinematicScene : public CScene
{
public :
    HardStoryCinematicScene(int);

    virtual ~HardStoryCinematicScene();

    virtual void render();
    
    int number;


};



#endif
