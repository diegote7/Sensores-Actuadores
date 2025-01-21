![logo](../E%20-%20assets/caratula.jpg)  

# ¿Qué es LoRaWAN?

LoRaWAN (Long Range Wide Area Network) es un protocolo de comunicación de largo alcance y baja potencia diseñado para dispositivos IoT (Internet of Things). Utiliza la modulación **LoRa** (Long Range) para la transmisión de datos y está optimizado para aplicaciones donde es importante la eficiencia energética y el alcance de la señal.

## Características de LoRaWAN

- **Bajo consumo de energía:** Ideal para dispositivos que funcionan con baterías, con autonomía que puede durar varios años.
  
- **Alcance largo:** Puede cubrir distancias de hasta 10-15 km en zonas rurales y 2-5 km en entornos urbanos.
  
- **Modulación LoRa:** Utiliza una técnica de espectro ensanchado que permite transmisiones a larga distancia con baja potencia y resistencia a interferencias.
  
- **Capas del protocolo:** LoRaWAN define la capa de red, mientras que LoRa se encarga de la capa física de la transmisión.

- **Topología de red:** Utiliza una arquitectura de **estrellas**, donde los dispositivos finales (nodos) se comunican directamente con **Gateways**. Los **Gateways** retransmiten los datos al **servidor de red** central.
  
- **Seguridad:** Emplea encriptación AES de extremo a extremo, lo que garantiza la integridad y confidencialidad de los datos.

- **Clases de dispositivos:**
  - **Clase A:** Modo por defecto. El dispositivo escucha solo después de enviar un mensaje.
  - **Clase B:** Los dispositivos pueden recibir datos en momentos programados, gracias a un reloj sincronizado.
  - **Clase C:** Los dispositivos tienen la escucha casi continua (consumen más energía).

## Aplicaciones de LoRaWAN

LoRaWAN es especialmente útil en escenarios donde es necesario transmitir pequeñas cantidades de datos a lo largo de distancias considerables, y donde la eficiencia energética es crucial. Algunas aplicaciones comunes incluyen:

- **Monitoreo ambiental:** Recolección de datos sobre calidad del aire, temperatura, humedad, etc., en áreas remotas o rurales.
  
- **Agricultura inteligente:** Sensores para medir el riego, la calidad del suelo y las condiciones climáticas en grandes extensiones de terreno.

- **Gestión de ciudades inteligentes:** Control de alumbrado público, recolección de basura, estacionamiento y otros sistemas urbanos.

- **Monitoreo industrial:** Supervisión de equipos, control de inventario, o detección de fallos en tiempo real en plantas industriales.

- **Seguimiento de activos:** Monitoreo de vehículos, maquinaria, o cualquier tipo de activo móvil a lo largo de grandes áreas.

- **Medición remota de servicios públicos:** Uso en la gestión de medidores inteligentes para agua, gas y electricidad, permitiendo el monitoreo en tiempo real sin necesidad de intervención manual.

## Ventajas

- **Cobertura amplia:** LoRaWAN permite la comunicación a través de grandes distancias sin necesidad de infraestructura costosa.
- **Escalabilidad:** Se puede implementar una red LoRaWAN para miles de dispositivos.
- **Bajo costo:** Tanto el despliegue de la red como los dispositivos LoRa son más económicos comparados con otras tecnologías de conectividad.
