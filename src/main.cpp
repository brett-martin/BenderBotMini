/*******************************************************************
    BenderClockMini.cpp
    Brett Martin
    2/16/2022
    
    Implementation and state logic for Bender clock
    Interupt from RTC fires every 1 second triggering the clock to 
    ask the RTC for the current time and update the display
    Menu button controls the state and +/- buttons control settings in various states
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

BenderSetting::bSetting currentSetting;

/************************************************************
  State Machine methods
************************************************************/
StateMachine machine = StateMachine();

void StateStart();
void StateShowTime();
void StateSettting1();
void StateSettting2();
void StateSettting3();
void StateSettting4();

bool transitionStartShowTime();
bool transitionShowTimeSetting1();
bool transitionSetting1Setting2();
bool transitionSetting2Setting3();
bool transitionSetting3Setting4();
bool transitionSetting4ShowTime();

State* sStart = machine.addState(&StateStart);
State* sShowTime = machine.addState(&StateShowTime);
State* sSetting1 = machine.addState(&StateSettting1);
State* sSetting2 = machine.addState(&StateSettting2);
State* sSetting3 = machine.addState(&StateSettting3);
State* sSetting4 = machine.addState(&StateSettting4);

// Display Settings/config
String daysOfTheWeek[7] = {"Sun", "Mon", "Tue", "Wed", "THu", "FRi", "SAt"};
    
String months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "SeP", "Oct", "Nov", "DEC"};  
    
int daysInMonth[12] = {31,28,31,31,31,31,31,31,31,31,31,31};      

int minBrightness = 1;

int maxBrightness = 15;

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
  sStart->addTransition(&transitionStartShowTime,sShowTime);
  sShowTime->addTransition(&transitionShowTimeSetting1,sSetting1);
  sSetting1->addTransition(&transitionSetting1Setting2,sSetting2);
  sSetting2->addTransition(&transitionSetting2Setting3,sSetting3);
  sSetting3->addTransition(&transitionSetting3Setting4,sSetting4);
  sSetting4->addTransition(&transitionSetting4ShowTime,sShowTime);

  // clock->setBrightness(clock->readSetting(BenderSetting::sBrightness).sValue);
  clock->setBrightness(2);
}

/************************************************************
  Main program Loop
************************************************************/
void loop() {
  machine.run(); // Run the current state continually until we move to a new state etc

  // Blink antenna every second unless we are showing the time, then that state will handle the blink
  if (EDGE == 0 && machine.currentState != sShowTime->index) {
    clock->antennaOn(blinkColon);
    blinkColon = !blinkColon;
    EDGE = 1; 
  }
}

/************************************************************
  State functions
************************************************************/

void StateStart(){
  // Do nothing but go to next state for now.
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

// Brightness setting
void StateSettting1() {
  if(machine.executeOnce){
    clock->showText("ONE");
  }
  // if(machine.executeOnce){
  //   currentSetting = clock->readSetting(BenderSetting::sBrightness);
  //   clock->showText(currentSetting.sPrintName);
  // }

  // if ( clock->buttonPushed(clock->up)) {
  //   if( (currentSetting.sValue + 1) <= maxBrightness ) {
  //     currentSetting.sValue = currentSetting.sValue + 1;
  //     clock->setBrightness(currentSetting.sValue);
  //   }
  // }

  // if ( clock->buttonPushed(clock->down)) {
  //   if( (currentSetting.sValue - 1) >= minBrightness ) {
  //     currentSetting.sValue = currentSetting.sValue - 1;
  //     clock->setBrightness(currentSetting.sValue);
  //   }
  // }
}

// Set DST on/off
void StateSettting2() {
  if(machine.executeOnce){
    clock->showText("T2T2");
  }
}

// Set 24hr on/off
void StateSettting3() {
  if(machine.executeOnce){
    clock->showText("TRE");
  }
}

// Set time
void StateSettting4() {

  if(machine.executeOnce){
    clock->showText("FOUR");
  }
}

// Set Blink on/off

// Set Demo mode on/off

// Set Faces off/15/30/60

// Reset all settings? yes/no

/************************************************************
  State transition conditions
************************************************************/

bool transitionStartShowTime() {
  // Do nothing but go to next state for now.
  return true;
}

bool transitionShowTimeSetting1() {
  if (clock->buttonPushed(clock->menu)) {
    return true;
  }

  return false;
}

bool transitionSetting1Setting2() {
  if (clock->buttonPushed(clock->menu)) {
    // Save settings to memory
    return true;
  }

  return false;
}

bool transitionSetting2Setting3() {
  if (clock->buttonPushed(clock->menu)) {
    // Save settings to memory
    return true;
  }

  return false;
}

bool transitionSetting3Setting4() {
  if (clock->buttonPushed(clock->menu)) {
  // Save settings to memory
    return true;
  }

  return false;
}

bool transitionSetting4ShowTime() {
  if (clock->buttonPushed(clock->menu)) {
    // clock->writeSetting(BenderSetting::sBrightness, currentSetting.sValue);
    return true;
  }

  return false;
}