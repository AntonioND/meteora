#ifndef __IntroScene_H__
#define __IntroScene_H__

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

class IntroScene : public CScene
{
public :
    IntroScene();

    virtual ~IntroScene();

    virtual void render();


};



#endif
