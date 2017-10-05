#ifndef ENTIDAD_1_H_INCLUDED
#define ENTIDAD_1_H_INCLUDED
typedef struct
{
    int id;
    int flagEstadoOcupado;
    char a[50];
    int b;
} sEntidad1;

#endif // ENTIDAD_1_H_INCLUDED

#define FLAG_ESTADO_OCUPADO 1
#define FLAG_ESTADO_LIBRE 0

int ent1_init(sEntidad1* array, int len);
int ent1_alta(sEntidad1* array, int len);
int ent1_modificar (sEntidad1* array, int len, int id);
int ent1_baja(sEntidad1* array,int len, int id);
int ent1_buscarIndicePorDni(sEntidad1* array, int len, char dni[]);
int ent1_buscarIndicePorId(sEntidad1* array, int len, int id);

