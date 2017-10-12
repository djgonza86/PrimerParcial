#ifndef PUBLICIDAD_H_INCLUDED
#define PUBLICIDAD_H_INCLUDED

typedef struct
{
    int idCliente;
    unsigned char flagEstado;
    char cuit[20];
    int dias;
    char nombreArchivoVideo[50];
} sPublicidad;

#define PUBLICIDAD_LIBRE 0
#define PUBLICIDAD_EN_CURSO 1
#define PUBLICIDAD_FINALIZADA 2


int publ_init(sPublicidad* array, int longitud);
int publ_generarProximoId(void);
int publ_buscarIndiceLibre(sPublicidad* array, int longitud);


#endif // PUBLICIDAD_H_INCLUDED
