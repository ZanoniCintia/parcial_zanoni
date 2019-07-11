#ifndef CONTROLLER_C_INCLUDED
#define CONTROLLER_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"
#include "llamada.h"
#include "parser.h"
#include "funciones.h"
#include "Controller.h"
#define MAX_ID 1000000
#define SORT_DOWN 0
#define SORT_UP 1

int controller_loadFromText(char* path , LinkedList* pArrayListLlamada)
{
    int retorno=-1;

    FILE* pFile; //= NULL;

    if (path!=NULL && pArrayListLlamada!=NULL)
    {
        pFile = fopen (path, "w");

                if (pFile!=NULL)
                {
                    ll_clear(pArrayListLlamada);
                    if (!parser_LlamadaFromText(pFile,pArrayListLlamada))
                    {
                        retorno=0;
                        printf ("Carga Llamada ok.\n");
                    }
                }
            //}
        fclose (pFile);
    }
    return retorno;
}



int controller_ListLlamada(LinkedList* pArrayListLlamada)
{
    int retorno=-1;
    Llamada* pLlamada;
    int auxId;
    char bufferFecha[1000];
    //char bufferCliente[500];
    int auxCliente;
    int auxIdProblema;
    char bufferSolucion[500];
    int length;
    int i;

    if (pArrayListLlamada!=NULL)
    {
        length=ll_len(pArrayListLlamada);
        for (i=0;i<length;i++)
        {
            pLlamada = ll_get(pArrayListLlamada,i);
            if (pLlamada!=NULL)
            {
                if (!Llamada_getId(pLlamada,&auxId) &&
                    !Llamada_getFecha(pLlamada,bufferFecha) &&
                    !Llamada_getNumeroCliente(pLlamada, &auxCliente) &&
                    !Llamada_getIdProblema(pLlamada,&auxIdProblema) &&
                    !Llamada_getSolucion(pLlamada,&bufferSolucion))
                {
                    printf("ID:%d Fecha:%s Numero cliente:%d ID problema:%d Solucion:%s  \n",auxId,bufferFecha, auxCliente, auxIdProblema, bufferSolucion);
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListLlamada)
{
    int retorno = -1;
    Llamada* pLlamada;
    //FILE* pFile;
    int i;
    char solucion[51];
    char fecha[51];
    int numeroCliente;
    int idProblema;
    int idLlamada;
    //int totalpolaroid=0;

    //LinkedList* Polaroid= ll_newLinkedList();
    //LinkedList* Mayores300 = ll_newLinkedList();

    FILE *pFile = NULL;

    if(path != NULL && pArrayListLlamada != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
              if(path != NULL && pArrayListLlamada != NULL)
    {
        pFile = fopen(path,"w");
        if(pFile != NULL)
        {
            for(i=0;i<ll_len(pArrayListLlamada);i++)
            {
                pLlamada = ll_get(pArrayListLlamada,i);
                if(pLlamada != NULL)
                {
                    Llamada_getId(pLlamada,&idLlamada);
                    Llamada_getFecha(pLlamada,fecha);
                    Llamada_getNumeroCliente(pLlamada, &numeroCliente);
                    Llamada_getIdProblema(pLlamada,&idProblema);
                    Llamada_getSolucion(pLlamada,solucion);
                    fprintf(pFile,"%d,%s,%d,%d,%s\n",idLlamada,fecha,numeroCliente,idProblema,solucion);
                }
            }
            retorno = 0;
            fclose(pFile);
        }

    }                                                                                   //totalFotos=cantidadFotos(pArrayListVenta);
            retorno = 0;
        }
        if (retorno==0)
        {
            printf ("\nLista guardada correctamente.\n");
        }else
            printf ("\nNo se pudo guardar la lista correctamente.\n");
        fclose(pFile);
    }
    return retorno;
}
                                                                                                //ventasMayor150=ll_count(pArrayListVenta,montoMayor150);
 int controller_problemas(void* p)
{
    int problemas;
    int retorno = 0;
    if(p!=NULL)
    {
        Llamada_getIdProblema(p,&problemas);
        if(problemas<=5)
        {
            retorno = 1;

        }
    }

    return retorno;

}                                                                                               //ventasMayor300=ll_count(pArrayListVenta,montoMayor300);
                                                                                                //totalPolaroid=ll_count(pArrayListVenta,PolaroidReveladas);
                                                                                                //totalpolaroid=cantidadPolaroid(pArrayListVenta);

                                                                                                //printf ("Total polaroid: %d",Polaroid);
                                                                                                //fprintf(pFile, "*****************************\nInforme de Ventas\n*****************************\n");
                                                                                                //fprintf(pFile, "- Cantidad Total de fotos: %d\n", totalFotos);
                                                                                                //fprintf(pFile, "- Cantidad de ventas por un monto mayor a $150: %d \n",ventasMayor150);
                                                                                                //fprintf(pFile, "- Cantidad de ventas por un monto mayor a $300: %d \n",ventasMayor300);
                                                                                                //fprintf(pFile, "- Cantidad de polaroids: %d\n", totalPolaroid);
                                                                                                //fprintf(pFile, "- Importe promedio por Entrega: %.2f\n", promedioPorEntrega);
                                                                                                //fprintf(pFile, "*****************************


/*int cantidadFotos(LinkedList* pArrayList)
{
    int retorno=-1;
    int i;
    int cantidadFotos=0;
    int acumulador=0;

    if (pArrayList!=NULL)
    {
        Venta* pAux;
        for (i=0;i<ll_len(pArrayList);i++)
        {
            pAux=ll_get(pArrayList,i);
            if(Venta_getCantidad(pAux,&cantidadFotos)==0)
            {
                acumulador = cantidadFotos+acumulador;
            }
            retorno=acumulador;
            //printf("Acumulador: %d",acumulador);
        }

    }
    return retorno;
}

int montoMayor150(void* p)
{
    int retorno=0;
    float auxImporte;
    int cantidad;
    float total;

    if (p!=NULL)
    {
        Venta_getImporte(p,&auxImporte);
        Venta_getCantidad(p,&cantidad);
        total= auxImporte*cantidad;
        if (total>150)
        {

            retorno=1;
        }
    }

    return retorno;
}

int montoMayor300(void* p)
{
    int retorno=0;
    float auxImporte;
    int cantidad;
    float total;

    if (p!=NULL)
    {
        Venta_getImporte(p,&auxImporte);
        Venta_getCantidad(p,&cantidad);
        total= auxImporte*cantidad;
        //printf ("Total: %f",total);
        if (total>300)
        {
            retorno=1;
        }
    }

    return retorno;
}*/

/*int PolaroidReveladas(void* p)
{
    int retorno = 0;
    Venta* auxVenta = (Venta*)p;

    if ((strcmp(auxVenta->tipo,"POLAROID_11x9")==0) || (strcmp(auxVenta->tipo,"POLAROID_10x10")==0))
    {
        retorno=1;
    }
    return retorno;
}

int cantidadPolaroid(LinkedList* arrayListVentas)
{
    int retorno=-1;
    int i;
    //char tipo;
    int cantidad;
    int acumulador;
    Venta* pAux;

    if (arrayListVentas!=NULL)
    {
        for (i=0;i<ll_len(arrayListVentas);i++)
        {
            pAux=ll_get(arrayListVentas,i);
            if ((strcmp(pAux->tipo,"POLAROID_11X9")==0) || (strcmp(pAux->tipo,"POLAROID_10X10")==0))
            {
                Venta_getCantidad(pAux,&cantidad);
                acumulador=cantidad+acumulador;
            }
        }
        retorno=acumulador;
    }
    return retorno;
}*/
#endif // CONTROLLER_C_INCLUDED
