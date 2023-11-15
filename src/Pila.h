#ifndef Pila_H
#define Pila_H

#include <Pangodream_18650_CL.h>

class Pila {
public:
  Pila();
  void initialize();
  void printBatteryInfo();
  void BatteryLevel();
  Pangodream_18650_CL pila;
};

#endif // Pila_H
