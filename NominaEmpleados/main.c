#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "menu.h"
#include "ingresoDatos.h"

#define ELEMENTS 1000


int main()
{
    sEmployee listEmployees[ELEMENTS];
    initEmployees(listEmployees, ELEMENTS);

    int option;
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int index;
    int flag = 0;

    do
    {
        option = menu();

        switch(option)
        {
        case 1:
            flag = 1;
            puts("Ingrese ID: ");
            fflush(stdin);
            scanf("%d", &id);

            puts("Ingrese nombre: ");
            fflush(stdin);
            gets(name);
            while(strlen(name) > 50)
            {
                puts("Nombre demasiado largo. Ingrese nuevamente");
                gets(name);
            }

            puts("Ingrese apellido: ");
            fflush(stdin);
            gets(lastName);
            while(strlen(name) > 50)
            {
                puts("Apellido demasiado largo. Ingrese nuevamente");
                gets(name);
            }

            puts("Ingrese salario: ");
            fflush(stdin);
            scanf("%f", &salary);
            while(salary < 0)
            {
                puts("Salario invalido. Ingrese nuevamente");
                scanf("%f", &salary);
            }

            puts("Ingrese sector: ");
            fflush(stdin);
            scanf("%d", &sector);
            while(sector < 0)
            {
                puts("Sector invalido. Ingrese nuevamente");
                scanf("%d", &sector);
            }

            addEmployee(listEmployees, ELEMENTS, id, name, lastName, salary, sector);
            break;

        case 2:
            if(flag == 1)
            {
                id = getId();
                index = findEmployeeById(listEmployees, ELEMENTS, id);
                modifyEmployee(listEmployees, ELEMENTS, index);
            }
            else
            {
                puts("No hay empleados cargados");
            }

            break;

        case 3:
            if(flag == 1)
            {
                puts("Ingrese el ID del empleado");
                fflush(stdin);
                scanf("%d", &id);
                removeEmployee(listEmployees, ELEMENTS, id);
            }
            else
            {
                puts("No hay empleados cargados");
            }


            break;

        case 4:
            if(flag == 1)
            {
                //sortEmployees(listEmployees, ELEMENTS, 1);
                printEmployees(listEmployees, ELEMENTS);
            }
            else
            {
                puts("No hay empleados cargados");
            }
            break;

        case 5:
            break;

        default:
            printf("Elija una opcion valida");
        }
        system("pause");
        system("cls");
    }
    while(option != 5);

    return 0;
}
