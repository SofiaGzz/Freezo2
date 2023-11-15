#include "Pila.h"
#include "Arduino.h"

Pila::Pila() {
  // Constructor (if needed)
}

void Pila::initialize() {
  // Initialization code, if needed
}

void Pila::printBatteryInfo() {
  Serial.print("Value from pin: ");
  Serial.println(analogRead(34));
  Serial.print("Average value from pin: ");
  Serial.println(pila.pinRead());
  Serial.print("Volts: ");
  Serial.println(pila.getBatteryVolts());
  Serial.print("Charge level: ");
  Serial.println(pila.getBatteryChargeLevel());
  Serial.println("");
}

void Pila::BatteryLevel()
{
    if (pila.getBatteryChargeLevel() <= 20) {
        Serial.print("Mensaje SMS menos de 20%"); //agregar el sms 
    }
}
