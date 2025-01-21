#include "sensor_yl83.h"

// Constructor que inicializa el pin del sensor
SensorYL83::SensorYL83(int digitalPin) {
  pin = digitalPin;
}

// Método begin: configura el pin como entrada
void SensorYL83::begin() {
  pinMode(pin, INPUT);
}

// Método para detectar si está lloviendo
bool SensorYL83::detectarLluvia() {
  // Leer el valor digital del sensor (HIGH = no lluvia, LOW = lluvia)
  return digitalRead(pin) == LOW;  // LOW indica que está lloviendo
}
