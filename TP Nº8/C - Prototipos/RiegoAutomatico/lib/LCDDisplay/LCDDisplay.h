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
    void displayMenu(int menu);
    void updateMenu(int menu, float Humedad_CAP, float Humedad_YL69, bool Lluvia_YL83, float nivel_tanque, int bomba, int EVZ1, int EVZ2, int EVT);
};

#endif
