#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <SoftwareSerial.h>

class Bluetooth { 
  private:
    SoftwareSerial bt;

  public:
    Bluetooth(int rxPin, int txPin) : bt(rxPin, txPin) {}

    void iniciar() {
      bt.begin(9600); 
    }

    bool disponible() {
      return bt.available() > 0;   
    }

    char leer() {
      return bt.read();            
    }

    void enviar(String msg) {
      bt.println(msg);
    }
};
#endif
