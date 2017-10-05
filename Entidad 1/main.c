#include <stdio.h>
#include <stdlib.h>
#include "entidad 1.h"
#include "entidad 2.h"
#include "validacion.h"
#define LONGITUD_ENTIDADES1 50
#define LONGITUD_ENTIDADES2 50


int main()
{
    sEntidad1 listaentidades1[LONGITUD_ENTIDADES1];
    sEntidad2 listaentidades2[LONGITUD_ENTIDADES2];

    ent1_init(listaentidades1,LONGITUD_ENTIDADES1);
    ent2_init(listaentidades2,LONGITUD_ENTIDADES2);

    while(1)
    {
        printf("1-OPCION 1");
        printf("1-OPCION 2");
        printf("1-OPCION 3");

        char opcion [50];
        if(val_getUnsignedInt(opcion,"Elija: ","ERROR",3,50)== 0)
        {
            int op =atoi(opcion);
            switch(op)
            {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
            }
        }

    }
    return 0;
}
