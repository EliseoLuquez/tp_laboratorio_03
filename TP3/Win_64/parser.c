#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ret;
    ret = RETURN_ERROR;
    FILE* pfile;
    int cant;
    char id[6];
    char nombre[20];
    char horasTrabajadas[6];
    char sueldo[6];

    if(pfile != NULL)
    {
        while(!feof(pFile))
        {
            ret = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n", id, nombre, horasTrabajadas, sueldo);
            if(cant != 4)
            {
                printf("Error al cargar Arvhivo \n\n");
            }
            else
            {
                Employee* emp = employee_new();
                emp->id = atoi(id);
                strcpy(emp->nombre, nombre);
                emp->horasTrabajadas = atoi(horasTrabajadas);
                emp->sueldo = atoi(sueldo);
                ll_add(pArrayListEmployee, emp);
                system("pause");
            }
        fclose(pfile);
        RETURN_OK;
        }
    }
    else
    {
        printf("Arvhivo hay datos\n\n");
    }

    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ret;
    ret = RETURN_ERROR;
    FILE* pfile;

    if(pfile != NULL)
    {
        while(!feof(pFile))
        {

                Employee* emp = employee_new();
                ret = fread(emp, sizeof(Employee),1,pFile);
                ll_add(pArrayListEmployee, emp);
                ret = RETURN_OK;

        }
    }
    else
    {
        printf("No hay datos");
    }
    fclose(pfile);

    return ret;
}
