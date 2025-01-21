#ifndef COM_LORA_H
#define COM_LORA_H

#include <SPI.h>
#include <LoRa.h>

class com_LoRa {
private:
    long frequency;  // Frecuencia del módulo LoRa
public:
    com_LoRa(long freq);
    void init();              // Inicializar LoRa
    void sendMessage(String msg);  // Enviar mensaje
    String receiveMessage();  // Recibir mensaje
};

#endif
