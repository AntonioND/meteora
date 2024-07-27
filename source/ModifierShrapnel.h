#ifndef __ModifierShrapnel_H__
#define __ModifierShrapnel_H__

#include "Modifier.h"
#include "CBullet.h"

class ModifierShrapnel : public Modifier
{
public :
    ModifierShrapnel(CSprite *);

    int oldx, oldy;
    u16 trailerColor;

    virtual ~ModifierShrapnel();
    void thinking();

private:
    int angle;

    int pa_weight;

    CBullet * parent_bul;

    virtual void duplicateAndAttachTo(CSprite *);

};



#endif
