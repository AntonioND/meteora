/*

    Sprite class for player ship

*/

#include "CLineDecal.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "meteor.h"

#include <cstdlib>
#include <time.h>
#include "math.h"
#include "bullet.h"


CLineDecal::CLineDecal(): CSprite() {
    lifetime = 4;
    alpha = 30;
    nextThink = 1;
    layer = 1;
    border = 5;
    height = 50;
    color = RGB15(255,255,255);
    
    x1 = 0;
    y1 = 0;
    
    x2 = 50;
    y2 = 50;
}

CLineDecal::~CLineDecal() {
}

void CLineDecal::thinking()
{

/*        if (lifetime !=0) {
            lifetime--;
            return;
        }*/

        alpha-=1;
        //border -=1;

        if (alpha <1) {
                this->dead();
        }


}

void CLineDecal::draw(int offset) {

        //get angle
        u16 angle = PA_GetAngle(x1,y1,x2,y2);
        
        int x21,x22,y21,y22;
        
        x21 = x2-PA_Sin(angle)/50;
        x22 = x2+PA_Sin(angle)/50;
        
        y21 = y2-PA_Cos(angle)/50;
        y22 = y2+PA_Cos(angle)/50;

        ulSetAlpha(UL_FX_ALPHA, alpha, layer);

        ulDisableTexture();
        
        ulVertexBegin(GL_TRIANGLES);
        
        ulVertexColor(color);
        
        ulVertexXY(x1, y1-offset);
        ulVertexXY(x21, y21-offset);
        ulVertexXY(x22, y22-offset  );
        ulVertexEnd();
        
        ulVertexHandleDepth();

        ulSetAlpha(UL_FX_DEFAULT, 0, 0);

}
