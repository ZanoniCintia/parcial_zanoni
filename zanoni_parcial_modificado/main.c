#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "utn.h"
#include "orquesta.h"
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
    char c;

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
    {   system("clear");
        utn_getUnsignedInt("\n1- Menu orquesta\n2- Menu musicos \n3- Menu instrumentos\n4- Informes\n5- Salir\nIngrese su opcion: ","\nOpcion Invalida.",1,sizeof(int),1,6,1,&primeraOpcion);
        switch(primeraOpcion)
        {
            case 1:
                do{
                system("clear");
                utn_getUnsignedInt("\n\n-------MENU ORQUESTAS-------\n\n1) Alta \n2) Baja\n3) Listar \n4) Salir\nIngrese la opcion: ",                   //cambiar
                                   "\nError",1,sizeof(int),1,6,1,&opcion);

                switch(opcion)
                {
                case 1:
                    system("clear");
                    orquesta_alta(arrayOrquesta,QTY_ARRAY_ORQUESTA,&contadorIdOrquesta);
                    printf("\nAlta exitosa, id creado es :%d",contadorIdOrquesta);
                    printf("\n\n Presione una tecla para continuar...");
                    c = getchar();
                    break;

                case 2:
                    system("clear");
                    orquesta_listar(arrayOrquesta,QTY_ARRAY_ORQUESTA);
                    musico_Y_orquesta_baja(arrayOrquesta,QTY_ARRAY_ORQUESTA,arrayMusicos,QTY_ARRAY_MUSICO);
                    printf("\n\n Presione una tecla para continuar...");
                    c = getchar();
                    break;

                case 3:
                    system("clear");
                    orquesta_listar(arrayOrquesta,QTY_ARRAY_ORQUESTA);
                    printf("\n\n Presione una tecla para continuar...");
                    c = getchar();
                    break;
                case 4:
                    break;
                }
                }while(opcion!=4);
            break;

            case 2:
               do{
                    system("clear");
                    utn_getUnsignedInt("\n\n-------MENU MUSICOS-------\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar\n5) Salir\nIngrese su opcion: ",                   //cambiar
                                       "\nError",1,sizeof(int),1,6,1,&opcion);

                    switch(opcion)
                    {
                    case 1:
                        system("clear");
                        musicos_alta(arrayMusicos,QTY_ARRAY_MUSICO,arrayOrquesta,QTY_ARRAY_ORQUESTA,arrayInstrumentos,QTY_ARRAY_INSTRUMENTOS,&contadorIdMusico);                   //cambiar
                        printf("\n\n Presione una tecla para continuar...");
                        c = getchar();
                        break;

                    case 2:
                        system("clear");
                        musicos_listar(arrayMusicos,QTY_ARRAY_MUSICO);
                        musicos_modificar(arrayMusicos,QTY_ARRAY_MUSICO);
                        printf("\n\n Presione una tecla para continuar...");
                        c = getchar();
                        break;

                    case 3:
                        system("clear");
                        musicos_listar(arrayMusicos,QTY_ARRAY_MUSICO);
                        musicos_baja(arrayMusicos,QTY_ARRAY_MUSICO);
                        printf("la baja fue exitosa");
                        printf("\n\n Presione una tecla para continuar...");
                        c = getchar();
                        break;

                    case 4:
                        system("clear");
                        musicos_listar(arrayMusicos,QTY_ARRAY_MUSICO);
                        printf("\n\n Presione una tecla para continuar...");
                        c = getchar();
                        break;

                    case 5:

                        break;
                    }
                }while(opcion!=5);
            break;


            case 3:
                do{
                 system("clear");
                 utn_getUnsignedInt("\n\n-------MENU INSTRUMENTOS-------\n\n1) Alta \n2) Baja \n3) Listar \n4) Salir\nIngrese su opcion: ",                   //cambiar
                                   "\nError",1,sizeof(int),1,6,1,&opcion);

                switch(opcion)
                {
                case 1:
                    system("clear");
                    instrumentos_alta(arrayInstrumentos,QTY_ARRAY_INSTRUMENTOS,&contadorIdInstrumentos);
                    printf("\n\n Presione una tecla para continuar...");
                    c = getchar();
                    break;

                case 2:
                    system("clear");
                    instrumentos_baja(arrayInstrumentos,QTY_ARRAY_INSTRUMENTOS);
                    printf("\n\n Presione una tecla para continuar...");
                    c = getchar();
                    break;
                case 3:
                    system("clear");
                    instrumentos_listar(arrayInstrumentos, QTY_ARRAY_INSTRUMENTOS);
                    printf("\n\n Presione una tecla para continuar...");
                    c = getchar();
                    break;
                case 4:
                break;
                }

                }while(opcion!=4);
            break;


            case 4:
                do{
                system("clear");
                utn_getUnsignedInt("-------MENU INFORMES-------\n\n1) Listar orquesta por lugar\n2) Músicos menores a 25 años\n3) Orquesta con menos de seis musicos\n4) Lista de instrumentos de una orquesta \n5) Orquestas completas\n6) Orquesta con menos musicos \n7) Promedio de instrumentos por orquesta\n8) Musicos que NO tocan vientos\n9)Salir\nIngrese la opcion: ",                   //cambiar
                                   "\nError",1,sizeof(int),1,6,1,&opcion);

                switch(opcion)
                {
                case 1:
                    system("clear");
                    printf("LISTADO DE ORQUESTA POR LUGAR\n\n");
                    inf_orquesta_listarLugar(arrayOrquesta, QTY_ARRAY_ORQUESTA);
                    printf("\n\n Presione una tecla para continuar...");
                    c = getchar();
                    break;
                case 2:
                    system("clear");
                    printf("LISTADO DE MUSICOS MENORES DE 25 AÑOS\n\n");
                    inf_musicos_mostrarArray(arrayMusicos,QTY_ARRAY_MUSICO);
                    printf("\n\n Presione una tecla para continuar...");
                    c = getchar();
                    break;
                case 3:
                    system("clear");
                    printf("LISTADO DE ORQUESTAS CON MENOS DE 6 MUSICOS\n\n");
                    inf_orquesta_listadoMenosSeis(arrayOrquesta,QTY_ARRAY_ORQUESTA,arrayMusicos,QTY_ARRAY_MUSICO);
                    printf("\n\n Presione una tecla para continuar...");
                    c = getchar();
                    break;
                case 4:
                    system("clear");
                    printf("LISTADO DE INSTRUMENTOS POR ORQUESTA\n\n");
                    inf_musicos_InstrumentosPorOrquesta(arrayMusicos,QTY_ARRAY_MUSICO,arrayInstrumentos,QTY_ARRAY_INSTRUMENTOS);
                    printf("\n\n Presione una tecla para continuar...");
                    c = getchar();

                case 5:

                    break;
                case 6:
                    system("clear");
                    printf("LISTADO ORQUESTAS CON MENOS MUSICOS\n\n");
                    inf_orquesta_MenorCantidadMusicos(arrayOrquesta,QTY_ARRAY_ORQUESTA,arrayMusicos,QTY_ARRAY_MUSICO);
                    printf("\n\n Presione una tecla para continuar...");
                    c = getchar();
                    break;

                case 7:
                    system("clear");
                    printf("LISTADO DE PROMEDIO DE INSTRUMENTO POR ORQUESTA\n\n");
                    inf_orquesta_calcularPromedioInstrumentos(arrayOrquesta,QTY_ARRAY_ORQUESTA,arrayMusicos,QTY_ARRAY_MUSICO );
                    printf("\n\n Presione una tecla para continuar...");
                    c = getchar();
                    break;

                case 8:
                    system("clear");
                    printf("LISTADO DE MUSICOS QUE NO TOCAN VIENTOS\n\n");
                    inf_musicos_listarPorInstrumentos(arrayMusicos, QTY_ARRAY_MUSICO);
                    printf("\n\n Presione una tecla para continuar...");
                    c = getchar();
                    break;

                    break;
                case 9:

                    break;
                }
                }while(opcion!=9);
            break;
        }
        }while(primeraOpcion!=6);
    return 0;
}





