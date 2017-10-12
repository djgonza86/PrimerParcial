#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "publicidad.h"
#include "validar.h"
#include "informes.h"
#define CANTIDAD_PANTALLAS 1
#define CANTIDAD_PUBLICIDADES 1000
#define INTENTOS 3

int main()
{
    {
    sPantalla arrayPantallas[CANTIDAD_PANTALLAS];
    sPublicidad arrayPublicidad[CANTIDAD_PUBLICIDADES];

    char idPantallaBorrar[5];

    pant_init(arrayPantallas, CANTIDAD_PANTALLAS);
    publ_init(arrayPublicidad, CANTIDAD_PUBLICIDADES);

    char bufferOpcion[5];

    do
    {
         val_getUnsignedInt(bufferOpcion, "\tMENU\n\n1) ALTA DE PANTALLAS\n2) MODIFICAR DATOS DE PANTALLAS \n3) BAJA DE PANTALLAS\n"
                                        "4) CONTRATAR UNA PUBLICIDAD\n5) MODIFICAR CONDICIONES DE PUBLICACION\n6) CANCELAR CONTRATACION\n"
                                        "7) CONSULTA FACTURACION\n8) LISTAR CONTRATACIONES\n9) LISTAS PANTALLAS\n10) INFORMAR\n\n0) SALIR\n",
                                        "ERROR",INTENTOS, 10);
        switch(atoi(bufferOpcion))
        {
            case 1:
                system("cls");
                pant_cargarPantalla(arrayPantallas, CANTIDAD_PANTALLAS);
                break;
            case 2:
                system("cls");
                pant_modificarPantalla(arrayPantallas, CANTIDAD_PANTALLAS);
                break;
            case 3:
                system("cls");
                val_getUnsignedInt(idPantallaBorrar, "\nIngrese el ID de la pantalla: \n", "ID no existe\n", INTENTOS, 5);
                pant_borrarPantalla(arrayPantallas, atoi(idPantallaBorrar), CANTIDAD_PANTALLAS);
                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            case 9:
                system("cls");
                pant_printPantalla(arrayPantallas,CANTIDAD_PANTALLAS);

                break;
            case 10:

                break;
        }
    }
    while(atoi(bufferOpcion) != 0);

    return 0;
}
}
