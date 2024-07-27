#ifndef __CMultipleShotsManager_H__
#define __CMultipleShotsManager_H__

#include "CBullet.h"

class CMultipleShotsManager : public CSprite
{
public :
    CMultipleShotsManager();

    virtual ~CMultipleShotsManager();
//    CMultipleShotsManager() {};
    void thinking();

    float size;

    int bulletNumber;

    int _bulletSize;

    virtual void draw(int offset);

private:
    int angle;

};



#endif
