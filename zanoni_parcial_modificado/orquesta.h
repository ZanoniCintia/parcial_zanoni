#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED
#define TEXT_SIZE_ORQUESTA 51

typedef struct
{
    int idOrquesta;
    int isEmpty;
    char nombre[TEXT_SIZE_ORQUESTA];
    char lugar[TEXT_SIZE_ORQUESTA];
    int tipo;

}Orquesta;




int orquesta_Inicializar(Orquesta array[], int size);
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion);
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion);
//int orquesta_buscarInt(Orquesta array[], int size, int valorBuscado, int* posicion);
//int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice);
int orquesta_alta(Orquesta array[], int size, int* contadorID);
//int orquesta_baja(Orquesta array[], int sizeArray,Musicos arrayMusico[],int sizeArrayMusico);
//int orquesta_bajaValorRepetidoInt(Orquesta array[], int sizeArray, int valorBuscado);
int orquesta_modificar(Orquesta array[], int sizeArray);
int orquesta_ordenarPorDobleCriterio(Orquesta array[],int size, int orderFirst, int orderSecond);
int orquesta_listar(Orquesta array[], int size);
void orquesta_mock(Orquesta arrayAutor[], int size,int *contadorId);
int orquesta_tipo(Orquesta tipoOrquesta,char* tipos);




#endif // ORQUESTA_H_INCLUDED
