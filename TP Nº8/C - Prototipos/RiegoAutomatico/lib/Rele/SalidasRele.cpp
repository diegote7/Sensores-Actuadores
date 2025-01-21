#include "SalidasRele.h"

//Constructor
SalidasRele::SalidasRele(int pin_bomba, int pin_EVZ1, int pin_EVZ2, int pin_EVT){
    bomba = pin_bomba;
    EVZ1 = pin_EVZ1;
    EVZ2 = pin_EVZ2;
    EVT = pin_EVT;
    }

//inicializador
void SalidasRele::begin(){
    //nada para inicializar, se hace en el main
}

//metodo para actualizar las salidas
void SalidasRele::ActualizarSalidas(int * act_reles){
    for (int i = 0; i < 4; i++){
        if (estado[i] != act_reles[i]){
            estado[i] = act_reles[i];
        }
    }
    digitalWrite(bomba, estado[0]);
    digitalWrite(EVZ1, estado[1]);
    digitalWrite(EVZ2, estado[2]);
    digitalWrite(EVT, estado[3]);
}

//metodo que devuelve el estado de las salidas para mostrar por el display LCD
void SalidasRele::EstadoSalidas(int * inf_salidas){
    for (int i = 0; i < 4; i++){
            inf_salidas[i] = estado[i];
        }
}