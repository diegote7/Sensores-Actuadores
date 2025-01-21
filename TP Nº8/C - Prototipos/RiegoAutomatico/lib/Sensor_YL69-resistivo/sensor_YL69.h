#ifndef SENSOR_YL69_H
#define SENSOR_YL69_H

#include <Arduino.h>

class Sensor_YL69{
    private: 
        int pin; //defino el pin que voy a usar para la entrada del sensor

    public:
        //Constructor, recibe el numero de pin 
        Sensor_YL69(int pin_yl69);

        //metodo de inicalizacion
        void begin();

        //lectura de la humedad del suelo
        float leerHumedad();
};

#endif
