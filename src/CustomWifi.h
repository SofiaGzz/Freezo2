#ifndef CustomWiFi_h
#define CustomWiFi_h

#include <Arduino.h>
#include <WiFi.h>

class CustomWiFi {
public:
  CustomWiFi(const char* ssid, const char* password);
  void connect();
  bool isConnected();
  void time_temperature(char (&result)[9]);
private:
  const char* _ssid;
  const char* _password;
};

#endif