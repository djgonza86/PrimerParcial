#ifndef VALIDACION_H_INCLUDED
#define VALIDACION_H_INCLUDED

#endif // VALIDACION_H_INCLUDED


void myFgets(char* buffer, int limite,FILE* archivo);

int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getFloat(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarNombre(char* buffer);
int val_validarFloat(char* buffer);
int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarUnsignedInt(char* buffer);
int val_getDesc(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarDesc(char* buffer);
