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
#include <time.h>
#include <sys/socket.h>

#include <nds.h>
#include <dswifi9.h>

static inline int PA_Rand(void)
{
    return rand();
}

static inline void PA_Init(void)
{
    srand(time(NULL));
}

static inline void PA_InitVBL(void)
{
    // No need to do anything
}

static inline void PA_WaitForVBL(void)
{
    swiWaitForVBlank();
}

static inline void PA_InitSound(void)
{
    soundEnable();
}

static inline int PA_MicGetVol(void)
{
    // TODO
    // return PA_IPC.Mic.Volume
    return 0;
}

static inline void PA_StopSound(int ch)
{
    // TODO
}

static inline void PA_PlaySoundRepeat(int ch, const void *data)
{
    // TODO
}

static inline void PA_PlaySoundEx(int ch, const void *data, int length,
                                  int volume, int freq, int format)
{
    // TODO
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

#define PA_NONBLOCKING_TCP 2

int PA_InitSocket(int *sock, char *host, int port, int mode);

typedef struct {
    int volume;
    int freq;
    int format;
} PA_SoundOptionInfo;

__attribute__ ((unused)) static PA_SoundOptionInfo PA_SoundOption = { 0, 0, 0 };

typedef struct {
    const char *Name;
} PA_UserInfoInfo;

__attribute__ ((unused)) static PA_UserInfoInfo PA_UserInfo = { "Firmware" };

#ifdef __cplusplus
}
#endif

#endif // PA9_H__
