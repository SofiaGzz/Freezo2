#define ENABLE_GxEPD2_GFX 0

#include "Pantalla.h"
#include "GUI_Paint.h"
#include "imagedata.h"
#include <stdlib.h>
using namespace std;
#include <string.h>
#include <stdio.h>

//U8G2
//u8g2Fonts.begin(display);


  // Constructor: recibe como parametro un string con el nombre del archivo a abrir
Pantalla::Pantalla(){};
Pantalla::Pantalla(double _tem, std::string _hor, std::string _fecha){
    temperatura = _tem;
    hora = _hor;
    fecha = _fecha;  
};
   
    //sets
void Pantalla::iniciarPantalla() {
    DEV_Module_Init();
    EPD_2IN7_V2_Init();
    EPD_2IN7_V2_Clear();
}

void Pantalla::BienFreezo() {
    // Drawing on the image
    UWORD Imagesize = ((EPD_2IN7_V2_WIDTH % 8 == 0) ?    (EPD_2IN7_V2_WIDTH / 8) : (EPD_2IN7_V2_WIDTH / 8 + 1)) * EPD_2IN7_V2_HEIGHT;
    if ((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        while (1);
    }
    Paint_NewImage(BlackImage, EPD_2IN7_V2_WIDTH, EPD_2IN7_V2_HEIGHT, 90, BLACK);
    printf("Drawing\r\n");
    Paint_SelectImage(BlackImage);
    Paint_Clear(BLACK);

    // Agregar el mensaje "Bienvenido a FREEZO" en toda la pantalla
    Paint_DrawString_EN(10, 60, "Bienvenido a     FREEZO", &Font24, BLACK, WHITE);
    DEV_Delay_ms(5000);

}

void Pantalla::printTemperatura(float _temp){
    EPD_2IN7_V2_Display_Base(BlackImage);
    Paint_NewImage(BlackImage, EPD_2IN7_V2_WIDTH, EPD_2IN7_V2_HEIGHT, 90, BLACK);
    Paint_Clear(BLACK);

    char tempStr[10];
    dtostrf(_temp, 4, 2, tempStr);

    Paint_DrawString_EN(85, 85, tempStr, &Font24, BLACK, WHITE);
    Paint_DrawString_EN(170, 85, " C", &Font24, BLACK, WHITE);
    DEV_Delay_ms(5000);
}

/*
void Pantalla::printTemperatura(float _temp){
    u8g2Fonts.setFont(u8g2_font_fub49_tn)
}
*/

