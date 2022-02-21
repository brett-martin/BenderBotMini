/*******************************************************************
    BenderClock.cpp
    Brett Martin
    2/16/2020
    
    Wrapping class for all BenderClock functions and classes into a single
    BenderClock class.
********************************************************************/

#include "BenderClock.h"


BenderClock::BenderClock(byte displayAddress, int menuButton, int upButton, int downButton, int antenna) {
    init(displayAddress, menuButton, upButton, downButton, antenna);
}

void BenderClock::init(byte displayAddress, int menuButton, int upButton, int downButton, int antenna) {
    _buttonMenu = new Button(menuButton); 
    _buttonDown = new Button(downButton); 
    _buttonUp = new Button(upButton);  
    _clock = new BenderTime();
    _display = new Bender7Seg(displayAddress,7); 
    _tests = new BenderClockTests();
    _antenna = new Led(antenna);
}

bool BenderClock::buttonPushed(buttons button) {
    switch (button)
    {
    case up:
        return _buttonUp->wasPressed();
        break;
    case menu:
        return _buttonMenu->wasPressed();
        break;
    case down:
        return _buttonDown->wasPressed();
        break;
    
    default:
        break;
    }
    return false;
}

void BenderClock::antennaOn(byte state) {
    if (state)
         _antenna->on();
    else
         _antenna->off();
}

int BenderClock::getTime() {
    return _clock->getTime();
}

void BenderClock::showClock(bool showColon) {
    int time = _clock->getTime();
    _display->showTime(time, showColon);
}

void BenderClock::showText(String text) {
    _display->showText(text);
}

void BenderClock::setTime(int year, int month, int day, int hour, int min, int sec) {  
    _clock->setTime( year, month, day, hour, min, sec );
}
