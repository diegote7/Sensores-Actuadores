#include "sensor_hcsr04.h"

SensorHCSR04::SensorHCSR04(int trigPin, int echoPin) {
  pinTrig = trigPin;
  pinEcho = echoPin;
}

void SensorHCSR04::begin() {
  pinMode(pinTrig, OUTPUT);  // Configuramos el Trigg como salida
  pinMode(pinEcho, INPUT);   // Configuramos el Echo como entrada
}

float SensorHCSR04::medirDistancia() {
  // Enviamos un pulso de 10 us al pin Trigg
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  // Calculamos el tiempo que tarda el pulso en regresar
  long duracion = pulseIn(pinEcho, HIGH);

  // Convertimos el tiempo en distancia (en cm)
  float distancia = duracion * 0.034 / 2;

  return distancia;
}
