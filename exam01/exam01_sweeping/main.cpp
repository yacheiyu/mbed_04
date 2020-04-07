#include "mbed.h"


PwmOut PWM1(D6);


int main() {

  while(1){
  PWM1.period(0.001);
  
  bool duty;
  float i;
  if (duty)
  {
      if(PWM1==1){
        PWM1=PWM1-0.1;
        !duty;
        PWM1.period(0.1);
      }
      else 
      {
          PWM1=PWM1+0.1;
          PWM1.period(0.1);
      }
  }
  else if(!duty)
  {
      if(PWM1==0){
        PWM1=PWM1+0.1;
        duty;
        PWM1.period(0.1);
      }
      else 
      {
          PWM1=PWM1-0.1;
          PWM1.period(0.1);
      }
  }
  }

}