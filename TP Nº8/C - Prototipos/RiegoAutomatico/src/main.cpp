#include <Arduino.h>
#include <Wire.h>
#include "sensor_hum_cap.h"
#include "sensor_hcsr04.h"
#include "sensor_yl83.h"
#include "sensor_YL69.h"
#include "SalidasRele.h"
#include "LCDDisplay.h"
#include "time.h"

// --------------------- Configuración de Pines para ESP32 mini 30 pines---------------------
#define YL_83 16 // lluvia
#define SHC A1 //sensor de humedad capacitivo
#define SHR A0 // sensor de humedad resistivo
#define TRG 9 // disparo para sensor ultrasonido
#define ECO 8 // Echo sensor ultrasonido
#define puls 2 // pulsador para navegar el LCD
#define EVT 6 // salida rele para electrovalvula entrada tanque
#define EVZ1 4 // salida rele para electrovalvula zona de riego 1
#define EVZ2 5 // salida rele para electrovalvula zona de riego 2
#define BOMBA 3 // salida rele para bomba


// --------------------- Inicialización de Sensores y Periféricos ---------------------
LCDDisplay lcd;
SalidasRele salidas(BOMBA, EVZ1, EVZ2, EVT);
SensorHumedad humcap(SHC);
SensorHCSR04 nivel_tanque(TRG, ECO);
SensorYL83 lluvia(YL_83);
Sensor_YL69 humres(SHR);

 
int menuActual = 0;
const int numMenus = 3;
int sal_status [4] = {0,0,0,0};
int com_salidas [4] = {0,0,0,0};
int bomba, evz1, evz2, evt;
int cambia_menu = 0;
//------------atencion de la interrupcion por pulsador---------
void pulsin() {
  delay(5);
  if (digitalRead(puls) == LOW) {  
    cambia_menu = 1;
  }
}


// --------------------- Configuración Inicial ---------------------
void setup() {
    Serial.begin(9600);
    while (!Serial);
    Wire.begin();
    
    // Inicializar sensores y perifericos
    lcd.begin();
    salidas.begin();
    humcap.begin();
    nivel_tanque.begin();
    lluvia.begin();
    humres.begin();

    lcd.displayMenu(menuActual); // Mostrar el menú inicial
    pinMode(puls, INPUT);
    attachInterrupt(digitalPinToInterrupt(puls), pulsin, FALLING);
    Serial.println("configurado, iniciamos");
}

// --------------------- Lógica del Menú ---------------------
void navegarMenu() {
          if (cambia_menu == 1){  
            if (menuActual < 2)
                menuActual += 1;
            else
                menuActual = 0; 

        lcd.displayMenu(menuActual);
        cambia_menu = 0;
        }
} 
        
// --------------------- Bucle Principal ---------------------
void loop() {
    navegarMenu();
    
    // Lectura de Sensores
    float hz1 = humcap.leerHumedad(); //humedad de la zona de riego 1
    float hz2 = humres.leerHumedad(); //humedad de la zona de riego 2
    int llueve = lluvia.detectarLluvia(); //pruebo si llueve
    // Suponemos un tanque de base circular (tanque cilindrico vertical) de 10000 litros de capacidad
    // con el sensor colocado a 10 cm del nivel superior. Diametro del tanque 4 metros, entonces
    // para 10000 litros la altura lleno es de 7,95dm, y sumamos 1dm correspondiente a la distancia
    // del sensor hasta el punto maximo de reserva. 
    // Asi obtenemos que reserva_agua = (8,95 - (nivel_tanque.medirDistancia() / 10))*(3.1416 * 20 * 20)
    // las medidas se llevan todas a decimetros para conservar la relacion 1 litro = 1 dm3
    // podemos calcular un rango optima del 50% hasta lleno donde la EV_T permanezca cerrada
    // 
    // 
    
    float reserva_agua = (8.95 - (nivel_tanque.medirDistancia() / 10))*(3.1416 * 20 * 20); //mido el nivel del tanque de agua, aca puedo calcular los litro si conozco la dimensiones del tanque.

    //logica de control del sistema
    if(llueve == 0){
        if (hz1 < 30){
          Serial.println("Zona 1 demasiado seca! Se activara riego");
          com_salidas[1] = 1;
        }
        if (hz1 > 70){
          Serial.println("Zona 1 con suficiente humedad! Se corta el riego");
          com_salidas[1] = 0;
        }

        if (hz2 < 30){
          Serial.println("Zona 2 demasiado seca! Se activara riego");
          com_salidas[2] = 1;
        }
        if (hz2 > 70){
          Serial.println("Zona 2 con suficiente humedad! Se corta el riego");
          com_salidas[2] = 0;
        }
        if (hz1 < 30 || hz2 < 30){
          Serial.println("Se enciende la bomba");
          com_salidas[0] = 1;
        }
        else{
          Serial.println("Apagando bomba");
          com_salidas[0] = 0;
        }
    }
    else 
      {
        Serial.println("Esta lloviendo, se detiene actividad de riego");
        com_salidas[0] = 0;
        com_salidas[1] = 0;
        com_salidas[2] = 0;
      }
    if (reserva_agua < 5000){
      com_salidas[3] = 1;
      Serial.println("Bajo nivel de reserva, abriendo ingreso de agua");
      }
    if (reserva_agua > 10000){
      com_salidas[3] = 0;
      Serial.println("Optimo nivel de reserva, cerrando ingreso de agua");
    }
    
    salidas.ActualizarSalidas(com_salidas);
    salidas.EstadoSalidas(sal_status);
    bomba = sal_status[0];
    evz1 = sal_status[1];
    evz2 = sal_status[2];
    evt = sal_status[3];
    
    // Actualizar el menú y mostrar en el LCD
    lcd.updateMenu(menuActual, hz1, hz2, (bool)llueve, reserva_agua, bomba, evz1, evz2, evt);
    
     

    Serial.println("tomando nuevo datos");
    delay(1000); // Esperar 1 segundo antes de la siguiente lectura
    
}
