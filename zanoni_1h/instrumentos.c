#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "instrumentos.h"
#define TEXT_SIZE_INSTRUMENTOS 50 //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array instrumentos
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int instrumentos_Inicializar(Instrumentos array[], int size)                                    //cambiar libros
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
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int instrumentos_buscarEmpty(Instrumentos array[], int size, int* posicion)                    //cambiar libros
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
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int instrumentos_alta(Instrumentos array[], int size, int* contadorID)                          //cambiar libros
{
    int retorno=-1;
    int posicion;
    char tipo[30];
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(instrumentos_buscarEmpty(array,size,&posicion)==-1)                          //cambiar libros
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idInstrumentos=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
                      //mensaje + cambiar campo varInt
            //utn_getFloat("\ngetFloat: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
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
int instrumentos_buscarID(Instrumentos array[], int size, int valorBuscado, int* posicion)                    //cambiar socios
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idInstrumentos==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array instrumentos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumentos_baja(Instrumentos array[], int sizeArray)                                      //cambiar libros
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(instrumentos_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idInstrumentos=0;                                                                   //cambiar campo id
            array[posicion].tipo=0;                                                               //cambiar campo varInt
                                                                //cambiar campo varFloat
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo varString
      ;                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}
/** \brief Lista los elementos de un array
* \param array instrumentos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int instrumentos_listar(Instrumentos array[], int size)                      //cambiar autor
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
                printf("\n ID : %d\n nombre : %s \ntipo : %s ",
                       array[i].idInstrumentos,array[i].nombre,tipo);
            }//cambiar todos
        }
        retorno=0;
    }
    return retorno;
}
void instrumentos_mock(Instrumentos arrayInstrumentos[], int size,int *contadorId)                      //cambiar libros
{
    //*******************************************************************
    arrayInstrumentos[1].idInstrumentos=*contadorId;
    arrayInstrumentos[1].isEmpty=0;
    arrayInstrumentos[1].idInstrumentos=1;
    strcpy(arrayInstrumentos[1].nombre,"piano");
    arrayInstrumentos[1].tipo=1;
    *contadorId=*contadorId + 1;

    arrayInstrumentos[2].idInstrumentos=*contadorId;
    arrayInstrumentos[2].isEmpty=0;
    arrayInstrumentos[2].idInstrumentos=2;
    strcpy(arrayInstrumentos[2].nombre,"guitarra");
    arrayInstrumentos[2].tipo=2;
    *contadorId=*contadorId + 1;

    arrayInstrumentos[3].idInstrumentos=*contadorId;
    arrayInstrumentos[3].isEmpty=0;
    arrayInstrumentos[3].idInstrumentos=3;
    strcpy(arrayInstrumentos[3].nombre,"baj0");
    arrayInstrumentos[3].tipo=2;
    *contadorId=*contadorId + 1;

    arrayInstrumentos[4].idInstrumentos=*contadorId;
    arrayInstrumentos[4].isEmpty=0;
    arrayInstrumentos[4].idInstrumentos=4;
    strcpy(arrayInstrumentos[4].nombre,"baj0");
    arrayInstrumentos[4].tipo=3;
    *contadorId=*contadorId + 1;

    arrayInstrumentos[5].idInstrumentos=*contadorId;
    arrayInstrumentos[5].isEmpty=0;
    arrayInstrumentos[5].idInstrumentos=5;
    strcpy(arrayInstrumentos[5].nombre,"bateria");
    arrayInstrumentos[5].tipo=4;

    //contadorId++;
}

