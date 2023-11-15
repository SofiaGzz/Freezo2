/*#ifndef conectividad_h
#define conectividad_h

#include <Wire.h>
#include <TinyGsmClient.h>
#include <Arduino.h>

// Set serial for debug console (to Serial Monitor, default speed 115200)
//#define SerialMon Serial
// Set serial for AT commands (to SIM800 module)
#define SerialAT  Serial1
#define MODEM_RST            5
#define MODEM_PWKEY          4
#define MODEM_POWER_ON       23
#define MODEM_TX             27
#define MODEM_RX             26
#define I2C_SDA              21
#define I2C_SCL              22
#define OUTPUT_1             2
uint32_t lastReconnectAttempt = 0;

// Your phone number to send SMS: + (plus sign) and country code, for Portugal +351, followed by phone number
// SMS_TARGET Example for Portugal +351XXXXXXXXX
#define SMS_TARGET  "+528180827303"

// Configure TinyGSM library
#define TINY_GSM_MODEM_SIM800      // Modem is SIM800
#define TINY_GSM_RX_BUFFER   1024  // Set RX buffer to 1Kb
#define SerialAT Serial1
#define GSM_PIN "14992720"
const int MSG_BUFFER_SIZE = 80;       // Tamaño de buffer del mensaje
char msg[MSG_BUFFER_SIZE];            // Generar un arreglo para el mensaje

#include <TinyGsmClient.h>

#ifdef DUMP_AT_COMMANDS
  #include <StreamDebugger.h>
  StreamDebugger debugger(SerialAT, Serial); // ** SerialMon en lugar de Serial
  TinyGsm modem(debugger);
#else
  TinyGsm modem(SerialAT);
#endif

class conectividad {
private:
  const char simPIN[4]   = "1111"; 
  const char apn[] = "internet"; // APN (example: internet.vodafone.pt) use https://wiki.apnchanger.org
  const char gprsUser[1] = ""; // webgprs
  const char gprsPass[] = ""; //webgprs2002

public: 
  TinyGsmClient client(modem);
  void setupDatos();
  void sendMessageAlarm();

};

#endif
*/