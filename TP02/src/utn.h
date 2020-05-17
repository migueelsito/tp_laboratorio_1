/*
 * utn.h
 *
 *  Created on: 16 may. 2020
 *      Author: JUNMI
 */

#ifndef UTN_H_
#define UTN_H_

int getString(char* mensaje, char* mensajeError, int min, int max, int* reintentos, char* resultado);

int utn_getName(char* mensaje, char* mensajeError,int min, int max, int reintentos, char* resultado);
int isValidName(char* stringRecibido);

int utn_getInt(char* mensaje, char* mensajeError, int minSize, int maxSize, int min, int max, int reintentos, int* input);
int isValidNumber(char* stringRecibido);

int utn_getSignedInt(char* mensaje, char* mensajeEror, int minSize, int maxSize, int min, int max, int reintentos, int* input);
int isValidSignedNumber(char* stringRecibido);

int utn_getFloat(char* mensaje, char* mensajeError, int minSize, int maxSize, int min, int max, int reintentos, float* input);
int isValidFloatNumber(char* stringRecibido);

int utn_getTexto(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, char* input);
int isValidTexto(char* stringRecibido);

int utn_getAlfanumerico(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, char* input);
int isValidAlphanumeric(char* stringRecibido);

int utn_getChar(char* mensaje, char* mensajeError, int min, int max, int reintentos, char* resultado);
int isValidChar(char charRecibido);



#endif /* UTN_H_ */
