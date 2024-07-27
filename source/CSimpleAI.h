#ifndef __CSimpleAI_H__
#define __CSimpleAI_H__

#include "CBullet.h"


class CSimpleAI : public CSprite
{
public :
    CSimpleAI();

    virtual ~CSimpleAI();
//    CSimpleAI() {};
    void thinking();

    float size;

    virtual void draw(int offset);

    virtual void dead();

    virtual void manageBullet(int, CBullet *);


    int probaTotalStop;
    int probaDeviation;
    int probaPartialDmg;


    int probaSimpleAttack;
    int probaMassiveAttack;
    int probaShrapnelAttack;
    int probaMeteorAttack;
    int probaBigAttack;

    float reactivity;

    int extraPower;
    int probaAbsorb;

    CFixed mana_gain;

private:
    int angle;

};



#endif
