#ifndef led_H
#define led_H

class led {
public:
  led();
  void initialize();
  void setColor(int red, int green, int blue);
  void conexion(int durationC);
  void Alarma(int durationA);
  void valid(int durationD);
  const int pinRed    = 14; // GPIO23
  const int pinGreen  = 27; // GPIO22
  const int pinBlue   = 26; // GPIO21
};

#endif // led_H
