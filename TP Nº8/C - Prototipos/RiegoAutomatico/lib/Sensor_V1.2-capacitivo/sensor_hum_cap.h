#ifndef SENSOR_HUM_CAP_H
#define SENSOR_HUM_CAP_H

#include <Arduino.h>

class SensorHumedad {
  private:
    int pin;  // Pin analógico donde está conectado el sensor

  public:
    // Constructor que recibe el pin donde está conectado el sensor
    SensorHumedad(int analogPin);

    // Método de inicialización
    void begin();

    // Método para leer la humedad del suelo (retorna un valor en porcentaje)
    float leerHumedad();
};

#endif
