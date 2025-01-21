#ifndef BOMBA_RIEGO_H
#define BOMBA_RIEGO_H

#include <Arduino.h>

class BombaRiego {
  private:
    int pinRelé;   // Pin donde está conectado el relé

  public:
    // Constructor que recibe el pin del relé
    BombaRiego(int pin);

    // Método de inicialización
    void begin();

    // Método para encender la bomba/electroválvula
    void encender();

    // Método para apagar la bomba/electroválvula
    void apagar();
};

#endif
