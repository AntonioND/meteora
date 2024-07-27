#ifndef __CScoreDecal_H__
#define __CScoreDecal_H__

#include "CSprite.h"

class CScoreDecal : public CSprite
{
public :

    int lifetime;
    int alpha;
    int layer;
    
    int score;

    CScoreDecal(int pScore);

    virtual ~CScoreDecal();

    virtual void thinking();

    virtual void draw(int offset);


};



#endif
