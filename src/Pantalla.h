#ifndef Pantalla_h 
#define Pantalla_h

#include <iostream>
#include <string>
#include "TemperatureSensor.h"
#include "EPD.h"
#include "DEV_Config.h"
#include <GxEPD2_BW.h>
#include <U8g2_for_Adafruit_GFX.h>

using namespace std;

class Pantalla{// Nombre de la clase: Punto
 private:
    double temperatura;
    std::string fecha;
    std::string hora;
    UBYTE *BlackImage; 

 public: // parte pública
    Pantalla(); // método constructor por omisión, asignando el valor de cero a ambos atributos
    Pantalla(double _tem, std::string _hor, std::string _fecha); // parámetros que se van a traer de las funciones: temperatura, hora y fecha

     //métodos
    void iniciarPantalla(); //método que inicializa la pantalla
    void BienFreezo(); //método que imprime "bienvenido a Freezo"
    void printTemperatura(float _temp);
    
};
#endif /* Episodio_h */