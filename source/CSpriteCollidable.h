#ifndef __CSpriteCollidable_H__
#define __CSpriteCollidable_H__

#include "CSprite.h"

class CSpriteCollidable : public CSprite
{
public :
    CSpriteCollidable(int x=0, int y=0, int angle=0, int mFrameNumber = 1);

    virtual ~CSpriteCollidable();
    virtual void updatePos();



};



#endif
