#ifndef __HelpScene_H__
#define __HelpScene_H__

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

class HelpScene : public CScene
{
public :
    HelpScene();

    virtual ~HelpScene();

    virtual void render();


};



#endif
