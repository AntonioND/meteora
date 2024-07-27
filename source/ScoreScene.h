#ifndef __ScoreScene_H__
#define __ScoreScene_H__

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
