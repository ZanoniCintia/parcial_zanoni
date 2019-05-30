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
    {
        // MENU PRINCIPAL
        system("clear");
        utn_getUnsignedInt("-----MENU PRINCIPAL------ \n\n1) MENU ORQUESTAS\n2) MENU MUSICOS \n3) MENU INSTRUMENTOS\n4) INFORMES\n5) SALIR\n\n *Ingrese su opcion: ","\nOpcion Invalida.",1,sizeof(int),1,6,1,&primeraOpcion);
        switch(primeraOpcion)
        {
            case 1: // MENU ORQUESTA.
                do{
                system("clear");
                utn_getUnsignedInt("-------MENU ORQUESTAS-------\n\n1) ALTA DE ORQUESTA \n2) BAJA DE ORQUESTA\n3) LISTAR ORQUESTAS \n4) SALIR\n\n *Ingrese la opcion: ",                   //cambiar
                                   "\nError",1,sizeof(int),1,6,1,&opcion);

                switch(opcion)
                {
                    case 1: // ALTA DE ORQUESTA
                        system("clear");
                        printf("-------ALTA DE ORQUESTAS-------\n\n");
                        orquesta_alta(arrayOrquesta,QTY_ARRAY_ORQUESTA,&contadorIdOrquesta);
                        printf("\nAlta exitosa, id creado es :%d",contadorIdOrquesta);
                        printf("\n\n Presione una tecla para continuar...");
                        c = getchar();
                        break;

                    case 2:// BAJA DE ORQUESTA
                        system("clear");
                        printf("-------BAJA DE ORQUESTAS-------\n\n");
                        orquesta_listar(arrayOrquesta,QTY_ARRAY_ORQUESTA);
                        musico_Y_orquesta_baja(arrayOrquesta,QTY_ARRAY_ORQUESTA,arrayMusicos,QTY_ARRAY_MUSICO);
                        printf("\n\n Presione una tecla para continuar...");
                        c = getchar();
                        break;

                    case 3: // LISTADO DE ORQUESTAS
                        system("clear");
                        printf("-------LISTADO DE ORQUESTAS-------\n\n");
                        orquesta_listar(arrayOrquesta,QTY_ARRAY_ORQUESTA);
                        printf("\n\n Presione una tecla para continuar...");
                        c = getchar();
                        break;

                    case 4: // SALIR DE ORQUESTAS
                        break;
                }
                }while(opcion!=4);
            break;

            case 2: // MENU MUSICOS
               do{
                    system("clear");
                    utn_getUnsignedInt("-------MENU MUSICOS-------\n\n1) ALTA DE MUSICO \n2) MODIFICAR MUSICO \n3) BAJA DE MUSICO \n4) LISTAR MUSICOS\n5) SALIR\n\n *Ingrese su opcion: ",                   //cambiar
                                       "\nError",1,sizeof(int),1,6,1,&opcion);

                    switch(opcion)
                    {
                    case 1: // ALTA DE MUSICOS
                        system("clear");
                        printf("-------ALTA DE MUSICOS-------\n\n");
                        musicos_alta(arrayMusicos,QTY_ARRAY_MUSICO,arrayOrquesta,QTY_ARRAY_ORQUESTA,arrayInstrumentos,QTY_ARRAY_INSTRUMENTOS,&contadorIdMusico);                   //cambiar
                        printf("\n\n Presione una tecla para continuar...");
                        c = getchar();
                        break;

                    case 2: //MODIFICAR MUSICOS
                        system("clear");
                        printf("-------MODIFICAR MUSICOS-------\n\n");
                        musicos_listar(arrayMusicos,QTY_ARRAY_MUSICO,arrayOrquesta,QTY_ARRAY_ORQUESTA,arrayInstrumentos,QTY_ARRAY_INSTRUMENTOS);
                        musicos_modificar(arrayMusicos,QTY_ARRAY_MUSICO);
                        printf("\n\n Presione una tecla para continuar...");
                        c = getchar();
                        break;

                    case 3: //BAJA DE MUSICOS
                        system("clear");
                        printf("-------BAJA DE MUSICOS-------\n\n");
                        musicos_listar(arrayMusicos,QTY_ARRAY_MUSICO,arrayOrquesta,QTY_ARRAY_ORQUESTA,arrayInstrumentos,QTY_ARRAY_INSTRUMENTOS);
                        musicos_baja(arrayMusicos,QTY_ARRAY_MUSICO);
                        printf("la baja fue exitosa");
                        printf("\n\n Presione una tecla para continuar...");
                        c = getchar();
                        break;

                    case 4: // LISTADO DE MUSICOS
                        system("clear");
                        printf("-------LISTADO DE MUSICOS-------\n\n");
                        musicos_listar(arrayMusicos,QTY_ARRAY_MUSICO,arrayOrquesta,QTY_ARRAY_ORQUESTA,arrayInstrumentos,QTY_ARRAY_INSTRUMENTOS);
                        printf("\n\n Presione una tecla para continuar...");
                        c = getchar();
                        break;

                    case 5: // SALIR DE MUSICOS
                        break;
                    }
                }while(opcion!=5);
            break;


            case 3: // MENU INSTRUMENTOS
                do{
                 system("clear");
                 utn_getUnsignedInt("-------MENU INSTRUMENTOS-------\n\n1) ALTA DE INSTRUMENTO \n2) BAJA DE INSTRUMENTO\n3) LISTAR INSTRUMENTOS\n4) SALIR\n\n *Ingrese su opcion: ",                   //cambiar
                                   "\nError",1,sizeof(int),1,6,1,&opcion);

                switch(opcion)
                {
                    case 1: // ALTA DE INSTRUMENTOS
                        system("clear");
                        printf("-------ALTA DE INSTRUMENTOS-------\n\n");
                        instrumentos_alta(arrayInstrumentos,QTY_ARRAY_INSTRUMENTOS,&contadorIdInstrumentos);
                        printf("\n\n Presione una tecla para continuar...");
                        c = getchar();
                        break;

                    case 2: // BAJA INSTRUMENTOS
                        system("clear");
                        printf("-------BAJA DE INSTRUMENTOS-------\n\n");
                        instrumentos_baja(arrayInstrumentos,QTY_ARRAY_INSTRUMENTOS);
                        printf("\n\n Presione una tecla para continuar...");
                        c = getchar();
                        break;

                    case 3: // LISTAR INSTRUMENTOS
                        system("clear");
                        printf("-------LISTADO DE INSTRUMENTOS-------\n\n");
                        instrumentos_listar(arrayInstrumentos, QTY_ARRAY_INSTRUMENTOS);
                        printf("\n\n Presione una tecla para continuar...");
                        c = getchar();
                        break;

                    case 4:// SALIR DE INSTRUMENTOS
                        break;
                }

                }while(opcion!=4);
            break;


            case 4: // INFORMES
                do{
                    system("clear");
                    utn_getUnsignedInt("-------MENU INFORMES-------\n\n1) LISTAR ORQUESTA POR LUGAR\n2) LISTAR MUSICOS MENORES A 25 AÑOS\n3) LISTAR ORQUESTAS CON MENOS DE 6 MUSICOS\n4) LISTAR INSTRUMENTOS DE UNA ORQUESTA \n5) LISTAR ORQUESTAS COMPLETAS\n6) LISTAR ORQUESTA CON MENOS MUSICOS \n7) PROMEDIO DE INSTRUMENTOS POR ORQUESTA\n8) LISTAR MUSICOS QUE NO TOCAN VIENTOS\n9) SALIR\n\n *Ingrese la opcion: ",                   //cambiar
                                    "\nError",1,sizeof(int),1,6,1,&opcion);

                    switch(opcion)
                    {
                        case 1: // LISTADO DE ORQUESTA POR LUGAR
                            system("clear");
                            printf("LISTADO DE ORQUESTA POR LUGAR\n\n");
                            inf_orquesta_listarLugar(arrayOrquesta, QTY_ARRAY_ORQUESTA);
                            printf("\n\n Presione una tecla para continuar...");
                            c = getchar();
                            break;

                        case 2: // LISTADO DE MUSICOS MENORES DE 25 AÑOS
                            system("clear");
                            printf("LISTADO DE MUSICOS MENORES DE 25 AÑOS\n\n");
                            inf_musicos_mostrarArray(arrayMusicos,QTY_ARRAY_MUSICO);
                            printf("\n\n Presione una tecla para continuar...");
                            c = getchar();
                            break;

                        case 3: // LISTADO DE ORQUESTAS CON MENOS DE 6 MUSICOS
                            system("clear");
                            printf("LISTADO DE ORQUESTAS CON MENOS DE 6 MUSICOS\n\n");
                            inf_orquesta_listadoMenosSeis(arrayOrquesta,QTY_ARRAY_ORQUESTA,arrayMusicos,QTY_ARRAY_MUSICO);
                            printf("\n\n Presione una tecla para continuar...");
                            c = getchar();
                            break;

                        case 4: // LISTADO DE INSTRUMENTOS POR ORQUESTA
                            system("clear");
                            printf("LISTADO DE INSTRUMENTOS POR ORQUESTA\n\n");
                            inf_musicos_InstrumentosPorOrquesta(arrayMusicos,QTY_ARRAY_MUSICO,arrayInstrumentos,QTY_ARRAY_INSTRUMENTOS);
                            printf("\n\n Presione una tecla para continuar...");
                            c = getchar();
                            break;

                        case 5: // LISTADO DE ORQUESTAS COMPLETAS
                            system("clear");
                            printf("LISTADO DE ORQUESTAS COMPLETAS\n\n");
                            inf_orquestasCompletas(arrayOrquesta,QTY_ARRAY_ORQUESTA,arrayMusicos,QTY_ARRAY_MUSICO,arrayInstrumentos,QTY_ARRAY_INSTRUMENTOS);
                            printf("\n\n Presione una tecla para continuar...");
                            c = getchar();
                            break;

                        case 6: // LISTADO DE ORQUESTAS CON MENOS MUSICOS
                            system("clear");
                            printf("LISTADO ORQUESTAS CON MENOS MUSICOS\n\n");
                            inf_orquesta_MenorCantidadMusicos(arrayOrquesta,QTY_ARRAY_ORQUESTA,arrayMusicos,QTY_ARRAY_MUSICO);
                            printf("\n\n Presione una tecla para continuar...");
                            c = getchar();
                            break;

                        case 7: //LISTADO DE PROMEDIO DE INSTRUMENTO POR ORQUESTA
                            system("clear");
                            printf("LISTADO DE PROMEDIO DE INSTRUMENTO POR ORQUESTA\n\n");
                            inf_orquesta_calcularPromedioInstrumentos(arrayOrquesta,QTY_ARRAY_ORQUESTA,arrayMusicos,QTY_ARRAY_MUSICO );
                            printf("\n\n Presione una tecla para continuar...");
                            c = getchar();
                            break;

                        case 8: //LISTADO DE MUSICOS QUE NO TOCAN VIENTOS
                            system("clear");
                            printf("LISTADO DE MUSICOS QUE NO TOCAN VIENTOS\n\n");
                            inf_musicos_listarPorInstrumentos(arrayMusicos, QTY_ARRAY_MUSICO);
                            printf("\n\n Presione una tecla para continuar...");
                            c = getchar();
                            break;

                        case 9: // SALIR DE LISTADOS
                            break;
                        }
                    }while(opcion!=9);
                break;
            }
        }while(primeraOpcion!=5);
    return 0;
}





