#ifndef __ModifierAddTrailer_H__
#define __ModifierAddTrailer_H__

#include "Modifier.h"

class ModifierAddTrailer : public Modifier
{
public :
    ModifierAddTrailer(CSprite *);

    int oldx, oldy;
    u16 trailerColor;

    virtual ~ModifierAddTrailer();
    void thinking();

private:
    int angle;

};



#endif
