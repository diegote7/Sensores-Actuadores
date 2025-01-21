#include "LCDDisplay.h"


LCDDisplay::LCDDisplay() : lcd(0x3F, 20, 4) {}

void LCDDisplay::begin() {
    lcd.begin(20, 4, 0);
    lcd.backlight();
}

void LCDDisplay::displayMenu(int menu) {
    lcd.clear();
    switch (menu) {
        case 0:
            lcd.clear();
            lcd.print("HUMEDAD DEL SUELO: ");
            break;
        case 1:
            lcd.clear();
            lcd.print("RIEGO: ");
            break;
        case 2:
            lcd.clear();
            lcd.print("Nivel Tanque/E_valv:");
            break;
    }
}

void LCDDisplay::updateMenu(int menu, float Humedad_CAP, float Humedad_YL69, bool Lluvia_YL83, float nivel_tanque, int bomba, int EVZ1, int EVZ2, int EVT){
    lcd.setCursor(0, 1);

    switch (menu) {
        case 0:
            if (Lluvia_YL83 == true){
                lcd.clear();
                lcd.setCursor(6, 0);
                lcd.print("Lluvia");
                lcd.setCursor(0, 1);
                lcd.print("Lectura interrumpida");
            }
            else
            {
                lcd.setCursor(0, 0);
                displayMenu(menu);
                lcd.setCursor(0, 1);
                lcd.print("Z1: ");
                lcd.print(Humedad_CAP);
                lcd.print(" Z2: ");
                lcd.print(Humedad_YL69);
            }
            break;

        case 1:
            if (Lluvia_YL83 == true){
                lcd.clear();
                lcd.setCursor(6, 0);
                lcd.print("Lluvia");
                lcd.setCursor(0, 1);
                lcd.print("Riego interrumpido");
                }
            else{
                lcd.setCursor(0, 0);
                displayMenu(menu);
                lcd.setCursor(0, 1);
                lcd.print("B: ");
                lcd.print(bomba);
                lcd.print(" EVZ1: ");
                lcd.print(EVZ1);
                lcd.print(" EVZ2: ");
                lcd.print(EVZ2);
                }
            break;
            
        case 2:
            //lcd.clear();
            lcd.print("Nivel: ");
            lcd.print(nivel_tanque);
            lcd.print("lts");
            lcd.setCursor(0, 2);
            lcd.print("EV_T: ");
            lcd.print(EVT);
            break;
    }
}