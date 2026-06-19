# TalentOso: Sistema Robotico Cuadrupedo Bio-inspirado

Proyecto de ingenieria enfocado en el desarrollo de un robot cuadrupedo que emula la morfologia de un oso, integrando control inalambrico y sistemas de audio embebido.

![Foto del Robot TalentOso](oso.png)

## Resumen del Proyecto
TalentOso es una plataforma mecatronica controlada mediante una arquitectura hibrida. Utiliza un microcontrolador **Arduino Uno** para la ejecucion de movimientos en tiempo real y una interfaz desarrollada en **Python** para el mando a distancia. El robot es capaz de caminar, sentarse, realizar movimientos de ataque y reproducir sonidos sincronizados.

## Objetivos y Proposito
El proposito de este proyecto es:
1. Implementar un sistema de locomocion estable mediante 4 puntos de apoyo.
2. Establecer una comunicacion serial robusta via Bluetooth.
3. Gestionar perifericos complejos (servos de alto torque y modulos de audio) mediante Programacion Orientada a Objetos (POO).

## Especificaciones de Hardware y Materiales
Para garantizar el movimiento y la potencia necesaria, se utilizaron los siguientes componentes:

| Cantidad | Componente | Descripcion Tecnica |
| :--- | :--- | :--- |
| 1 | **Arduino Uno** | Cerebro del sistema (ATmega328P). |
| 4 | **Servomotores** | Alimentacion de 6V con torque de 6kg. |
| 1 | **Modulo Bluetooth HC-06** | Comunicacion inalambrica (incluye divisor de tension 1k/2k). |
| 1 | **DFPlayer Mini** | Modulo de reproduccion de audio MP3. |
| 1 | **Bocina** | Salida de audio conectada al preamplificador del DFPlayer. |
| 1 | **Chasis** | Estructura base en MDF de 5mm y piezas en impresion 3D. |

## Funcionamiento del Sistema
El robot opera mediante una maquina de estados programada en C++. El flujo de trabajo es el siguiente:
1. La interfaz en Python envia un caracter ASCII.
2. El modulo HC-06 recibe la señal y la transmite al Arduino.
3. El Arduino procesa el comando y ejecuta la funcion correspondiente (caminar, atacar, etc.).

### Protocolo de Comandos
*   **C**: Ejecuta la secuencia de caminata.
*   **P**: Posicion de parado/sentado.
*   **L**: Levantarse gradualmente (proteccion de motores).
*   **A**: Modo de ataque (oscilacion de garras).
*   **R**: Reproduccion de audio (musica/rugido).

## Interfaz de Usuario (Python)
La consola de control fue desarrollada con la libreria **Tkinter**. Permite una operacion intuitiva mediante botones que gestionan la conexion serial con el puerto COM correspondiente.

![Interfaz de Usuario](imgs/Aplicación.png)

### Instalacion de dependencias
Para ejecutar la interfaz, es necesario instalar `pyserial`:
```bash
pip install pyserial
