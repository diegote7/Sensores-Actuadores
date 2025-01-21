#include <Arduino.h>
#include "DisplayOutput.h"

// Dirección I2C de la pantalla LCD
#define LCD_ADDRESS 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// Crear un objeto de la clase DisplayOutput
DisplayOutput display(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void setup() {
    // Inicializar la comunicación serial
    Serial.begin(115200);
    // Inicializar el display
    display.init();
    // Mostrar mensaje en la LCD
    display.printMessage("Grupo Nro 1");
}

void loop() {
    // Enviar el mismo mensaje por el Monitor Serial
    Serial.println("Grupo Nro 1");
    delay(2000); // Esperar 2 segundos
}
