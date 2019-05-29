#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int musicos_ordenarMayoraMenor(Musicos *arrayMusicos,int len);
int musicos_ordenarMenoraMayor(Musicos *arrayMusicos,int len);
int musicos_calcularPromedioEdades(Musicos *arrayMusicos,int len);
int musicos_mostrarArray(Musicos *arrayMusicos,int len);
int musicos_cantidadDeMusicosEnCadaOrquesta(Musicos *arrayMusicos,Orquesta *arrayOrquesta,int len);
int orquesta_calcularPromedioInstrumentos(Orquesta *arrayOrquesta,int lenOrquesta, Musicos *arrayMusicos,int lenMusicos );
int musicos_listarPorInstrumentos(Musicos array[], int size);
int orquesta_buscarPorLugar(Orquesta *array, int len, char lugar);
int orquesta_listarLugar(Orquesta array[], int size);
int orquesta_listadoMenosSeis(Orquesta OrquestaArray[],int Osize,Musicos MusicoArray[], int Msize);
int orquesta_MenorCantidadMusicos(Orquesta OrquestaArray[],int Osize,Musicos MusicoArray[], int Msize);

#endif // INFORMES_H_INCLUDED
