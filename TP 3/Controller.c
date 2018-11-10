#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "ingresoDatos.h"
#include "validaciones.h"


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


/** \brief Carga datos de empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Ruta del archivo que contiene los datos
 * \param pArrayListEmployee LinkedList* Puntero a la lista en que serán agregados los datos
 * \return int "-1" si alguno de los punteros pasados es nulo o si no logra abrir el archivo; "1" si logra realizar el parseo
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE* pArchivo;
        pArchivo = fopen(path, "r");
        if(pArchivo != NULL)
        {
            parser_EmployeeFromText(pArchivo, pArrayListEmployee);
            retorno = 1;
        }
        else
        {
            puts("\nERROR. NO SE LOGRO ABRIR EL ARCHIVO\n\n");
        }
    }
    return retorno;
}


/** \brief Carga datos de empleados desde el archivo data.bin (modo binario).
 *
 * \param path char* Puntero a la ruta del archivo desde el que se subirán los datos
 * \param pArrayListEmployee LinkedList* Puntero a la lista a la cual se asociarán los datos
 * \return int "-1" si alguno de los punteros pasados es nulo o si no logra abrir el archivo; "1" si logra realizar el parseo
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE* pArchivo;
        pArchivo = fopen(path, "rb");

        if(pArchivo != NULL)
        {
            parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
            retorno = 1;
        }
        else
        {
            puts("\nERROR. NO SE LOGRO ABRIR EL ARCHIVO\n");
        }
    }
    return retorno;
}

/** \brief Pide los datos de un empleado al usuario, calcula su ID y lo asocia a la lista
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista en que será cargado el dato
 * \return int "-1" si el puntero a la lista era nulo o no logra reservarse espacio en memoria para el nuevo empleado; "1" si logra
 * cargar al empleado
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        Employee* pEmployee;
        pEmployee = employee_new();

        if(pEmployee != NULL)
        {
            employee_setId(pEmployee, controller_calculaNuevoId(pArrayListEmployee));
            char auxNombre[128];
            ingresaCadenaSoloLetras(auxNombre, "Ingrese el nombre del empleado: ", 128);
            ubicaMayusculasYMinusculas(auxNombre);
            employee_setNombre(pEmployee, auxNombre);
            employee_setHorasTrabajadas(pEmployee, ingresaEntero("Ingrese las horas trabajadas: ", 720, 0));
            employee_setSueldo(pEmployee, ingresaEntero("Ingrese el sueldo del empleado: ", 2000000, 0));

            ll_add(pArrayListEmployee, pEmployee);
            puts("\nSE DIO EL ALTA A UN EMPLEADO\n");
            retorno = 1;
        }
    }
    return retorno;
}


/** \brief Permite al usuario modificar los datos de un empleado
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista a la que pertenece el empleado a modificar
 * \return int "-1" si el puntero a la lista es nulo; "0" si la lista está vacía, y "1" si no se logra encontrar
 * al empleado, el cambio es rechazado por el usuario o se realiza el cambio adecuadamente
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        retorno = 0;

        if(ll_len(pArrayListEmployee))
        {
            retorno = 1;
            controller_ListEmployee(pArrayListEmployee); // Muestra la lista al usuario

            int auxId;
            auxId = ingresaEntero("Ingrese el ID del empleado: ", 1000000, 0); // Pide ID al usuario

            Employee* pEmployee;
            int bandera = 0;

            int largoLista;
            largoLista = ll_len(pArrayListEmployee);

            int i;
            for(i = 0; i < largoLista; i++)
            {
                pEmployee = ll_get(pArrayListEmployee, i);
                if(pEmployee->id == auxId)
                {
                    bandera = 1;
                    break;
                }
            }

            if(bandera  == 1)
            {
                char confirmaSeguir;
                char opcionModificacion;

                printf("Se encontro al empleado: %s\n", pEmployee->nombre);
                puts("Es correcto? s/n");
                confirmaSeguir = pideYValidaSiNo();
                if(confirmaSeguir == 's')
                {
                    char auxNombre[128];
                    int auxHoras;
                    int auxSueldo;

                    do
                    {
                        opcionModificacion = menuModificacionEmpleado();

                        switch(opcionModificacion)
                        {
                        case 'a':
                            ingresaCadenaSoloLetras(auxNombre, "Ingrese el nuevo nombre: ", 128);
                            employee_setNombre(pEmployee, auxNombre);
                            puts("\nSE MODIFICARON LOS DATOS DE UN EMPLEADO\n");
                            retorno = 1;
                            break;

                        case 'b':
                            auxHoras = ingresaEntero("Ingrese las nuevas horas trabajadas", 720, 0);
                            employee_setHorasTrabajadas(pEmployee, auxHoras);
                            puts("\nSE MODIFICARON LOS DATOS DE UN EMPLEADO\n");
                            retorno = 1;
                            break;

                        case 'c':
                            auxSueldo = ingresaEntero("Ingrese el nuevo sueldo: ", 2000000, 0);
                            employee_setSueldo(pEmployee, auxSueldo);
                            puts("\nSE MODIFICARON LOS DATOS DE UN EMPLEADO\n");
                            retorno = 1;
                            break;

                        case 'd':
                            break;

                        default:
                            puts("\nNO SE INGRESO UNA OPCION VALIDA\n");
                        }
                    }
                    while(opcionModificacion != 'a' && opcionModificacion != 'b' && opcionModificacion != 'c'
                            && opcionModificacion != 'd');
                }
                else
                {
                    puts("\nACCION CANCELADA\n");
                }
            }
            else
            {
                puts("\nNO SE ENCONTRO NINGUN EMPLEADO CON ESE ID\n");
            }
        }
        else
        {
            puts("\nAUN NO HAY EMPLEADOS CARGADOS\n");
        }
    }
    return retorno;
}


/** \brief Pide al usuario el ID de un empleado, lo rastrea en la llista y, en caso de encontrarlo, lo elimina
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de la que se eliminará el empleado
 * \return int "-1" si el puntero a la lista es nulo; "0" si la lista está vacía, y "1" si no se logra encontrar
 * al empleado, la eliminación es rechazada por el usuario o se realiza el borrado adecuadamente
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        retorno = 0;

        if(ll_len(pArrayListEmployee))
        {
            retorno = 1;

            int auxId;
            int index = -1;
            int largoLista;
            Employee* pEmployee;

            controller_ListEmployee(pArrayListEmployee);

            puts("Ingrese el ID del empleado a eliminar: ");
            fflush(stdin);
            scanf("%d", &auxId);

            largoLista = ll_len(pArrayListEmployee);
            int i;
            for(i=0; i<largoLista; i++)
            {
                pEmployee = ll_get(pArrayListEmployee, i);
                if(pEmployee->id == auxId)
                {
                    index = i;
                    break;
                }
            }

            if(index == -1)
            {
                puts("\nNO SE ENCONTRO AL EMPLEADO\n");
            }
            else
            {
                retorno = 1;
                printf("Se encontro al empleado: %s\n", pEmployee->nombre);
                puts("Es correcto? s/n");
                char confirmaSeguir;
                confirmaSeguir = pideYValidaSiNo();
                if(confirmaSeguir == 's')
                {
                    ll_remove(pArrayListEmployee, index);
                    puts("\nSE DIO DE BAJA A UN EMPLEADO\n");
                }
                else
                {
                    puts("\nACCION CANCELADA\n");
                }
            }
        }
        else
        {
            puts("\nAUN NO HAY EMPLEADOS CARGADOS\n");
        }
    }
    return retorno;
}


/** \brief Muestra la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista
 * \return int "-1" si el puntero a la lista es nulo, "0" si no hay empleados para mostrar, y "1" si se muestra al menos un empleado
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        retorno = 0;
        int largoLista;
        largoLista = ll_len(pArrayListEmployee);

        if(largoLista == 0)
        {
            puts("\nNO HAY EMPLEADOS PARA MOSTRAR\n");
        }
        else
        {
            retorno = 1;
            Employee* auxEmployee;

            puts("ID      NOMBRE         HORAS TRABAJADAS   SUELDO");
            int i;
            for(i=0; i <largoLista; i++)
            {
                auxEmployee = ll_get(pArrayListEmployee, i);
                printf("%-8d%-15s%-19d%-d\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas,
                       auxEmployee->sueldo);
            }
        }
    }
    return retorno;
}


/** \brief Muestra una versión de la lista de empleados ordenada alfabéticamente
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista a ordenar
 * \return int "-1" si el puntero a la lista es nulo, "1" si logra ordenar los elementos de la lista
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        retorno = 0;
        if(ll_len(pArrayListEmployee))
        {
            retorno = 1;
            LinkedList* auxPLinkedList;
            auxPLinkedList = ll_clone(pArrayListEmployee);

            puts("Ordenando. . .");

            ll_sort(auxPLinkedList, controller_comparaEmployees, 1);
            controller_ListEmployee(auxPLinkedList);
        }
        else
        {
            puts("\nAUN NO HAY EMPLEADOS CARGADOS\n");
        }

    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* Ruta al archivo a abrir o crear
 * \param pArrayListEmployee LinkedList* Puntero a la lista de los que tomará los datos
 * \return int "-1" si alguno de los punteros pasados como parámetros es nulos, "0" si no logra abrir o crear el archivo
 *             y "1" si logra abrir o crear el archivo
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        retorno = 0;
        FILE* pArchivo;
        pArchivo = fopen(path, "w");

        if(pArchivo != NULL)
        {
            retorno = 1;

            puts("\nSe guardara el estado actual de la lista en el archivo.");
            puts("Los datos que hayan sido eliminados o modificados no podran ser recuperados.");
            puts("Desea continuar? s/n");
            char confirmaSeguir;
            confirmaSeguir = pideYValidaSiNo();

            if(confirmaSeguir == 's')
            {
                fprintf(pArchivo, "id,nombre,horasTrabajadas,sueldo\n");

                Employee* pEmployee;
                int largoLista;
                largoLista = ll_len(pArrayListEmployee);
                int i;
                for(i=0; i<largoLista; i++)
                {
                    pEmployee = ll_get(pArrayListEmployee, i);
                    fprintf(pArchivo, "%d,%s,%d,%d\n", pEmployee->id, pEmployee->nombre, pEmployee->horasTrabajadas,
                            pEmployee->sueldo);
                }
                fclose(pArchivo);
                puts("\nSE GUARDARON LOS DATOS EN EL ARCHIVO DE TEXTO(data.csv)\n");
            }
            else
            {
                puts("\nACCION CANCELADA\n");
            }
        }
        else
        {
            puts("\nERROR. NO SE PUDO ABRIR/CREAR EL ARCHIVO\n");
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char* Ruta al archivo a abrir o crear
 * \param pArrayListEmployee LinkedList* Puntero a la lista de los que tomará los datos
 * \return int "-1" si alguno de los punteros pasados como parámetros es nulo, "0" si no logra abrir o crear el archivo
 *             y "1" si logra abrir o crear el archivo
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        retorno = 0;
        FILE* pArchivo;
        pArchivo = fopen(path, "wb");

        if(pArchivo != NULL)
        {
            retorno = 1;

            puts("\nSe guardara el estado actual de la lista en el archivo.");
            puts("Los datos que hayan sido eliminados o modificados no podran ser recuperados.");
            puts("Desea continuar? s/n");
            char confirmaSeguir;
            confirmaSeguir = pideYValidaSiNo();

            if(confirmaSeguir == 's')
            {
                Employee* pEmployee;
                int len;
                len = ll_len(pArrayListEmployee);
                int i;
                for(i=0; i<len; i++)
                {
                    pEmployee = ll_get(pArrayListEmployee, i);
                    fwrite(pEmployee, sizeof(Employee), 1, pArchivo);
                }
                fclose(pArchivo);
                puts("\nSE GUARDARON LOS DATOS EN EL ARCHIVO BINARIO(data.bin)\n");
            }
            else
            {
                puts("\nACCION CANCELADA\n");
            }
        }
        else
        {
            puts("\nERROR. NO SE PUDO ABRIR/CREAR EL ARCHIVO\n");
        }
    }
    return retorno;
}


/** \brief Calcula automáticamente un nuevo ID para un empleado cargado por el usuario
 *
 * \param lista LinkedList* Puntero a la lista en que será agregado el ampleado
 * \return int El nuevo ID para el empleo a cargar
 *
 */
