#ifndef ARVORE_B_ARVORE_B_H
#define ARVORE_B_ARVORE_B_H

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int m; //quantidade de chaves armazenadas no nó
    struct No *pai;
    int *s; //array de chaves
    struct No **p; //ponteiro para array de ponteiros para os filhos
} TNo;

TNo *cria(int d);
TNo *libera(TNo *a, int d);
void imprime_arvore(TNo *a, int nivel);
void imprime_no(TNo *a);
int posicao(int chave, TNo *no);
TNo *busca(TNo *no, int chave);
void particiona(TNo *P, int d, int pos, int chave, TNo *pt);
void insere(TNo *no, int d, int pos, int chave, TNo *pt);
TNo *insere_folha(TNo *raiz, int d, int chave);
void cria_e_salva_arvore_com_ids(FILE *out, const char *arquivo_saida, int D);
void salva_arvore_em_arquivo(TNo *no, FILE *arquivo);
//TNo *cria_arvore_com_ids(FILE *out, int D);
void busca_e_imprime_jogador(TNo *raiz, int id);
TNo *remove_chave(TNo *no, int d, int chave);
TNo *remove_arvore(TNo *raiz, int d, int chave);

#endif //ARVORE_B_ARVORE_B_H
