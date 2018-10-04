#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "menu.h"

int menu()
{
    int option;
    printf("MENU DE OPCIONES \n");
    printf("1. Dar de alta a un empleado \n");
    printf("2. Modificar \n");
    printf("3. Baja \n");
    printf("4. Lista \n");
    printf("5. Salir \n");
    printf("Ingrese una opcion: ");
    scanf("%d", &option);

    return option;
}
