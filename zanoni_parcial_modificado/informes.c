#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musico.h"
#include "instrumentos.h"
#include "orquesta.h"

int musicos_ordenarMayoraMenor(Musicos *arrayMusicos,int len)
{
    int i;
    int j;
    int retorno =-1;
    Musicos aux;

    for(i=0; i<len; i++)
    {
        for(j=i+1; j<=len; j++)
        {
            if(strncmp(arrayMusicos[i].apellido,arrayMusicos[j].apellido,50)<0)
            {
                aux=arrayMusicos[i];
                arrayMusicos[i]=arrayMusicos[j];
                arrayMusicos[j]=aux;
                retorno =0;
            }
            else if(arrayMusicos[i].edad<arrayMusicos[j].edad)
            {
                aux=arrayMusicos[i];
                arrayMusicos[i]=arrayMusicos[j];
                arrayMusicos[j]=aux;
                retorno =0;
            }
        }
    }
    musicos_listar(arrayMusicos,len);
    return retorno;

}
int musicos_ordenarMenoraMayor(Musicos *arrayMusicos,int len)
{
    int i;
    int j;
    int retorno =-1;
    Musicos aux;

    for(i=0; i<len; i++)
    {
        for(j=i+1; j<=len; j++)
        {
            if(strncmp(arrayMusicos[i].apellido,arrayMusicos[j].apellido,50)<0)
            {
                aux=arrayMusicos[i];
                arrayMusicos[i]=arrayMusicos[j];
                arrayMusicos[j]=aux;
                retorno =0;
            }
            else if(strcmp(arrayMusicos[i].apellido,arrayMusicos[j].apellido)==0)
            {
                if(arrayMusicos[i].edad<arrayMusicos[j].edad)
                {
                    aux=arrayMusicos[i];
                    arrayMusicos[i]=arrayMusicos[j];
                    arrayMusicos[j]=aux;
                    retorno =0;
                }
            }
        }
    }

    return retorno;

}

int orquesta_calcularPromedioInstrumentos(Orquesta *arrayOrquesta,int lenOrquesta, Musicos *arrayMusicos,int lenMusicos )
{
    int i;
    float acumulador=0;
    float cantidad=0;
    float promedio;
    int retorno = -1;
    for(i=0;i<lenMusicos;i++)
    {
       if(arrayMusicos[i].isEmpty==0)
       {

            cantidad++;
       }
       retorno = 0;
    }
     for(i=0;i<lenOrquesta;i++)
    {
       if(arrayOrquesta[i].isEmpty==0)
       {

            acumulador++;
       }
       retorno = 0;
    }
    promedio=cantidad/acumulador;
    printf("el promedio de instrumentos por orquesta  es: %.2f\n",promedio);

    return retorno;
}

int musicos_mostrarArray(Musicos *arrayMusicos, int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        if(arrayMusicos[i].isEmpty==0)
        {
            if(arrayMusicos[i].edad<25)
            {
            printf("Id: %d \n", arrayMusicos[i].idMusico);
            printf("Nombre: %s \n",arrayMusicos[i].nombre);
            printf("Apellido: %s \n",arrayMusicos[i].apellido);
            printf("Edad: %d \n",arrayMusicos[i].edad);
            printf("Id instrumento: %d \n",arrayMusicos[i].idInstrumento);
            printf("Id orquesta: %d \n\n",arrayMusicos[i].idOrquesta);
            }
        }
    }
    return 0;
}

int musicos_cantidadDeMusicosEnCadaOrquesta(Musicos *arrayMusicos,Orquesta *arrayOrquesta,int len)
{
    int i;
    int acumuladorMusicos=0;
    int musicos;
    int retorno = -1;
    for(i=0;i<len;i++)
    {
       if(arrayOrquesta[i].isEmpty==0)
       {
            acumuladorMusicos+=arrayMusicos[i].idMusico;

       }
       retorno = 0;
    }
    musicos=acumuladorMusicos;
    printf("la cantidad de musicos por orquesta es: %d\n",musicos);
    return retorno;
}
int musicos_listarPorInstrumentos(Musicos array[], int size)
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
            if((array[i].idInstrumento==1) || (array[i].idInstrumento==4))

                {
                    printf("\n ID: %d\n nombre: %s\n apellido: %s\n edad: %d\n id orquesta : %d \n id instrumento: %d",
                    array[i].idMusico,array[i].nombre,array[i].apellido,array[i].edad,array[i].idOrquesta,array[i].idInstrumento);
                }

        }
        retorno=0;
    }
    return retorno;
}

