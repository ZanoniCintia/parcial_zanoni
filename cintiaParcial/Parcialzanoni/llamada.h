#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED
typedef struct
{
    int id;
    char fecha[500];
    int numeroCliente;
    int id_problema;
    char solucion[128];

}Llamada;
Llamada* llamada_new();
Llamada* llamada_newParametros(char* idStr,char* fecha, char* numero, char* idProblema, char* solucion);
int Llamada_setIdString(Llamada* this, char* id);
//int Llamada_getCantidadString(Llamada* this, char* cantidad);
//int Llamada_setCantidadString(Llamada* this, char* cantidad);
int Llamada_getNumeroCliente(Llamada* this,char* cantidad);
int Llamada_setNumeroCliente(Llamada* this,char cantidad);
int Llamada_getIdString(Llamada* this, char* id);
int Llamada_getId(Llamada* this,int* id);
int Llamada_getIdProblema(Llamada* this,char* id);
int Llamada_setIdProblema(Llamada* this,char id);
int Llamada_setId(Llamada* this,int id);
int Llamada_delete(Llamada* this);
int Llamada_setFecha(Llamada* this,char* fecha);
int Llamada_getFecha(Llamada* this,char* fecha);
int Llamada_setSolucion(Llamada* this,char* tipo);
int Llamada_getSolucion(Llamada* this,char* tipo);
#endif // LLAMADA_H_INCLUDED
