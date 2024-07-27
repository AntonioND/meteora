#ifndef __InsaneStoryCinematicScene_H__
#define __InsaneStoryCinematicScene_H__

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

class InsaneStoryCinematicScene : public CScene
{
public :
    InsaneStoryCinematicScene(int);

    virtual ~InsaneStoryCinematicScene();

    virtual void render();
    
    int number;


};



#endif
