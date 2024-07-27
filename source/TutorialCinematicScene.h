#ifndef __TutorialCinematicScene_H__
#define __TutorialCinematicScene_H__

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

class TutorialCinematicScene : public CScene
{
public :
    TutorialCinematicScene(int);

    virtual ~TutorialCinematicScene();

    virtual void render();
    
    int number;


};



#endif
