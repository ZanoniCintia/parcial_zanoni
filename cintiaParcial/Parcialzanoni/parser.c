#ifndef PARSER_C_INCLUDED
#define PARSER_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"
#include "llamada.h"

int parser_LlamadaFromText(FILE* pFile , LinkedList* pArrayListLlamada)
{
    int retorno=-1;
    char auxId[500];
    char auxFecha[500];
    char auxCliente[500];
    char auxidProblema[500];
    char solucion[4096];
    int flag=0;

    Llamada* pAuxLlamada;

    if (pFile!=NULL && pArrayListLlamada!=NULL)
    {
        while (!feof(pFile))
        {
            if (flag==0)
            {
                flag++;
                continue;
            }

            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxFecha,auxCliente,auxidProblema,solucion);


            //printf ("ID: %s \n",auxId);
            pAuxLlamada = llamada_newParametros(auxId,auxFecha,auxCliente,auxidProblema,solucion);
            if (pAuxLlamada !=NULL)
            {
                ll_add(pArrayListLlamada,pAuxLlamada);
                retorno=0;
            }
        }
        fclose(pFile);
    }

    return retorno;
}


#endif // PARSER_C_INCLUDED
