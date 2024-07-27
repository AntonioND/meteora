#ifndef __CFixed_H__
#define __CFixed_H__

#include <ulib/ulib.h>

//Make it a float point value (1 = 256, 0.5 = 128, etc.)
#define FIX(x)		((x) << 8)
//Return the real value of a float point
#define UNFIX(x)	((x) >> 8)

class CFixed
{
public :
    CFixed();
    virtual ~CFixed();

    CFixed(const CFixed& fixedVal);
	CFixed(const CFixed* fixedVal);
    CFixed(float f);
    CFixed(double f);
    CFixed(int i);

    CFixed& operator=(CFixed fixedVal);

    CFixed operator+(CFixed b);
    CFixed operator*(CFixed b);
    CFixed operator-(CFixed b);
    CFixed operator/(CFixed b);

    operator int(void);
    operator float(void);

    double toDouble() { return (float)val/256;}

    s32 val;

};



#endif
