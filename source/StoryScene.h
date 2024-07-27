#ifndef __StoryScene_H__
#define __StoryScene_H__

#include "CScene.h"
#include "GameCtrl.h"


#include "CBullet.h"
#include "CExplosion.h"

#include "bullet.h"
#include "meteor.h"
#include "spacebas.h"
#include "spacehaut.h"

#include "CSimpleAI.h"

#include "GameScene.h"

#include <sstream>

class StoryScene : public CScene
{
public :
    StoryScene();

    virtual ~StoryScene();

    virtual void render();

    virtual CSimpleAI * generateAI(int level);
    virtual void renderCinematic(int i );

    string mode;

    int step;

    virtual void displayCongrat();

    GameScene * game;


};



#endif
