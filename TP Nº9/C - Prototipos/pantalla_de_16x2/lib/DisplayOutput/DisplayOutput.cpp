#include "DisplayOutput.h"

// Constructor
DisplayOutput::DisplayOutput(int address, int lcdCols, int lcdRows)
: lcdColumns(lcdCols), lcdRows(lcdRows) {
    lcd = new LiquidCrystal_I2C(address, lcdCols, lcdRows); // Crear el objeto LCD
}

// Inicializar el LCD
void DisplayOutput::init() {
    lcd->begin(lcdColumns, lcdRows);
    lcd->backlight();
}

// Mostrar mensaje en el LCD
void DisplayOutput::printMessage(const String &message) {
    lcd->clear();
    lcd->setCursor(0, 0); // Iniciar desde la primera línea
    lcd->print(message);
}
