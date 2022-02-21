/*******************************************************************
    BenderTime.h
    Brett Martin
    7/1/2020
    
    Wrapping class for RTClib to manage setting and getting time
    via a DS3231 RTC connected via I2C and Wire lib
********************************************************************/

#ifndef BenderTime_h
#define BenderTime_h

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "Wprogram.h"
#endif

#include "RTClib.h"

class BenderTime {

protected:
    
    enum daysOfTheWeek {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday} day;
    
    RTC_DS3231 *_rtc;           // DS3231 Real Time Clock object

    int _ticks = 0;

    int _previousTick = 0;

public:
  
    BenderTime();               // Constructor

    void init();                // Init

    int getTime();   // Returns the current time in an array of digits

    int getSeconds();              // Returns the current time in seconds

    int getTemp();              // Returns the current temp

    void setTime();

    void systemTick();           // Counts seconds for clock

    void setTime(int year, int month, int day, int hour, int min, int sec);
};


#endif // BenderTime_h
