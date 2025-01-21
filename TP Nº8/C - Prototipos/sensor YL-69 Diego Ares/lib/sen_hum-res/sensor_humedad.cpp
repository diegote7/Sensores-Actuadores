#include "sensor_humedad.h"

// contructor para inicializar el pin de entrada
Sensor_YL69::Sensor_YL69(int pin_yl69){
    sensorPin = pin_yl69;
}

// Implementación de la función para inicializar el sensor
void Sensor_YL69::begin(){
// no se requuiere configuracion adicional de pines
}

// Implementación de la función para leer el valor de humedad
float Sensor_YL69::leerHumedad(){
    int valorLectura = analogRead(sensorPin); // leer el valor analogico
    // convertir el valor analogico en un parcentaje de humedad (0 - 100%)
    float porcentajedeHumedad = (float)map(valorLectura, 0, 4095, 0, 100);
    return porcentajedeHumedad;
}

 