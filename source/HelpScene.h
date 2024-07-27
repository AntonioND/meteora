#ifndef __HelpScene_H__
#define __HelpScene_H__

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

class HelpScene : public CScene
{
public :
    HelpScene();

    virtual ~HelpScene();

    virtual void render();


};



#endif
