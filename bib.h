#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct{
    char Codg[11];
    char Regiao[13];
    char UF[3];
    char Data[11];
    int Dados[6];
    }dados_cov;

typedef struct{
    char Chave[11];
    int posicao;
}indexacao;


int menu();

int tamfile(FILE *file);

void PreencheStruct(int N, FILE *file, dados_cov *D);

void Indexar(indexacao *I, dados_cov *D, int N);

int Consulta(dados_cov *D, indexacao *I, int N);

#endif // BIB_H_INCLUDED
