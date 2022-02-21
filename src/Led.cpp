/*******************************************************************
    Led.cpp
    Brett Martin
    7/1/2020
    
    Simple class to turn on or off an LED
********************************************************************/

#include "Led.h"

Led::Led(byte pin) {
    _pin = pin;
    init();
}

void Led::init() {
    pinMode(_pin, OUTPUT);
    off();
}

void Led::on() {
    digitalWrite(_pin, HIGH);
    _state = true;
}

void Led::on(int onTime) {
    on();
    delay(onTime);
    off();
}

void Led::off() {
    digitalWrite(_pin, LOW);
    _state = false;
}

byte Led::getState() {
    return _state;
}
