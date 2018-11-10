#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"


/** \brief Constructor: reserva un espacio en memoria para la estructura e inicializa todos los valores en "0"
 *
 * \return Employee* Puntero a la estructura creada
 *
 */
Employee* employee_new()
{
    Employee* pEmployee;
    pEmployee = (Employee*) calloc(1, sizeof(Employee));

    return pEmployee;
}


/** \brief Constructor con parámetros: reserva un espacio en memoria y setea los valos iniciales de acuerdo a los parámetros
 *
 * \param idStr char* ID con el que se inicializará la estructura
 * \param nombreStr char* Nombre con el que se inicializará la estructura
 * \param horasTrabajadasStr char* Cantidad de horas trabajadas con las que se inicializará la estructura
 * \return Employee* Puntero a la estructura creada
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Employee* pEmployee;
    pEmployee = employee_new();

    int auxId;
    int auxHoras;

    auxId = atoi(idStr);
    employee_setId(pEmployee, auxId);
    employee_setNombre(pEmployee, nombreStr);
    auxHoras = atoi(horasTrabajadasStr);
    employee_setHorasTrabajadas(pEmployee, auxHoras);
    employee_setSueldo(pEmployee, 0);

    return pEmployee;
}


/** \brief Destructor: libera el espacio en memoria reservado para un empleado y lleva el puntero a NULL
 *
 * \return void
 *
 */
void employee_delete(Employee* this)
{
    free(this);
    this = NULL;
}


/** \brief Asigna un nuevo valor al campo ID del empleado
 *
 * \param this Employee* Puntero a la estructura empleado a modificar
 * \param id int Nuevo ID
 * \return int "0" si el puntero a empleado es nulo, "1" si no lo es
 *
 */
int employee_setId(Employee* this,int id)
{
    int retorno = 0;
    if(this != NULL)
    {
        retorno = 1;
        this->id = id;
    }
    return retorno;
}


/** \brief Permite obtener el valor del ID de un empleado
 *
 * \param this Employee* Puntero al empleado del cual se requiere el dato
 * \param id int* Puntero al espacio en memoria donde se alojará el dato
 * \return int "-1" si alguno de los dos punteros pasados como parámetros es nulo, "1" si logra realizar la asignación
 *
 */
int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}


/** \brief Asigna un nuevo nombre al empleado
 *
 * \param this Employee* Puntero al empleado a modificar
 * \param nombre char* Nuevo nombre
 * \return int "0" si el puntero a empleado es nulo, "1" si no lo es
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = 0;
    if(this != NULL)
    {
        retorno = 1;
        strcpy(this->nombre, nombre);
    }
    return retorno;
}


/** \brief Permite obtener el valor del campo Nombre de un empleado
 *
 * \param this Employee* Puntero al empleado del cual se requiere el dato
 * \param nombre char* Puntero al espacio en memoria donde se alojará el dato
 * \return int "-1" si alguno de los dos punteros pasados como parámetros es nulo, "1" si logra realizar la asignación
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 1;
    }
    return retorno;
}


/** \brief Asigna un nuevo valor al campo Horas Trabajadas del empleado
 *
 * \param this Employee* Puntero a la estructura empleado a modificar
 * \param horasTrabajadas int Nueva cantidad de horas
 * \return int "0" si el puntero a empleado es nulo, "1" si no lo es
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 0;
    if(this != NULL)
    {
        retorno = 1;
        this->horasTrabajadas = horasTrabajadas;
    }
    return retorno;
}


/** \brief Permite obtener el valor del campo Horas Trabajadas de un empleado
 *
 * \param this Employee* Puntero al empleado del cual se requiere el dato
 * \param horasTrabajadas int* Puntero al espacio en memoria donde se alojará el dato
 * \return int "-1" si alguno de los dos punteros pasados como parámetros es nulo, "1" si logra realizar la asignación
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}


/** \brief Asigna un nuevo valor al campo Sueldo del empleado
 *
 * \param this Employee* Puntero a la estructura empleado a modificar
 * \param sueldo int Nuevo valor de Sueldo
 * \return int "0" si el puntero a empleado es nulo, "1" si no lo es
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = 0;
    if(this != NULL)
    {
        retorno = 1;
        this->sueldo = sueldo;
    }
    return retorno;
}


/** \brief Permite obtener el valor del campo Horas Trabajadas de un empleado
 *
 * \param this Employee* Puntero al empleado del cual se requiere el dato
 * \param sueldo int* Puntero al espacio en memoria donde se alojará el dato
 * \return int "-1" si alguno de los dos punteros pasados como parámetros es nulo, "1" si logra realizar la asignación
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 1;
    }
    return retorno;
}
