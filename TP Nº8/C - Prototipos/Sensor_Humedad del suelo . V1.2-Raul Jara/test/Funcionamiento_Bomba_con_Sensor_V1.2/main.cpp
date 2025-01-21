#include <Arduino.h>
#include "sensor_humedad.h"
#include "bomba_riego.h"

// Crear una instancia del sensor de humedad en el pin GPIO 34
SensorHumedad sensorSuelo(34);

// Crear una instancia de la bomba/electroválvula controlada por el relé en el pin GPIO 25
BombaRiego bombaRiego(25);

// Umbral de humedad para activar o desactivar el riego
const float umbralHumedad = 40.0;

void setup() {
  Serial.begin(115200);  // Inicializamos la comunicación serie
  sensorSuelo.begin();   // Inicializamos el sensor de humedad
  bombaRiego.begin();    // Inicializamos la bomba/electroválvula
}

void loop() {
  // Leer el porcentaje de humedad del suelo
  float humedad = sensorSuelo.leerHumedad();

  // Mostrar el valor de humedad en el monitor serie
  Serial.print("Humedad del suelo: ");
  Serial.print(humedad);
  Serial.println("%");

  // Lógica para encender o apagar la bomba según la humedad
  if (humedad < umbralHumedad) {
    Serial.println("Humedad baja, activando riego...");
    bombaRiego.encender();
  } else {
    Serial.println("Humedad suficiente, desactivando riego...");
    bombaRiego.apagar();
  }

  delay(1000);  // Pausa de 1 segundo entre lecturas
}
