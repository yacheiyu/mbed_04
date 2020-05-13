#include "mbed.h"

#include "uLCD_4DGL.h"


uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;


int main()

{

    // basic printf demo = 16 by 18 characters on screen

    

    uLCD.color(RED);
    uLCD.text_width(2);
    uLCD.text_height(2);
    uLCD.printf("Nangang");

    uLCD.color(GREEN);
    uLCD.text_width(1);
    uLCD.text_height(1);
    uLCD.printf("\n\n\nThis stop");

    uLCD.color(GREEN);
    uLCD.text_width(2);
    uLCD.text_height(2);
    uLCD.printf("\nChaozhou");




}