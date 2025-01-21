#ifndef DISPLAY_OUTPUT_H
#define DISPLAY_OUTPUT_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class DisplayOutput {
private:
    LiquidCrystal_I2C *lcd; // Puntero a la pantalla LCD
    int lcdColumns;
    int lcdRows;
    
public:
    // Constructor
    DisplayOutput(int address, int lcdCols, int lcdRows);

    // Inicializar la pantalla
    void init();

    // Mostrar mensaje en el LCD
    void printMessage(const String &message);
};

#endif
