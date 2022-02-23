/*******************************************************************
    BenderSetting.cpp
    Brett Martin
    2/21/2022
    
    Class to store persistent user settings and preferences
********************************************************************/

#include "BenderSetting.h"
#include "EEPROM.h"

BenderSetting::BenderSetting() {
    init();
}
    
void BenderSetting::init() {
    // writeInitialSettings();
}

int BenderSetting::readIntFromEEPROM(int address)
{
  return (EEPROM.read(address) << 8) + EEPROM.read(address + 1);
}

void BenderSetting::writeIntIntoEEPROM(int address, int number)
{ 
  EEPROM.write(address, number >> 8);
  EEPROM.write(address + 1, number & 0xFF);
}

BenderSetting::bSetting BenderSetting::readSetting(settingName setting) {

    // for(uint8_t i = 0; i < sizeof(benderSettings)/sizeof(bSetting); ++i) {
    //     if ( benderSettings[i].sName == setting) {

    //         int readValue = readIntFromEEPROM(benderSettings[i].sAddress);
    //         Serial.println("Read Setting Val>");
    //         Serial.println(readValue);

    //         bSetting currentSetting = benderSettings[i];
    //         currentSetting.sValue = readValue;

    //         return currentSetting;
    //     }
    // }
    Serial.println("Setting Not found!!");
    return BenderSetting::bSetting();
}

void BenderSetting::writeSetting(settingName setting, int value) {
    bSetting currentSetting = readSetting(setting);

    if (currentSetting.sValue != value) {
        writeIntIntoEEPROM(currentSetting.sAddress, value);
    }
}

void BenderSetting::writeInitialSettings() {
    int firstBoot = readIntFromEEPROM(benderSettings[0].sAddress);
    Serial.println("First Boot? " + readIntFromEEPROM(benderSettings[0].sAddress));
    if (firstBoot != 517) {
        Serial.println("Writing initial settings to EEPROM");
        for(uint8_t i = 0; i < sizeof(benderSettings)/sizeof(bSetting); ++i) {
            writeSetting(benderSettings[i].sName, benderSettings[i].sValue);
            printSetting(benderSettings[i].sName);
        }
    }
    Serial.println("First Boot??? Read 517? >");
    Serial.println(readIntFromEEPROM(benderSettings[0].sAddress));
    Serial.println("</FirstBoot>");
}
    

void BenderSetting::printSetting(settingName setting) {
    // Print out everything that is stored in our dictionary
    Serial.println("Printing Settings");
    bSetting thisSetting = readSetting(setting);
    
    Serial.println("> Name");
    Serial.println(thisSetting.sAddress);
    Serial.println("</Name>");
    Serial.println("> Print Name");
    Serial.println(thisSetting.sPrintName);
    Serial.println("</Print Name>");
    Serial.println("> Address ");
    Serial.println(thisSetting.sAddress);
    Serial.println("</Address>");
    Serial.println("> Stored Value");
    Serial.println(readIntFromEEPROM(thisSetting.sAddress));
    Serial.println("</Stored Value>");
}