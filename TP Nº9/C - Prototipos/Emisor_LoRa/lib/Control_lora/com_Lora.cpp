#include "com_LoRa.h"

// Constructor de la clase com_LoRa
// Asigna el valor de la frecuencia pasada como argumento al atributo 'frequency'
com_LoRa::com_LoRa(long freq) : frequency(freq) {}

// Método para inicializar el módulo LoRa
void com_LoRa::init() {
    // Configuración de los pines necesarios para la comunicación con el módulo LoRa
    // NSS (Chip Select), Reset, DIO0 (Data In/Out)
    LoRa.setPins(10, 9, 2);  
    
    // Iniciar el módulo LoRa con la frecuencia especificada
    // Si la inicialización falla, muestra un mensaje de error y detiene el programa
    if (!LoRa.begin(frequency)) {
        Serial.println("Error al inicializar LoRa.");
        while (1);  // Bucle infinito para detener la ejecución en caso de error
    }
    
    // Si la inicialización es exitosa, imprime un mensaje en el monitor serie
    Serial.println("LoRa inicializado.");
}

// Método para enviar un mensaje a través de LoRa
void com_LoRa::sendMessage(String msg) {
    LoRa.beginPacket();  // Comenzar un nuevo paquete LoRa
    LoRa.print(msg);     // Escribir el mensaje en el paquete
    LoRa.endPacket();    // Finalizar el paquete y enviarlo
    Serial.println("Mensaje enviado: " + msg);  // Mostrar el mensaje enviado en el monitor serie
}

// Método para recibir un mensaje a través de LoRa
String com_LoRa::receiveMessage() {
    String message = "";  // Variable para almacenar el mensaje recibido
    int packetSize = LoRa.parsePacket();  // Verificar si hay un paquete recibido
    
    // Si se ha recibido un paquete, leer el mensaje byte por byte
    if (packetSize) {
        while (LoRa.available()) {
            message += (char)LoRa.read();  // Leer y concatenar los caracteres del mensaje
        }
        Serial.println("Mensaje recibido: " + message);  // Mostrar el mensaje recibido en el monitor serie
    }
    return message;  // Devolver el mensaje recibido
}
