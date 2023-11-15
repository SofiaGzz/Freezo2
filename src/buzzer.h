#pragma once
#include <Arduino.h>
#ifndef buzzer_h
#define buzzer_h

class buzzer{
private:
  int buzzerPin=13;

public:
  buzzer(int pin);
  void playConexion(const int* tonesC, int countC, int durationC);
  void playAlarma(const int* tonesA, int countA, int durationA);
  
};

#endif