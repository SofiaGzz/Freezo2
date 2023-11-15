/*#ifndef SMS_h
#define SMS_h

#include <iostream>
#include<Arduino.h>
#include <Wire.h>
#include <TinyGsmClient.h>
#include<TinyGSM.h>
#include <HardwareSerial.h>

#define TINY_GSM_MODEM_SIM800      // Modem is SIM800
#define TINY_GSM_RX_BUFFER   1024  // Set RX buffer to 1Kb

//#define SerialMon Serial;
//#define SerialAT Serial1;
using namespace std;

// Configure TinyGSM library
#define TINY_GSM_MODEM_SIM800      // Modem is SIM800
#define TINY_GSM_RX_BUFFER   1024  // Set RX buffer to 1Kb

/*
#ifdef DUMP_AT_COMMANDS
  #include <StreamDebugger.h>
  StreamDebugger debugger(SerialAT, SerialMon);
  TinyGsm modem(debugger);
#else
  TinyGsm modem(SerialAT);
#endif
*/
/*
class SMS{
    private:
        const int MODEM_RST = 5;
        const int MODEM_PWKEY = 4;
        const int MODEM_POWER_ON = 23;
        const int MODEM_TX = 27;
        const int MODEM_RX = 26;
        const int I2C_SDA = 21;
        const int I2C_SCL = 22;
        const int IP5306_ADDR = 0x75;
        const int IP5306_REG_SYS_CTL0 = 0x00;
        const char simPIN[5]  = "1111";
        const char SMS_TARGET[14] = "+52813285011";
        HardwareSerial interfazSerial;

    public:
        SMS(HardwareSerial& serial);
        bool setPower(int en);
        void setupSMS();
        void mensaje(const char* mensaje);
};


#include <Arduino.h>
#include <Wire.h>
#include <TinyGsmClient.h>
#include <TinyGsm.h>

class SmsManager {
private:
  TinyGsm& modem;
  Stream& debugSerial;
  static const char simPIN[];

  bool setPowerBoostKeepOn(int en);

public:
  SmsManager(TinyGsm& modem, Stream& debugSerial);
  void initialize();
  bool unlockSim();
  bool restartModem();
  bool sendHelloMessage();
};

#endif
*/