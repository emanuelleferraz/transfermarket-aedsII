#include <stdlib.h>
#include <stdio.h>

typedef struct Olheiro{
    int id;
    int cpf;
    char nome[100];
    char email[200];
} TScout;

void imprimeOlheiro(TScout *olheiro);

TScout *criarOlheiro(int id, int cpf, char *nome, char *email);

void salvaOlheiro(TScout *olheiro, FILE *out);

void *leOlheiro(FILE *out);

int insere_multiplos_olheiros(FILE *out);

void *le_olheiros(FILE *in);

void busca_sequencial_olheiro(FILE *in);

int tamanho_registro_olheiro();

int tamanho_arquivo_olheiro(FILE *arq);

void insertion_sort_disco_olheiro(FILE *arq);

TScout* busca_binaria_olheiro(FILE *arq);

int validar_olheiro(FILE *in);
