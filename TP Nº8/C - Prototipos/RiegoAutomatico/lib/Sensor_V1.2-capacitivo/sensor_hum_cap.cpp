#include "sensor_hum_cap.h"

// Constructor que inicializa el pin del sensor
SensorHumedad::SensorHumedad(int analogPin) {
  pin = analogPin;
}

// Método begin: no se requiere configuración especial, pero lo incluimos por consistencia
void SensorHumedad::begin() {
  // No se requiere configuración especial para pines analógicos
}

// Método para leer la humedad del suelo y convertirla en un porcentaje
float SensorHumedad::leerHumedad() {
  int valorLectura = analogRead(pin);  // Leer el valor analógico
  // Convertir el valor analógico a un porcentaje de humedad (0 - 100%)
  float porcentajeHumedad = map(valorLectura, 0, 1024/*4095*/, 0, 100);
  return porcentajeHumedad;
}
