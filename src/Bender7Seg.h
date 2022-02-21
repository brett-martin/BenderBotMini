/*******************************************************************
    Bender7Seg.h
    Brett Martin
    2/16/2022
    
    This class handles displaying images and animations on a 4 digit
    7-segment Led display
********************************************************************/

#ifndef Bender7Seg_h
#define Bender7Seg_h

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "Wprogram.h"
#endif

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
#include "Adafruit_LEDBackpack.h" // Generates warning messages, why?
#include "Led.h"


class Bender7Seg {
public:
  
    Bender7Seg(byte address, uint8_t brightness); // Setup the display

    void init();                                        // Init

    void setBrightness(uint8_t b);                      // Set brightness 0-15

    void writeDisplay();                                // Re-draw the display

    void clear();                                       // Clear the display

    // void showExpression(ExpressionNames name);                              // Show an expression spanning all segments

    void showNumber(int number, int segment);           // Show a single digit on a single segment

    void showText(const String text);

    void colonOn(bool state);                           // Turns on the colon for displaying time

    void showTime(int time, bool colon);

private:

    Adafruit_7segment display= Adafruit_7segment();

    int _hours = 0;
    int _minutes = 0;
    int _seconds = 0;

    bool _blinkColon = false;
    bool _time_24_hour = false;

    uint8_t _brightness = 2;                           // Holds current brightness

};


#endif // Bender7Seg_h
