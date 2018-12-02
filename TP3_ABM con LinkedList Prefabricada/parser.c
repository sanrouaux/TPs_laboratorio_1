#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Parsea los datos de un empleado desde el archivo data.csv (modo texto), corrobora que el ID no haya sido ya utilizado
 *         y, en caso de estar disponible el ID, agrega el empleado a la lista. Repite el proceso hasta el final del archivo
 *
 * \param path char* Puntero a la estructura asociada a la archivo desde el cual se leerán los datos
 * \param pArrayListEmployee LinkedList* Puntero a la lista en que se cargarán los datos
 * \return int "-1" si alguno de los punteros pasados como referencia es nulo, "0" si se produjo algún error de lectura, y "1"
 *             si se pudo realizar la lectura
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        retorno = 1;

        int datosParseados;
        int cantidadEmpleadosRechazados = 0;
        int cantidadEmpleadosAceptados = 0;

        char idStr[4];
        char nombreStr[128];
        char horasStr[4];
        char sueldoStr[6];
        Employee* pEmployee;
        Employee* auxPEmployee;

        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasStr, sueldoStr); //Lee la cabecera del archivo pero no la asigna a la lista
        while(!feof(pFile))
        {
            datosParseados = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasStr, sueldoStr);
            if(datosParseados == 4)
            {
                pEmployee = (Employee*) malloc(sizeof(Employee));

                pEmployee->id = atoi(idStr);
                strcpy(pEmployee->nombre, nombreStr);
                pEmployee->horasTrabajadas = atoi(horasStr);
                pEmployee->sueldo = atoi(sueldoStr);

                int largoLista;
                largoLista = ll_len(pArrayListEmployee);
                int bandera = 0;
                int i;
                for(i=0; i<largoLista; i++)
                {
                    auxPEmployee = ll_get(pArrayListEmployee, i);
                    if(pEmployee->id == auxPEmployee->id)
                    {
                        bandera = 1;
                        break;
                    }
                }

                if(bandera == 0)
                {
                    ll_add(pArrayListEmployee, pEmployee);
                    cantidadEmpleadosAceptados++;
                }
                else
                {
                    cantidadEmpleadosRechazados++;
                }
            }
            else
            {
                puts("\nERROR DE CARGA. SE SUSPENDIO EL PROCESO\n");
                retorno = 0;
                break;
            }
        }
        fclose(pFile);

        printf("\nSE CARGARON %d NUEVOS EMPLEADOS A LA LISTA\n", cantidadEmpleadosAceptados);
        if(cantidadEmpleadosRechazados != 0)
        {
            printf("\n%d EMPLEADOS FUERON RECHAZADOS POR INCOMPATIBILIDAD DE ID\n", cantidadEmpleadosRechazados);
        }
    }
    return retorno;
}


/** \brief Parsea los datos de un empleado desde el archivo data.bin (modo binario), corrobora que el ID no haya sido ya utilizado
 *         y, en caso de estar disponible el ID, agrega el empleado a la lista. Repite el proceso hasta el final del archivo
 *
 * \param path char* Puntero a la estructura asociada a la archivo desde el cual se leerán los datos
 * \param pArrayListEmployee LinkedList* Puntero a la lista en que se cargarán los datos
 * \return int "-1" si alguno de los punteros pasados como referencia es nulo, "0" si se produjo algún error de lectura, y "1"
 *             si se pudo realizar la lectura
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        retorno = 1;

        int datosParseados;
        int bandera = 0;
        int largoLista;
        int cantidadEmpleadosRechazados = 0;
        int cantidadEmpleadosIncluidos = 0;

        Employee* pEmployee;
        Employee* auxUnoEmpleado;
        auxUnoEmpleado = (Employee*) malloc(sizeof(Employee));
        Employee* auxDosEmpleado;
        auxDosEmpleado = (Employee*) malloc(sizeof(Employee));

        largoLista = ll_len(pArrayListEmployee);

        while(!feof(pFile))
        {
            datosParseados = fread(auxUnoEmpleado, sizeof(Employee), 1, pFile);
            if(datosParseados == 1)
            {
                int i;
                for(i=0; i<largoLista; i++)
                {
                    auxDosEmpleado = ll_get(pArrayListEmployee, i);
                    if(auxUnoEmpleado->id == auxDosEmpleado->id)
                    {
                        cantidadEmpleadosRechazados++;
                        bandera = 1;
                        break;
                    }
                }

                if(bandera == 0)
                {
                    pEmployee = (Employee*) malloc(sizeof(Employee));
                    *pEmployee = *auxUnoEmpleado;
                    ll_add(pArrayListEmployee, pEmployee);
                    cantidadEmpleadosIncluidos++;
                }
            }
        }
        fclose(pFile);

        printf("\nSE CARGARON %d NUEVOS EMPLEADOS A LA LISTA\n", cantidadEmpleadosIncluidos);
        if(cantidadEmpleadosRechazados != 0)
        {
            printf("\n%d EMPLEADOS FUERON RECHAZADOS POR INCOMPATIBILIDAD DE ID\n", cantidadEmpleadosRechazados);
        }
    }
    return retorno;
}
