#include "mbed.h"

#include "uLCD_4DGL.h"


uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;


int main()

{

    // basic printf demo = 16 by 18 characters on screen

    uLCD.color(RED);
    uLCD.printf("106061142\n"); //Default Green on black text

    //uLCD.printf("\n  Starting Demo...");
    /*
    uLCD.text_width(4); //4X size text

    uLCD.text_height(4);

    uLCD.color(RED);

    for (int i=10; i>=0; --i) {

        uLCD.locate(1,2);

        uLCD.printf("%2D",i);

        wait(.5);

    }
    */
    uLCD.rectangle(50,50,100,100,0x00FF00);

}