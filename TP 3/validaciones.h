#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

int validaLargoCadena(char* cadena, int largoMaximo);

int validaRangoEntero(int numero, int max, int min);
float validaRangoFlotante(float numero, float max, float min);

int validaSoloNumeros(char* cadena);
int validaSoloLetras(char* cadena);
int validaSoloAlfanumericos(char* cadena);

int validaSiNo(char respuesta);

#endif // VALIDACIONES_H_INCLUDED
