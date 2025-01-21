#include "com_LoRa.h"

com_LoRa::com_LoRa(long freq) : frequency(freq) {}

void com_LoRa::init() {
    LoRa.setPins(10, 9, 2);  // NSS, Reset, DIO0
    if (!LoRa.begin(frequency)) {
        Serial.println("Error al inicializar LoRa.");
        while (1);
    }
    Serial.println("LoRa inicializado.");
}

void com_LoRa::sendMessage(String msg) {
    LoRa.beginPacket();
    LoRa.print(msg);
    LoRa.endPacket();
    Serial.println("Mensaje enviado: " + msg);
}

String com_LoRa::receiveMessage() {
    String message = "";
    int packetSize = LoRa.parsePacket();
    if (packetSize) {
        while (LoRa.available()) {
            message += (char)LoRa.read();
        }
        Serial.println("Mensaje recibido: " + message);
    }
    return message;
}
