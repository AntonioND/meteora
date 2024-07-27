#ifndef __EasyStoryScene_H__
#define __EasyStoryScene_H__

#include "CScene.h"
#include "GameCtrl.h"


#include "CBullet.h"
#include "CExplosion.h"

#include "bullet_png.h"
#include "meteor_png.h"
#include "spacebas_png.h"
#include "spacehaut_png.h"

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
