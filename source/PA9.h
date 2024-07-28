#ifndef PA9_H__
#define PA9_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#include <nds.h>
#include <dswifi9.h>

static inline int PA_MicGetVol(void)
{
    // TODO
    // return PA_IPC.Mic.Volume
    return 0;
}

int PA_Sin(int angle);

int PA_Cos(int angle);

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
