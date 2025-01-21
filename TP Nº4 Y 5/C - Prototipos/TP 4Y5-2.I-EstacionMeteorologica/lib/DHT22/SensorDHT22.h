#ifndef SENSOR_DHT22_H
#define SENSOR_DHT22_H

#include <DHT.h>

class SensorDHT22 {
public:
    SensorDHT22(int pin);
    void begin();
    float readTemperature();
    float readHumidity();

private:
    DHT dht;
};

#endif
