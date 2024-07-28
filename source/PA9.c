#include <PA9.h>

// The sample rate used for the recording (samples per second)
#define SAMPLE_RATE 120

// Temporary double buffer that will cause a callback from the ARM7 30 times
// per second.
static uint8_t temp_buffer[SAMPLE_RATE * 2 / 30];

static int mic_volume;

static void microphone_handler(void *completed_buffer, int length)
{
    // Read from an uncached mirror so that the buffer isn't brought into the
    // cache. That would prevent the ARM7 from sending data to the ARM9
    // reliably.
    int8_t *data = memUncached(completed_buffer);

    // Get absolute value to go from -128..127 to 0..127
    mic_volume = (int)*data;
    if (mic_volume < 0)
        mic_volume = -mic_volume;
    if (mic_volume > 127)
        mic_volume = 127;
}

void MicInit(void)
{
    // We need to ensure that the temporary buffer isn't cached so that the ARM7
    // can use it without issues. We also need to flush the recording and
    // playback buffers so that we can use DMA between them. We also need to
    // flush the playback buffer so that the audio hardware can see the
    // up-to-date values of the buffer always.
    DC_FlushRange(temp_buffer, sizeof(temp_buffer));

    // The microphone (especially on the DS) requires about a second to get its
    // input levels to a valid baseline. Normally you could just discard the
    // first half second, but in this example we enable it at the beginning of
    // main() so that we can always draw the waveform.
    soundMicRecord(temp_buffer, sizeof(temp_buffer),
                   MicFormat_8Bit, SAMPLE_RATE, microphone_handler);
}

int PA_MicGetVol(void)
{
    return mic_volume;
}

static u16 PA_AdjustAngle(u16 angle, s16 anglerot, s32 startx, s32 starty, s32 targetx, s32 targety)
{
    u64 distances[3];

    startx = startx << 8; // Fixed point...
    starty = starty << 8; // Fixed point...
    targetx = targetx << 8; // Fixed point...
    targety = targety << 8; // Fixed point...

    u16 tempangle = (angle - anglerot) & 511;

    // Calcul des distances en fonction des angles
    distances[0] = PA_Distance(startx + PA_Cos(tempangle), starty - PA_Sin(tempangle), targetx, targety);
    tempangle += anglerot;
    tempangle &= 511;
    distances[1] = PA_Distance(startx + PA_Cos(tempangle), starty - PA_Sin(tempangle), targetx, targety);
    tempangle += anglerot;
    tempangle &= 511;
    distances[2] = PA_Distance(startx + PA_Cos(tempangle), starty - PA_Sin(tempangle), targetx, targety);

    // On regarde si l'angle est optimal. Si ce n'est pas le cas,
    // on fait tourner toujours dans le meme sens...
    if (distances[0] < distances[1])
        angle -= anglerot;
    else if (distances[2] < distances[1])
        angle += anglerot;

    return angle & 511;
}

u16 PA_GetAngle(s32 startx, s32 starty, s32 targetx, s32 targety)
{
    u16 angle = 0;
    u16 anglerot = 180;

    while (anglerot > 5)
    {
        angle = PA_AdjustAngle(angle, anglerot, startx, starty, targetx, targety);
        anglerot = anglerot - ((3 * anglerot) >> 3); // On diminue petit ? petit la rotation...
    }

    // Ajustement encore plus pr?cis...
    anglerot = 4;
    angle = PA_AdjustAngle(angle, anglerot, startx, starty, targetx, targety);
    anglerot = 2;
    angle = PA_AdjustAngle(angle, anglerot, startx, starty, targetx, targety);
    anglerot = 1;
    angle = PA_AdjustAngle(angle, anglerot, startx, starty, targetx, targety);

    return angle;
}
