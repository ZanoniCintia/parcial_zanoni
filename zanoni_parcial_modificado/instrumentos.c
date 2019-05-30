#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "instrumentos.h"
#define TEXT_SIZE_INSTRUMENTOS 50


/** \brief  indica la primer posicion del array instrumentos
* \param array de instrumentos
* \param size tamaño del array
* \return la primer posicion del array
*
*/
int instrumentos_Inicializar(Instrumentos array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}
/** \brief Busca el primer lugar vacio en un array
* \param array instrumentos
* \param size int Tamaño del array
* \param posicion Puntero a la posicion del array donde se encuentra el valor buscado
* \return primer posicion vacia del array
*
*/
int instrumentos_buscarEmpty(Instrumentos array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array instrumentos
* \param size int Tamaño del array
* \param contadorID  Puntero al ID unico que se va a asignar al nuevo elemento
* \return los datos completos correctos ingresados por el usuario
*
*/
int instrumentos_alta(Instrumentos array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    char tipo[30];
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(instrumentos_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idInstrumentos=*contadorID;
            array[posicion].isEmpty=0;
            utn_getTexto("\ningrese nombre de instrumento: ","\nError",1,TEXT_SIZE_INSTRUMENTOS,1,array[posicion].nombre);
            utn_getUnsignedInt("\ningrese tipo:\n1 Cuerdas : \n2 Viento-Madera : \n3 Viento-Metal : \n4 Percusion ","\nerror, 1/2/3/4",1,4,1,4,1,&array[posicion].tipo); //mensaje + cambiar campo varString
            instrumentos_tipo(array[posicion],tipo);
            printf("\n ID: %d\n nombre: %s\n tipo %s\n ",
                  array[posicion].idInstrumentos,array[posicion].nombre,tipo);
            retorno=0;
        }
    }
    return retorno;
}
int instrumentos_tipo(Instrumentos tipoInstrumentos,char* tipos)
{
    int retorno=0;
    if(tipos!=NULL)
    {
        switch(tipoInstrumentos.tipo)
        {
            case 1:
                strcpy((char*)tipos,"Cuerdas");
                break;
            case 2:
                strcpy((char*)tipos,"Viento-Madera");
                break;
            case 3:
                strcpy((char*)tipos,"Viento-Metal");
                break;
             case 4:
                strcpy((char*)tipos,"Percusion");
                break;
            }
            return 1;
    }
    return retorno;
}
int instrumentos_buscarID(Instrumentos array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idInstrumentos==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Borra un elemento de la estructura instrumentos por ID
* \param array instrumentos
* \param size int Tamaño del array
* \return
*
*/
int instrumentos_baja(Instrumentos array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(instrumentos_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idInstrumentos=0;
            array[posicion].tipo=0;

            strcpy(array[posicion].nombre,"");
      ;
            retorno=0;
        }
    }
    return retorno;
}
/** \brief Lista los elementos de la estructura instrumentos
* \param array instrumentos
* \param size int Tamaño del array
* \return cero (ok) lista elementos del array
*
*/
int instrumentos_listar(Instrumentos array[], int size)
{
    int retorno=-1;
    int i;
    char tipo[30];
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else{
                instrumentos_tipo(array[i],tipo);
                printf("\n ID : %d - Nombre : %s - Tipo : %s ",
                       array[i].idInstrumentos,array[i].nombre,tipo);
            }
        }
        retorno=0;
    }
    return retorno;
}
void instrumentos_mock(Instrumentos arrayInstrumentos[], int size,int *contadorId)
{

    arrayInstrumentos[1].idInstrumentos=*contadorId;
    arrayInstrumentos[1].isEmpty=0;
    arrayInstrumentos[1].idInstrumentos=1;
    strcpy(arrayInstrumentos[1].nombre,"inst1");
    arrayInstrumentos[1].tipo=1;
    *contadorId=*contadorId + 1;

    arrayInstrumentos[2].idInstrumentos=*contadorId;
    arrayInstrumentos[2].isEmpty=0;
    arrayInstrumentos[2].idInstrumentos=2;
    strcpy(arrayInstrumentos[2].nombre,"inst2");
    arrayInstrumentos[2].tipo=2;
    *contadorId=*contadorId + 1;

    arrayInstrumentos[3].idInstrumentos=*contadorId;
    arrayInstrumentos[3].isEmpty=0;
    arrayInstrumentos[3].idInstrumentos=3;
    strcpy(arrayInstrumentos[3].nombre,"inst3");
    arrayInstrumentos[3].tipo=2;
    *contadorId=*contadorId + 1;

    arrayInstrumentos[4].idInstrumentos=*contadorId;
    arrayInstrumentos[4].isEmpty=0;
    arrayInstrumentos[4].idInstrumentos=4;
    strcpy(arrayInstrumentos[4].nombre,"inst4");
    arrayInstrumentos[4].tipo=3;
    *contadorId=*contadorId + 1;

    arrayInstrumentos[5].idInstrumentos=*contadorId;
    arrayInstrumentos[5].isEmpty=0;
    arrayInstrumentos[5].idInstrumentos=5;
    strcpy(arrayInstrumentos[5].nombre,"inst5");
    arrayInstrumentos[5].tipo=4;


}

