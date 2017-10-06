#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entidad 1.h"
#include "validacion.h"

static int ultimoValorIdAutoincrementable = -1;
static int pLcd_generarProximoId(sPantallaLcd* arrayLcd, int len);
static int pLcd_buscarPosicionLibre(sPantallaLcd* arrayLcd, int len);


/** \brief Inicializa las posiciones del array.
 *
 * \param arrayLcd Recibe el array
 * \param len Recibe la longitud
 * \return Devuelve un -1(no esta ok) y 0(ok)
 *
 */
int pLcd_init(sPantallaLcd* arrayLcd, int len)
{
    int retorno = -1;
    int i;
    if(arrayLcd != NULL && len > 0)
    {
        for(i = 0; i < len ; i++)
        {
            arrayLcd[i].flagEstadoOcupado = FLAG_ESTADO_LIBRE;
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
static int pLcd_generarProximoId(sPantallaLcd* arrayLcd, int len)
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
static int pLcd_buscarPosicionLibre(sPantallaLcd* arrayLcd, int len)
{
    // me devuelve el indice del primer item         //
    //vacio del array                                   BORRARRRR!
    //La voy a usar para el ALTA.                    //

    int retorno = -1;
    int i;
    if(arrayLcd != NULL && len > 0)
    {
        for(i = 0; i < len ; i++)
        {
            if(arrayLcd[i].flagEstadoOcupado == FLAG_ESTADO_LIBRE)
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
int pLcd_alta(sPantallaLcd* arrayLcd, int len)
{
    int retorno = -1;
    //1.Buscar posicion libre
    int indiceVacio = pLcd_buscarPosicionLibre(arrayLcd, len);

    if(indiceVacio == 0);
    {
        //2. Generar id
        int idNuevo = pLcd_generarProximoId(arrayLcd,len);

        //3.Pedir datos al usuario(validados)
        char bufferNombre[CANTIDAD_CHAR];
        char bufferDireccion[CANTIDAD_CHAR];
        char bufferPrecio[CANTIDAD_CHAR];

        if(val_getNombre(bufferNombre, "Ingrese Nombre: \n", "\nNombre no valido",INTENTOS,CANTIDAD_CHAR)== 0)
        {
            if(val_getDesc(bufferDireccion, "Ingrese Direccion: \n", "Direccion no valida", INTENTOS, CANTIDAD_CHAR) == 0)
            {
                if(val_getFloat(bufferPrecio, "Ingrese Precio: \n", "Precio no valido", INTENTOS, CANTIDAD_CHAR) == 0)
                {
                    arrayLcd[indiceVacio].flagEstadoOcupado = 1;
                    arrayLcd[indiceVacio].id = idNuevo;
                    strncpy(arrayLcd[indiceVacio].nombreLcd,bufferNombre,CANTIDAD_CHAR);
                    strncpy(arrayLcd[indiceVacio].direccionLcd,bufferDireccion,CANTIDAD_CHAR);
                    arrayLcd[indiceVacio].precioLcd = atof(bufferPrecio);
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
int pLcd_buscarIndicePorId(sPantallaLcd* arrayLcd, int len, int id)
{
    int i;
    int retorno = -1;
    if(arrayLcd != NULL && len > 0 && id > 0)
    {
        for(i = 0; i < len ; i++)
        {
            if(arrayLcd[i].flagEstadoOcupado == FLAG_ESTADO_OCUPADO)
            {
                if(arrayLcd[i].id == id);
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
int pLcd_modificar(sPantallaLcd* arrayLcd, int len, int id)
{
    int retorno = -1;
    //1.Busco la posicion donde esta el id
    int indice = pLcd_buscarIndicePorId(arrayLcd,len,id);
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
                    strncpy(arrayLcd[indice].nombreLcd,bufferNombre,CANTIDAD_CHAR);
                    strncpy(arrayLcd[indice].direccionLcd,bufferDireccion,CANTIDAD_CHAR);
                    arrayLcd[indice].precioLcd = atof(bufferPrecio);
                    retorno = 0;
                }
            }

        }


    }return retorno;
}

/** \brief Se busca mediante el ID la posicion del mismo y se cambia el FlagEstado
 *
 * \param arrayLcd Recibe el array
 * \param len Recibe la longitud
 * \param id Recibe el ID
 * \return Devuelve -1(no esta ok) y 0(ok)
 *
 */
int pLcd_baja(sPantallaLcd* arrayLcd, int len, int id)
{
    int retorno = -1;
    int i = 0;

    if(arrayLcd != NULL && len > 0)
    {
        for(i = 0; i < len ; i++)
        {
            if(arrayLcd[i].flagEstadoOcupado == FLAG_ESTADO_OCUPADO && arrayLcd[i].id == id)
            {
                arrayLcd[i].flagEstadoOcupado = FLAG_ESTADO_LIBRE;
                printf("\nEliminado");
                retorno=0;
            }
        }
    }
    return retorno;
}
/** \brief Recorro el array para obtener un id
 *
 * \param arrayLcd Recibe el array
 * \param len Recibe la longitud
 * \return retorno Me devuelve el id
 *
 */

int pLcd_obtenerId(sPantallaLcd* arrayLcd, int len)
{
    int i, bId = -1;
    int retorno = -1;
    if(arrayLcd != NULL && len > 0)
    {
        for(i = 0; i < len ; i++)
        {
            if((arrayLcd[i].flagEstadoOcupado == FLAG_ESTADO_OCUPADO)&&(arrayLcd[i].id> bId))
            {
                bId = arrayLcd[i].id;
            }
        }
        retorno = bId + 1;
    }
    return retorno;
}









