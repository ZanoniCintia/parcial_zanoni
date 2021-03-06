#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"  //cambiar por nombre entidad
#include "musico.h"
#include "instrumentos.h"
#include "informes.h"
#define QTY_ARRAY_ORQUESTA 51
#define QTY_ARRAY_MUSICO 51
#define QTY_ARRAY_INSTRUMENTOS 51
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    int opcion;
    int contadorIdOrquesta=0;
    //Orquesta tipo;
    Orquesta arrayOrquesta[QTY_ARRAY_ORQUESTA];
    orquesta_Inicializar(arrayOrquesta,QTY_ARRAY_ORQUESTA);
    orquesta_mock(arrayOrquesta, QTY_ARRAY_ORQUESTA, &contadorIdOrquesta) ;

    int contadorIdMusico=0;
    Musicos arrayMusicos[QTY_ARRAY_MUSICO];
    musicos_Inicializar(arrayMusicos,QTY_ARRAY_MUSICO);
    musicos_mock(arrayMusicos, QTY_ARRAY_MUSICO, &contadorIdMusico);

    int contadorIdInstrumentos=0;
    Instrumentos arrayInstrumentos[QTY_ARRAY_INSTRUMENTOS];
    instrumentos_Inicializar(arrayInstrumentos,QTY_ARRAY_INSTRUMENTOS);
    instrumentos_mock(arrayInstrumentos, QTY_ARRAY_INSTRUMENTOS, &contadorIdInstrumentos) ;


    int primeraOpcion;
    do
    {
        utn_getUnsignedInt("\n1-Menu orquesta\n2-Menu musicos \n3-Menu instrumentos\n4-Informes\n5-Salir\nIngrese su opcion: ","\nOpcion Invalida.",1,sizeof(int),1,6,1,&primeraOpcion);
        system("clear");
        switch(primeraOpcion)
        {
            case 1:
                do{
                utn_getUnsignedInt("\n\n-------MENU ORQUESTAS-------\n\n1) Alta \n2) Baja\n3)Listar \n4)Salir\nIngrese la opcion: ",                   //cambiar
                                   "\nError",1,sizeof(int),1,6,1,&opcion);
                system("clear");
                switch(opcion)
                {
                case 1: //Alta
                    orquesta_alta(arrayOrquesta,QTY_ARRAY_ORQUESTA,&contadorIdOrquesta);
                    printf("\nAlta exitosa, id creado es :%d",contadorIdOrquesta);                   //cambiar
                    break;

                case 2: //Modificar
                    orquesta_listar(arrayOrquesta,QTY_ARRAY_ORQUESTA);
                    musico_Y_orquesta_baja(arrayOrquesta,QTY_ARRAY_ORQUESTA,arrayMusicos,QTY_ARRAY_MUSICO);
                    break;

                case 3: //Baja
                    orquesta_listar(arrayOrquesta,QTY_ARRAY_ORQUESTA);                //cambiar
                    break;
                case 4:
                    break;
                }
                }while(opcion!=4);
            break;

            case 2:
               do{
                    utn_getUnsignedInt("\n\n-------MENU MUSICOS-------\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar\n5)Salir\nIngrese su opcion: ",                   //cambiar
                                       "\nError",1,sizeof(int),1,6,1,&opcion);
                    system("clear");
                    switch(opcion)
                    {
                    case 1: //Alta
                        musicos_alta(arrayMusicos,QTY_ARRAY_MUSICO,arrayOrquesta,QTY_ARRAY_ORQUESTA,arrayInstrumentos,QTY_ARRAY_INSTRUMENTOS,&contadorIdMusico);                   //cambiar
                        break;

                    case 2: //Modificar
                        musicos_listar(arrayMusicos,QTY_ARRAY_MUSICO);
                        musicos_modificar(arrayMusicos,QTY_ARRAY_MUSICO);                   //cambiar
                        break;

                    case 3: //Baja
                        musicos_listar(arrayMusicos,QTY_ARRAY_MUSICO);
                        musicos_baja(arrayMusicos,QTY_ARRAY_MUSICO);
                        printf("la baja fue exitosa");                  //cambiar
                        break;

                    case 4://Listar
                        musicos_listar(arrayMusicos,QTY_ARRAY_MUSICO);                   //cambiar
                        break;

                    case 5:

                        break;
                    }
                }while(opcion!=5);
            break;


            case 3:
                do{
                 utn_getUnsignedInt("\n\n-------MENU INSTRUMENTOS-------\n\n1)Alta \n2)baja \n3)listar \n4)Salir\nIngrese su opcion: ",                   //cambiar
                                   "\nError",1,sizeof(int),1,6,1,&opcion);
                system("clear");
                switch(opcion)
                {
                case 1: //Alta
                    instrumentos_alta(arrayInstrumentos,QTY_ARRAY_INSTRUMENTOS,&contadorIdInstrumentos);                   //cambiar
                    break;

                case 2: //Modificar
                    instrumentos_baja(arrayInstrumentos,QTY_ARRAY_INSTRUMENTOS);                   //cambiar
                    break;
                case 3:
                    instrumentos_listar(arrayInstrumentos, QTY_ARRAY_INSTRUMENTOS);
                    break;
                case 4:
                break;
                }

                }while(opcion!=4);
            break;


            case 4:
                do{
                utn_getUnsignedInt("\n\n-------MENU INFORMES-------\n\n1)Listar orquesta por lugar\n2)Musicos menores a 25 años\n3)Promedio de instrumentos por orquesta\n4)Musicos que no tocan vientos\n5)Salir\nIngrese la opcion: ",                   //cambiar
                                   "\nError",1,sizeof(int),1,6,1,&opcion);
                system("clear");
                switch(opcion)
                {
                case 1:
                    orquesta_listarLugar(arrayOrquesta, QTY_ARRAY_ORQUESTA);
                    break;
                case 2: //Modificar
                    musicos_mostrarArray(arrayMusicos,QTY_ARRAY_MUSICO);
                    break;
                case 3:
                    orquesta_calcularPromedioInstrumentos(arrayOrquesta,QTY_ARRAY_ORQUESTA,arrayInstrumentos,QTY_ARRAY_INSTRUMENTOS );

                     break;
                case 4:
                    musicos_listarPorInstrumentos(arrayMusicos, QTY_ARRAY_MUSICO);
                    break;
                 case 5:
                    break;
                }
                }while(opcion!=5);
            break;
        }
        }while(primeraOpcion!=6);
    return 0;
}





