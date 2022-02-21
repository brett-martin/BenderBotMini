/*******************************************************************
    BenderClockMini.cpp
    Brett Martin
    2/16/2022
    
    Implementation and state logic for Bender clock
    Interupt from RTC fires every 1 second triggering the clock to 
    ask the RTC for the current time and update the display
********************************************************************/
#include <Arduino.h>

#include "BenderClock.h"
#include "StateMachine.h"

/************************************************************
  Clock and interupts
************************************************************/

BenderClock *clock;       // Bender clock Object that will perform all of the clock functions

bool blinkColon = false;  // todo: move this into the clock object

const byte SQWinput = 17; // Arduino pin listining for sqw signal from RTC

volatile int EDGE;        // A variable to store when a falling 1Hz clock edge has occured on the SQW pin of the DS3231.
                          // It's recommended to make a variable volatile if it is to be shared with an Interrupt Service Routine (ISR)

//Interrupt Service Routine - This routine is performed when a falling edge on the 1Hz SQW clock from the RTC is detected
ISR(PCINT1_vect)
{
    EDGE = 0;
}

/************************************************************
  State Machine methods
************************************************************/
StateMachine machine = StateMachine();

void StateInit();
void StateShowTime();
void StateTestBrett();
void StateTestMaryana();
void StateTestLeon();
void StateTestMatilda();
// void StateSetTime();

bool transitionInitShowTime();
// bool transitionShowTimeSetTime();
// bool transitionSetTimeShowTime();
bool transitionShowTimeBrett();
bool transitionBrettMaryana();
bool transitionBrettShowTime();
bool transitionMaryanaLeon();
bool transitionLeonMatilda();
bool transitionMatildaBrett();

State* sInit= machine.addState(&StateInit);
State* sShowTime = machine.addState(&StateShowTime);
// State* sSetTime = machine.addState(&StateSetTime);
State* sBrett = machine.addState(&StateTestBrett);
State* sMaryana = machine.addState(&StateTestMaryana);
State* sLeon = machine.addState(&StateTestLeon);
State* sMatilda = machine.addState(&StateTestMatilda);

/************************************************************
  Setup
************************************************************/
void setup() {
  Serial.begin(57600);
  
  pinMode(SQWinput, INPUT_PULLUP);
  
  PCMSK1 |= bit (PCINT11); // want pin 17/adc3 // This is a bitmask for pin 17...
  PCIFR |= bit (PCIF2); // clear any outstanding interrupts
  PCICR |= bit (PCIE1); // enable pin change interrupts for D8 to D13
  
  attachInterrupt(digitalPinToInterrupt(SQWinput), PCINT11, FALLING);

  EDGE = 1; //Initialize EDGE equal to 1. The Interrupt Service Routine will make EDGE equal to zero when triggered by a falling clock edge on SQW

  clock = new BenderClock(0x70,15,14,16,13);     // Setup clock with display address and button pins
                                                  // Add all transitions to each state
  sInit->addTransition(&transitionInitShowTime,sShowTime);
  // sShowTime->addTransition(&transitionShowTimeSetTime,sSetTime);
  // sSetTime->addTransition(&transitionSetTimeShowTime,sShowTime);
  sShowTime->addTransition(&transitionShowTimeBrett,sBrett);
  sBrett->addTransition(&transitionBrettMaryana,sMaryana);
  sBrett->addTransition(&transitionBrettShowTime,sShowTime);
  sMaryana->addTransition(&transitionMaryanaLeon,sLeon);
  sLeon->addTransition(&transitionLeonMatilda,sMatilda);
  sMatilda->addTransition(&transitionMatildaBrett,sBrett);
}

/************************************************************
  Main program Loop
************************************************************/
void loop() {
  machine.run();
}

/************************************************************
  State functions
************************************************************/

void StateInit(){
  // Do nothing but go to next state for now.
  //clock->setTime(2022, 2, 20, 15, 20, 0);
}

// Show the time on the clock and update it once per second, respecting the blinking colon
void StateShowTime() {
  if (EDGE == 0) {
    clock->showClock(blinkColon);
    clock->antennaOn(blinkColon);
    blinkColon = !blinkColon;
    EDGE = 1; 
  }
}

// Show an alternating message every second to test state
// void StateSetTime() {
//   if (EDGE == 0) {
//     if (blinkColon) {
//       clock->showText("LEON");
//     } else {
//       clock->showText("MRTN");
//     }
//     clock->antennaOn(blinkColon);
//     blinkColon = !blinkColon;
//     EDGE = 1;
//   }
// }

void StateTestBrett() {
  if(machine.executeOnce){
    clock->showText("BRETT");
  }
}
void StateTestMaryana() {
  if(machine.executeOnce){
    clock->showText("MARY");
  }
}
void StateTestLeon() {
  if (EDGE == 0) {
    if (blinkColon) {
      clock->showText("LEON");
    } else {
      clock->showText("MRTN");
    }
    clock->antennaOn(blinkColon);
    blinkColon = !blinkColon;
    EDGE = 1;
  }
}
void StateTestMatilda() {
  if(machine.executeOnce){
    clock->showText("TILY");
  }
}

/************************************************************
  State transition conditions
************************************************************/

bool transitionInitShowTime() {
  // Do nothing but go to next state for now.
  return true;
}

// Check for button input to go to next state
// bool transitionShowTimeSetTime() {

//   if ( clock->buttonPushed(clock->menu)) {
//     Serial.println("Menu Button Pushed!");
//     return true;
//   }

//   return false;
// }

bool transitionSetTimeShowTime() {
  if ( clock->buttonPushed(clock->menu)) {
    return true;
  }

  return false;
}

bool transitionShowTimeBrett() {
  if ( clock->buttonPushed(clock->menu)) {
    return true;
  }

  return false;
}
bool transitionBrettShowTime() {
  if ( clock->buttonPushed(clock->menu)) {
    return true;
  }

  return false;
}
bool transitionBrettMaryana() {
  if ( clock->buttonPushed(clock->up)) {
    return true;
  }

  return false;
}

bool transitionMaryanaLeon() {
  if ( clock->buttonPushed(clock->up)) {
    return true;
  }

  return false;
}
bool transitionLeonMatilda() {
  if ( clock->buttonPushed(clock->up)) {
    return true;
  }

  return false;
}
bool transitionMatildaBrett() {
  if ( clock->buttonPushed(clock->up)) {
    return true;
  }

  return false;
}