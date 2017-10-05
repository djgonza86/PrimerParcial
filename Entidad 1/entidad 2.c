#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entidad 2.h"
#include "validacion.h"

static int ent2_generarProximoId(sEntidad2 array[], int len);
static int ent2_buscarPosicionLibre(sEntidad2 array[], int len);

/** \brief Inicializa las posiciones del array.
 *
 * \param array Recibe el array
 * \param len Recibe la longitud
 * \return Devuelve un -1(no esta ok) y 0(ok)
 *
 */
int ent2_init(sEntidad2* array, int len)
{
    int retorno = -1;
    int i;
    if(array!= NULL && len > 0)
    {
        for(i=0; i<len ; i++)
        {
            array[i].flagEstadoOcupado = FLAG_ESTADO_LIBRE;
            retorno = 0;
        }
    }
    return retorno;
}



/** \brief Genera un ID que se autoincrementa.
 *
 * \param array Recibe el array
 * \param len Recibe la longitud
 * \return Devuelve el proximo ID
 *
 */
static int ent2_generarProximoId(sEntidad2* array, int len) // funcion primitiva, la de entidad1 es nueva
{
    int i, bId = -1;
    int retorno = -1;
    if(array != NULL && len > 0)
    {
        for(i=0; i<len ; i++)
        {
            if((array[i].flagEstadoOcupado == FLAG_ESTADO_OCUPADO)&&(array[i].id > bId))
            {
                bId = array[i].id;
            }
        }
        retorno = bId + 1;
    }
    return retorno;
}



/** \brief Busca el primer item vacio dentro de los array.
 *
 * \param array Recibe el array
 * \param len Recibe la longitud
 * \return Devuelve el indice del primer item vacio que encuentra.
 *
 */
static int ent2_buscarPosicionLibre(sEntidad2* array, int len)
{
    // me devuelve el index del primer item
    //vacio del array
    //La voy a usar para el ALTA.

    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0; i<len ; i++)
        {
            if(array[i].flagEstadoOcupado == FLAG_ESTADO_LIBRE)
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
 * \param array Recibe el array.
 * \param len Recibe la longitud.
 * \return Devuelve -1(no esta ok) y 0(ok)
 *
 */
int ent2_alta(sEntidad2* array, int len)
{
    int retorno = -1;
    //1.Buscar posicion libre
    int indiceVacio = ent2_buscarPosicionLibre(array, len);

    if(indiceVacio == 0);
    {
        //2. Generar id
        int idNuevo = ent2_generarProximoId(array, len);

        //3.Pedir datos al usuario(validados)
        char bufferAuxNombre[50];
        if(val_getNombre(bufferAuxNombre, "Ingrese nombre", "Nombre invalido",3,50)== 0);
        // Campo bien cargado
        //4.Cargar datos en items vacios
        {
            array[indiceVacio].flagEstadoOcupado = 1;
            array[indiceVacio].id = idNuevo;
            strncpy(array[indiceVacio].a,bufferAuxNombre,50);
            retorno = 0;
        }
    }
    return retorno;
}


/** \brief Se busca mediante el ID la posicion del mismo y se cambia el FlagEstado
 *
 * \param array Recibe el array
 * \param len Recibe la longitud
 * \param id Recibe el ID
 * \return Devuelve -1(no esta ok) y 0(ok)
 *
 */
int ent2_baja(sEntidad2* array, int len, int id)
{
    int retorno = -1;
    int i = 0;

    if(array != NULL && len > 0)
    {
        for(i=0; i<len ; i++)
        {
            if(array[i].flagEstadoOcupado == FLAG_ESTADO_OCUPADO && array[i].id == id)
            {
                array[i].flagEstadoOcupado = FLAG_ESTADO_LIBRE;
                printf("\nBorrado\n");
                retorno=0;
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
int ent2_modificar(sEntidad2* array, int len, int id)
{
    int retorno = -1;
    //1.Busco la posicion donde esta el id
    int indice = ent2_buscarIndicePorId(array,len,id);
    if(indice >= 0)
    {
        //el id esta
        //2.Pido datos nuevos
        char bufferAux[50];
        if(val_getUnsignedInt(bufferAux,"Ingrese edad","ERROR",3,50)== 0);
        {
            //3.Cargo en los campos
            array[indice].b = atoi(bufferAux);
            retorno = 0;
        }
    }
    return retorno;
}
