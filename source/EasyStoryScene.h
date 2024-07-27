#ifndef __EasyStoryScene_H__
#define __EasyStoryScene_H__

#include "CScene.h"
#include "GameCtrl.h"


#include "CBullet.h"
#include "CExplosion.h"

#include "bullet.h"
#include "meteor.h"
#include "spacebas.h"
#include "spacehaut.h"

#include "CSimpleAI.h"

#include "StoryScene.h"

#include <sstream>

class EasyStoryScene : public StoryScene
{
public :
    EasyStoryScene();

    virtual ~EasyStoryScene();

    virtual CSimpleAI * generateAI(int level);
    virtual void renderCinematic(int i );

    virtual void displayCongrat();


};



#endif
