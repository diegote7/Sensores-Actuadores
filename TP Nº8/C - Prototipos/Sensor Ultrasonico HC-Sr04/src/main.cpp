#include "sensor_hcsr04.h"

SensorHCSR04 sensorNivel(39, 34);  // Pines configurados: Trigg en GIOP39 (pata 4), Echo en GIOP34 (pata 5)

void setup() {
  Serial.begin(9600);    // Inicializamos comunicación serial
  sensorNivel.begin();   // Inicializamos el sensor HC-SR04
}

void loop() {
  float nivelAgua = sensorNivel.medirDistancia();  // Medimos la distancia

  Serial.print("Nivel de agua: ");
  Serial.print(nivelAgua);
  Serial.println(" cm");  // Mostramos la distancia en cm

  delay(2000);  // Esperamos 2 segundos entre lecturas
}
