#ifndef __MarathonScene_H__
#define __MarathonScene_H__

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

class MarathonScene : public CScene
{
public :
    MarathonScene();

    virtual ~MarathonScene();

    virtual void render();


};



#endif
