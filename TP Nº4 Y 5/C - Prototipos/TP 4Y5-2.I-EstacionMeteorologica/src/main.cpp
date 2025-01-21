#include "Arduino.h"
#include "Wire.h"
#include "BMP280Sensor.h"
#include "SPI.h"
#include "DHT.h"

// --------------------- Configuración de Pines ---------------------

#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT11    // DHT 22  (AM2302)
// --------------------- Inicialización de Sensores y Periféricos ---------------------
DHT dht(DHTPIN, DHTTYPE);
BMP280Sensor bmp280;


// --------------------- Configuración Inicial ---------------------
void setup() {
    Serial.begin(9600);
    while (!Serial);
    Wire.begin();
    dht.begin();
    bmp280.begin();
    
}

// --------------------- Bucle Principal ---------------------
void loop() {
	delay(2000);
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    // Lectura de Sensores
    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Error al leer los datos del sensor DHT22");
        }
    else {
            Serial.print("Humedad: ");
            Serial.print(humidity);
            Serial.print(" %, Temperatura: ");
            Serial.print(temperature);
            Serial.println(" °C");
       }
    float bmpTemp, bmpPressure;
    bmp280.readData(bmpTemp, bmpPressure);
    
    Serial.print("Presion: ");
    Serial.println(bmpPressure);
    Serial.println("---.---.---.---");
    delay(1000); // Esperar 1 segundo antes de la siguiente lectura
}
