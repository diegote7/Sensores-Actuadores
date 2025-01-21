#include <Arduino.h>
#include "sensor_humedad.h"   // Incluir la cabecera del sensor de humedad del suelo

// Crear una instancia del sensor de humedad en el pin GPIO 34 (pin analógico)
SensorHumedad sensorSuelo(34);

void setup() {
  Serial.begin(115200);  // Inicializamos la comunicación serie
  sensorSuelo.begin();   // Inicializamos el sensor
}

void loop() {
  // Leer el porcentaje de humedad del suelo
  float humedad = sensorSuelo.leerHumedad();

  // Mostrar el valor de humedad en el monitor serie
  Serial.print("Humedad del suelo: ");
  Serial.print(humedad);
  Serial.println("%");

  // Esperar 1 segundo antes de la siguiente lectura
  delay(1000);
}
