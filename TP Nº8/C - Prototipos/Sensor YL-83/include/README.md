# Archivo `sensor_yl83.h` - Explicación del Código

Este archivo de cabecera (`.h`) define la clase `SensorYL83`, que se utiliza para manejar el sensor de lluvia YL-83. A continuación, se explica cada parte del archivo:

## 1. Protección contra inclusiones múltiples
```cpp
#ifndef SENSOR_YL83_H
#define SENSOR_YL83_H
```
`#ifndef SENSOR_YL83_H:` Significa "si no está definido SENSOR_YL83_H".

Se utiliza para asegurarse de que este archivo no se incluya más de una vez durante la compilación.

---
`#define SENSOR_YL83_H:` Si no está definido, lo define para evitar inclusiones múltiples. 

Esto previene errores relacionados con múltiples inclusiones del mismo archivo durante la compilación. 

## 2. Inclusión de la librería Arduino.h

```cpp
#include <Arduino.h>
```
Esta línea incluye la librería principal de Arduino, que proporciona acceso a funciones como pinMode(), digitalRead(), y otras necesarias para interactuar con el hardware del ESP32.

## 3. Declaración de la clase SensorYL83
```cpp
class SensorYL83 {
```
La clase SensorYL83 encapsula todo lo necesario para interactuar con el sensor de lluvia YL-83, permitiendo reutilizar y organizar el código de manera más eficiente.

## 4. Atributos privados
```cpp
private:
    int pin;  // Pin digital donde está conectado el sensor
```
El atributo pin es privado y almacena el número del pin GPIO del ESP32 donde está conectado el sensor de lluvia. Al ser privado, solo los métodos de la clase pueden acceder o modificar este valor.

## 5. Métodos públicos
```cpp
public:
    // Constructor que recibe el pin donde está conectado el sensor
    SensorYL83(int digitalPin);

    // Método de inicialización (aunque no requiere configuración especial)
    void begin();

    // Método para detectar lluvia (retorna true si está lloviendo)
    bool detectarLluvia();
```
### Descripción de los métodos:
Constructor `SensorYL83(int digitalPin)`:

Inicializa la clase con el número de pin donde está conectado el sensor.  

### Ejemplo de uso:

```cpp
SensorYL83 rainSensor(12);  // El sensor está en el pin 12
Método begin():
```

Configura el pin como entrada digital utilizando pinMode(). Este método sigue la convención de inicialización, aunque el sensor no necesita configuraciones complejas.  

### Ejemplo de uso:
```cpp
rainSensor.begin();  // Configura el pin como entrada
Método detectarLluvia():
```
Lee el estado del pin digital donde está conectado el sensor y devuelve true si detecta lluvia (si el pin está en LOW).  

### Ejemplo de uso:
```cpp
if (rainSensor.detectarLluvia()) {
    Serial.println("Está lloviendo");
}
```
## 6. Cierre de la protección contra inclusiones múltiples
```cpp
#endif
```
Esta directiva cierra la protección contra inclusiones múltiples, asegurando que todo el código entre #ifndef y #endif solo se incluya una vez durante la compilación.

### Resumen:
**Protección contra inclusiones múltiples**: Evita que el archivo se incluya más de una vez.  

**Incluir Arduino.h**: Proporciona las funciones necesarias para trabajar con el ESP32.  

**Clase SensorYL83:** Organiza el código para interactuar con el sensor YL-83.  

**Atributos y métodos:** El pin se guarda en un atributo privado, y los métodos permiten inicializar el sensor y detectar si está lloviendo.