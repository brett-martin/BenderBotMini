/*******************************************************************
    Led.h
    Brett Martin
    7/1/2020

    Simple class to turn on or off an LED
********************************************************************/

#ifndef Led_h
#define Led_h

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "Wprogram.h"
#endif


class Led {

private:

    byte _pin;              // Pin # on board

    byte _state;            // Track the state of the LED

public:

    Led(byte pin);          // Setup with LED pin

    void init();            // Init
    
    void on();              // Turns LED on

    void on(int onTime);    // Turns LED on for xxxx miliseconds
    
    void off();             // Turns LED off

    byte getState();        // Gets the current state of the LED
};

#endif