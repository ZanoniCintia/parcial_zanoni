//#ifndef LLAMADA_C_INCLUDED
#define LLAMADA_C_INCLUDED
#include "llamada.h"
#include "validaciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Llamada* llamada_new()
{
    return (Llamada*) malloc(sizeof(Llamada));
}
Llamada* llamada_newParametros(char* idStr,char* fecha, char* numero, char* idProblema, char* solucion)
{
    Llamada* retorno=NULL;
    Llamada* pAuxLlamada;

    if (idStr!=NULL && fecha!=NULL && numero!=NULL && idProblema!=NULL && solucion!=NULL)
    {
        pAuxLlamada=llamada_new();

        if (pAuxLlamada!=NULL)
        {
            if (!Llamada_setIdString(pAuxLlamada,idStr) &&
                !Llamada_setFecha(pAuxLlamada,fecha) &&
                !Llamada_getNumeroCliente(pAuxLlamada,numero) &&
                !Llamada_setIdProblema(pAuxLlamada,idProblema)&&
                !Llamada_setSolucion(pAuxLlamada,solucion))
                {
                    retorno=pAuxLlamada;
                }else
                     {
                        Llamada_delete(pAuxLlamada);
                     }
        }
    }
    return retorno;
}
int Llamada_delete(Llamada* this)
{
    int retorno=-1;

    if (this!=NULL )
    {
        free (this);
        retorno=0;
    }
    return retorno;
}
int Llamada_setId(Llamada* this,int id)
{
    int retorno=-1;

    if (this!=NULL && id>=0 && isValidInt(id,1,50000))
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}
int Llamada_setIdProblema(Llamada* this,char id)
{
    int retorno=-1;

    if (this!=NULL && id>=0 && isValidNumber(id))
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}
int Llamada_getId(Llamada* this,int* id)
{
    int retorno=-1;

    if (this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}
int Llamada_getIdProblema(Llamada* this,char* id)
{
    int retorno=-1;

    if (this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}
int Llamada_getIdString(Llamada* this, char* id)
{
    int retorno = -1;
    int buffer;

    if(this != NULL && id != NULL)
    {
        Llamada_getId(this,&buffer);
        sprintf(id,"%d",buffer);
        retorno = 0;
    }
    return retorno;
}
int Llamada_setNumeroCliente(Llamada* this,char numeroCliente)
{
    int retorno=-1;
    if (this!=NULL && numeroCliente>=0 && isValidNumber(numeroCliente))
    {
        this->numeroCliente=numeroCliente;
        retorno=0;
    }
    return retorno;
}
int Llamada_getNumeroCliente(Llamada* this,char* numeroCliente)
{
    int retorno=-1;
    if (this!=NULL && numeroCliente!=NULL)
    {
        *numeroCliente=this->numeroCliente;
        retorno=0;
    }
    return retorno;
}
/*int Llamada_setCantidadString(Llamada* this, char* cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad!=NULL)
    {
        if (isValidNumber(cantidad))
        {

            retorno= Llamada_setCantidad(this,atoi(cantidad));
        }
    }
    return retorno;
}

int Llamada_getCantidadString(Llamada* this, char* cantidad)
{
    int retorno = -1;
    int buffer;

    if(this != NULL && cantidad != NULL)
    {
        Llamada_getCantidad(this,&buffer);
        sprintf(cantidad,"%d",buffer);
        retorno = 0;
    }
    return retorno;
}*/
int Llamada_setIdString(Llamada* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id!=NULL)
    {
        if (isValidNumber(id))
        {

            retorno = Llamada_setId(this,atoi(id));
        }
    }
    return retorno;
}
int Llamada_setSolucion(Llamada* this,char* numeroCliente)
{
    int retorno=-1;

    if (this!=NULL && numeroCliente!=NULL)
    {
        strcpy(this->numeroCliente,numeroCliente);
        retorno=0;
    }
    return retorno;
}

int Llamada_getSolucion(Llamada* this,char* numeroCliente)
{
    int retorno=-1;

    if (this!=NULL && numeroCliente!=NULL )
    {
        strcpy(numeroCliente,this->numeroCliente);
        retorno=0;
    }
    return retorno;
}
int Llamada_setFecha(Llamada* this,char* fecha)
{
    int retorno=-1;

    if (this!=NULL && fecha!=NULL)// && isValidFecha(fecha)
    {
        strcpy(this->fecha,fecha);
        retorno=0;
    }
    return retorno;
}

int Llamada_getFecha(Llamada* this,char* fecha)
{
    int retorno=-1;

    if (this!=NULL && fecha!=NULL )
    {
        strcpy(fecha,this->fecha);
        retorno=0;
    }
    return retorno;
}
