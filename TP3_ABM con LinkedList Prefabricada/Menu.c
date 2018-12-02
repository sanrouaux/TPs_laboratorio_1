#include <stdio.h>
#include <stdlib.h>
#include "ingresoDatos.h"

/** \brief Desplega el menú de opciones y pide al usuario una opción
 *
 * \return int Opción seleccionada por el usuario
 *
 */
int menuDeOpciones()
{
    int option;

    printf("-------------------MENU DE OPCIONES--------------------------\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n");
    printf("Introduzca una opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}


/** \brief Despliega el menú de opciones de datos del empleado a modificar y pide una opción al usuario
 *
 * \return char Caracter seleccionado por el usuario
 *
 */
char menuModificacionEmpleado()
{
    char option;

    puts("Que dato desea cambiar?");
    puts("a. Nombre");
    puts("b. Horas trabajadas");
    puts("c. Sueldo");
    puts("d. Cancelar");
    option = ingresaCaracter("Ingrese una opcion: ");

    return option;
}
