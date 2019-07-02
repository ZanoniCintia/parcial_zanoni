#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "utn_validaciones.h"
#define TRUE 0
#define FALSE 1


int getString ( char* msg,char* msgError,int minimo, int maximo, int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {

        do
        {
            printf("%s",msg);
            __fpurge(stdin);
            fgets(bufferStr,sizeof(bufferStr)-1,stdin);
            if(strlen(bufferStr)>=minimo && strlen(bufferStr) <=maximo)
            {
                strncpy(resultado,bufferStr,maximo-1);
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",msgError);
        }while(reintentos>=0);
    }
    return retorno;
}

int getName (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];


    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {

            if(!isValidName(bufferStr))
            {
                bufferStr[strlen(bufferStr)-1] = '\0';
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}
int isValidName (char* cadena)
{
    int retorno = -1;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a')  )
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int getFloat(char* msg,char* msgError,float minimo,float maximo,int reintentos,float* resultado)
{
    char buffer[4096];
    int retorno = -1;

    if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>0)
    {
          do {
          if(!getString(msg,msgError,1,15,reintentos,buffer))
          {

                if(isValidFloat(buffer,minimo,maximo))
                {
                    *resultado=atof(buffer);
                    retorno =0;
                    break;
                }else{
                    printf("%s",msgError);
                }
               reintentos--;
           }
           }while(reintentos>=0);
    }
    return retorno;

}
int isValidFloat(char* numero, float minimo,float maximo)
{
    int retorno = 0;
    float aux;
    if(atof(numero)!=0)
    {
        aux=atof(numero);

        if(aux>=minimo && aux<=maximo)
        {

            retorno = 1;
        }

    }
    return retorno;
}
int getInt(char* msg,char* msgError,int minimo,int maximo,int reintentos,char *resultado)
{
    char buffer[4096];

    int retorno = -1;

    if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>0)
    {
        do
        {
            if(!getString(msg,msgError,minimo,maximo,reintentos,buffer))
            {
                if(isValidInt(buffer))
                {
                    strncpy(resultado,buffer,maximo);
                    retorno=0;
                    break;
                }else
                    {
                        printf("Horas invalida, reintente");
                    }
            }else{

                printf("%s",msgError);
            }
            reintentos--;
            }while(reintentos>=0);
    }
    return retorno;

}

int isValidInt(char* cadena)
{
    int retorno = 1;
    int i;
    for(i=0;cadena[i]!='\n';i++)
    {
        if(cadena[i]<'0' || cadena[i]>'9')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
int getEntero(char* msg,char* msgError,int minimo,int maximo,int reintentos,int *resultado)
{
    char buffer[4096];

    int retorno = -1;

    if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>0)
    {
        do
        {
            printf("%s",msg);
            scanf("%s",buffer);
            if(isValidEntero(buffer))
            {
                *resultado=atoi(buffer);
                retorno =0;
                break;
            }else{

                printf("%s",msgError);
            }
            reintentos--;
            }while(reintentos>=0);
    }
    return retorno;



}

int isValidEntero(char* cadena)
{
    int retorno = 0;
    int i;
    if(cadena != NULL)
    {
        for(i=0; cadena[i]!='\0'; i++)
        {
            if(cadena[i] >= '0' && cadena[i]<='9')
            {
                retorno = 1;
            }
        }
    }
    return retorno;
}

int isValidDni(char* cadena)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    int contadorPunto=0;
    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'0' || cadena[i]>'9') && (cadena[i]!='.'))
        {
            retorno=0;
        }
        if (cadena[i]=='.')
        {
            contadorPunto++;
        }
        if(contadorPunto>2)
        {
            retorno=FALSE;
        }
        if ((cadena[1]=='.' && cadena[5]=='.') || (cadena[2]=='.' && cadena[6]=='.'))
        {
            retorno=1;
        }
    }
    return retorno;
}

int isNumber (char* pString)
{
    int i=0;
    while(pString[i]!='\0')
    {
        if(pString[i]<'0' || pString[i]>'9')
        {
            return FALSE;
        }
        i++;
    }
    return TRUE;
}

