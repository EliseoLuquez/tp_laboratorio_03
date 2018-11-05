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

    char id[5];
    char nombre[20];
    char horasTrabajadas[5];
    char sueldo[5];
    int line = 0;

    pfile = fopen("data.csv", "r");

    if(pfile != NULL)
    {
        while(!feof(pFile))
        {
            ret = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n],%[^,]\n", id, nombre, horasTrabajadas, sueldo);
            if(ret == 4 && line > 0)
            {
                Employee* emp = employee_new();
                emp->id = atoi(id);
                strcpy(emp->nombre, nombre);
                emp->horasTrabajadas = atoi(horasTrabajadas);
                emp->sueldo = atoi(sueldo);
                ll_add(pArrayListEmployee, emp);
                line++;
            }
            else if(line == 0)
            {
                line++;
            }
            else
            {
                break;
            }
        }
        fclose(pfile);
        ret = RETURN_OK;
    }
    else
    {
        printf("Arvhivo Vacio\n\n");
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
    int id;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;
    int line = 0;

    pfile = fopen("data.csv", "rb");

    if(pfile != NULL)
    {
        while(!feof(pFile))
        {
            ret = fscanf(pFile,"%d,%s,%d,%d\n", &id, nombre, &horasTrabajadas, &sueldo);
            if(ret == 4 && line > 0)
            {
                Employee* emp = employee_new();
                emp->id = id;
                strcpy(emp->nombre, nombre);
                emp->horasTrabajadas = horasTrabajadas;
                emp->sueldo = sueldo;
                ll_add(pArrayListEmployee, emp);
                line++;
            }
            else if(line == 0)
            {
                line++;
            }
            else
            {
                break;
            }
        }
        fclose(pfile);
        ret = RETURN_OK;
    }
    else
    {
        printf("Arvhivo Vacio\n\n");
    }

    return ret;
}
