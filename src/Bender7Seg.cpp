/*******************************************************************
    Bender7Seg.cpp
    Brett Martin
    2/16/2022
    
    This class handles displaying images and animations on 4x 
    7 segment LED display
********************************************************************/

#include "Bender7Seg.h"

#ifndef _BV
#define _BV(bit) (1 << (bit)) ///< Bit-value if not defined by Arduino
#endif

#ifndef _swap_int16_t
#define _swap_int16_t(a, b)                                                    \
  {                                                                            \
    int16_t t = a;                                                             \
    a = b;                                                                     \
    b = t;                                                                     \
  } ///< 16-bit var swap
#endif


Bender7Seg::Bender7Seg(byte address, uint8_t brightness) {
  _brightness = brightness;
  display.begin(address);
  init();
}

void Bender7Seg::init() {
  display.setBrightness(_brightness);
}

void Bender7Seg::setBrightness(uint8_t value) { // 0-15
  display.setBrightness(value);
}

void Bender7Seg::writeDisplay() {
  display.writeDisplay();
}

void Bender7Seg::clear() {
  display.clear();
}

// void Bender7Seg::showExpression(ExpressionNames name) {
//     colonOn(false);
//     clear();
//     _segments[0]->drawBitmap(0, 0, Expressions[name][0], 8, 16, LED_ON);
//     _segments[1]->drawBitmap(0, 0, Expressions[name][1], 8, 16, LED_ON);
//     _segments[2]->drawBitmap(0, 0, Expressions[name][2], 8, 16, LED_ON);
//     _segments[3]->drawBitmap(0, 0, Expressions[name][3], 8, 16, LED_ON);
  
//     writeDisplay();
// }

void Bender7Seg::showNumber(int number, int segment) {
//  _segments[segment]->drawBitmap(0, 0, Numbers[number], 8, 16, LED_ON);
}

void Bender7Seg::showTime(int time, bool colon) {
  display.print(time, DEC);
  display.drawColon(colon);
  display.writeDisplay();
}

void Bender7Seg::showText(const String text) {
  display.println(text);
  display.drawColon(false);
  display.writeDisplay();
}

void Bender7Seg::colonOn(bool state) {
  _blinkColon = state;
  display.drawColon(state);
  // display.writeDisplay();
}


