#ifndef __ModifierDie_H__
#define __ModifierDie_H__

#include "Modifier.h"

#include "CBullet.h"

class ModifierDie : public Modifier
{
public :
    ModifierDie(CSprite *);

    int oldx, oldy;
    u16 trailerColor;

    virtual ~ModifierDie();
    void thinking();
    
    CBullet * par;

private:
    int angle;

    int growing_count;
    int growing_max;
    int growing_inc;

    virtual void duplicateAndAttachTo(CSprite *);
    
    int duration;

};



#endif
