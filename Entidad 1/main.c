#include <stdio.h>
#include <stdlib.h>
#include "entidad 1.h"
#include "entidad 2.h"
#include "validacion.h"
#include "informes.h"
#define LONGITUD_PANTALLA_LCD 3
#define LONGITUD_PANTALLA_LED 3


int main()
{
    sPantallaLcd arrayLcd[LONGITUD_PANTALLA_LCD];
    sPAntallaLed arrayLed[LONGITUD_PANTALLA_LED];

    pLcd_init(arrayLcd, LONGITUD_PANTALLA_LCD);
    pLed_init(arrayLed, LONGITUD_PANTALLA_LED);


    while(1)
    {
        printf("\n1-ALTA DE PANTALLA\n");
        printf("\n2-MODIFICACION DATOS DE PANTALLA\n");
        printf("\n3-BAJA DE PANTALLA\n");
        printf("\n4-LISTAR PANTALLAS\n");

        int id = 15;
        char opcion [50];
        if(val_getUnsignedInt(opcion,"\n\nElija la Opcion: ","Opcion no valida",INTENTOS,CANTIDAD_CHAR) == 0)
        {
            int op =atoi(opcion);
            switch(op)
            {
                case 1:
                    system("cls");
                    pLcd_alta(arrayLcd,LONGITUD_PANTALLA_LCD);

                    break;
                case 2:
                    system("cls");
                    pLcd_modificar(arrayLcd, LONGITUD_PANTALLA_LCD, pLcd_obtenerId(arrayLcd,LONGITUD_PANTALLA_LCD));
                    break;
                case 3:
                    system("cls");
                    pLcd_baja(arrayLcd, LONGITUD_PANTALLA_LCD, id);
                    break;
                case 4:
                    system("cls");
                    imprimirTodo(arrayLcd,LONGITUD_PANTALLA_LCD,arrayLed,LONGITUD_PANTALLA_LED);
                    break;
            }
        }

    }
    return 0;
}
