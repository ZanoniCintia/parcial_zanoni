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

int musicos_calcularPromedioEdades(Musicos *arrayMusicos,int len)
{
    int i;
    int acumuladorEdadesEncimaPromedio=0;
    int acumuladorEdadesDebajoPromedio=0;
    float acumulador=0;
    int cantidad=0;
    float promedio;
    int retorno = -1;
    for(i=0;i<len;i++)
    {
       if(arrayMusicos[i].isEmpty==0)
       {
            acumulador+=arrayMusicos[i].edad;
            cantidad++;
       }
       retorno = 0;
    }
    promedio=acumulador/cantidad;
    printf("el promedio de edades es: %.2f\n",promedio);
    for(i=0;i<len;i++)
    {
        if((arrayMusicos[i].isEmpty==0)&&(arrayMusicos[i].edad>promedio))
        {
            acumuladorEdadesEncimaPromedio++;
        }

        if((arrayMusicos[i].isEmpty==0)&&(arrayMusicos[i].edad<promedio))
        {
            acumuladorEdadesDebajoPromedio++;
        }
    }
    printf("la cantidad de musicos con edades mayores al promedio es : %d\n",acumuladorEdadesEncimaPromedio);

    printf("la cantidad de musicos con edades menores al promedio es : %d\n",acumuladorEdadesDebajoPromedio);
    return retorno;
}

int musicos_mostrarArray(Musicos *arrayMusicos, int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        if(arrayMusicos[i].isEmpty==0)
        {
            printf("Id: %d \n", arrayMusicos[i].idMusico);
            printf("Nombre: %s \n",arrayMusicos[i].nombre);
            printf("Apellido: %s \n",arrayMusicos[i].apellido);
            printf("Edad: %d \n",arrayMusicos[i].edad);
            printf("Id instrumento: %d \n",arrayMusicos[i].idInstrumento);
            printf("Id orquesta: %d \n\n",arrayMusicos[i].idOrquesta);

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
