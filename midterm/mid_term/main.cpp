
#include "mbed.h"

#include "fsl_port.h"

#include "fsl_gpio.h"

#include <cmath>

#include "DA7212.h"


#define bufferLength (32)

#define signalLength (1024)


DA7212 audio;

#define UINT14_MAX        16383

// FXOS8700CQ I2C address

#define FXOS8700CQ_SLAVE_ADDR0 (0x1E<<1) // with pins SA0=0, SA1=0

#define FXOS8700CQ_SLAVE_ADDR1 (0x1D<<1) // with pins SA0=1, SA1=0

#define FXOS8700CQ_SLAVE_ADDR2 (0x1C<<1) // with pins SA0=0, SA1=1

#define FXOS8700CQ_SLAVE_ADDR3 (0x1F<<1) // with pins SA0=1, SA1=1

// FXOS8700CQ internal register addresses

#define FXOS8700Q_STATUS 0x00

#define FXOS8700Q_OUT_X_MSB 0x01

#define FXOS8700Q_OUT_Y_MSB 0x03

#define FXOS8700Q_OUT_Z_MSB 0x05

#define FXOS8700Q_M_OUT_X_MSB 0x33

#define FXOS8700Q_M_OUT_Y_MSB 0x35

#define FXOS8700Q_M_OUT_Z_MSB 0x37

#define FXOS8700Q_WHOAMI 0x0D

#define FXOS8700Q_XYZ_DATA_CFG 0x0E

#define FXOS8700Q_CTRL_REG1 0x2A

#define FXOS8700Q_M_CTRL_REG1 0x5B

#define FXOS8700Q_M_CTRL_REG2 0x5C

#define FXOS8700Q_WHOAMI_VAL 0xC7


I2C i2c( PTD9,PTD8);

Serial pc(USBTX, USBRX);

Timer debounce;

InterruptIn button(SW2);

InterruptIn keyboard(SW3);

DigitalOut redLED(LED1);

EventQueue queue(32*EVENTS_EVENT_SIZE);

Thread thread1;
Thread thread2;

int m_addr = FXOS8700CQ_SLAVE_ADDR1;

bool switch2 = false;

void FXOS8700CQ_readRegs(int addr, uint8_t * data, int len);

void FXOS8700CQ_writeRegs(uint8_t * data, int len);

int idC = 0;


float signal[signalLength];

int16_t waveform[kAudioTxBufferSize];

char serialInBuffer[bufferLength];

int serialCount = 0;


void playNote(int freq)

{

  for (int i = 0; i < kAudioTxBufferSize; i++)

  {

    waveform[i] = (int16_t) (signal[(uint16_t) (i * freq * signalLength * 1. / kAudioSampleFrequency) % signalLength] * ((1<<16) - 1));

  }

  // the loop below will play the note for the duration of 1s

  for(int j = 0; j < kAudioSampleFrequency / kAudioTxBufferSize; ++j)

  {

    audio.spk.play(waveform, kAudioTxBufferSize);

  }

}


void playNoteC(void) 
{
    if(selection_mode==1)
    {
        idC = queue.call_every(1, playNote, 261);
    }
    else if(selection_mode==2)
    {
        idC = queue.call_every(1, playNote, 261);
    }
    else if(selection_mode==3)
    {
        idC = queue.call_every(1, playNote, 261);
    }
}

void loadSignalHandler(void) {queue.call(loadSignal);}

int selection_mode(void)
{
    queue.cancel(idC);
    //
    return 1;
    return 2;
    return 3;
}

int main()
{
    thread1.start(callback(&queue, &EventQueue::dispatch_forever));
    queue.event(loadSignalHandler)
    queue.event(playNoteC);

    while(1){
    button.rise(queue.event(selection_mode));
    buttin.fall(queue.event(playNoteC));
    };

}

