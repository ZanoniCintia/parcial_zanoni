#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musico.h"
#include "instrumentos.h"
#include "orquesta.h"


int inf_orquesta_calcularPromedioInstrumentos(Orquesta *arrayOrquesta,int lenOrquesta, Musicos *arrayMusicos,int lenMusicos )
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

int inf_musicos_mostrarArray(Musicos *arrayMusicos, int len)
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


int inf_musicos_cantidadDeMusicosEnCadaOrquesta(Musicos *arrayMusicos,Orquesta *arrayOrquesta,int len)
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
int inf_musicos_listarPorInstrumentos(Musicos array[], int size)
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

int inf_orquesta_listadoMenosSeis(Orquesta OrquestaArray[],int Osize,Musicos MusicoArray[], int Msize)
{
    int i;
    int j;


        for(i=0;i<Osize;i++)
        {
            if (!OrquestaArray[i].isEmpty)
            {
                if (musicos_CantidadPorOrquesta(MusicoArray,Msize,OrquestaArray[i].idOrquesta) < 6)
                {
                    printf("\n ORQUESTA:");

                    printf(" ID: %d - nombre: %s - Lugar : %s - Tipo : %d \n",
                      OrquestaArray[i].idOrquesta,OrquestaArray[i].nombre,OrquestaArray[i].lugar,OrquestaArray[i].tipo);

                    for(j=0;j<Msize;j++)
                    {
                        if (!MusicoArray[j].isEmpty && MusicoArray[j].idOrquesta == OrquestaArray[i].idOrquesta)
                        {
                            printf(" ->  MUSICO - ID: %d - Nombre: %s - Apellido: %s - Edad: %d - id Instrumento: %d \n",
                           MusicoArray[j].idMusico,MusicoArray[j].nombre,MusicoArray[j].apellido,MusicoArray[j].edad,MusicoArray[j].idInstrumento);
                        }
                    }
                }
            }
        }
    return 0;
}

int inf_orquesta_MenorCantidadMusicos(Orquesta OrquestaArray[],int Osize,Musicos MusicoArray[], int Msize)
{
    int i;
    int j;
    int cantidad=9999;

        for(i=0;i<Osize;i++){
            if (!OrquestaArray[i].isEmpty)
            {
                if (musicos_CantidadPorOrquesta(MusicoArray,Msize,OrquestaArray[i].idOrquesta) < cantidad)
                {
                    cantidad = musicos_CantidadPorOrquesta(MusicoArray,Msize,OrquestaArray[i].idOrquesta);
                }
            }
        }

        for(i=0;i<Osize;i++)
        {
            if (!OrquestaArray[i].isEmpty)
            {
                if (musicos_CantidadPorOrquesta(MusicoArray,Msize,OrquestaArray[i].idOrquesta) == cantidad)
                {
                    printf("\n ORQUESTA:");

                    printf(" ID: %d - nombre: %s - Lugar : %s - Tipo : %d \n",
                      OrquestaArray[i].idOrquesta,OrquestaArray[i].nombre,OrquestaArray[i].lugar,OrquestaArray[i].tipo);

                    for(j=0;j<Msize;j++)
                    {
                        if (!MusicoArray[j].isEmpty && MusicoArray[j].idOrquesta == OrquestaArray[i].idOrquesta)
                        {
                            printf(" ->  MUSICO - ID: %d - Nombre: %s - Apellido: %s - Edad: %d - id Instrumento: %d \n",
                           MusicoArray[j].idMusico,MusicoArray[j].nombre,MusicoArray[j].apellido,MusicoArray[j].edad,MusicoArray[j].idInstrumento);
                        }
                    }
                }
            }
        }


    return 0;
}

int inf_orquesta_buscarPorLugar(Orquesta *array, int len, char *lugar)
{

    int retorno = -1;
    /*int i;
    char auxLug[30];

    if (array!=NULL && len>0 && lugar!=NULL)
    {

        for(i=0; i<len; i++)
        {
            if(array[i].lugar==0)
            {
                retorno=i;
                break;
            }
        }
    }
    */
    return retorno;
}

int inf_orquesta_listarLugar(Orquesta array[], int size)
{
    int retorno=-1;
    int i;
    char tipo[30];
    char auxLugar[50];

    if(array!=NULL && size>=0)
    {

        getString ("Ingrese lugar de orquesta a buscar :","Id invalido",1,30,1,auxLugar);
        for(i=0;i<size;i++)
        {
            if(!array[i].isEmpty &&  strcmp(array[i].lugar,auxLugar) == 0)
                {
                //inf_orquesta_buscarPorLugar(array,size,tipo);
                orquesta_tipo(array[i],tipo);
                printf("\n ID: %d\n lugar : %s \ntipo : %s ",
                      array[i].idOrquesta,array[i].lugar,tipo);
               }
        }
        retorno=0;
    }
    return retorno;
}



int inf_musicos_InstrumentosPorOrquesta(Musicos Marray[],int Msize,Instrumentos IArray[], int Isize)
{

    int i;
    int j;
    int id;

        utn_getUnsignedInt("\nID a consultar: ","\nError",1,sizeof(int),1,Isize,1,&id);

        for(i=0;i<Msize;i++)
        {
            if (!Marray[i].isEmpty && Marray[i].idOrquesta == id)
            {
                 for(j=0;j<Isize;j++){
                    if(!IArray[j].isEmpty && IArray[j].idInstrumentos == Marray[i].idInstrumento)
                    {
                        printf("\nInstrumento : %s del tipo %d y lo toca el musico id %d llamado %s %s",IArray[j].nombre,IArray[j].tipo,Marray[i].idMusico,Marray[i].apellido,Marray[i].nombre);
                    }
                 }
            }
        }

    return 0;
}

int inf_orquestasCompletas(Orquesta Oarray[],int Osize,Musicos Marray[], int Msize, Instrumentos Iarray[],int Isize)
{
    int i;
    int j;
    int k;
    int contadorCuerdas;
    int contadorVientos;
    int contadorPercusion;

        for(i=0;i<Osize;i++)
        {
            if (!Oarray[i].isEmpty){
                contadorCuerdas = 0;
                contadorPercusion = 0;
                contadorVientos = 0;

                for(j=0;j<Msize;j++){
                    if(!Marray[j].isEmpty && Oarray[i].idOrquesta == Marray[j].idOrquesta){
                        for(k=0;k<Isize;k++){
                            if(!Iarray[k].isEmpty && Iarray[k].idInstrumentos == Marray[j].idInstrumento){
                                switch(Iarray[k].tipo){
                                    // tipo:\n1 Cuerdas : \n2 Viento-Madera : \n3 Viento-Metal : \n4 Percusion "

                                    case 1: //CUERDAS
                                        contadorCuerdas += 1;
                                        break;
                                    case 2: //Vientos
                                        contadorVientos += 1;
                                        break;
                                    case 3: //Vientos
                                        contadorVientos += 1;
                                        break;
                                    case 4:
                                        contadorPercusion += 1;
                                        break;
                                }
                            }
                        }
                    }
                }

                printf("\nOrquesta %d tiene %d cuerdas, %d vientos y %d Percuison",Oarray[i].idOrquesta,contadorCuerdas,contadorVientos,contadorPercusion);

              /*  if(contadorCuerdas>=4 && contadorVientos >= 4 && contadorPercusion >= 1){
                    printf("\n ID: %d - nombre: %s - Lugar : %s - Tipo : %d \n",
                    Oarray[i].idOrquesta,Oarray[i].nombre,Oarray[i].lugar,Oarray[i].tipo);
                }*/
            }
        }
    return 0;


}

