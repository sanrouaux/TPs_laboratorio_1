#ifndef INGRESODATOS_H_INCLUDED
#define INGRESODATOS_H_INCLUDED

int ingresaEntero(char mensaje[], int max, int min);
float ingresaFlotante (char mensaje[]);
char ingresaCaracter(char mensaje[]);

char pideYValidaSiNo(void);

int ingresaCadena(char cadena[], char mensaje[], int largo);
int ingresaCadenaSoloLetras(char cadena[], char mensaje[], int largo);

int ubicaMayusculasYMinusculas(char cadena[]);

#endif // INGRESODATOS_H_INCLUDED
