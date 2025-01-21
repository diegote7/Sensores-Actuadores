#ifndef SENSOR_YL83_H
#define SENSOR_YL83_H

#include <Arduino.h>

class SensorYL83 {
  private:
    int pin;  // Pin digital donde está conectado el sensor

  public:
    // Constructor que recibe el pin donde está conectado el sensor
    SensorYL83(int digitalPin);

    // Método de inicialización (aunque no requiere configuración especial)
    void begin();

    // Método para detectar lluvia (retorna true si está lloviendo)
    bool detectarLluvia();
};

#endif
