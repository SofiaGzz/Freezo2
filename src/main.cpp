#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include "imagedata.h"
#include <stdlib.h>
#include "Pantalla.h"
#include <stdio.h>
#include <string.h>
#include "TemperatureSensor.h"
#include "CustomWifi.h"
#include "Pila.h"
#include "buzzer.h"
#include "led.h"

//Objetos
CustomWiFi myWiFi("Protexa-Guest","19192019"); // objeto clase de conección WIFI
Pantalla miPantalla; // objeto clase de pantalla
TemperatureSensor sensor(0.0, 30.0); //clase de Temperatura
Pila bateria; //objeto de clase batería
buzzer mibuzzer(13); //objeto clase buzzer
led miled; //objeto clase 
WiFiClient espClient;  //objeto clase WiFi
PubSubClient client(espClient);  //objeto clase PubSubClient

//Pangodream_18650_CL fuente;
//HardwareSerial miSerial(1); //algo del SMS

//métodos
void callback(char*, byte*, unsigned int); // Función para procesar mensajes recibidos por MQTT 
void reconnect(); // Función para conectarse a MQTT 

//Parámetros
  //MQTT
const char* mqtt_server = "broker.mqtt-dashboard.com";
const int mqtt_port = 1883;
const char* topico_salida = "equipoPATO"; 
const char* topico_entrada = "equipoPATO";
const int MSG_BUFFER_SIZE = 200;       // Tamaño de buffer del mensaje  
char msg[MSG_BUFFER_SIZE];            // Generar un arreglo para el mensaje 
  //variable
char wifiData[20]; 
  //Buzzer
const int tonosA[] = {2000,1800,2000,1800,2000,1800};
const int countTonosA = 6;


void setup() {
  Serial.begin(115200);

  miPantalla.iniciarPantalla(); //método que inicializa la pantalla
  miPantalla.BienFreezo(); //método que imprime "bienvenido a Freezo"
  myWiFi.connect();
  bateria.initialize();  //inicializar la  batería
  miled.initialize();
  client.setCallback(callback); //Callback MQTT
  client.setServer(mqtt_server, mqtt_port);// Conéctate al servidor MQTT
  if (!client.connected()) {
    if (client.connect("ESP32Client")) {
      Serial.println("¡Conectado al servidor MQTT!");
    } else {
      Serial.print("Error de conexión, rc=");
      Serial.print(client.state());
      Serial.println(" Intentando de nuevo en 5 segundos...");
      delay(5000);
    }
  }
  client.subscribe(topico_entrada);

  /*if (!client.connected()) {
    reconnect();
  }*/
}

//Función Callback
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.println("Mensaje recibido:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void loop(){
  
  if (myWiFi.isConnected()){
    // Crea un objeto de la clase TemperatureSensor con valores Tmin y Tmax
    // Llama a la función readTemp() para obtener la temperaturax
    //wifi_datos = "WiFi";
    strcpy(wifiData, "Wifi");
    //MQTT
    float temperature;
    if (!client.connected()) {
      reconnect(); 
    }
    client.loop();

    //Temperatura
    // agregar una variable valid = 1/0 si es valido o no. 
    temperature = sensor.readTemp();
    bool alarma;
    int Bateria_corriente;
   
    // Verifica si la temperatura es válida
    if (sensor.IsTempValid()) {
      Serial.print("Temperature is valid: ");
      alarma = false;
      miled.valid(5000);
    } else {
      Serial.print("Temperature is not valid: ");
      alarma= true;
      mibuzzer.playAlarma(tonosA, countTonosA, 200);
      miled.Alarma(5000);
    
      //mandar a llamar al buzzer y al led rojo 
    }
    Serial.print(temperature);
    Serial.println(" ºC");
    char hora[9];
    myWiFi.time_temperature(hora);
    Serial.print("Esta es la Hora:");
    Serial.print(hora);
    Serial.print("");
    Serial.print("");
    
  //leer la temperatura y luego mandarla. leer la temp
    miPantalla.printTemperatura(temperature);

    /*Batería
    Serial.print("batería:");
    Serial.print("nuevo:");
    int x; //map
    x = analogRead(33); //34,36,39
    Serial.print(x);
    Serial.print("\n");
*/
    //bateria.printBatteryInfo();
    //fuente
    //Bateria_corriente = fuente.fuenteAlim(fuente.getBatteryVolts());
    
    //MQTT
    snprintf (msg, MSG_BUFFER_SIZE, "{\"id_Refri\":\"Refrigerador 1\",\"alarma\":%d,\"wifi_datos\":\"%s\",\"bat_elec\":\"Corriente\",\"tiempo\":\"%s\",\"temperatura\":%.2f}", alarma, wifiData,hora, temperature*1.0);
    client.publish(topico_entrada, msg); 
    Serial.print("MENSAJE PUBLICADO");
    Serial.print("\n");
    delay(5000);
  }
  else{
    strcpy(wifiData, "Datos");
  }
}


//Función Reconnect
void reconnect() { // Función para conectarse a MQTT

  //if (millis() + 1000 )  -- 
  // if (millis() > lastTime + 5000) {
    // lastTime = millis();
  // }
  

  if (!client.connected() ) {
    //timeStamp = millis();
    Serial.print("Attempting MQTT connection... ");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected.");
      // Once connected, publish an announcement...
      //client.publish("outTopic", "hello world");
      // ... and resubscribe
      //client.subscribe("inTopic");
      client.subscribe(topico_entrada);
      client.subscribe(topico_salida);   
    } else {
      Serial.print("Failed, rc = ");
      Serial.print(client.state());
      Serial.println(". Try again in 5 seconds.");
      // Wait 5 seconds before retrying
      delay(5000);
      
    }
  }
}