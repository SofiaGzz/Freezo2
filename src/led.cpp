#include "led.h"
#include "Arduino.h"

led::led() {
}

void led::initialize() {
  pinMode(pinRed,   OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue,  OUTPUT);
}

void led::setColor(int red, int green, int blue) {
  analogWrite(pinRed,   red);
  analogWrite(pinGreen, green);
  analogWrite(pinBlue,  blue);
}

void led::Alarma(int durationA) {
  setColor(0, 256, 256);
  delay(durationA);
}

void led::conexion(int durationC) {
  setColor(256,256,256);
  delay(durationC);
  setColor(256, 256, 0); // azul
}

void led::valid(int duracionD){
  setColor(256,0,256);
  delay(duracionD);
}
