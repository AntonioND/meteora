#ifndef __TutorialScene_H__
#define __TutorialScene_H__

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

class TutorialScene : public CScene
{
public :
    TutorialScene();

    virtual ~TutorialScene();

    virtual void render();


};



#endif
