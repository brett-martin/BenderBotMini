/*******************************************************************
    BenderClock.h
    Brett Martin
    2/16/2022
    
    Wrapping class for all Benderclock functions
********************************************************************/

#ifndef BenderClock_h
#define BenderClock_h

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "Wprogram.h"
#endif

#include "Led.h"
#include "Button.h"
#include "BenderTime.h"
#include "Bender7Seg.h"
#include "BenderClockTests.h"
#include "BenderSetting.h"

class BenderClock {

private:
    Led *_antenna;              // antenna Led object

    Button *_buttonMenu;        // button input object

    Button *_buttonDown;        // button input object

    Button *_buttonUp;          // button input object
    
    BenderTime *_clock;         // Clock object

    Bender7Seg *_display;       // Display object

    BenderClockTests *_tests;   // Hardware tests for clock

    BenderSetting *_settings;

public:

    enum buttons {
        menu,
        up,
        down
    } myButtons;

    BenderClock(byte displayAddress, int menuButton, int upButton, int downButton, int antenna);    // Constructor including constructor vars for included classes

    void init(byte displayAddress, int menuButton, int upButton, int downButton, int antenna);      // Init

    bool buttonPushed(buttons button);                                                              // Checks to see if the button was pushed recently

    void antennaOn(byte state);                                                                     // Turn on the antenna

    void showClock(bool showColon);                                                                 // Display the time on the LED screen

    void showText(String text);                                                                     // Display text on the LED screen

    void showNumber(int number);                                                                    // Display a number on the LED screen

    int getTime();                                                                                  // Gets the current time

    void setTime(int year, int month, int day, int hour, int min, int sec);                         // Sets time on RTC

    BenderSetting::bSetting readSetting(BenderSetting::settingName setting);                                                                // Reads settings from EEPROM/SPI flash

    void writeSetting(BenderSetting::settingName setting, int value);   // Saves settings to EEPROM/SPI flash

    void setBrightness(uint8_t value);                                      
};
#endif