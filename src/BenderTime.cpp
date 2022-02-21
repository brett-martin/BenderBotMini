/*******************************************************************
    BenderTime.cpp
    Brett Martin
    7/1/2020
    
    Wrapping class for RTClib to manage setting and getting time
    via a DS3231 RTC connected via I2C and Wire lib
********************************************************************/

#include "RTClib.h"
#include "BenderTime.h"
#include <time.h>

BenderTime::BenderTime() {
  init(); 
}

void BenderTime::init() {
   _rtc = new RTC_DS3231();

  Serial.println("Starting RTC");

  if (! _rtc->begin()) {
    Serial.println("Couldn't find RTC");
    //abort();
  }

  if (_rtc->lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    _rtc->adjust(DateTime(2020, 7, 16, 5, 17, 0));
  }
  _rtc->writeSqwPinMode(DS3231_SquareWave1Hz); // Tell RTC to output a 1hz pulse from it's output so we can use it to update the time ever second
}

int BenderTime::getTime() {
  // Get the time
  DateTime now = _rtc->now();
  int hours = now.hour();
  int minutes = now.minute();
  int time = hours*100 + minutes;

  // Serial.printf("%d:%d",hours,minutes);
  // Serial.print(time);
  // TODO: add 12/24 hr check here
  // convert 24hr rtc to 12hr time
  if (hours > 12) {
  time -= 1200;
  }

  // Convert Midnight to 1200
  if (hours == 0) {
    time += 1200;
  }

  return time;
}

int BenderTime::getSeconds() {
  DateTime now = _rtc->now();
  return now.secondstime();
}

int BenderTime::getTemp() {
   return _rtc->getTemperature();
}

void BenderTime::setTime(int year, int month, int day, int hour, int min, int sec) {  
    _rtc->adjust(DateTime(year, month, day, hour, min, sec));
}