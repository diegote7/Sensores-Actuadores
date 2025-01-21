#include "sensor_YL69.h"

//Constructor para inicializar el pin de entrada
Sensor_YL69::Sensor_YL69(int pin_yl69){
    pin = pin_yl69;
}
// Implementación de la función para inicializar el sensor
void Sensor_YL69::begin() {
    //no se requiere configuracion adicional de pines
}

// Implementación de la función para leer el valor de humedad
float Sensor_YL69::leerHumedad() {
  int valorLectura = analogRead(pin);  // Leer el valor analógico
  // Convertir el valor analógico a un porcentaje de humedad (0 - 100%)
  float porcentajeHumedad = map(valorLectura, 0, 1024/*4095*/, 0, 100);
  return porcentajeHumedad;
}
