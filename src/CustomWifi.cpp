#include "CustomWiFi.h"
#include <WiFi.h>
#include <NTPClient.h>
#include <TimeLib.h>
#include <buzzer.h>
#include "led.h"
led miled2; //objeto clase 
buzzer mibuzzer2(13);
const int buzzerPin = 12;
const int tonosC[] = {1000, 1200, 1400, 1600};
const int countTonosC = 4;



CustomWiFi::CustomWiFi(const char* ssid, const char* password) {
  _ssid = ssid;
  _password = password;
}

void CustomWiFi::connect() {
  WiFi.begin(_ssid, _password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
    miled2.conexion(100);
    Serial.print("Suena Conexión");
    mibuzzer2.playConexion(tonosC, countTonosC, 300);
    delay(3000);
  }
  Serial.println("Connected to WiFi!");
}

bool CustomWiFi::isConnected() {
  return (WiFi.status() == WL_CONNECTED);
}
void CustomWiFi::time_temperature(char (&result)[9]){
  const long utcOFFsetInSeconds = -21600;
  WiFiUDP ntpUDP;
  NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOFFsetInSeconds);
  timeClient.begin();
  timeClient.update();
  
  // Obtener la hora actual
  String formattedTime = timeClient.getFormattedTime();
  
  // Extraer las partes de la hora, minuto y segundo
  int hour = formattedTime.substring(0, 2).toInt();
  int minute = formattedTime.substring(3, 5).toInt();
  int second = formattedTime.substring(6, 8).toInt();

  // Formatear en el formato deseado (HH:MM:SS)
  snprintf(result, 9, "%02d:%02d:%02d", hour, minute,second);
}