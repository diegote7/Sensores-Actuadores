#include <Arduino.h>
#include "sensor_yl83.h"  // Incluimos el archivo de cabecera del sensor

SensorYL83 rainSensor(12);  // Instanciamos un objeto del sensor en el pin GPIO 12

void setup() {
  Serial.begin(115200);  // Inicializamos la comunicación serie
  rainSensor.begin();    // Inicializamos el sensor (configura el pin)
}

void loop() {
  // Detectar si está lloviendo
  bool estaLloviendo = rainSensor.detectarLluvia();

  if (estaLloviendo) {
    Serial.println("Está lloviendo");
  } else {
    Serial.println("No está lloviendo");
  }

  delay(1000);  // Pausa de 1 segundo
}
