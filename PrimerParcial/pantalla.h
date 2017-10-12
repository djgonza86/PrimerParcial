#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
typedef struct
{
    int id;
    char tipo[10];
    char nombre[50];
    char direccion[100];
    float precio;
    unsigned char flagEstado;
}sPantalla;

#define PANTALLA_LIBRE 0
#define PANTALLA_OCUPADA 1


int pant_init(sPantalla* array, int longitud);
int pant_generarProximoId(void);
int pant_buscarPosicionLibre(sPantalla* array, int longitud);
int pant_buscarIndicePorId(sPantalla* array, int len, int id);
int pant_cargarPantalla(sPantalla* array, int longitud);
int pant_borrarPantalla(sPantalla* array, int id, int limite);
int pant_modificarPantalla(sPantalla* array, int longitud);


#endif // PANTALLA_H_INCLUDED
