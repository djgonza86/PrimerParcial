#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "publicidad.h"
#include "validar.h"

/** \brief inicializa el array
 * \param array recibido por referencia
 * \param longitud cantidad de elemntos del array
 * \return 0 (ok)  o -1 (error)
 *
 */
int publ_init(sPublicidad* array, int longitud)
{
    int retorno = -1;
    int i;
    if(array != NULL && longitud > 0)
    {
        for(i = 0; i < longitud ; i++)
        {
            array[i].flagEstado = PUBLICIDAD_LIBRE;
        }
    }
    return retorno;
}

/** \brief genera un id autoincrementable
 * \return retorna idAutoincrementable
 *
 */
static int idPublicidad = -1;

int publ_generarProximoId(void)
{
    idPublicidad++;
    return idPublicidad;
}


/**
 * \brief Busca un índice libre en el array de Contrataciones
 * \param array Es el array a analizar
 * \param longitud cantidad de elementos del array
 * \return retorna el indice, o -1 en caso de error
 */
int publ_buscarIndiceLibre(sPublicidad* array, int longitud)
{
    int retorno = -1;
    int i;
    if(array != NULL && longitud > 0)
    {
        for(i = 0; i < longitud ; i++)
        {
            if(array[i].flagEstado == PUBLICIDAD_LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
