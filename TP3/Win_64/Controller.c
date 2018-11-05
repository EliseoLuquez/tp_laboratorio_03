#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"

#define RETURN_OK 1
#define RETURN_ERROR 0


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pfile = fopen("data.csv", "r");
    if(pfile != NULL)
    {
        ret = parser_EmployeeFromText(pfile, pArrayListEmployee);
    }
    else
    {
        printf("El Archivo No Existe\n\n");
    }

    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pfile = fopen("data.csv", "rb");
    if(pfile != NULL)
    {
        ret = parser_EmployeeFromText(pfile, pArrayListEmployee);
    }
    else
    {
        printf("El Archivo No Existe\n\n");
    }

    return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret;
    ret = RETURN_ERROR;

    Employee* emp = employee_new();
    int id;
    char nombre[20];
    int horasTeabajadas;
    int sueldo;

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese ID: ");
        scanf("%d", &id);
        ret = employee_setId(emp, id);

        printf("Ingrese Nombre: ");
        scanf("%s", nombre);
        ret = employee_setNombre(emp, nombre);

        printf("Ingrese Horas Trabajafas: ");
        scanf("%d", &horasTeabajadas);
        ret = employee_setHorasTrabajadas(emp, horasTeabajadas);

        printf("Ingrese Sueldo: ");
        scanf("%d", &sueldo);
        ret = employee_setSueldo(emp, sueldo);

        ret = ll_add(pArrayListEmployee, emp);
    }
    else
    {
        printf("No hay Datos\n\n");
    }
    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ret;
    ret = RETURN_ERROR;

    int id = 0;
    int idEdit = 0;
    char nombre[20];
    int horasTeabajadas = 0;
    int sueldo = 0;

    Employee* empAux = employee_new();

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese Id: ");
        scanf("%d", &idEdit);

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            empAux = (Employee*) ll_get(pArrayListEmployee, i);
            ret = employee_getId(empAux, &id);

            if(ret == RETURN_OK)
            {
                if(id == idEdit)
                {
                    switch(menuEdit())
                    {
                    case 1:
                            printf("Ingrese Nombre: ");
                            scanf("%s",empAux->nombre);
                            strcpy(empAux->nombre, nombre);
                            break;
                    case 2:
                            printf("Ingrese Horas Trabajadas: ");
                            scanf("%d",empAux->horasTrabajadas);
                            empAux->horasTrabajadas = horasTeabajadas;
                            break;
                    case 3:
                            printf("Ingrese Horas Trabajadas: ");
                            scanf("%d",empAux->sueldo);
                            empAux->sueldo = sueldo;
                            break;
                    default:
                            break;

                    }
                    ret = ll_set(pArrayListEmployee, i, empAux);
                    break;
                }
            }
        }
    }
    else
    {
        printf("No hay Datos\n\n");
    }




    return ret;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ret;
    ret = RETURN_ERROR;

    char seguir;
    int id = 0;
    int indice;

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese Id: ");
        scanf("%d", &id);

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            indice = (Employee*) ll_get(pArrayListEmployee, i);
            ret = employee_getId(indice, &id);

            if(ret == RETURN_OK)
            {
                 employee_showEmployee(ret);

                 printf("\nConfima borrado s/n: ");
                 fflush(stdin);
                 scanf("%c", &seguir);

                 if(seguir == 'n')
                 {
                     printf("Baja cancelada\n\n");

                 }
                 else

                 {
                     ll_remove(pArrayListEmployee, indice);
                     printf("Borrado exitoso\n\n");
                 }
                 system("pause");
            }
        }
     }




    return ret;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int ret;
    ret = RETURN_ERROR;
    Employee* emp = employee_new();

    if(pArrayListEmployee != NULL)
    {
        printf("Id  Nombre  Hs.Trab.  Sueldo\n\n");
        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            emp = (Employee*) ll_get(pArrayListEmployee, i);
            employee_showEmployee(emp);
        }
     }
     else
     {
         printf("No hay datos");
     }
    system("pause");



    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}


