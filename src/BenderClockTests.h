/*******************************************************************
    BenderClockTests.h
    Brett Martin
    2/16/2022
    
    Class to run tests against RTC hardware to ensure it functions correctly
********************************************************************/

#ifndef BenderClockTests_h
#define BenderClockTests_h

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "Wprogram.h"
#endif

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
#include "RTClib.h"
#include "Adafruit_LEDBackpack.h" 

class BenderClockTests {

private:
    // Button Pins
    const int buttonOne = 15;
    const int buttonTwo = 16;
    const int buttonThree = 17;
    const int led =  13;  

    // Button States
    int bStateOne = 0;
    int bStateTwo = 0;
    int bStateThree = 0;

    int LCDBrightness = 0;

    // Set to false to display time in 12 hour format, or true to use 24 hour:
    #define TIME_24_HOUR      false

    // I2C address of the display.  Stick with the default address of 0x70
    // unless you've changed the address jumpers on the back of the display.
    #define DISPLAY_ADDRESS   0x70


    // Create display and DS1307 objects.  These are global variables that
    // can be accessed from both the setup and loop function below.
    Adafruit_7segment clockDisplay = Adafruit_7segment();
    RTC_DS3231 rtc = RTC_DS3231();

    // Keep track of the hours, minutes, seconds displayed by the clock.
    // Start off at 0:00:00 as a signal that the time should be read from
    // the DS1307 to initialize it.
    int hours = 0;
    int minutes = 0;
    int seconds = 0;

    // Remember if the colon was drawn on the display so it can be blinked
    // on and off every second.
    bool blinkColon = false;

    char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    bool doOnce = false;

public:

    BenderClockTests();                   // Constructor including constructor vars for included classes

    void init();                // Init
   
};
#endif