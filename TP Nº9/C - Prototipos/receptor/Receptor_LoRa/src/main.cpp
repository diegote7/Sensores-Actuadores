#include <Arduino.h>
#include "com_LoRa.h"
#include "lcdDisplay.h"

com_LoRa lora(433E6);
lcdDisplay display;

volatile bool mensajeDisponible = false;

void IRAM_ATTR isrLoRa() {
    mensajeDisponible = true;  // Bandera para recibir mensaje
}

void setup() {
    Serial.begin(9600);
    display.init();
    lora.init();

    // Configura interrupción en DIO0
    attachInterrupt(digitalPinToInterrupt(2), isrLoRa, RISING);

    Serial.println("Receptor listo.");
}

void loop() {
    if (mensajeDisponible) {
        mensajeDisponible = false;  // Reinicia bandera

        // Procesa el mensaje recibido
        String mensaje = lora.receiveMessage();
        if (mensaje != "") {
            Serial.println("Mensaje recibido: " + mensaje);
            display.showMessage(mensaje);  // Mostrar en LCD

            lora.sendMessage("ACK");
            Serial.println("ACK enviado.");
        }
    }
}
