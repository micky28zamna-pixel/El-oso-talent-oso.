#include <Servo.h>              //libreria para usar los servos 
#include <Arduino.h>            //Libreria para el funcionamiento del arduino
#include <DFRobotDFPlayerMini.h> //Libreria para el funcionamiento de la bocina
#include <SoftwareSerial.h>       //Libreria tambien para el funcionamiento tanto como de la bocina y tambien del modulo bluetooth
#include "Bluetooth.h"            //Libreria donde exportamos el bluetooth de la carpeta de bluetooth

class ServoMotor {            //Clase servomotor que esta dedicada solamente al funcionamiento de todos los servos 
  Servo motor1;
  Servo motor2;
  Servo motor3;
  Servo motor4;

public:    //Metodo
  void iniciar(int p6, int p7, int p8, int p9) { //Funcion para inicializar los servos 
    motor1.attach(p6);
    motor2.attach(p7);
    motor3.attach(p8);
    motor4.attach(p9);
  }
                            //Funcion para que oso pueda caminar
  void caminar() {

    motor1.write(90);
    motor2.write(90);
    motor3.write(90);
    motor4.write(90);
    delay(250);

    motor1.write(132);
    motor4.write(48);
    delay(250);

    motor1.write(90);
    motor4.write(90);
    delay(250);

    motor2.write(53);
    motor3.write(127);
    delay(250);

    motor2.write(90);
    motor3.write(90);
    delay(250);
  }
                  // Funcion para que oso pueda sentarse 
  void pararse() {

    motor3.write(180);
    motor4.write(0);

    delay(500);
  }
                    //Funcion para que el oso pueda atacar 
  void atacar() {

    for (int i = 0; i < 10; i++) {

      motor1.write(110);
      motor2.write(110);
      delay(200);

      motor1.write(70);
      motor2.write(70);
      delay(200);
    }

    motor1.write(90);
    motor2.write(90);
  }
        // Funcion para que el oso pueda levantarse gradualmente 
  void levantarse() {

    motor1.write(80);
    motor2.write(80);
    delay(150);

    motor3.write(160);
    motor4.write(20);
    delay(250);

    motor3.write(140);
    motor4.write(40);
    delay(250);

    motor3.write(120);
    motor4.write(60);
    delay(250);

    motor3.write(100);
    motor4.write(80);
    delay(250);

    motor3.write(90);
    motor4.write(90);

    motor1.write(90);
    motor2.write(90);

    delay(200);
  }
};
//Todo lo que ocupa la bocian para poder reproducir los audios 
class Bocina {

  DFRobotDFPlayerMini player;

public:
  bool iniciar(SoftwareSerial &serial) {

    if (player.begin(serial)) {

      player.outputDevice(DFPLAYER_DEVICE_SD);
      player.volume(30);  // Control de volumen 
      return true;
    }

    return false;
  }

  void reproducirLoop(int track) {
    player.loop(track);
  }
};

class Robot {   //clase general donde mandas a llamar todas las clases y funciones 

  Bluetooth bt;
  ServoMotor servos;
  Bocina audio;
  SoftwareSerial mySerial;

public:
//Pines que se conectan al arduino
  Robot() : bt(10,11), mySerial(3,4) {}

  void iniciar() {

    Serial.begin(9600);
    //Inicio del funcionamiento del bluetooth
    bt.iniciar();

    //
    // mySerial.begin(9600);  
    //inicio del funcionamiento de la bocina y reproduccion del audio

    // if(!audio.iniciar(mySerial)) {
    //   Serial.println("Error inicializando DFPlayer");
    // }
    // 

    servos.iniciar(6,7,8,9);
  //Pines de servos 
    Serial.println("Robot iniciado");
  }

  void ejecutar() {
      //Esta parte del codigo es donde se va reflejar si el bluetooth recibe la señal ya que si la recibe aparecen los comandos en el serial monitor del arduino
    if(bt.disponible()) {

      char comando = bt.leer();

      Serial.print("ASCII: ");
      Serial.println((int)comando);

      Serial.print("CHAR: ");
      Serial.println(comando);

      procesarComando(comando);
    }
  }
  //Recibir señales de python y acciones del robot
  void procesarComando(char comando) {
        
    Serial.print("Comando recibido: ");
    Serial.println(comando);
//Robot camina con el caracter de python C y tambien lo refleja en el monitor serial
    if(comando == 'C') {

      Serial.println("CAMINAR");
      servos.caminar();
//Robot se para con el caracter de python P y tambien lo refleja con el monitor serial
    } else if(comando == 'P') {

      Serial.println("PARARSE");
      servos.pararse();
//Robot ataca con el caracter de python A y tambien lo refleja con el monitor serial
    } else if(comando == 'A') {

      Serial.println("ATACAR");
      servos.atacar();
//Robot Reproduce musica con el caracter de python R y tambien lo refleja con el monitor serial
    } else if(comando == 'R') {

      Serial.println("REPRODUCIR");

      // audio.reproducirLoop(2);
//Robot se levanta gradualmente con el caracter de python L y tambien lo refleja con el monitor serial
    } else if(comando == 'L') {

      Serial.println("LEVANTARSE");
      servos.levantarse();

    } else {
//En dado caso que no reciba nada aparece comando invalido
      Serial.print("Comando invalido: ");
      Serial.println(comando);
    }
  }
};

Robot robot;

void setup() {
  robot.iniciar();  //Inicializa el robot 
}

void loop() {
  robot.ejecutar(); // ejecuta el ciclo del robot
}
