/*

    Sprite class for player ship

*/

#include "CFixed.h"
#include "GameCtrl.h"
#include "CExplosion.h"

#include "meteor.h"

#include <cstdlib>
#include <time.h>
#include "math.h"


CFixed::CFixed() {
    val = 0;
}

CFixed::CFixed(const CFixed& fixedVal) {
    val = fixedVal.val;
}

CFixed::CFixed(const CFixed* fixedVal) {
    val = fixedVal->val;
}

CFixed::CFixed(int i) {
    val = FIX(i);
}

CFixed::CFixed(float f) {
    val = ((int)(f*256));
}

CFixed::CFixed(double f) {
    val = ((int)(f*256));
}

CFixed CFixed::operator+(CFixed b) {
    CFixed ret;
    ret.val = val + b.val;
    return ret;
}

CFixed CFixed::operator*(CFixed b) {
    CFixed ret;
    ret.val = (val>>4)*(b.val>>4);
    return ret;
}

CFixed CFixed::operator-(CFixed b) {
    CFixed ret;
    ret.val =  val - b.val;
    return ret;
}

CFixed& CFixed::operator=(CFixed fixedVal) {
     if (this == &fixedVal)      // Same object?
      return *this;        // Yes, so skip assignment, and just return *this.

    val = fixedVal.val;
    return *this;
}



CFixed CFixed::operator/(CFixed fixedVal) {
    CFixed ret;
    ret.val = (val<<4)/(fixedVal.val>>4);
    return ret;
}

CFixed::operator int(void) {
    s32 ret = val;
    return UNFIX(ret);
}

CFixed::operator float(void) {
    return float(val)/256;
}


CFixed::~CFixed() {
}
