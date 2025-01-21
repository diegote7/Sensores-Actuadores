#include "SensorDHT22.h"

SensorDHT22::SensorDHT22(int pin) : dht(pin, DHT22) {}

void SensorDHT22::begin() {
    dht.begin();
}

float SensorDHT22::readTemperature() {
    return dht.readTemperature();
}

float SensorDHT22::readHumidity() {
    return dht.readHumidity();
}
