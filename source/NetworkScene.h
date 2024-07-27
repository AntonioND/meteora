#ifndef __NetworkScene_H__
#define __NetworkScene_H__

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

class NetworkScene : public CScene
{
public :
    NetworkScene();

    virtual ~NetworkScene();

    virtual void render();


};



#endif
