
#include "mbed.h"
#include "math.h"

BusOut display(D6, D7, D9, D10, D11, D5, D4, D8);
Serial pc( USBTX, USBRX );

AnalogOut Aout(DAC0_OUT);

AnalogIn Ain(A0);
char table[20] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,
                  0xBF, 0x86, 0xDB, 0xCF, 0xE6, 0xED, 0xFD, 0x87, 0xFF, 0xEF };


float ADCdata;

int main(){

  float data[1000];

  for(int i=0; i<1000; i++)
  {
    data[i] = Ain;
    wait(0.001);
    pc.printf("%1.3f\r\n", data[i]);
  }
  while(1){

    ADCdata = Ain;

    Aout = ADCdata;

    wait(0.001);

  }


}