int controller_calculaNuevoId(LinkedList* pArrayListEmployee)
{
    int idMayor = 0;
    int bandera = 0;
    Employee* pEmployee;

    int largoLista;
    largoLista = ll_len(pArrayListEmployee);
    int i;
    for(i=0; i<largoLista; i++)
    {
        pEmployee = ll_get(pArrayListEmployee, i);
        if(bandera == 0)
        {
            idMayor = pEmployee->id;
            bandera = 1;
        }

        if(pEmployee->id > idMayor)
        {
            idMayor = pEmployee->id;
        }
    }
    return idMayor+1;
}


/** \brief Recibe dos elementos de la lista, los compara segun el campo "nombre" y devuelve el resultado de la comparación
 *
 * \param punteroUno void* Primer elemento a comparar de la lista
 * \param punteroDos void* Segundo elemento a comparar de la lista
 * \return int "-1" si el primer elemento es alfabéticamente anterior, "0" si son iguales, y "1" si el primer elemento
 * es alfabéticamente posterior al segundo
 *
 */
int controller_comparaEmployees(void* punteroUno, void* punteroDos)
{
    int retorno = 0;

    Employee* pEmployeeUno;
    Employee* pEmployeeDos;

    pEmployeeUno = (Employee*) punteroUno;
    pEmployeeDos = (Employee*) punteroDos;

    if(stricmp(pEmployeeUno->nombre, pEmployeeDos->nombre)<0)
    {
        retorno = -1;
    }
    else if(stricmp(pEmployeeUno->nombre, pEmployeeDos->nombre)>0)
    {
        retorno = 1;
    }
    return retorno;
}
