#ifndef __MenuScene_H__
#define __MenuScene_H__

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

class MenuScene : public CScene
{
public :
    MenuScene();

    virtual ~MenuScene();

    virtual void render();


};



#endif
