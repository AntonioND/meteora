#ifndef __FastMath_H__
#define __FastMath_H__

class FastMath
{
public :
    FastMath();
    virtual ~FastMath();
    
    static int * sqrtPreCalc;
    
    static void init();
    static int sqrt(int i);

};



#endif
