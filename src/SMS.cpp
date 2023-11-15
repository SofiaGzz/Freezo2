/*#include "SMS.h"
using namespace std;

#define SerialMon Serial
#define SerialAT Serial1

HardwareSerial miSerial(1);
SMS miSMS(miSerial);

SMS::SMS(HardwareSerial& serial) : interfazSerial(serial){

}

bool SMS::setPower(int en){
    Wire.beginTransmission(IP5306_ADDR);
    Wire.write(IP5306_REG_SYS_CTL0);
    if (en) {
        Wire.write(0x37); // Set bit1: 1 enable 0 disable boost keep on
    } else {
        Wire.write(0x35); // 0x37 is default reg value
    }
    return Wire.endTransmission() == 0;
}

void SMS::setupSMS(){
    SerialMon.begin(115200);
    delay(1000);
    // Set console baud rate

  Keep power when running from battery
  Wire.begin(I2C_SDA, I2C_SCL);
  bool isOk = setPower(1);
  SerialMon.println(String("IP5306 KeepOn ") + (isOk ? "OK" : "FAIL"));

  // Set modem reset, enable, power pins
  pinMode(MODEM_PWKEY, OUTPUT);
  pinMode(MODEM_RST, OUTPUT);
  pinMode(MODEM_POWER_ON, OUTPUT);
  digitalWrite(MODEM_PWKEY, LOW);
  digitalWrite(MODEM_RST, HIGH);
  digitalWrite(MODEM_POWER_ON, HIGH);

  // Set GSM module baud rate and UART pins
  miSerial.begin(9600, SERIAL_8N1, MODEM_RX, MODEM_TX);
  delay(3000);
  
  // Restart SIM800 module, it takes quite some time
  // To skip it, call init() instead of restart()
  SerialMon.println("Initializing modem...");
  modem.restart();
  // use modem.init() if you don't need the complete restart

  // Unlock your SIM card with a PIN if needed
  if (strlen(simPIN) && modem.getSimStatus() != 3 ) {
    modem.simUnlock(simPIN);
  }
}

void SMS::mensaje(const char* mensaje){
        // To send an SMS, call modem.sendSMS(SMS_TARGET, smsMessage)
    Serial.println("Simulacion perro");
    Serial.println(mensaje);
}


const char SmsManager::simPIN[] = "1111";

SmsManager::SmsManager(TinyGsm& modem, Stream& debugSerial) : modem(modem), debugSerial(debugSerial){}

bool SmsManager::setPowerBoostKeepOn(int en) {
  Wire.beginTransmission(0x75);
  Wire.write(0x00);
  Wire.write(en ? 0x37 : 0x35);
  return Wire.endTransmission() == 0;
}

void SmsManager::initialize() {
  Wire.begin();
  setPowerBoostKeepOn(1);

  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(23, OUTPUT);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(23, HIGH);

  Serial1.begin(9600, SERIAL_8N1, 26, 27);
  delay(3000);
  restartModem();

  if (strlen(simPIN) && modem.getSimStatus() != 3) {
    unlockSim();
  }
}

bool SmsManager::unlockSim() {
  return simPIN[0] == '\0' || modem.simUnlock(simPIN);
}

bool SmsManager::restartModem() {
  SerialMon.println("Initializing modem...");
  return modem.restart();
}

bool SmsManager::sendHelloMessage() {
  String smsMessage = "Hello from ESP32!";
  return Sms("+528180827303", smsMessage);
}

bool SmsManager::Sms(const String &phoneNumber, const String &message) {
  return modem.sendSMS(phoneNumber, message);
}
*/