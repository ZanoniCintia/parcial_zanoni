#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"
#include "Controller.h"
#include "llamada.h"
#include "funciones.h"

int main()
{
    int option = 0;
    LinkedList* listaLlamadas = ll_newLinkedList();
    LinkedList* auxLL;                                                                           // LinkedList* listaVenta = ll_newLinkedList();
        printf("\n1-Cargar archivo\n");
        printf("2-Imprimir llamadas\n");
        printf("3-Generar archivo de llamadas\n");
        printf("4-Salir\n");
        getInt("ingrese una opcion: ","ingrese una opcion valida",1,5,3,&option);                                                                         //controller_loadFromText("data.csv",listaVenta);
     do{
        switch(option)
        {
            case 1:
                system("clear");
                controller_loadFromText("DATA_final1.csv",listaLlamadas);
            break;

            case 2:
                system("clear");
                printf("cantidad:%d\n",ll_len(listaLlamadas));
                controller_ListLlamada(listaLlamadas);
            break;

            case 3:
                auxLL = ll_filter(listaLlamadas,controller_problemas);
                controller_saveAsText("archivoLlamadas.csv",auxLL);
            break;

            case 4:
            break;


        }


                                                                               //controller_ListVenta(listaVenta);
        }while(option != 4);                                                                        //controller_saveAsTextInformes("informes",listaVenta);
    return 0;
}
