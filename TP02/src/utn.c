/*
 * utn.c
 *
 *  Created on: 16 may. 2020
 *      Author: JUNMI
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int getString(char* mensaje, char* mensajeError, int min, int max, int* reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max+10];

    if(mensaje!=NULL && mensajeError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",mensaje);
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)
            {
                strncpy(resultado,bufferStr,max);
                retorno=0;
                break;
            }
            printf("%s",mensajeError);
            (*reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return retorno;
}

int isValidName(char* stringRecibido)
{
    int retorno = 1;

    int i;

    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'A' || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int utn_getInt(char* mensaje, char* mensajeError, int minSize, int maxSize, int min, int max, int reintentos, int* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(mensaje!=NULL && mensajeError!=NULL && minSize<maxSize && min<max && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(mensaje,mensajeError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidNumber(bufferStr)==1)
                {
                    *input=atoi(bufferStr);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int utn_getChar(char* mensaje, char* mensajeError, int min, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferChar[256];

    if(mensaje!=NULL && mensajeError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(mensaje,mensajeError,1,3,&reintentos,bufferChar))
            {
                if(isValidChar(bufferChar[0])==1)
                {
                    *resultado=bufferChar[0];
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidChar(char charRecibido)
{
    int retorno=1;
    if(charRecibido<'A'||(charRecibido>'Z' && charRecibido<'a')||charRecibido>'z')
       retorno=0;
    return retorno;
}

int utn_getFloat(char* mensaje, char* mensajeError, int minSize, int maxSize, int min, int max, int reintentos, float* input)
{
    int retorno = -1;
    char bufferStr[maxSize];

    if(mensaje!=NULL && mensajeError!=NULL && minSize<maxSize && min<max && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(mensaje,mensajeError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidFloatNumber(bufferStr)==1)
                {
                    *input=atof(bufferStr);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidFloatNumber(char* stringRecibido)
{
    int retorno = 1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int utn_getTexto(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(mensaje!=NULL && mensajeError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(mensaje,mensajeError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidTexto(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidTexto(char* stringRecibido)
{
    int retorno = 1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<' '||stringRecibido[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
