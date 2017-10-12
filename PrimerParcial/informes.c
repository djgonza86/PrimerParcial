#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "publicidad.h"
#include "informes.h"
#include "validar.h"


/** \brief Imprime los elementos que tenga su campo de flag "ocupado"
 *
 * \param array Recibe el array
 * \param longitud Tamaño del array
 * \return 0(ok) y -1(error)
 *
 */
int pant_printPantalla(sPantalla* array, int longitud)
{
    int retorno = -1;
    int i;
    if(array != NULL && longitud > 0)
    {
        for(i = 0; i < longitud ; i++)
        {
            if(array[i].flagEstado == PANTALLA_OCUPADA)
            {
                printf("\nID: %d\nTIPO: %s\nNOMBRE: %s\nDIRECCION: %s\nPRECIO: %f\n", array[i].id, array[i].tipo, array[i].nombre, array[i].direccion, array[i].precio);
                retorno = 0;
            }
        }
    }
    return retorno;
}
