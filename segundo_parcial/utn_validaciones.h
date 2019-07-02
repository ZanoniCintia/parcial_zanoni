#ifndef UTN_VALIDACIONES_H_INCLUDED
#define UTN_VALIDACIONES_H_INCLUDED
int getString ( char* msg,char* msgError,int minimo, int maximo, int reintentos,char* resultado);

int getName (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado);
int isValidName (char* cadena);

int getFloat(char* msg,char* msgError,float minimo,float maximo,int reintentos,float* resultado);
int isValidFloat(char* numero, float minimo,float maximo);

int getInt(char* msg,char* msgError,int minimo,int maximo,int reintentos,char *resultado);
int isValidInt(char* cadena);

int getEntero(char* msg,char* msgError,int minimo,int maximo,int reintentos,int *resultado);
int isValidEntero(char* cadena);

int isValidDni(char* cadena);//aca dni
int isValidFecha(char *cadena);
//int isDni (char* pString);
int isNumber(char* pString);
int isValidFloatNumber(char* stringRecibido);
int isValidNumber(char* stringRecibido);
int isCuit (char* pString);
int isTelefono (char* pString);
int isValidSex(char letra, char maximo, char minimo);
int isValidEmail(char* cadena);
int isEmail(char* cadena);
int isValidAlphanumeric(char* stringRecibido);

#endif // UTN_VALIDACIONES_H_INCLUDED
