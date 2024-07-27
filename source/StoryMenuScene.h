#ifndef __StoryMenuScene_H__
#define __StoryMenuScene_H__

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

class StoryMenuScene : public CScene
{
public :
    StoryMenuScene();

    virtual ~StoryMenuScene();

    virtual void render();


};



#endif
