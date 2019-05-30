#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"


/** \brief indica la primer posicion en el array
*
* \param array del tipo orquesta
* \param longitud del array
* \return retorna 0(ok) cuando esta en la primer posicion del array
*
*/
int orquesta_Inicializar(Orquesta array[], int size)
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
* \param array tipo orquesta
* \param Tamaño del array
* \param Puntero a la posicion del array donde se encuentra el valor buscado
* \return Retorna (0) si encuentra una posicion vacia
*
*/
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion)
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

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array autor Array de autor
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion)                    //cambiar autor
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idOrquesta==valorBuscado)                                                   //cambiar campo ID
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
* \param array orquesta
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int orquesta_alta(Orquesta array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    char tipo[30];
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(orquesta_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idOrquesta=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;

            utn_getTexto("\ningrese nombre de la orquesta: ","\nError",1,TEXT_SIZE_ORQUESTA,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
            utn_getTexto("\ningrese lugar : ","\nError",1,TEXT_SIZE_ORQUESTA,1,array[posicion].lugar);
            utn_getUnsignedInt("\ningrese tipo:\n1 sinfonica : \n2 filarmonica : \n3 camara : ","\nerror, 1/2/3",1,3,1,3,1,&array[posicion].tipo);
            orquesta_tipo(array[posicion],tipo);
            printf("\nID: %d\n nombre : %s\n lugar : %s \n tipo : %s", array[posicion].idOrquesta,array[posicion].nombre,array[posicion].lugar,tipo);
            retorno=0;
        }
    }
    return retorno;
}
int orquesta_tipo(Orquesta tipoOrquesta,char* tipos)
{
    int retorno=0;
    if(tipos!=NULL)
    {
        switch(tipoOrquesta.tipo)
        {
            case 1:
                strcpy((char*)tipos,"Sinfónica");
                break;
            case 2:
                strcpy((char*)tipos,"Filarmónica");
                break;
            case 3:
                strcpy((char*)tipos,"Cámara");
                break;
            }
            return 1;
    }
    return retorno;
}




/** \brief Busca un elemento por ID y modifica sus campos
* \param array autor Array de autor
* \param size int Tamaño del array
* \return modifica los datos elegidos
*/
int orquesta_modificar(Orquesta array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                printf("\n Posicion: %d - ID: %d - Nombre: %s - Lugar: %s - Tipo : %d ",
                   posicion, array[posicion].idOrquesta,array[posicion].nombre,array[posicion].lugar,array[posicion].tipo);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE_ORQUESTA,1,array[posicion].nombre);
                        break;
                    case 'B':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE_ORQUESTA,1,array[posicion].lugar);
                        break;
                    case 'C':

                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].tipo);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpción no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}


int orquesta_ordenarPorDobleCriterio(Orquesta array[],int size, int orderFirst, int orderSecond)
{
    int retorno=-1;
    int i;
    Orquesta buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].nombre,array[i+1].nombre) < 0) && orderFirst) ||
                    ((strcmp(array[i].nombre,array[i+1].nombre) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
                /*else if(strcmp(array[i].nombre,array[i+1].nombre) == 0)
                {
                    if( ((array[i].varFloat < array[i+1].varFloat) && orderSecond) ||
                        ((array[i].varFloat > array[i+1].varFloat) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = array[i];
                        array[i] = array[i+1];
                        array[i+1] = buffer;
                    }
                }*/
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}


/** \brief Lista los elementos de un array
* \param array tipo orquesta
* \param size int Tamaño del array
* \return lista elemtos del array orquesta
*
*/
int orquesta_listar(Orquesta array[], int size)
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

                orquesta_tipo(array[i],tipo);
                printf("\n ID: %d - Nombre: %s - Lugar: %s - Tipo: %s ",
                      array[i].idOrquesta,array[i].nombre,array[i].lugar,tipo);
               }              //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}


void orquesta_mock(Orquesta arrayOrquesta[], int size,int *contadorIdOrquesta)
{
    *contadorIdOrquesta = *contadorIdOrquesta + 1;
    arrayOrquesta[1].idOrquesta=*contadorIdOrquesta ;
    arrayOrquesta[1].isEmpty=0;
    strcpy(arrayOrquesta[1].nombre,"Orquesta1");
    strcpy(arrayOrquesta[1].lugar,"Lugar1");
    arrayOrquesta[1].tipo=1;

    *contadorIdOrquesta = *contadorIdOrquesta + 1;
    arrayOrquesta[2].idOrquesta=*contadorIdOrquesta ;
    arrayOrquesta[2].isEmpty=0;
    strcpy(arrayOrquesta[2].nombre,"Orquesta2");
    strcpy(arrayOrquesta[2].lugar,"Lugar1");
    arrayOrquesta[2].tipo=2;

    *contadorIdOrquesta = *contadorIdOrquesta+ 1;
    arrayOrquesta[3].idOrquesta=*contadorIdOrquesta ;
    arrayOrquesta[3].isEmpty=0;
    strcpy(arrayOrquesta[3].nombre,"Orquesta3");
    strcpy(arrayOrquesta[3].lugar,"Lugar2");
    arrayOrquesta[3].tipo=3;

    *contadorIdOrquesta = *contadorIdOrquesta+ 1;
    arrayOrquesta[4].idOrquesta=*contadorIdOrquesta ;
    arrayOrquesta[4].isEmpty=0;
    strcpy(arrayOrquesta[4].nombre,"Orquesta4");
    strcpy(arrayOrquesta[4].lugar,"Lugar3");
    arrayOrquesta[4].tipo=2;


}

