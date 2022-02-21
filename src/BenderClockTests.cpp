/*******************************************************************
    BenderClockTests.cpp
    Brett Martin
    7/1/2020
    
    Wrapping class for bender clock tests
    BenderClockTests class.
********************************************************************/

#include "BenderClockTests.h"


BenderClockTests::BenderClockTests() {
    init();
}

void BenderClockTests::init() {
    // _antenna = new Led(9);
    // _buttonRed = new Button(15); 
    // _buttonYellow = new Button(16); 
    // _buttonGreen = new Button(17); 
    // _buttonBlue = new Button(18); 
    // _clock = new BenderTime();
    // _display = new BenderDisplay(4,7); //# segments, brightness etc pass in
    // _mouth = new BenderSound();
}

// bool SimpleRTCTests::buttonPushed(int b) {
//     switch (b)
//     {
//     case 1:
//         return _buttonRed->wasPressed();
//         break;
//     case 2:
//         return _buttonYellow->wasPressed();
//         break;
//     case 3:
//         return _buttonGreen->wasPressed();
//         break;
//     case 4:
//         return _buttonBlue->wasPressed();
//         break;
    
//     default:
//         break;
//     }
//     return false;
// }

// Blinks the LED x number of times
// void BlinkLED(int blinkTimes)
// {
//     for( int i = 0; i < blinkTimes; i++) {
//         delay(200);
//         digitalWrite(led, HIGH);
//         delay(200);
//         digitalWrite(led, LOW);
//   }
// }

// // Listen to buttons and blink LED to indicate button press
// void ButtonTest() {
  
//   bStateOne = digitalRead(buttonOne);
//   bStateTwo = digitalRead(buttonTwo);
//   bStateThree = digitalRead(buttonThree);
  
//   if (bStateOne == LOW) {
//     BlinkLED(1);
//   }

//   if (bStateTwo == LOW) {
//     BlinkLED(2);
//   }

//   if (bStateThree == LOW) {
//     BlinkLED(3);
//   }
// }

// void LCDCountDown() {
//   int start = 1234;

//   clockDisplay.print(1234, DEC);
//   clockDisplay.writeDisplay();

//   for( int i = 0; i < start; i++) {
//     clockDisplay.print(start - i, DEC);
//     clockDisplay.writeDisplay();
//     delay(10);
//   }
//     clockDisplay.clear();
//     clockDisplay.writeDisplay();
//   delay(1000);
// }

// void LCDScroll() {
//   clockDisplay.print(1, DEC);
//   clockDisplay.writeDisplay();
//   delay(1000);
//   clockDisplay.print(12, DEC);
//   clockDisplay.writeDisplay();
//   delay(1000);
//   clockDisplay.print(123, DEC);
//   clockDisplay.writeDisplay();
//   delay(1000);
//   clockDisplay.print(1234, DEC);
//   clockDisplay.writeDisplay();
//   delay(1000);
// }

// // Brightness test
// void BrightnessTest() {
//   for( int i=0; i<16; i++) {
//     clockDisplay.setBrightness(i);
//     clockDisplay.print(i);
//     clockDisplay.writeDigitAscii(0, '0');
//     clockDisplay.writeDigitAscii(1, '0');
//     clockDisplay.writeDisplay();
//     delay(500);
//   }
// }

// // LCD special charas test
// void LCDSpecialTest() {
//     blinkColon = !blinkColon;
//     clockDisplay.drawColon(blinkColon);
//     clockDisplay.writeDisplay();
//     delay(1000);
//     uint8_t c='A';
//     clockDisplay.writeDigitAscii(0,c,true);
// }

// // LCD ASCII test
// void LCDASCIITest() {
//   for (uint8_t i='A'; i<='Z'; i++) {
//     clockDisplay.writeDigitAscii(4, i);
//     clockDisplay.writeDisplay();
//     delay(300);
//   }
// }

// void LCDAnimation() {
//   clockDisplay.writeDigitRaw(0, 0x1); // 1
//   clockDisplay.writeDigitRaw(1, 0x1); // 1
//   clockDisplay.writeDigitRaw(3, 0x1); // 1
//   clockDisplay.writeDigitRaw(4, 0x1); // 1
//   clockDisplay.writeDisplay();
//   delay(100);

//   clockDisplay.writeDigitRaw(0, 0x2); // 2
//   clockDisplay.writeDigitRaw(1, 0x2); // 1
//   clockDisplay.writeDigitRaw(3, 0x2); // 1
//   clockDisplay.writeDigitRaw(4, 0x2); // 1
//   clockDisplay.writeDisplay();
//   delay(300);

