#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ingresoDatos.h"
#include "validaciones.h"


/** \brief pide un numero al usuario, valida que esté dentro del rango de un int, que no haya caracteres
 *         que no sean numericos y que el numero entre dentro de un rango establecido por el usuario
 *
 * \param mensaje[] char mensaje que será mostrado al usuario
 * \param max int Numero maximo elegible
 * \param min int Numero minimo elegible
 * \return int número ingresado por el usuario
 *
 */
int ingresaEntero(char mensaje[], int max, int min)
{
    int numero;
    char buffer[11];

    int banderaLargo;
    int banderaSoloNumeros;
    int banderaRango;

    puts(mensaje);
    fflush(stdin);
    gets(buffer);

    do
    {
        banderaSoloNumeros = 0;
        banderaLargo = 0;
        banderaRango = 0;

        if(validaSoloNumeros(buffer) == 0)
        {
            puts("Error. Ingreso caracteres invalidos.");
            banderaSoloNumeros = 1;
        }

        if(banderaSoloNumeros == 0 && validaLargoCadena(buffer, 10) != 1)
        {
            if(validaLargoCadena(buffer, 10)==0)
            {
                 puts("Error. Demasiados digitos.");
                 banderaLargo = 1;
            }
            else
            {
                puts("Error. No se introdujo ningun digito.");
                banderaLargo = 1;
            }
        }

        numero = atoi(buffer);
        if(banderaSoloNumeros == 0 && banderaLargo == 0 && validaRangoEntero(numero, max, min) == 0)
        {
            puts("Error. Numero fuera de rango.");
            banderaRango = 1;
        }

        if(banderaSoloNumeros == 1 || banderaLargo == 1 || banderaRango == 1)
        {
            puts("Ingrese el numero nuevamente: ");
            fflush(stdin);
            gets(buffer);
        }
    }
    while(banderaSoloNumeros == 1 || banderaLargo == 1 || banderaRango == 1);

    return numero;
}


/** \brief pide un numero al usuario y lo retorna
 *
 * \param mensaje[] char mensaje que será mostrado al usuario
 * \return float número ingresado por el usuario
 *
 */
float ingresaFlotante(char mensaje[])
{
    float numero;
    char buffer[15];

    printf("%s", mensaje);
    fflush(stdin);
    gets(buffer);

    while(validaSoloNumeros(buffer) == 0)
    {
        puts("Ingreso caracteres invalidos. Reingrese el numero: ");
        fflush(stdin);
        gets(buffer);
    }

    numero = atof(buffer);

    return numero;
}


/** \brief pide un carcater al usuario y lo retorna
 *
 * \param mensaje[] char mensaje que será mostrado al usuario
 * \return char caracter ingresado por el usuario
 *
 */
char ingresaCaracter(char mensaje[])
{
    char caracter;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &caracter);
    return caracter;
}


/** \brief Queda a la espera de un caracter de confirmación: s/n. Repite el proceso hasta que se introduzca un caracter válido
 *
 * \return char Caracter introducido por el usuario
 *
 */
char pideYValidaSiNo()
{
    char letra;
    fflush(stdin);
    letra = getchar();

    while(letra != 's' && letra != 'n')
    {
        puts("Ingrese una opcion correcta: s/n");
        fflush(stdin);
        letra = getchar();
    }
    return letra;
}


/** \brief Pide al usuario una cadena de caracteres y valida que no sobrepase el largo indicado
 *
 * \param cadena[] char Puntero al lugar donde será guardada la cadena
 * \param mensaje[] char Mensaje que pedirá el dato al usuario
 * \param largo int Largo maximo que puede tomar la cadena
 * \return int
 *
 */
int ingresaCadena(char* cadena, char mensaje[], int largo)
{
    char buffer[1024];
    int validacion;

    puts(mensaje);
    gets(buffer);

    validacion = validaLargoCadena(buffer, largo);

    while(validacion != 1)
    {
        if(validacion == -1)
        {
            puts("Demasiados carcateres. Ingrese nuevamente");
            fflush(stdin);
            gets(buffer);
            validacion = validaLargoCadena(buffer, largo);
        }
        else
        {
            puts("No ingreso ningun caracter. Ingrese nuevamente");
            fflush(stdin);
            gets(buffer);
            validacion = validaLargoCadena(buffer, largo);
        }
    }
    strcpy(cadena, buffer);
    return 0;
}


/** \brief Pide al usuario una cadena alfabética, valida que conste únicamente de letras y que no sobrepase el largo indicado
 *
 * \param cadena[] char Puntero al lugar en el que será guardada la cadena
 * \param mensaje[] char Mensaje que se mostrará para pedir el dato al usuario
 * \param largo int Largo maximo que puede tomar la cadena
 * \return int
 *
 */
int ingresaCadenaSoloLetras(char cadena[], char mensaje[], int largo)
{
    char buffer[1024];
    int validacionLargo;
    int validacionCaracteres;

    puts(mensaje);
    fflush(stdin);
    gets(buffer);

    validacionLargo = validaLargoCadena(buffer, largo);
    validacionCaracteres = validaSoloLetras(buffer);

    while(validacionLargo != 1 || validacionCaracteres != 1)
    {
        if(validacionLargo == -1)
        {
            puts("Demasiados carcateres");
        }

        if(validacionLargo == 0)
        {
            puts("No ingreso ningun caracter");
        }

        if(validacionCaracteres == 0)
        {
            puts("Ingreso caracteres invalidos");
        }

        puts("Ingrese nuevamente: ");
        fflush(stdin);
        gets(buffer);
        validacionLargo = validaLargoCadena(buffer, largo);
        validacionCaracteres = validaSoloLetras(buffer);
    }

    strcpy(cadena, buffer);
    return 0;
}


/** \brief En una cadena de caracteres alfabético, pone mayúscula a la primera letra de cada palabra y minúsculas al resto
 *
 * \param arrayLetras[] char Array de caracteres sobre el que se hará la modificación
 * \return int "-1" si el puntero al array es nulo y "1" si se logra hacer las modificaciones
 *
 */
int ubicaMayusculasYMinusculas(char cadena[])
{
    int retorno = -1;
    if(cadena != NULL)
    {
        retorno = 1;
        strlwr(cadena);
        cadena[0] = toupper(cadena[0]);

        int largoCadena;
        largoCadena = strlen(cadena);

        int i;
        for(i = 1; i < largoCadena; i++)
        {
            if(cadena[i] == ' ')
            {
                cadena[i+1] = toupper(cadena[i+1]);
            }
        }
    }
    return retorno;
}
