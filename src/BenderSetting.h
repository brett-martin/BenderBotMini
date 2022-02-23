/*******************************************************************
    BenderSetting.h
    Brett Martin
    2/21/2022
    
    Class to store persistent user settings and preferences
********************************************************************/

#ifndef BenderSetting_h
#define BenderSetting_h

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "Wprogram.h"
#endif


class BenderSetting {
    
public:

    enum settingName {
        sFirstLoad,
        sBrightness,
        sTime,
        s24Hr,
        sDST,
        sBlink,
        sDemo,
        sFace,
    };

   struct bSetting {
        settingName sName;
        String sPrintName;
        int sAddress;
        int sValue;
    };

    BenderSetting();

    void init();                                                        // Init functions

    void writeIntIntoEEPROM(int address, int number);

    int readIntFromEEPROM(int address);

    BenderSetting::bSetting readSetting(settingName setting);           // Reads settings from EEPROM/SPI flash

    void writeSetting(settingName setting, int value);                  // Saves settings to EEPROM/SPI flash

    void writeInitialSettings();                                        // Writes initial settings if this is the first boot

    void printSetting(settingName setting);                             // Print out the settings to serial

private:

    const struct bSetting benderSettings[8] {
        {sFirstLoad, "FRST", 0, 517},
        {sBrightness, "BRTE", 2, 7},
        {sTime, "TIME", 4, 1234},
        {s24Hr, "24HR", 6, 0},
        {sDST, "DST", 8, 1},
        {sBlink, "BLNK", 10, 1},
        {sDemo, "DEMO", 12, 0},
        {sFace, "FACE", 14, 1}
    };

}; 

#endif