#ifndef __CChargesShotManager_H__
#define __CChargesShotManager_H__

#include "CBullet.h"

class CChargesShotManager : public CSprite
{
public :
    CChargesShotManager();

    virtual ~CChargesShotManager();
//    CChargesShotManager() {};
    void thinking();

    float size;

    int bulletNumber;

    int _bulletSize;

    virtual void draw(int offset);

private:
    int angle;

};



#endif
