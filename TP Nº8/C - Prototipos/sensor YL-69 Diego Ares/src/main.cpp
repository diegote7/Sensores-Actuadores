#include <Arduino.h>
#include "sensor_humedad.h"  // Incluir el archivo de encabezado del sensor

// Definir el pin analógico donde está conectado el sensor YL-69
#define PIN_SENSOR_HUMEDAD 34

// Crear una instancia del sensor
Sensor_YL69 sensorHumedad(PIN_SENSOR_HUMEDAD);

// Definición de variables para el timer y la bomba de agua
unsigned long tiempoTarea1 = 0;
const unsigned long intervaloTarea1 = 1000; 
int sensorYL69 = 0;
int tiempoS = 0;
int tiempoB = 0;
int validar = 0;

// Pantalla OLED
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

String infoYL69 = ""; // Variable que se muestra en la pantalla

#define SCREEN_WIDTH 128 // Ancho de la pantalla
#define SCREEN_HEIGHT 64 // Alto de la pantalla
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
    // Configuración del sensor de humedad
    Serial.begin(115200);
    sensorHumedad.begin();
    
    // Configuración de pines
    pinMode(14, OUTPUT); // Bomba de agua (rele)
    pinMode(26, INPUT);  // Sensor YL-69

    // Inicialización de la pantalla OLED
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 Error de la pantalla"));
        for (;;);
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Mi primera chamba");
    display.display();
    delay(4000);
    display.clearDisplay();
}

void loop() {
    unsigned long tiempoActual = millis();

    // Tarea 1 - Control del sensor y la bomba de agua
    if (tiempoActual - tiempoTarea1 >= intervaloTarea1) {
        sensorYL69 = analogRead(26);
        sensorYL69 = map(sensorYL69, 0, 4095, 0, 100);

        if (sensorYL69 >= 100) {
            Serial.println("fuera de tierra");
            infoYL69 = "fuera de tierra";
            tiempoS = 0;
        } else if (sensorYL69 <= 99 && sensorYL69 >= 80) {
            Serial.println("suelo seco");
            infoYL69 = "suelo seco";
            tiempoS++;
            if (tiempoS >= 10) {
                validar = 1;
            }
        } else if (sensorYL69 >= 70 && sensorYL69 < 80) {
            Serial.println("suelo humedo");
            infoYL69 = "suelo humedo";
            tiempoS = 0;
        } else if (sensorYL69 < 70) {
            Serial.println("mucha agua");
            infoYL69 = "mucha agua";
            tiempoS = 0;
        }

        // Control de la bomba de agua
        if (validar == 1) {
            tiempoB++;
            if (tiempoB <= 5) {
                digitalWrite(14, HIGH);
            } else {
                digitalWrite(14, LOW);
                validar = 0;
                tiempoB = 0;
                tiempoS = 0;
            }
        }

        Serial.println(sensorYL69);
        tiempoTarea1 = tiempoActual;

        // Actualización de la pantalla OLED
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(0, 0);
        display.println(infoYL69);
        display.display();
        delay(4000);
        display.clearDisplay();
    }
}
