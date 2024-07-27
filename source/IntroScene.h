#ifndef __IntroScene_H__
#define __IntroScene_H__

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

class IntroScene : public CScene
{
public :
    IntroScene();

    virtual ~IntroScene();

    virtual void render();


};



#endif
