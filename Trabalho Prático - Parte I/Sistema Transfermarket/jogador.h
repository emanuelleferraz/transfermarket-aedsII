#include <stdlib.h>
#include <stdio.h>
#include "clube.h"

typedef struct Jogador{
    int id;
    char nome[100];
    char posicao[50];
    int idade;
    double salario;
    double valorMercado;
    float score;
    char contrato[100];
    TClub clube;
} TPlayer;

//IMPRIMIR
void imprime(TPlayer *jogador);

// CRIAR JOGADOR
TPlayer *criarJogador(int id, char *nome, char *posicao, int idade, double salario,
                       double valorMercado, float score, char *contrato, TClub *clube);

// SALVA JOGADOR
void salva(TPlayer *jogador, FILE *out);

//LE JOGADOR
TPlayer *le(FILE *out);

//INSERE MULTIPLOS JOGADORES
int insere_multiplos_jogadores(FILE *out);

//
void le_jogadores(FILE *in);

// BUSCA SEQUENCIAL JOGADOR
void busca_sequencial_jogador(FILE *in);

//TAMANHO REGISTRO JOGADOR
int tamanho_registro();

int tamanho_arquivo(FILE *arq);

//ORDENAR JOGADORES
void insertion_sort_disco(FILE *arq);

//BUSCA BINARIA JOGADOR
TPlayer* busca_binaria(FILE *arq);

//PESQUISAR JOGADOR POR CLUBE
void pesquisar_jogadores_clube(FILE *out);

//TRANSFERIR JOGADOR
void transferencia_jogador(FILE *in, FILE *clube);
