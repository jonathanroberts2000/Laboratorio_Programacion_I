#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "eEmpleado.h"
#define PATHT "data.csv"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int status = 0;
    char id[100], nombre[100], horasTrabajadas[100], edad[100], empleo[100];
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            eEmpleado* aux = employee_new();
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, empleo, edad, horasTrabajadas);
            aux = employee_newParametros(id, nombre, empleo, edad, horasTrabajadas);
            ll_add(pArrayListEmployee, aux);
        }
        status = 1;
    }
    return status;
}

