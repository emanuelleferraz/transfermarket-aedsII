#include <stdlib.h>
#include <stdio.h>
#ifndef CLUBE_H_INCLUDED
#define CLUBE_H_INCLUDED

typedef struct Clube{
    int id;
    char nome[100];
} TClub;

//IMPRIMIR CLUBE
void imprimeClube(TClub *clube);

// CRIAR CLUBE
TClub *criarClube(int id, char *nome);

// SALVA CLUBE
void salvaClube(TClub *clube, FILE *out);

//LE CLUBE
void *leClube(FILE *out);

//INSERE CLUBES
void insereClubes(FILE *out);

//BUSCA SEQUENCIAL CLUBE
void busca_sequencial_clube(FILE *in);

//TAMANHO REGISTRO DE CLUBE
int tamanho_registro_clube();

//TAMANHO ARQUIVO CLUBE
int tamanho_arquivo_clube(FILE *arq);

//ORDENAR CLUBES
void insertion_sort_disco_clube(FILE *arq);

//BUSCA BINARIA CLUBE
TClub* busca_binaria_clube(FILE *arq);

#endif // CLUBE_H_INCLUDED
