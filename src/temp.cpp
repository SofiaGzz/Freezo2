/*#include <Arduino.h> Asegúrate de incluir las bibliotecas necesarias para tu plataforma
#include "TemperatureSensor.h"

void setup() {
  Serial.begin(9600);
  
}
void loop() {
  
  // Crea un objeto de la clase TemperatureSensor con valores Tmin y Tmax
  TemperatureSensor sensor(20.0, 30.0);
  // Llama a la función readTemp() para obtener la temperaturax
  float temperature = sensor.readTemp();

  // Verifica si la temperatura es válida
  if (sensor.IsTempValid()) {
    Serial.print("Temperature is valid: ");
  } else {
    Serial.print("Temperature is not valid: ");
  }

  Serial.print(temperature);
  Serial.println(" ºC");
}
*/