#include "bomba_riego.h"

// Constructor que inicializa el pin del relé
BombaRiego::BombaRiego(int pin) {
  pinRelé = pin;
}

// Método begin: configura el pin del relé como salida
void BombaRiego::begin() {
  pinMode(pinRelé, OUTPUT);
  apagar();  // Asegurar que la bomba esté apagada al inicio
}

// Método para encender la bomba/electroválvula
void BombaRiego::encender() {
  digitalWrite(pinRelé, LOW);  // LOW activa el relé (depende del tipo de relé)
}

// Método para apagar la bomba/electroválvula
void BombaRiego::apagar() {
  digitalWrite(pinRelé, HIGH);  // HIGH desactiva el relé
}
