#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entidad 1.h"
#include "entidad 2.h"
#include "informes.h"

void imprimirTodo(sPantallaLcd* arrayLcd, int lenLcd, sPAntallaLed* arrayLed, int lenLed)
{
    int indiceLed;
    int i;
    for(i = 0; i < lenLed; i++)
    {
        if(arrayLed[indiceLed].flagEstadoOcupado == 1)
        {
            int idLcd =  arrayLed[indiceLed].id_PantallaLcd;
            int indiceLcd = pLcd_buscarIndicePorId(arrayLcd,lenLcd,idLcd);

            printf("%d \t%s \t%s \t%.2f | %d \t%s \t%s \t%.2f", arrayLcd[indiceLcd].id, arrayLcd[indiceLcd].nombreLcd, arrayLcd[indiceLcd].direccionLcd, arrayLcd[indiceLcd].precioLcd, arrayLed[indiceLed].id, arrayLed[indiceLed].nombreLed, arrayLed[indiceLed].direccionLed, arrayLed[indiceLed].precioLed);

        }
    }
}

