#ifndef __DSIODEVICE_H__
#define __DSIODEVICE_H__

void DSIO_Init(void);

bool DSIO_Connect(void);

u8 DSIO_CMD(u8 addr);

void DSIO_Rumble_On(void);

void DSIO_Rumble_Off(void);

u8 DSIO_Light(void);

u8 DSIO_BP(void);

void DSIO_LedOn(void);

void DSIO_LedOff(void);

u8 DSIO_Tilt(void);

u8 DSIO_Axe_X(void);

u8 DSIO_Axe_Y(void);

u8 DSIO_Axe_Z(void);



#endif


