#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"


/** \brief valida el largo de una cadena de caracteres
 *
 * \param cadena[] char Cadena a ser medida
 * \param largoMaximo int Largo maximo que puede tener la cadena, incluyendo al caracter de cierre
 * \return int retorna 1 si el largo es valido, y 0 si el largo no es valido, y -1 si no se introdujeron caracteres
 *
 */
int validaLargoCadena(char* cadena, int largoMaximo)
{
    int retorno = 1;
    if(strlen(cadena) > largoMaximo)
    {
        retorno = -1;
    }
    else if(strlen(cadena) == 0)
    {
        retorno = 0;
    }
    return retorno;
}



/** \brief valida si un numero entero respeta el maximo y el minimo permitido
 *
 * \param numero int numero elegido
 * \param maximo int maximo permitido
 * \param minimo int minimo permitido
 * \return int 1 si esta dentro del rango; 0 si no lo esta
 *
 */
int validaRangoEntero(int numero, int max, int min)
{
    int retorno = 1;
    if(numero < min || numero > max)
    {
        retorno = 0;
    }
    return retorno;
}


/** \brief valida si un numero respeta el maximo y el minimo permitido
 *
 * \param numero float numero elegido
 * \param maximo float maximo permitido
 * \param minimo float minimo permitido
 * \return float 1 si esta dentro del rango; 0 si no lo esta
 *
 */
float validaRangoFlotante(float numero, float max, float min)
{
    int retorno = 1;
    if(numero < min || numero > max)
    {
        retorno = 0;
    }
    return retorno;
}


/** \brief comprueba si una cadena de caracteres tiene todos sus elementos numericos
 *
 * \param cadena[] char cadena a analizar
 * \return int retorna '1' si la comprobacion es positivo, '0' si es negativa
 *
 */
int validaSoloNumeros(char* cadena)
{
    int retorno = 1;

    int largo;
    largo = strlen(cadena);

    int i;
    for(i=0; i<largo; i++)
    {
        if((cadena[i] < 48 || cadena[i] > 57) && cadena[i] != '-' && cadena[i] != '.')
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}


/** \brief comprueba si una cadena de caracteres tiene todos sus elementos alfabeticos
 *
 * \param char[] cadena a ser evaluada
 * \return int devuelve '1' si la comprobacion es positiva; '0' si es negativa
 *
 */
int validaSoloLetras(char* cadena)
{

    int retorno = 1;

    int largo;
    largo = strlen(cadena);

    int i;
    for(i=0; i<largo; i++)
    {
        if((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && cadena[i] != ' '
           && cadena[i] != ',')
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}


/** \brief comprueba si una cadena de caracteres tiene todos sus elementos alfanumericos
 *
 * \param char[] cadena a ser evaluada
 * \return int devuelve '1' si la comprobacion es positiva; '0' si es negativa
 *
 */
int validaSoloAlfanumericos(char* cadena)
{
    int retorno = 1;

    int largo;
    largo = strlen(cadena);

    int i;
    for(i = 0; i < largo-1; i++)
    {
        if((cadena[i] < '0' || cadena[i] > '9') && cadena[i] != '-' && cadena[i] != '.'
           && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z')
           && cadena[i] != ' ' && cadena[i] != ',')
        {
            retorno= 0;
            break;
        }
    }
    return retorno;
}



/** \brief valida si el usuario introdujo una respuesta correcta: s/n
 *
 * \param respuesta char caracter ingresado por el usuario
 * \return int 1 si la validacion es positiva; 0 si no lo es
 *
 */
int validaSiNo(char respuesta)
{
    int retorno = 1;
    if(respuesta != 's' && respuesta != 'n')
    {
        retorno = 0;
    }
    return retorno;
}
