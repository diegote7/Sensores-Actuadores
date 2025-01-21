#ifndef SENSOR_HCSR04_H
#define SENSOR_HCSR04_H

#include <Arduino.h>

class SensorHCSR04 {
  private:
    int pinTrig;  // Pin de Trigg
    int pinEcho;  // Pin de Echo

  public:
    // Constructor que recibe los pines del Trigg y Echo
    SensorHCSR04(int trigPin, int echoPin);

    // Método de inicialización
    void begin();

    // Método para medir la distancia (en cm)
    float medirDistancia();
};

#endif
