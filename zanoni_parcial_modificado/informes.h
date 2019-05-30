#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

//int musicos_ordenarMayoraMenor(Musicos *arrayMusicos,int len);
//int musicos_ordenarMenoraMayor(Musicos *arrayMusicos,int len);
//int inf_musicos_calcularPromedioEdades(Musicos *arrayMusicos,int len);

int inf_musicos_mostrarArray(Musicos *arrayMusicos,int len); //MENOS 25
int inf_musicos_cantidadDeMusicosEnCadaOrquesta(Musicos *arrayMusicos,Orquesta *arrayOrquesta,int len);
int inf_orquesta_calcularPromedioInstrumentos(Orquesta *arrayOrquesta,int lenOrquesta, Musicos *arrayMusicos,int lenMusicos );
int inf_musicos_listarPorInstrumentos(Musicos array[], int size);
int inf_orquesta_buscarPorLugar(Orquesta *array, int len, char lugar);
int inf_orquesta_listarLugar(Orquesta array[], int size);
int inf_orquesta_listadoMenosSeis(Orquesta OrquestaArray[],int Osize,Musicos MusicoArray[], int Msize);
int inf_orquesta_MenorCantidadMusicos(Orquesta OrquestaArray[],int Osize,Musicos MusicoArray[], int Msize);
int inf_musicos_InstrumentosPorOrquesta(Musicos Marray[],int Msize,Instrumentos IArray[], int Isize);
#endif // INFORMES_H_INCLUDED
