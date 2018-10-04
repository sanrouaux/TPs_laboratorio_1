#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"

#define EMPTY 1
#define BUSY 0



/** \brief Inicializa el array de empleados
 * \param list sEmployee[] Puntero al array de empleados
 * \param len int tamano del array
 * \return int Retorna -1 si hay error, y 0 se funciona correctamente
 *
 */
int initEmployees(sEmployee list[], int len)
{
    int test = -1;

    if(len >= 0 && list != NULL)
    {
        test = 0;
        int i;
        for(i = 0; i < len; i++)
        {
            list[i].isEmpty = EMPTY;
        }
    }
    return test;
}



/** \brief Carga loss datos de un empleado en el array de empleados
 * \param Puntero al array de empleados
 * \param len int tamano del array
 * \param id int Id del empleado
 * \param name[] char Nombre del empleado
 * \param lastName[] char Apellido del empleado
 * \param salary float Salario del empleado
 * \param sector int Sector correspondiente al empleado
 * \return int Retorna -1 si hay error, y 0 si funciona correctamente
 */
int addEmployee(sEmployee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int test = -1;

    if(len >= 0 && list != NULL)
    {
        test = 0;
        int index = -1;

        int i;
        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty == EMPTY)
            {
                index = i;
                break;
            }
        }

        if(index >= 0)
        {
            list[index].id = id;
            strcpy(list[index].name, name);
            strcpy(list[index].lastName, lastName);
            list[index].salary = salary;
            list[index].sector = sector;
            list[index].isEmpty = BUSY;
            puts("Se ingreso un empleado");
        }
        else
        {
            test = -1;
        }
    }
    return test;
}

/** \brief Recibe el ID de un empleado, lo busca a traves del arra y devuelve el indice
 *
 * \param list Puntero al array de empleados
 * \param len int tamano del array
 * \param id int id a ser buscado
 * \return Retorna -1 si hay error, o, en caso contrario, el indice
 *
 */
int findEmployeeById(sEmployee list[], int len, int id)
{
    int index = -1;

    if(len>=0 && list!=NULL)
    {
        int i;
        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty == BUSY && list[i].id == id)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}


/** \brief Recibe el Id de un empleado y lo borra
 *
 * \param list Puntero al array de empleados
 * \param len int tamano del array
 * \param id int Id a ser buscado
 * \return int Retorna -1 si hay error y 0 si funciona correctamente
 *
 */
int removeEmployee(sEmployee list[], int len, int id)
{
    int test = -1;

    if(len>=0 && list!=NULL)
    {
        int i;
        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty == BUSY && list[i].id == id)
            {
                list[i].isEmpty = EMPTY;
                puts("Se elemino un empleado");
                test = 0;
                break;
            }
        }
    }
    return test;
}


/** \brief Imprime la lista de empleados cargados
 *
 * \param list Puntero al array de empleados
 * \param len int tamano del array
 * \return int Retorna 0
 *
 */
int printEmployees(sEmployee list[], int len)
{
    puts("---------NOMINA DE EMPLEADOS-------------");
    puts("ID    Nombre   Apellido   Salario  Sector");
    int i;
    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == BUSY)
        {
            printf("%d   %s    %s    %.2f    %d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
        }
    }
    return 0;
}


/** \brief Modifica los datos de un empleado, a eleccion del usuario
 *
 * \param list[] Puntero al array de empleados
 * \param len int tamano del array
 * \param index int indice del empleado a modificar
 * \return int Retorna -1 si hay error, y 0 si funciona correctamente
 *
 */
int modifyEmployee(sEmployee list[], int len, int index)
{
    int test = -1;

    if(len>=0 && list!=NULL)
    {
        test = 0;
        int option;
        puts("Que campo desea modificar?");
        puts("1. Nombre");
        puts("2. Apellido");
        puts("3. Salario");
        puts("4. Sector");
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            puts("Ingrese nuevo nombre");
            fflush(stdin);
            gets(list[index].name);
            puts("Se modifico el nombre del empleado");
            break;

        case 2:
            puts("Ingrese nuevo apellido");
            fflush(stdin);
            gets(list[index].lastName);
            puts("Se modifico el apellido del empleado");
            break;

        case 3:
            puts("Ingrese nuevo salario");
            fflush(stdin);
            scanf("%f", &list[index].salary);
            puts("Se modifico el salario del empleado");
            break;

        case 4:
            puts("Ingrese nuevo sector");
            fflush(stdin);
            scanf("%d", &list[index].sector);
            puts("Se modifico el sector del empleado");
            break;

        default:
            puts("No ingreso una opcion valida");
        }

    }
    return test;
}


/** \brief Ordena los elementos del array alfabeticamente, por apellido, en orden ascendente o descendente
 * de acuerdo a lo solicitado por el usuario
 * \param list Puntero al array de empleados
 * \param len int tamano del array
 * \param order int 1 para orden ascendente, 0 para orden descendente
 * \return Retorna -1 si hay error y 0 si funciona correctamente
 *
 */
int sortEmployees(sEmployee list[], int len, int order)
{
    int test = -1;
    if(len>=0 && list!=NULL)
    {
        test = 0;
        int i;
        int j;
        char aux[50];

        if(order == 1)
        {
            for(i = 0; i < len-1; i++)
            {
                for(j = i+1; j < len; j++)
                {
                    if(strcmp(list[i].lastName, list[j].lastName)>0)
                    {
                        strcpy(aux, list[j].lastName);
                        strcpy(list[j].lastName, list[i].lastName);
                        strcpy(list[i].lastName, aux);
                    }
                }
            }
        }
        else
        {
            for(i = 0; i < len-1; i++)
            {
                for(j = i+1; j < len; j++)
                {
                    if(strcmp(list[i].lastName, list[j].lastName)<0)
                    {
                        strcpy(aux, list[j].lastName);
                        strcpy(list[j].lastName, list[i].lastName);
                        strcpy(list[i].lastName, aux);
                    }
                }
            }
        }
    }
    return test;
}
