#ifndef ENTIDAD_2_H_INCLUDED
#define ENTIDAD_2_H_INCLUDED
typedef struct
{
    int id;
    int flagEstadoOcupado;
    char nombreLed[50];
    char direccionLed[50];
    float precioLed;
    int id_PantallaLcd;
}sPAntallaLed;

#endif // ENTIDAD_2_H_INCLUDED

#define FLAG_ESTADO_OCUPADO 1
#define FLAG_ESTADO_LIBRE 0
#define INTENTOS 2
#define CANTIDAD_CHAR 50

int pLed_init(sPAntallaLed* arrayLed, int len);
int pLed_alta(sPAntallaLed* arrayLed, int len);
int pLed_modificar(sPAntallaLed* arrayLed, int len, int id);
int pLed_baja(sPAntallaLed* arrayLed, int len, int id);
int pLed_buscarIndicePorId(sPAntallaLed* arrayLed, int len, int id);
