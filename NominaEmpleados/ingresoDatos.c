#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "menu.h"


/** \brief Solicita al usuario el ID de un empleado
 *
 * \return int Retorna el ID de un empleado
 *
 */
int getId()
{
    int id;
    puts("Ingrese el ID del empleado");
    fflush(stdin);
    scanf("%d", &id);
    return id;
}




