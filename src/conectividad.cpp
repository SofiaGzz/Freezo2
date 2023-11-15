/*#include <Arduino.h>
#include "conectividad.h"


void conectividad::setupDatos() {
  // Set console baud rate
  Serial.begin(9600);
  // Set console baud rate
  delay(10);
  
  // Start I2C communication
  I2CPower.begin(I2C_SDA, I2C_SCL, 400000);
  // I2CBME.begin(I2C_SDA_2, I2C_SCL_2, 400000);

  Serial.println("Wait...");

  // Set GSM module baud rate and UART pins
  SerialAT.begin(115200, SERIAL_8N1, MODEM_RX, MODEM_TX);
  delay(6000);

  // Restart takes quite some time
  // To skip it, call init() instead of restart()
  Serial.println("Initializing modem...");
  modem.restart();
  // modem.init();

  String modemInfo = modem.getModemInfo();
  Serial.print("Modem Info: ");
  Serial.println(modemInfo);

  // Unlock your SIM card with a PIN if needed
  if ( GSM_PIN && modem.getSimStatus() != 3 ) {
    modem.simUnlock(GSM_PIN);
  }

  Serial.print("Connecting to APN: ");
  Serial.print(apn);
  if (!modem.gprsConnect(apn, gprsUser, gprsPass)) {
    Serial.println(" fail");
    ESP.restart();
  }
  else {
    Serial.println(" OK");
  }
  
  if (modem.isGprsConnected()) {
    Serial.println("GPRS connected");
  }

  // Set modem reset, enable, power pins
  pinMode(MODEM_PWKEY, OUTPUT);
  pinMode(MODEM_RST, OUTPUT);
  pinMode(MODEM_POWER_ON, OUTPUT);
  digitalWrite(MODEM_PWKEY, LOW);
  digitalWrite(MODEM_RST, HIGH);
  digitalWrite(MODEM_POWER_ON, HIGH);
}

void conectividad::sendMessageAlarm(){
     // To send an SMS, call modem.sendSMS(SMS_TARGET, smsMessage)
  String smsMessage = "PROBELEMA! no hay conexión";
  if(modem.sendSMS(SMS_TARGET, smsMessage)){
    Serial.println(smsMessage);
  }
  else{
    Serial.println("SMS failed to send");
  }
  delay(10000);
}

*/