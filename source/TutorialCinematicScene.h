#ifndef __TutorialCinematicScene_H__
#define __TutorialCinematicScene_H__

#include "CScene.h"
#include "GameCtrl.h"


#include "CBullet.h"
#include "CExplosion.h"

#include "bullet_png.h"
#include "meteor_png.h"
#include "spacebas_png.h"
#include "spacehaut_png.h"

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
