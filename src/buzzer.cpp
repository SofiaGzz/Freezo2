#include <Arduino.h>
#include "buzzer.h"


buzzer::buzzer(int pin) : buzzerPin(pin) {
  pinMode(buzzerPin, OUTPUT);
}

void buzzer::playConexion(const int* tonesC, int countC, int durationC) {
for (int iTone = 0; iTone < countC; iTone++) {
  tone(buzzerPin, tonesC[iTone]);
  delay(durationC);
}
noTone(buzzerPin);
}
void buzzer::playAlarma(const int* tonesA, int countA, int durationA) {
for (int iTone = 0; iTone < countA; iTone++) {
  tone(buzzerPin, tonesA[iTone]);
  delay(durationA);
}
noTone(buzzerPin);
}

