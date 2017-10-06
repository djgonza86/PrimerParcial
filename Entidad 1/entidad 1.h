#ifndef ENTIDAD_1_H_INCLUDED
#define ENTIDAD_1_H_INCLUDED
typedef struct
{
    int id;
    unsigned int flagEstadoOcupado;
    char nombreLcd[50];
    char direccionLcd [50];
    float precioLcd ;
} sPantallaLcd;

#endif // ENTIDAD_1_H_INCLUDED

#define FLAG_ESTADO_OCUPADO 1
#define FLAG_ESTADO_LIBRE 0
#define INTENTOS 2
#define CANTIDAD_CHAR 50

int pLcd_init(sPantallaLcd* arrayLcd, int len);
int pLcd_alta(sPantallaLcd* arrayLcd, int len);
int pLcd_modificar(sPantallaLcd* arrayLcd, int len, int id);
int pLcd_baja(sPantallaLcd* arrayLcd,int len, int id);
int pLcd_buscarIndicePorId(sPantallaLcd* arrayLcd, int len, int id);
int pLcd_obtenerId(sPantallaLcd* arrayLcd, int len);


