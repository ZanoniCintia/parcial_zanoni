#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musico.h"
#include "instrumentos.h"
#include "orquesta.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array musicos
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musicos_Inicializar(Musicos array[], int size)                                    //cambiar socios
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

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array musicos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musicos_buscarEmpty(Musicos array[], int size, int* posicion)                    //cambiar socios
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
* \param array musicos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musicos_buscarID(Musicos array[], int size, int valorBuscado, int* posicion)                    //cambiar socios
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idMusico==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un string en un array
* \param array musicos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musicos_buscarNombreyApellido ( Musicos array[], int size, char* valorBuscado,char* apellidoBuscado, int* indice)                    //cambiar socios
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0 && strcmp(array[i].apellido,apellidoBuscado)==0)                                        //cambiar campo varString
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array musicos
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musicos_alta(Musicos array[], int size,Orquesta* arrayOrquesta,int lenOrquesta,Instrumentos* arrayInstrumento,int lenInstrumento, int* contadorID)                          //cambiar socios
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musicos_buscarEmpty(array,size,&posicion)==-1)                          //cambiar socios
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idMusico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;

            utn_getName("\ningrese nombre: ","\nError",1,TEXT_SIZE_MUSICO,1,array[posicion].nombre);
            utn_getName("\ningrese apellido: ","\nError",1,TEXT_SIZE_MUSICO,1,array[posicion].apellido);                    //mensaje + cambiar campo varString
            utn_getUnsignedInt("\n ingrese edad : ","\nError",1,99,1,99,1,&array[posicion].edad);
            orquesta_listar(arrayOrquesta,lenOrquesta);
            utn_getUnsignedInt("\n ingrese id orquesta : ","\nError",0,50,0,50,1,&array[posicion].idOrquesta);
            instrumentos_listar(arrayInstrumento,lenInstrumento);
            utn_getUnsignedInt("\n ingrese id instrumento : ","\nError",0,20,0,20,1,&array[posicion].idInstrumento);
                          //mensaje + cambiar campo varLongString
            printf("\n Posicion: %d\n ID: %d\n nombre : %s\n apellido: %s\n edad : %d\n id orquesta: %d \n id instrumento: %d",
                   posicion, array[posicion].idMusico,array[posicion].nombre,array[posicion].apellido,array[posicion].edad,array[posicion].idOrquesta,array[posicion].idInstrumento);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array musicos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musicos_baja(Musicos array[], int sizeArray)                                      //cambiar socios
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(musicos_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idMusico=0;                                                                   //cambiar campo id
            strcpy(array[posicion].nombre,"");                                                 //cambiar campo var//cambiar campo varFloat
            strcpy(array[posicion].apellido,"");
            array[posicion].edad=0;                                                  //cambiar campo varString
            array[posicion].idOrquesta=0;
            array[posicion].idInstrumento=0;
            retorno=0;
        }
    }
    return retorno;
}
int musicos_bajaPorOrquesta(Musicos array[],int sizeArray,int idOrquesta)
{
    int i;
    for(i=0;i<sizeArray;i++)
    {
        if(array[i].idOrquesta==idOrquesta)
        {
            array[i].isEmpty=1;
            array[i].idMusico=-1;
            strcpy(array[i].nombre,"");
            strcpy(array[i].apellido,"");
            array[i].edad=0;
            array[i].idOrquesta=-1;
            array[i].idInstrumento=-1;


        }
    }

return 0;

}
//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array socios Array de socios
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musicos_bajaValorRepetidoInt(Musicos array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idMusico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idMusico=0;                                                                   //cambiar campo id
                strcpy(array[i].nombre,"");                                                 //cambiar campo var//cambiar campo varFloat
                strcpy(array[i].apellido,"");
                array[i].edad=0;                                                  //cambiar campo varString
                array[i].idOrquesta=0;
                array[i].idInstrumento=0;                                                  //cambiar campo varString

                                                               //cambiar campo varLongString
                retorno=0;                                              //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array socios Array de socios
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musicos_modificar(Musicos array[], int sizeArray)                                //cambiar socios
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(musicos_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n nombre: %s\n apellido: %s\n edad: %d\n id orquesta : %d, \n id instrumento : %d",
                       posicion, array[posicion].idMusico,array[posicion].nombre,array[posicion].apellido,array[posicion].edad,array[posicion].idOrquesta,array[posicion].idInstrumento);
                utn_getChar("\nModificar: \nA-Edad \nB-id orquesta \nS:(salir)\ningrese opcion: ","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {

                    case 'A':
                        utn_getUnsignedInt("\ningrese edad : ","\nerror",1,99,1,99,1,&array[posicion].edad); //mensaje + cambiar campo varFloat
                        break;
                    case 'C':
                        utn_getUnsignedInt("\ningrese id orquesta : ","\nerror",0,50,0,50,1,&array[posicion].idOrquesta);//mensaje + cambiar campo varString
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}


int musicos_CantidadPorOrquesta(Musicos array[],int size, int IdOrquesta){
    int cantidad=0;
    int i;

        for(i=0;i<size;i++){
            if (!array[i].isEmpty && array[i].idOrquesta == IdOrquesta){
                    cantidad += 1;
                }
        }
    return cantidad;
}


/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array musicos
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int musicos_ordenarPorDobleCriterio(Musicos array[],int size, int orderFirst, int orderSecond)
{
    int retorno=-1;
    int i;
    Musicos buffer;
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
                else if(strcmp(array[i].nombre,array[i+1].nombre) == 0)
                {
                    if( ((array[i].apellido < array[i+1].apellido) && orderSecond) ||
                        ((array[i].apellido > array[i+1].apellido) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = array[i];
                        array[i] = array[i+1];
                        array[i+1] = buffer;
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

/** \brief Lista los elementos de un array
* \param array musicos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musicos_listar(Musicos array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n nombre: %s\n apellido: %s\n edad: %d\n id orquesta : %d \n id instrumento: %d",
                       array[i].idMusico,array[i].nombre,array[i].apellido,array[i].edad,array[i].idOrquesta,array[i].idInstrumento);
        }
        retorno=0;
    }
    return retorno;
}


void musicos_mock(Musicos arrayMusicos[], int size,int *contadorIdMusico)
{

    *contadorIdMusico = *contadorIdMusico + 1;
    arrayMusicos[1].idMusico=*contadorIdMusico;
    arrayMusicos[1].isEmpty=0;
    strcpy(arrayMusicos[1].nombre,"Mus1");
    strcpy(arrayMusicos[1].apellido,"Amus1");
    arrayMusicos[1].edad=30;
    arrayMusicos[1].idOrquesta=1;
    arrayMusicos[1].idInstrumento=2;

    *contadorIdMusico = *contadorIdMusico + 1;
    arrayMusicos[2].idMusico=*contadorIdMusico;
    arrayMusicos[2].isEmpty=0;
    strcpy(arrayMusicos[2].nombre,"Mus2");
    strcpy(arrayMusicos[2].apellido,"Amus2");
    arrayMusicos[2].edad=20;
    arrayMusicos[2].idOrquesta=2;
    arrayMusicos[2].idInstrumento=5;

    *contadorIdMusico = *contadorIdMusico + 1;
    arrayMusicos[3].idMusico=*contadorIdMusico;
    arrayMusicos[3].isEmpty=0;
    strcpy(arrayMusicos[3].nombre,"Mus3");
    strcpy(arrayMusicos[3].apellido,"Amus3");
    arrayMusicos[3].edad=25;
    arrayMusicos[3].idOrquesta=4;
    arrayMusicos[3].idInstrumento=2;

    *contadorIdMusico= *contadorIdMusico + 1;
    arrayMusicos[4].idMusico=*contadorIdMusico;
    arrayMusicos[4].isEmpty=0;
    strcpy(arrayMusicos[4].nombre,"Mus4");
    strcpy(arrayMusicos[4].apellido,"Amus4");
    arrayMusicos[4].edad=27;
    arrayMusicos[4].idOrquesta=4;
    arrayMusicos[4].idInstrumento=1;

    *contadorIdMusico= *contadorIdMusico + 1;
     arrayMusicos[5].idMusico=*contadorIdMusico;
    arrayMusicos[5].isEmpty=0;
    strcpy(arrayMusicos[5].nombre,"Mus5");
    strcpy(arrayMusicos[5].apellido,"Amus5");
    arrayMusicos[5].edad=22;
    arrayMusicos[5].idOrquesta=1;
    arrayMusicos[5].idInstrumento=3;

    *contadorIdMusico= *contadorIdMusico + 1;
    arrayMusicos[6].idMusico=*contadorIdMusico;
    arrayMusicos[6].isEmpty=0;
    strcpy(arrayMusicos[6].nombre,"Mus6");
    strcpy(arrayMusicos[6].apellido,"Amus6");
    arrayMusicos[6].edad=35;
    arrayMusicos[6].idOrquesta=3;
    arrayMusicos[6].idInstrumento=4;
}
int musico_Y_orquesta_baja(Orquesta array[], int sizeArray,Musicos arrayMusico[],int sizeArrayMusico)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            musicos_bajaPorOrquesta(arrayMusico,sizeArrayMusico,id);
            array[posicion].isEmpty=1;
            array[posicion].idOrquesta=0;
            strcpy(array[posicion].nombre,"");
            strcpy(array[posicion].lugar,"");
            array[posicion].tipo='v';

            retorno=0;
        }
    }
    return retorno;
}

