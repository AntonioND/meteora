/*

    Sprite class for player ship

*/

#include "CTextDecal.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "meteor_png.h"

#include <cstdlib>
#include <time.h>
#include "math.h"
#include "bullet_png.h"

#include <sstream>

using namespace std;




CTextDecal::CTextDecal(string pTxt): CSprite() {
    nextThink = 20000;

    text = pTxt;
    
    color = RGB15(31,31,31);
    
}

CTextDecal::~CTextDecal() {
}

void CTextDecal::thinking()
{



}

void CTextDecal::draw(int offset) {

        ulSetAlpha(UL_FX_DEFAULT, 0, 0);
        
        ulSetTextColor((unsigned)color);
        
        ulDrawString((int) x,(int)y-offset, text.c_str());
        
        ulSetTextColor((unsigned)RGB15(31,31,31));


}
