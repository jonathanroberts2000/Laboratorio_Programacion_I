#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "ePelicula.h"
#define PATHT "datosMF1.csv"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListPeliculas)
{
    int status = 0;
    char id[100], nombre[1000], anio[100], genero[1000];
    if(pFile != NULL && pArrayListPeliculas != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^\n]\n", id, nombre, anio);
        while(!feof(pFile))
        {
            ePelicula* aux = pelicula_new();
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, anio, genero);
            aux = pelicula_newParametros(id, nombre, anio, genero);
            ll_add(pArrayListPeliculas, aux);
        }
        status = 1;
    }
    return status;
}

