#include <stdio.h>
#include <stdlib.h>
#include "miLibreria.h"

int main()
{
    int opcionMenu;
    float numeroUno;
    float numeroDos;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    long long int resultadoFactorialUno;
    long long int resultadoFactorialDos;
    int banderaUno = 0;
    int banderaDos = 0;
    int banderaTres = 0;


    do
    {
        printf("----------CALCULADORA----------------\n");
        printf("--------------MENU-------------------\n");
        printf("1. Ingresar primer operando (A=%.2f)\n", numeroUno);
        printf("2. Ingresar segundo operando (B=%.2f)\n", numeroDos);
        printf("3. Calcular todas las operaciones\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n");
        printf("-------------------------------------\n");
        printf("%cQu%c acci%cn desea realizar?\n",168,130,162);
        printf("Ingrese una opci%cn: ",162);
        scanf("%d", &opcionMenu);
        printf("\n");


        switch(opcionMenu)
        {
        case 1:
            numeroUno = ingresarNumero("Ingrese el primer operando: ");
            printf("\nHas ingresado el %.2f\n\n", numeroUno);
            banderaUno = 1;
            system("pause");
            break;

        case 2:
            if(banderaUno == 0)
            {
                printf("Error. A%cn debe ingresar el primer operando. Seleccione la opci%cn 1\n\n",163,162);
            }
            else
            {
                numeroDos = ingresarNumero("Ingrese el segundo operando: ");
                printf("\nHas ingresado el %.2f\n\n", numeroDos);
                banderaDos = 1;
            }
            system("pause");
            break;

        case 3:
            if(banderaDos == 0)
            {
                printf("Error. A%cn no ingres%c todos los operandos. Seleccione la opci%cn 1 o 2\n\n",163,162,162);
            }
            else
            {
                resultadoSuma = sumar(numeroUno, numeroDos);
                resultadoResta = restar(numeroUno, numeroDos);

                if(numeroDos != 0)
                {
                    resultadoDivision = dividir(numeroUno, numeroDos);
                }

                resultadoMultiplicacion = multiplicar(numeroUno, numeroDos);

                if(numeroUno >= 0 && identificaDecimal(numeroUno) == 0)
                {
                    resultadoFactorialUno = calcularFactorial(numeroUno);
                }

                if(numeroDos >= 0 && identificaDecimal(numeroDos) == 0)
                {
                    resultadoFactorialDos = calcularFactorial(numeroDos);
                }

                printf("Todas las operaciones fueron realizadas... \n\n");
                banderaTres = 1;

            }
            system("pause");
            break;

        case 4:
            if(banderaTres == 0)
            {
                printf("Error. A%cn no se realizaron las operaciones. Seleccione la opci%cn 3\n\n",163,162);
            }
            else
            {
                printf("-------------RESULTADOS---------------\n");
                printf("El resultado de %.2f + %.2f es: %.2f", numeroUno, numeroDos, resultadoSuma);
                printf("\nEl resultado de %.2f - %.2f es: %.2f", numeroUno, numeroDos, resultadoResta);

                if(numeroDos != 0)
                {
                    printf("\nEl resultado de %.2f / %.2f es: %.2f", numeroUno, numeroDos, resultadoDivision);
                }
                else
                {
                    printf("\nNo es posible hacer %.2f / %.2f", numeroUno, numeroDos);
                }

                printf("\nEl resultado de %.2f * %.2f es: %.2f", numeroUno, numeroDos, resultadoMultiplicacion);

                if(numeroUno >= 0 && identificaDecimal(numeroUno) == 0)
                {
                    printf("\nEl factorial de %.2f es: %I64d", numeroUno, resultadoFactorialUno);
                }
                else
                {
                    printf("\nNo se puede calcular el factorial de %.2f", numeroUno);
                }

                if(numeroDos >= 0 && identificaDecimal(numeroDos) == 0)
                {
                    printf(" y el factorial de %.2f es: %I64d\n\n", numeroDos, resultadoFactorialDos);
                }
                else
                {
                    printf(" y no se puede calcular el factorial de %.2f\n\n", numeroDos);
                }

                resultadoSuma = 0;
                resultadoResta = 0;
                resultadoDivision = 0;
                resultadoMultiplicacion = 0;
                resultadoFactorialUno = 0;
                resultadoFactorialDos = 0;
                numeroUno = 0;
                numeroDos = 0;
                banderaUno = 0;
                banderaDos = 0;
                banderaTres = 0;
            }
            system("pause");
            break;

        case 5:
            printf("GRACIAS POR UTILIZAR LA CALCULADORA\n");
            printf("----------HASTA LUEGO--------------\n\n");
            system("pause");
            break;

        default:
            printf("No ingres%c una opci%cn v%clida\n\n",162,162,160);
            system("pause");

        }

        system("cls");

    }
    while(opcionMenu != 5);

    return 0;
}



