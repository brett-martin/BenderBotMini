/*******************************************************************
    Button.h
    Brett Martin
    7/1/2020
    
    Simple class to handle button input with debounce support
********************************************************************/

#ifndef Button_h
#define Button_h

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "Wprogram.h"
#endif


class Button {

private:

    byte _pin;                              // Pin # for button
    
    byte _state;                            // Current button state

    byte _pressedOnce = false;              // Counter for was button pushed once
    
    byte _lastState;                        // Previous state for debounce
    
    unsigned long _lastDebounceTime = 0;    // Debounce time counter
    
    unsigned long _debounceDelay = 50;      // Debounce delay

public:

    Button(byte pin);   // Setup with button pin number

    void init();        // Init functions
    
    void update();      // Get current state of button
    
    byte getState();    // True if button is currently being pushed
    
    bool isPressed();   // True while button is being held/pushed

    bool wasPressed();  // True only 1 time when button is pushed
}; 

#endif