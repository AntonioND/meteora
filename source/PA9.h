#ifndef PA9_H__
#define PA9_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <nds.h>

void MicInit(void);

int PA_MicGetVol(void);

static inline int PA_Sin(int angle)
{
    return sinLerp(angle * 64) >> 4;
}

static inline int PA_Cos(int angle)
{
    return cosLerp(angle * 64) >> 4;
}

u16 PA_GetAngle(s32 startx, s32 starty, s32 targetx, s32 targety);

static inline int PA_Distance(int x1, int y1, int x2, int y2)
{
    int64_t h = x1 - x2;
    int64_t v = y1 - y2;
    return h * h + v * v;
}

#ifdef __cplusplus
}
#endif

#endif // PA9_H__
