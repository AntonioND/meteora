#ifndef __CWindPowerManager_H__
#define __CWindPowerManager_H__

#include "CBullet.h"

class CWindPowerManager : public CSprite
{
public :
    CWindPowerManager();

    virtual ~CWindPowerManager();
//    CWindPowerManager() {};
    void thinking();

    int usageTime;

    virtual void draw(int offset);

private:
    int angle;

};



#endif
