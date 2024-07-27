/*

    Sprite class for player ship

*/

#include "FastMath.h"

#include "malloc.h"

int * FastMath::sqrtPreCalc;

FastMath::FastMath() {
}

FastMath::~FastMath() {

}

void FastMath::init() {
    sqrtPreCalc = (int*) malloc(sizeof(int)*3000);
    for (int i=0; i< 2999; i++) {
        sqrtPreCalc[i] = 0;
    }

}


int FastMath::sqrt(int i) {
    if (i>2999) {
        return sqrt(i);
    }

    if (sqrtPreCalc[i]==0) {
        sqrtPreCalc[i] = sqrt(i);
    } 
    return sqrtPreCalc[i];
}
