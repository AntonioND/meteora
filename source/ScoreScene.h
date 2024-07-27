#ifndef __ScoreScene_H__
#define __ScoreScene_H__

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

class ScoreScene : public CScene
{
public :
    ScoreScene();
    
    int totalMana;
    int totalTime;
    int win;

    virtual ~ScoreScene();

    virtual void render();


};



#endif
