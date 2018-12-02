#include <stdio.h>
#include <stdlib.h>
#include "miLibreria.h"


/** \brief pide un n�mero al usuario y lo retorna
 *
 * \param mensaje[] char mensaje que ser� mostrado al usuario
 * \return float n�mero ingresado por el usuario
 *
 */
float ingresarNumero(char mensaje[])
{
    float numero;
    printf("%s", mensaje);
    scanf("%f", &numero);
    return numero;
}


/** \brief realiza la suma de dos n�meros
 *
 * \param numeroUno float primer operando de la suma
 * \param numeroDos float segundo operando de la suma
 * \return float resultado de la suma
 *
 */
float sumar(float numeroUno, float numeroDos)
{
    float resultado;
    resultado = numeroUno + numeroDos;
    return resultado;
}


/** \brief realiza una resta entre dos n�meros
 *
 * \param numeroUno float primer operando de la resta
 * \param numeroDos float segundo operando de la resta
 * \return float resultado de la resta
 *
 */
float restar(float numeroUno, float numeroDos)
{
    float resultado;
    resultado = numeroUno - numeroDos;
    return resultado;
}


/** \brief realiza una divisi�n entre dos n�meros
 *
 * \param numeroUno float dividendo
 * \param numeroDos float divisor
 * \return float cociente
 *
 */
float dividir(float numeroUno, float numeroDos)
{
    float resultado;
    resultado = numeroUno / numeroDos;
    return resultado;
}


/** \brief multiplica dos n�meros
 *
 * \param numeroUno float primer factor de la multiplicaci�n
 * \param numeroDos float segundo factor de la multiplicaci�n
 * \return float producto de la multiplicaci�n
 *
 */
float multiplicar(float numeroUno, float numeroDos)
{
    float resultado;
    resultado = numeroUno * numeroDos;
    return resultado;
}


/** \brief calcula el factorial de un n�mero entero
 *
 * \param numero float n�mero del cual se calcular� el factorial
 * \return long int resultado de la operaci�n
 *
 */
long long int calcularFactorial(float numero)
{
    int numeroEntero;
    numeroEntero = (int)numero;
    long long int resultado = 1;
    for(int i = numeroEntero; i > 0; i--)
    {
        resultado *= i;
    }
    return resultado;

}


/** \brief identifica si un numero tiene parte decimal o no
 *
 * \param numero float numero sobre el cual evaluara la presencia de decimales
 * \return int 1 si tiene parte decimal y 0 si no
 *
 */
int identificaDecimal(float numero)
{
    int respuesta;
    int numeroEntero;
    numeroEntero = (int)numero;
    if(numero-numeroEntero != 0)
    {
        respuesta = 1;
    }
    else
    {
        respuesta = 0;
    }
    return respuesta;
}