int orquesta_listadoMenosSeis(Orquesta OrquestaArray[],int Osize,Musicos MusicoArray[], int Msize){
    int i;
    int j;
    int cantidad;

        for(i=0;i<Osize;i++){
            if (!OrquestaArray[i].isEmpty){
                if (musicos_CantidadPorOrquesta(MusicoArray,Msize,OrquestaArray[i].idOrquesta) < 6){
                    printf("\n ORQUESTA:");

                    printf(" ID: %d - nombre: %s - Lugar : %s - Tipo : %d \n",
                      OrquestaArray[i].idOrquesta,OrquestaArray[i].nombre,OrquestaArray[i].lugar,OrquestaArray[i].tipo);

                    for(j=0;j<Msize;j++){
                        if (!MusicoArray[j].isEmpty && MusicoArray[j].idOrquesta == OrquestaArray[i].idOrquesta){
                            printf(" ->  MUSICO - ID: %d - Nombre: %s - Apellido: %s - Edad: %d - id Instrumento: %d \n",
                           MusicoArray[j].idMusico,MusicoArray[j].nombre,MusicoArray[j].apellido,MusicoArray[j].edad,MusicoArray[j].idInstrumento);
                        }
                    }
                }
            }
        }
    return 0;
}

int orquesta_MenorCantidadMusicos(Orquesta OrquestaArray[],int Osize,Musicos MusicoArray[], int Msize){
    int i;
    int j;
    int cantidad=9999;

        for(i=0;i<Osize;i++){
            if (!OrquestaArray[i].isEmpty){
                if (musicos_CantidadPorOrquesta(MusicoArray,Msize,OrquestaArray[i].idOrquesta) < cantidad){
                    cantidad = musicos_CantidadPorOrquesta(MusicoArray,Msize,OrquestaArray[i].idOrquesta);
                }
            }
        }

        for(i=0;i<Osize;i++){
            if (!OrquestaArray[i].isEmpty){
                if (musicos_CantidadPorOrquesta(MusicoArray,Msize,OrquestaArray[i].idOrquesta) == cantidad){
                    printf("\n ORQUESTA:");

                    printf(" ID: %d - nombre: %s - Lugar : %s - Tipo : %d \n",
                      OrquestaArray[i].idOrquesta,OrquestaArray[i].nombre,OrquestaArray[i].lugar,OrquestaArray[i].tipo);

                    for(j=0;j<Msize;j++){
                        if (!MusicoArray[j].isEmpty && MusicoArray[j].idOrquesta == OrquestaArray[i].idOrquesta){
                            printf(" ->  MUSICO - ID: %d - Nombre: %s - Apellido: %s - Edad: %d - id Instrumento: %d \n",
                           MusicoArray[j].idMusico,MusicoArray[j].nombre,MusicoArray[j].apellido,MusicoArray[j].edad,MusicoArray[j].idInstrumento);
                        }
                    }
                }
            }
        }


    return 0;
}

int orquesta_buscarPorLugar(Orquesta *array, int len, char *lugar)
{
    int i;
    int retorno = -1;
    if (array!=NULL && len>0 && lugar!=NULL)
    {
        for(i=0; i<len; i++)
        {
            if(array[i].lugar==lugar)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

/*int inf_orquestasMenosSeisMusicos(Musicos* arrayMusico, int sizeMusico, Orquesta* arrayOrquesta, int sizeOrquesta)
{
    int retorno = -1;
    int arraySinRepetir[sizeMusico];
    int contador;
    int flag = 1;
    int i;
    if(arrayMusico != NULL && arrayOrquesta != NULL && sizeMusico > 0 && sizeOrquesta > 0)
    {
        for(i=0;i<sizeMusico;i++)
        {


        }
        retorno = 0;
    }
    return retorno;
}*/



int orquesta_listarLugar(Orquesta array[], int size)
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
                printf("\n ID: %d\n lugar : %s \ntipo : %s ",
                      array[i].idOrquesta,array[i].lugar,tipo);
               }
        }
        retorno=0;
    }
    return retorno;
}
