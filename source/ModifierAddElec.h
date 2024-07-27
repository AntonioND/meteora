#ifndef __ModifierAddElec_H__
#define __ModifierAddElec_H__

#include "Modifier.h"

class ModifierAddElec : public Modifier
{
public :
    ModifierAddElec(CSprite *);

    int oldx, oldy;
    u16 trailerColor;

    virtual ~ModifierAddElec();
    void thinking();

private:
    int angle;

};



#endif
