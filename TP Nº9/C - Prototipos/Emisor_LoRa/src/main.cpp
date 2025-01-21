#include <Arduino.h>
#include "com_LoRa.h"

#define BUTTON_PIN 12  // Pin del botón
#define LED_PIN 13     // Pin del LED

com_LoRa lora(433E6);  // Frecuencia 433 MHz

// Variables de control
volatile bool enviarMensaje = false;
volatile unsigned long ultimoRebote = 0;  // Tiempo del último evento

// ISR con debounce
void IRAM_ATTR isrButton() {
    unsigned long ahora = millis();
    if (ahora - ultimoRebote > 50) {  // Debounce de 50 ms
        enviarMensaje = true;
        ultimoRebote = ahora;
    }
}

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
    lora.init();

    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), isrButton, FALLING);

    Serial.println("Emisor listo.");
}

void loop() {
    if (enviarMensaje) {
        enviarMensaje = false;  // Reinicia bandera

        // Selecciona un mensaje aleatorio
        String mensajes[] = {
            "Prueba exitosa", "Alerta: Baja batería", "Sistema operativo estable",
            "Sensor activo", "Datos recibidos correctamente", "Reiniciar sistema"
        };
        String mensaje = mensajes[random(0, 6)];

        Serial.println("Enviando: " + mensaje);
        lora.sendMessage(mensaje);

        // Esperar ACK con timeout
        unsigned long inicio = millis();
        bool ackRecibido = false;
        while (millis() - inicio < 2000) {
            String ack = lora.receiveMessage();
            if (ack == "ACK") {
                ackRecibido = true;
                break;
            }
        }

        if (ackRecibido) {
            Serial.println("ACK recibido.");
            digitalWrite(LED_PIN, HIGH);
            delay(1000);
            digitalWrite(LED_PIN, LOW);
        } else {
            Serial.println("No se recibió ACK.");
        }
    }
}

