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

int orquesta_calcularPromedioInstrumentos(Orquesta *arrayOrquesta,int lenOrquesta, Instrumentos *arrayInstrumentos,int lenInstrumentos )
{
    int i;
    //int acumuladorEdadesEncimaPromedio=0;
    //int acumuladorEdadesDebajoPromedio=0;
    float acumulador=0;
    int cantidad=0;
    float promedio;
    int retorno = -1;
    for(i=0;i<lenInstrumentos;i++)
    {
       if(arrayInstrumentos[i].isEmpty==0)
       {
            acumulador+=arrayOrquesta[i].idOrquesta;
            cantidad++;
       }
       retorno = 0;
    }
    promedio=acumulador/cantidad;
    printf("el promedio de instrumentos por orquesta  es: %.2f\n",promedio);
    /*for(i=0;i<len;i++)
    {
        if((arrayMusicos[i].isEmpty==0)&&(arrayMusicos[i].edad>promedio))
        {
            acumuladorEdadesEncimaPromedio++;
        }

        if((arrayMusicos[i].isEmpty==0)&&(arrayMusicos[i].edad<promedio))
        {
            acumuladorEdadesDebajoPromedio++;
        }
    }*/
   // printf("la cantidad de musicos con edades mayores al promedio es : %d\n",acumuladorEdadesEncimaPromedio);

    //printf("la cantidad de musicos con edades menores al promedio es : %d\n",acumuladorEdadesDebajoPromedio);
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
    //int cantidad=0;
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
int musicos_listarPorInstrumentos(Musicos array[], int size)                      //cambiar socios
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
                    array[i].idMusico,array[i].nombre,array[i].apellido,array[i].edad,array[i].idOrquesta,array[i].idInstrumento);      //cambiar todos
                }

        }
        retorno=0;
    }
    return retorno;
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

int orquesta_listarLugar(Orquesta array[], int size)                      //cambiar autor
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
               }              //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}