//   clockDisplay.writeDigitRaw(0, 0x4); // 3
//   clockDisplay.writeDigitRaw(1, 0x4); // 1
//   clockDisplay.writeDigitRaw(3, 0x4); // 1
//   clockDisplay.writeDigitRaw(4, 0x4); // 1
//   clockDisplay.writeDisplay();
//   delay(300);

//   clockDisplay.writeDigitRaw(0, 0x8); // 4
//   clockDisplay.writeDigitRaw(1, 0x8); // 1
//   clockDisplay.writeDigitRaw(3, 0x8); // 1
//   clockDisplay.writeDigitRaw(4, 0x8); // 1
//   clockDisplay.writeDisplay();
//   delay(300);

//   clockDisplay.writeDigitRaw(0, 0x10); // 5
//   clockDisplay.writeDigitRaw(1, 0x10); // 1
//   clockDisplay.writeDigitRaw(3, 0x10); // 1
//   clockDisplay.writeDigitRaw(4, 0x10); // 1
//   clockDisplay.writeDisplay();
//   delay(300);

//   clockDisplay.writeDigitRaw(0, 0x20); // 6
//   clockDisplay.writeDigitRaw(1, 0x20); // 1
//   clockDisplay.writeDigitRaw(3, 0x20); // 1
//   clockDisplay.writeDigitRaw(4, 0x20); // 1
//   clockDisplay.writeDisplay();
//   delay(300);
// }

// void LCDEyes() {
//   clockDisplay.writeDigitRaw(0, 0x39);
//   clockDisplay.writeDigitRaw(1, 0xF);
//   clockDisplay.writeDigitRaw(3, 0x39);
//   clockDisplay.writeDigitRaw(4, 0xF);
//   clockDisplay.writeDisplay();
//   delay(2000);
  
//   clockDisplay.writeDigitRaw(0, 0x40);
//   clockDisplay.writeDigitRaw(1, 0x40);
//   clockDisplay.writeDigitRaw(3, 0x40);
//   clockDisplay.writeDigitRaw(4, 0x40);
//   clockDisplay.writeDisplay();
//   delay(400);
// }

// // Show all segments of the LED, count or blink or something useful
// void LCDTest() {
//   LCDScroll();
//   LCDCountDown();
//   LCDSpecialTest();
//   LCDASCIITest();
//   LCDAnimation();
//   LCDEyes();
// }

// void RTCPrintTime() {
//   DateTime now = rtc.now();
//   Serial.print(now.year(), DEC);
//   Serial.print('/');
//   Serial.print(now.month(), DEC);
//   Serial.print('/');
//   Serial.print(now.day(), DEC);
//   Serial.print(" (");
//   Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
//   Serial.print(") ");
//   Serial.print(now.hour(), DEC);
//   Serial.print(':');
//   Serial.print(now.minute(), DEC);
//   Serial.print(':');
//   Serial.print(now.second(), DEC);
//   Serial.println();
//   delay(1000);
// }

// manually set rtc time
// void RTCSetTime(int year, int month, int day, int hour, int min, int sec) {  
//     rtc.adjust(DateTime(year, month, day, hour, min, sec));
//     Serial.print("Time has been set!");
//     RTCPrintTime();
// }

// Prints the current time to the LCD as a time
// void LCDPrintTime() {
//   DateTime now = rtc.now();

//   hours = now.hour();
//   minutes = now.minute();
//     // Show the time on the display by turning it into a numeric
//   // value, like 3:30 turns into 330, by multiplying the hour by
//   // 100 and then adding the minutes.
//   int displayValue = hours*100 + minutes;
//   // Handle hour 0 (midnight) being shown as 12.
//   if (hours == 0) {
//     displayValue += 1200;
//   }

//   clockDisplay.print(displayValue, DEC);
//   blinkColon = !blinkColon;
//   clockDisplay.drawColon(blinkColon);
//   clockDisplay.writeDisplay();
//   delay(1000);
// }

// void loop() {
  // clockDisplay.setBrightness(5);
  // Run each of the following groups of tests individually

  // Use this to set the time as needed
  // if (!doOnce) {
  //   RTCSetTime(2022, 11, 20, 10, 41, 0);
  //   doOnce = true;
  // }

  // ButtonTest();

  // RTCPrintTime();

  // LCDPrintTime();

  // LCDTest();

  // BrightnessTest();
// }