int isValidFloatNumber(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int isValidNumber(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int isCuit (char* pString)
{
    int retorno=FALSE;
    int i=0;
    while(pString[i]!='\0')
    {
        if((pString[i]!='-')&&(pString[i]<'0' || pString[i]>'9'))
        {
            return FALSE;
        }
        else if((pString[2]=='-')&&(pString[10]=='-' || pString[11]=='-'))
        {
            retorno=TRUE;
        }
        i++;
    }
    return retorno;
}

int isTelefono (char* pString)
{
    int i=0;
    int contadorGuion=0;
    while(pString[i]!='\0')
    {
        if((pString[i]!=' ')&&(pString[i]!='-')&&(pString[i]<'0' || pString[i]>'9'))
        {
            return FALSE;
        }
        if(pString[i]=='-')
        {
            contadorGuion++;
        }
        i++;
    }
    if(contadorGuion==1)
        {
            return TRUE;
        }
    return FALSE;
}
/*
int isEmail(char* cadena)
{
    int retorno=TRUE;
    int contadorArroba=0;
    int i;
    for (i=0;i<50;i++)
    {
       while (cadena[i]!='\0')
        {
            if ((cadena[i]=='-')&&(cadena[i]=='_')&& (cadena[i]=='.')
                && (cadena[i]>='0' || cadena[i]<='9') && (cadena[i]>='A'||cadena[i]<='Z') &&
                (cadena[i]>='a' || cadena[i]<='z') && (cadena[i]=='@'))
            {
                retorno=TRUE;
                break;
            }
            if(cadena[i]=='@')
            {
                contadorArroba++;
            }
        }
    }
    if(contadorArroba==0 || contadorArroba>1)
    {
        retorno=FALSE;
    }
    return retorno;
}*/

int isValidEmail(char* cadena)
{
    int contador=0;
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'-' && cadena[i]!='+') || (cadena[i]>'9' && cadena[i]<'@') ||
           (cadena[i]>'Z' && cadena[i]!='_' && cadena[i]<'a')|| cadena[i]>'z')
        {
            retorno=0;
            break;
        }

        if (cadena[i]=='@')
        {
            contador++;
        }
    }

    if (contador==0 || contador>1)
    {
        retorno=0;
    }
    return retorno;
}

int isValidSex(char letra, char maximo, char minimo)
{
    int retorno = TRUE;

    if((letra != 'f') && (letra != 'F') && (letra != 'm') && (letra != 'M'))
    {
        retorno = FALSE;
    }
    return retorno;
}

/*
int isValidEmail(char* cadena)
{
    int retorno=TRUE;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    int contadorArroba=0;
    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'-' && cadena[i]!='+') || (cadena[i]>'9' && cadena[i]<'@') ||
           (cadena[i]>'Z' && cadena[i]!='_' && cadena[i]<'a')|| cadena[i]>'z')
        {
            retorno=FALSE;
        }
        if(cadena[i]=='@')
        {
            contadorArroba++;
        }
    }
        if(contadorArroba==1)
        {
            retorno=TRUE;
        }
    return retorno;
}
int isValidEmail(char* cadena)
{
    int retorno=TRUE;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    int contadorArroba=0;
    for(i=0;cadena[i]!='\0';i++)
    {
        if (cadena[i]=='@')
        {
            contadorArroba++;
            if (contadorArroba==1 && cadena[i]=='_' && cadena[i]=='-' && cadena[i]=='.' &&
                (cadena[i]>=0 || cadena[i]<=9) && (cadena[i]>'Z' || cadena[i]<'A') &&
                (cadena[i]>'z' || cadena[i]<'a'))
            {
                retorno=TRUE;
                break;
            }else
                {
                    retorno=FALSE;
                }
        }
    }
    return retorno;
}*/

int isValidAlphanumeric(char* cadena)
{
    int retorno=TRUE;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;cadena[i]!='\0';i++)
    {
        if(cadena[i]<'0' || (cadena[i]>'9' && cadena[i]<'A') || (cadena[i]>'Z' && cadena[i]<'a') || cadena[i]>'z' )
        {
            retorno=FALSE;
            break;
        }
    }
    return retorno;
}

int isValidFecha(char *cadena)
{
    int retorno=TRUE;
    int i;
    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'0' || cadena[i]>'9') && (cadena[i]!= '-' ))
        {
            retorno=FALSE;
        }
    }
    return retorno;
}



