#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entidad 2.h"
#include "validacion.h"

static int ultimoValorIdAutoincrementable = -1;
static int pLed_generarProximoId(sPAntallaLed* arrayLed, int len);
static int pLed_buscarPosicionLibre(sPAntallaLed* arrayLed, int len);


/** \brief Inicializa las posiciones del array.
 *
 * \param arrayLcd Recibe el array
 * \param len Recibe la longitud
 * \return Devuelve un -1(no esta ok) y 0(ok)
 *
 */
int pLed_init(sPAntallaLed* arrayLed, int len)
{
    int retorno = -1;
    int i;
    if(arrayLed != NULL && len > 0)
    {
        for(i = 0; i < len ; i++)
        {
            arrayLed[i].flagEstadoOcupado = FLAG_ESTADO_LIBRE;
            retorno = 0;
        }
    }
    return retorno;
}


/** \brief Genera un ID que se autoincrementa.
 *
 * \param arrayLcd Recibe el array
 * \param len Recibe la longitud
 * \return Devuelve el proximo ID
 *
 */
static int pLed_generarProximoId(sPAntallaLed* arrayLed, int len)
{
    ultimoValorIdAutoincrementable++;
    return ultimoValorIdAutoincrementable;
}


/** \brief Busca el primer item vacio dentro de los array.
 *
 * \param arrayLcd Recibe el array
 * \param len Recibe la longitud
 * \return Devuelve el indice del primer item vacio que encuentra.
 *
 */
static int pLed_buscarPosicionLibre(sPAntallaLed* arrayLed, int len)
{
    // me devuelve el indice del primer item         //
    //vacio del array                                   BORRARRRR!
    //La voy a usar para el ALTA.                    //

    int retorno = -1;
    int i;
    if(arrayLed != NULL && len > 0)
    {
        for(i = 0; i < len ; i++)
        {
            if(arrayLed[i].flagEstadoOcupado == FLAG_ESTADO_LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Carga los datos en los campos.
 *
 * \param arrayLcd Recibe el array.
 * \param len Recibe la longitud.
 * \return Devuelve -1(no esta ok) y 0(ok)
 *
 */
int pLed_alta(sPAntallaLed* arrayLed, int len)
{
    int retorno = -1;
    //1.Buscar posicion libre
    int indiceVacio = pLed_buscarPosicionLibre(arrayLed, len);

    if(indiceVacio == 0);
    {
        //2. Generar id
        int idNuevo = pLed_generarProximoId(arrayLed,len);

        //3.Pedir datos al usuario(validados)
        char bufferNombre[CANTIDAD_CHAR];
        char bufferDireccion[CANTIDAD_CHAR];
        char bufferPrecio[CANTIDAD_CHAR];

        if(val_getNombre(bufferNombre, "Ingrese Nombre", "Nombre no valido",INTENTOS,CANTIDAD_CHAR)== 0)
        {
            if(val_getDesc(bufferDireccion, "Ingrese Direccion", "Direccion no valida", INTENTOS, CANTIDAD_CHAR) == 0)
            {
                if(val_getFloat(bufferPrecio, "Ingrese Precio", "Precio no valido", INTENTOS, CANTIDAD_CHAR) == 0)
                {
                    arrayLed[indiceVacio].flagEstadoOcupado = 1;
                    arrayLed[indiceVacio].id = idNuevo;
                    strncpy(arrayLed[indiceVacio].nombreLed,bufferNombre,CANTIDAD_CHAR);
                    strncpy(arrayLed[indiceVacio].direccionLed,bufferDireccion,CANTIDAD_CHAR);
                    arrayLed[indiceVacio].precioLed = atof(bufferPrecio);
                    retorno = 0;
                }
            }
        }

    }
    return retorno;
}


/** \brief Recorre el array y busca el indice del item por ID.
 *
 * \param array Recibe el array
 * \param len Recibe la longitud
 * \param id Recibe el ID
 * \return Devuelve el Indice del ID especifico.
 *
 */
int pLed_buscarIndicePorId(sPAntallaLed* arrayLed, int len, int id)
{
    int i;
    int retorno = -1;
    if(arrayLed != NULL && len > 0 && id > 0)
    {
        for(i = 0; i < len ; i++)
        {
            if(arrayLed[i].flagEstadoOcupado == FLAG_ESTADO_OCUPADO)
            {
                if(arrayLed[i].id == id);
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}


/** \brief Se ingresa un ID para buscar el indice y poder modificar los campos en la posicion del mismo.
 *
 * \param array Recibe el array.
 * \param len Recibe la longitud.
 * \param id Recibe el ID.
 * \return Devuelve -1(no esta ok) y 0(ok)
 *
 */
int pLed_modificar(sPAntallaLed* arrayLed, int len, int id)
{
    int retorno = -1;
    //1.Busco la posicion donde esta el id
    int indice = pLed_buscarIndicePorId(arrayLed,len,id);
    if(indice >= 0)
    {
        //el id esta
        //2.Pido datos nuevos
        char bufferNombre[CANTIDAD_CHAR];
        char bufferDireccion[CANTIDAD_CHAR];
        char bufferPrecio[CANTIDAD_CHAR];
        if(val_getNombre(bufferNombre, "Ingrese Nombre", "Nombre no valido",INTENTOS,CANTIDAD_CHAR)== 0)
        {
            if(val_getDesc(bufferDireccion, "Ingrese Direccion", "Direccion no valida", INTENTOS, CANTIDAD_CHAR) == 0)
            {
                if(val_getFloat(bufferPrecio, "Ingrese Precio", "Precio no valido", INTENTOS, CANTIDAD_CHAR) == 0)
                {
                    strncpy(arrayLed[indice].nombreLed,bufferNombre,CANTIDAD_CHAR);
                    strncpy(arrayLed[indice].direccionLed,bufferDireccion,CANTIDAD_CHAR);
                    arrayLed[indice].precioLed = atof(bufferPrecio);
                    retorno = 0;
                }
            }

        }return retorno;

    }
}

/** \brief Se busca mediante el ID la posicion del mismo y se cambia el FlagEstado
 *
 * \param arrayLcd Recibe el array
 * \param len Recibe la longitud
 * \param id Recibe el ID
 * \return Devuelve -1(no esta ok) y 0(ok)
 *
 */
int pLed_baja(sPAntallaLed* arrayLed, int len, int id)
{
    int retorno = -1;
    int i = 0;

    if(arrayLed != NULL && len > 0)
    {
        for(i = 0; i < len ; i++)
        {
            if(arrayLed[i].flagEstadoOcupado == FLAG_ESTADO_OCUPADO && arrayLed[i].id == id)
            {
                arrayLed[i].flagEstadoOcupado = FLAG_ESTADO_LIBRE;
                printf("\nEliminado");
                retorno=0;
            }
        }
    }
    return retorno;
}












