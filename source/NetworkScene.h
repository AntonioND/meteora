#ifndef __NetworkScene_H__
#define __NetworkScene_H__

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

class NetworkScene : public CScene
{
public :
    NetworkScene();

    virtual ~NetworkScene();

    virtual void render();


};



#endif
