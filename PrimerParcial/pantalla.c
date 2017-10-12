#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "publicidad.h"
#include "validar.h"
#define INTENTOS 3


/** \brief inicializa el array
 * \param array recibido por referencia
 * \param longitud cantidad de elemntos del array
 * \return 0 (ok)  o -1 (error)
 *
 */
int pant_init(sPantalla* array, int longitud)
{
    int retorno = -1;
    int i;
    if(array != NULL && longitud > 0)
    {
        for(i = 0; i < longitud ; i++)
        {
            array[i].flagEstado = PANTALLA_LIBRE;
        }

    }
    return retorno;
}


/** \brief genera un id autoincrementable
 * \return retorna idAutoincrementable
 *
 */
static int idAutoincrementable = -1;

int pant_generarProximoId(void)
{
    idAutoincrementable++;
    return idAutoincrementable;
}


/**
* \brief Busca un indice libre
* \param array Corresponde a la posicion de memoria del array
* \param longitud Es la cantidad de elementos que contiene el array
* \return 0(ok) o -1 (error)
*
*/
int pant_buscarPosicionLibre(sPantalla* array, int longitud)
{
    int retorno = -1;
    int i;
    if(array != NULL && longitud > 0)
    {
        for(i = 0; i < longitud ; i++)
        {
            if(array[i].flagEstado == PANTALLA_LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief realiza la toma de datos validando y almacenando cada uno
 * \param array puntero al array
 * \param longitud cantidad de elementos del array
 * \return 0 (ok) o -1(error)
 *
 */
int pant_cargarPantalla(sPantalla* array, int longitud)
{
    int retorno = -1;
    int indice = pant_generarProximoId();
    char bufferNombre[50];
    char bufferDireccion[100];
    char bufferPrecio[20];
    char auxiliarTipo[5];

    if(array != NULL && longitud >= 0)
    {

        if(val_getString(bufferNombre,"\nIngrese el nombre de la pantalla: \n","\nError!\n",INTENTOS,50)==0)
        {
            if(val_getAlfanumerico(bufferDireccion, "\nIngrese la direccion: \n","\nError\n",INTENTOS,100)== 0)
            {
                if(val_getFloat(bufferPrecio,"\nIngrese el precio por dia: \n","\nError\n",INTENTOS,50)==0)
                {
                    if(val_getString(auxiliarTipo,"\nIngrese el tipo de pantalla: LED o LCD\n","\nError\n",INTENTOS,50)==0)
                    {
                        strncpy(array[indice].nombre,bufferNombre,51);
                        strncpy(array[indice].direccion,bufferDireccion,100);
                        array[indice].precio = atof(bufferPrecio);
                        strncpy(array[indice].tipo,auxiliarTipo,5);
                        array[indice].id = pant_generarProximoId();
                        array[indice].flagEstado = PANTALLA_OCUPADA;
                        retorno = 0;

                    }
                }
            }
        }
    }
    return retorno;
}


/** \brief recorre array busca el indice que coincida con el id pasado como parametro
 * \param array puntero al array
 * \param longitud Es la cantidad de elementos del array
 * \param id recibido por parametro para buscar indice
 * \param mensaje para el usuario
 * \return 0 OK  o -1 error
 *
 */
int pant_buscarIndicePorId(sPantalla* array, int longitud, int id)
{
    int i;
    int retorno = -1;
    if(array != NULL && longitud > 0 && id >0)
    {
        for(i = 0; i < longitud ; i++)
        {
            if(array[i].flagEstado == PANTALLA_OCUPADA)
            {
                if(array[i].id == id);
                {
                    retorno = i;
                    break;
                }
            }
        }

        if(retorno == -1)
        {
            printf("\n  ID NO ENCONTRADO \n");
        }
    }
    return retorno;
}


/** \brief Funcion para modificar un campo, reescribiendo sus datos.
 *
 * \param array Recibe el array.
 * \param longitud Recibe la longitud.
 * \return Devuelve -1(no esta ok) y 0(ok)
 *
 */
int pant_modificarPantalla(sPantalla* array, int longitud)
{
    int retorno = -1;
    int indice;
    char bufferNombre[51];
    char bufferDireccion[100];
    char bufferPrecio[10];
    int idAuxiliar;
    char buffer[10];
    char auxTipo[10];

    val_getUnsignedInt(buffer,"\nIngrese el ID de pantalla: ", "\nEl ID no se encontro",3,10);
    idAuxiliar = atoi(buffer);
    indice = pant_buscarIndicePorId(array,longitud,idAuxiliar);

    if(indice != -1)
    {
        if(val_getString(bufferNombre,"\nIngrese el nombre de la pantalla: \n","\nError!\n",INTENTOS,50)==0)
        {
            if(val_getAlfanumerico(bufferDireccion, "\nIngrese la direccion: \n","\nError!\n",INTENTOS,100)== 0)
            {
                if(val_getFloat(bufferPrecio,"\nIngrese el precio por dia: \n","\nError!\n",INTENTOS,50)==0)
                {
                    if(val_getString(auxTipo,"\nIngrese el tipo de pantalla: LED o LCD\n","\nError!\n",INTENTOS,50)==0)
                    {
                        strncpy(array[indice].nombre,bufferNombre,51);
                        strncpy(array[indice].direccion,bufferDireccion,100);
                        array[indice].precio = atof(bufferPrecio);
                        strncpy(array[indice].tipo,auxTipo,5);
                        retorno = 0;
                    }
                }
            }
        }
    }
    return retorno;
}


/** \brief Cambia el estado para "borrar" el elemento
 *
 * \param array es el array que recibe
 * \param longitud la cantidad de elementos para el array
 * \return 0 (ok) , -1(error)
 *
 */
int pant_borrarPantalla(sPantalla* array, int id, int longitud)
{
    int retorno = -1;
    int i = 0;

    if(array != NULL && longitud > 0)
    {
        for(i = 0; i < longitud ; i++)
        {
            if(array[i].flagEstado == PANTALLA_OCUPADA && array[i].id == id)
            {
                array[i].flagEstado = PANTALLA_LIBRE;
                printf("\nBorrado\n");
                retorno = 0;
            }
        }
    }
    return retorno;
}
