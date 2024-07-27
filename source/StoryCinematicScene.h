#ifndef __StoryCinematicScene_H__
#define __StoryCinematicScene_H__

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

class StoryCinematicScene : public CScene
{
public :
    StoryCinematicScene(int);

    virtual ~StoryCinematicScene();

    virtual void render();
    
    int number;


};



#endif
