#ifndef __EasyStoryCinematicScene_H__
#define __EasyStoryCinematicScene_H__

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

class EasyStoryCinematicScene : public CScene
{
public :
    EasyStoryCinematicScene(int);

    virtual ~EasyStoryCinematicScene();

    virtual void render();
    
    int number;


};



#endif
