#ifndef __ModifierGrow_H__
#define __ModifierGrow_H__

#include "Modifier.h"

class ModifierGrow : public Modifier
{
public :
    ModifierGrow(CSprite *,int groMax = 10, int groInc = 10);

    int oldx, oldy;
    u16 trailerColor;

    virtual ~ModifierGrow();
    void thinking();

private:
    int angle;

    int growing_count;
    int growing_max;
    int growing_inc;

    virtual void duplicateAndAttachTo(CSprite *);

};



#endif
