// uLCD-144-G2 basic text demo program for uLCD-4GL LCD driver library

//

#include "mbed.h"

#include "uLCD_4DGL.h"


uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;


int main()

{

    uLCD.background_color(WHITE);
    uLCD.cls();

    // basic printf demo = 16 by 18 characters on screen

    uLCD.color(BLUE);
    uLCD.textbackground_color(WHITE);

    uLCD.printf("\n106061142\n"); //Default Green on black text

    uLCD.printf("\n  Starting Demo...");

    uLCD.text_width(4); //4X size text

    uLCD.text_height(4);

    uLCD.color(GREEN);
    uLCD.textbackground_color(WHITE);
    

    for (int i=30; i>=0; --i) {

        uLCD.locate(1,2);

        uLCD.printf("%2D",i);

        wait(.5);

        if(i==0)
           i=31;
        else i=i;

    }

}
