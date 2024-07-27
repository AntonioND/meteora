#ifndef __EnnemyMultipleShotsManager_H__
#define __EnnemyMultipleShotsManager_H__

#include "../CBullet.h"

class EnnemyMultipleShotsManager : public CSprite
{
public :
    EnnemyMultipleShotsManager(int ppower = 1);

    virtual ~EnnemyMultipleShotsManager();
//    EnnemyMultipleShotsManager() {};
    void thinking();

    float size;

    int bulletNumber;

    virtual void draw(int offset);

private:
    int angle;
    int pow;

};



#endif
