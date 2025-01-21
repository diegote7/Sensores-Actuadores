#ifndef SALIDASRELE_H
#define SALIDASRELE_H

#include <Arduino.h>

class SalidasRele{
    private: 
        int bomba; //defino el pin que voy a usar para la entrada del sensor
        int EVZ1; //pin correspondiente a la elctrovalvula de la zona de riego 1
        int EVZ2; //pin correspondiente a la elctrovalvula de la zona de riego 2
        int EVT; //pin correspondiente a la elctrovalvula de entrada del tanque
        int estado [4] = {0,0,0,0}; 
    public:
        //Constructor, recibe el numero de pin 
        SalidasRele(int pin_bomba, int pin_EVZ1, int pin_EVZ2, int pin_EVT);

        //metodo de inicalizacion
        void begin();

        //lectura de la humedad del suelo
        void ActualizarSalidas(int * act_reles);

        //devuelve estado de las salidas
        void EstadoSalidas(int * inf_salidas);
};

#endif
