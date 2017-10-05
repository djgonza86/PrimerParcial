#include <stdio.h>
#include <stdlib.h>
#include "entidad 1.h"
#include "entidad 2.h"
#include "informes.h"

void imprimirTodo(sEntidad1 arrayEntidad1[], int lenEntidad1, sEntidad2 arrayEntidad2[], int lenEntidad2)
{
    int indiceE2;
    int i;
    for(i=0; i<lenEntidad2; i++)
    {
        if(arrayEntidad2[indiceE2].flagEstadoOcupado == 1)
        {
            int idE1 =  arrayEntidad2[indiceE2].idEntidad1;
            int indiceE1 = ent1_buscarIndicePorId(arrayEntidad1,lenEntidad1,idE1);

            printf("%d \t%s | %d \t%s", arrayEntidad1[indiceE1].id, arrayEntidad1[indiceE1].a, arrayEntidad2[indiceE2].id, arrayEntidad2[indiceE2].a);

        }
    }
}


/** \brief Insercion. Sirve para usarlo tanto en int como en char.
 *
 * \param Recibe el array
 * \param Recibe la longitud
 * \return No devuelve nada
 *
 */
void ordenarPorInsercion(sEntidad1* array, int len)
{
    char bufferNombre[CANTIDAD_CHAR];
    int bufferEdad;
    int i,j;

    for( i=0; i<len-1; i++)
    {
        for(j = i+1; j<len; j++)
        {
            if(array[i].flagEstadoOcupado == FLAG_ESTADO_OCUPADO && array[j].flagEstadoOcupado == FLAG_ESTADO_OCUPADO)
            {
                if(strcmp(array[i].a, array[j].a)>0)
                {
                    strcpy(bufferNombre,array[i].a);
                    strcpy(array[i].a, array[j].a);
                    strcpy(array[j].a, bufferNombre);

                    bufferEdad = array[i].b;
                    array[i].b = array[j].b;
                    array[j].b = bufferEdad;
                }
            }
        }
    }
}


