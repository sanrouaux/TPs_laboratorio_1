#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Menu.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();

    int option;

    do
    {
        option = menuDeOpciones();

        switch(option)
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            break;

        case 2:
            controller_loadFromBinary("data.bin", listaEmpleados);
            break;

        case 3:
            controller_addEmployee(listaEmpleados);
            break;

        case 4:
            controller_editEmployee(listaEmpleados);
            break;

        case 5:
            controller_removeEmployee(listaEmpleados);
            break;

        case 6:
            controller_ListEmployee(listaEmpleados);
            break;

        case 7:
            controller_sortEmployee(listaEmpleados);
            break;

        case 8:
            controller_saveAsText("data.csv", listaEmpleados);
            break;

        case 9:
            controller_saveAsBinary("data.bin", listaEmpleados);
            break;

        case 10:
            ll_deleteLinkedList(listaEmpleados);
            puts("\nGRACIAS POR UTILIZAR LA APLICACION\n");
            break;

        default:
            puts("\nNO INGRESO UNA OPCION VALIDA\n");

        }
        system("pause");
        system("cls");
    }
    while(option != 10);
    return 0;
}
