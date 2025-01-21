#ifndef LCDDISPLAY_H
#define LCDDISPLAY_H

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class LCDDisplay {
private:
    LiquidCrystal_I2C lcd;

public:
    LCDDisplay();
    void begin();
    void displayMenu();
    void updateInfo(float temp, float humidity, float pressure);
};

#endif
