/*

    Sprite class for player ship

*/

#include "CScoreDecal.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "meteor_png.h"

#include <cstdlib>
#include <time.h>
#include "math.h"
#include "bullet_png.h"

#include <sstream>

using namespace std;




CScoreDecal::CScoreDecal(int pScore): CSprite() {
    lifetime = 2;
    alpha = 31;
    nextThink = 4;
    layer = 8;
    score = pScore;
    velY = CFixed(0)-CFixed(0.2);
}

CScoreDecal::~CScoreDecal() {
}

void CScoreDecal::thinking()
{

        if (lifetime !=0) {
            lifetime--;
            return;
        }

        alpha --;

        if (alpha <1) {
                this->dead();
        }


}

void CScoreDecal::draw(int offset) {
        ulSetAlpha(UL_FX_ALPHA, alpha, layer);
        
         ostringstream oss;
         oss << score;
        
        ulDrawString((int) x,(int)y-offset, oss.str().c_str());
        //((int)x, (int)y-offset, (int)x+1, (int)y-offset+1, RGB15(255, 255, 255));

        ulSetAlpha(UL_FX_DEFAULT, 0, 0);

}
