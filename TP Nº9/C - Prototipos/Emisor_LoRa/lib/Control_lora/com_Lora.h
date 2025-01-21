// com_lora.h - Archivo de cabecera para la clase com_LoRa, que gestiona la comunicación mediante el módulo LoRa

#ifndef COM_LORA_H  // Guardas del preprocesador para evitar inclusiones múltiples del mismo archivo
#define COM_LORA_H

#include <SPI.h>    // Librería para la comunicación SPI, que utiliza LoRa
#include <LoRa.h>   // Librería específica para el manejo del módulo LoRa

// Declaración de la clase com_LoRa para manejar la comunicación con un módulo LoRa
class com_LoRa {
private:
    long frequency;  // Frecuencia a la que operará el módulo LoRa (en Hz)
    
public:
    // Constructor: Inicializa un objeto com_LoRa con una frecuencia específica
    com_LoRa(long freq);

    // Función para inicializar el módulo LoRa
    void init();

    // Función para enviar un mensaje a través de LoRa
    // Parámetro: msg (String) - El mensaje a enviar
    void sendMessage(String msg);

    // Función para recibir un mensaje a través de LoRa
    // Retorna: El mensaje recibido como String
    String receiveMessage();
};

#endif  // Fin del guardado por definición
