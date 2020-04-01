#include "mbed.h"

AnalogOut Aout(DAC0_OUT);
Serial pc( USBTX, USBRX );
AnalogIn Ain(A0);
//float ADCdata;
float Freq;
DigitalIn  Switch(SW3);
DigitalOut redLED(LED1);
DigitalOut greenLED(LED2);
BusOut display(D6, D7, D9, D10, D11, D5, D4, D8);
char table[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

int sample = 1000;

int main(){

  int i;
  float t = 1/sample;
  float ADCdata[sample];

  for(i=0;i<sample;i++)
  {
    //ADCdata[i] = Ain;
    ADCdata[i] = sin((i/5)*3.14);
    Aout = ADCdata[i];
    wait(t);
  }

  float max=0;
  for(i=0;i<sample;i++)
  {
    if(ADCdata[i]>max)
       max = ADCdata[i];
    else max = max;
  }

  //float Time;
  int n;

  for(i=0;i<sample;i++)
  {
    if(ADCdata[i]==max)
    {
      n = i;
      break;
    }
    else continue;
  }

  int diff;

  for(i=n+1;i<sample;i++)
  {
    if(ADCdata[i]==max)
    {
      diff = i-n;
      break;
    }
    else continue;
  }

  Freq = 1 / (diff*t);

  printf("%f",Freq);
 
}