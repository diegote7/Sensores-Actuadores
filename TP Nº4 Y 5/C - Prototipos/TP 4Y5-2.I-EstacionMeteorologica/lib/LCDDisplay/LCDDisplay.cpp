#include "LCDDisplay.h"

LCDDisplay::LCDDisplay() : lcd(0x27, 20, 2) {}

void LCDDisplay::begin() {
    lcd.begin(20, 2, 0);
    lcd.backlight();
}

void LCDDisplay::displayMenu() {
    lcd.clear();
    lcd.print("Temp/Hum/Pres: ");
    }

void LCDDisplay::updateInfo(float temp, float humidity, float pressure) {
    lcd.setCursor(0, 1);
    lcd.print("T: ");
    lcd.print(temp);
    lcd.print(" H: ");
    lcd.print(humidity);
    lcd.print(" P: ");
    lcd.print(pressure);
    
    }
