#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore-b.h"
#include "jogador.h"
#include <limits.h>

TNo *cria(int d) {
    TNo *novo = (TNo *) malloc(sizeof(TNo));
    novo->m = 0;
    novo->pai = NULL;
    novo->s = (int *) malloc(sizeof(int *) * (d * 2));
    novo->p = (TNo **) malloc(sizeof(TNo *) * (d * 2) + 1);
    for (int i = 0; i < (d * 2 + 1); i++) {
        novo->p[i] = NULL;
    }
    return novo;
}

TNo *libera(TNo *a, int d) {
    if (a != NULL) {
        for (int i = 0; i <= d * 2 + 1; i++) {
            libera(a->p[i], d);
        }
        free(a->s);
        free(a->p);
        free(a);
    }
    return NULL;
}

/*
 * A impressao da árvore é feita como se ela estivesse na vertical ao invés da horizontal, portanto cada nó é impresso na vertical,
 * com a menor chave do nó na parte inferior do nó
 */
void imprime_arvore(TNo *a, int nivel) {
    if (a != NULL) {
        char indent[10] = "";
        for (int i = 0; i < nivel; i++) {
            strcat(indent, "\t");
        }

        for (int i = a->m; i > 0; i--) {
            imprime_arvore(a->p[i], nivel + 1);
            printf("%s", indent);
            printf("%5d\n", a->s[i - 1]);
        }
        imprime_arvore(a->p[0], nivel + 1);
    }
}

void imprime_no(TNo *a) {
    if (a != NULL) {
        for (int i = 0; i < a->m; i++) {
            printf("%5d", a->s[i]);
        }
        printf("\n");
    }
}

/*
 * Busca binária da posição em que a chave deveria estar dentro do nó.
 */
int posicao(int chave, TNo *no) {
    int inicio = 0;
    int fim = no->m;
    int pos = (fim + inicio) / 2;
    while (pos != no->m && chave != no->s[pos] && inicio < fim) {
        if (chave > no->s[pos]) {
            inicio = pos + 1;
        } else {
            fim = pos;
        }
        pos = (fim + inicio) / 2;
    }
    return pos;
}

/*
 * Busca retorna ponteiro para o nó onde a chave está, ou onde ela deveria estar (se chegar numa folha e não encontrar a chave)
 */
TNo *busca(TNo *no, int chave) {
    int pos = posicao(chave, no);
    if (no->p[pos] == NULL || (pos < no->m && chave == no->s[pos])) {
        return no;
    } else {
        return busca(no->p[pos], chave);
    }
}

void particiona(TNo *P, int d, int pos, int chave, TNo *pt);

/*
 * Insere a chave e o seu repectivo ponteiro da direita (para Q) numa posição específica de um nó específico da árvore
 * d é a ordem da arvore
 * Caso a posição não seja informada (-1) o algoritmo busca pela posição correta
 * Retorna ponteiro para a raiz da árvore
 */
void insere(TNo *no, int d, int pos, int chave, TNo *pt) {
    if (pos == -1) {
        pos = posicao(chave, no);
    }

    if (no->m < 2 * d) { // Tem espaço no nó, então pode inserir diretamente
        for (int i = no->m; i > pos; i--) { // Abre espaço para a inserção
            no->s[i] = no->s[i - 1];
            no->p[i + 1] = no->p[i];
        }
        no->s[pos] = chave;
        no->p[pos + 1] = pt;
        if (pt != NULL) {
            pt->pai = no;
        }
        no->m++;
    } else { // Nó está cheio -- é necessário particionar
        particiona(no, d, pos, chave, pt);
    }
}

/*
 * Insere a chave numa folha da árvore
 * raiz é ponteiro para a raiz da árvore
 * d é a ordem da arvore
 * Retorna ponteiro para a raiz da árvore
 */
TNo *insere_folha(TNo *raiz, int d, int chave) {
    if (raiz != NULL) {
        TNo *no = busca(raiz, chave);
        int pos = posicao(chave, no);
        if (pos == no->m || chave != no->s[pos]) { // chave não existe no nó
            insere(no, d, pos, chave, NULL);
            if (raiz->pai != NULL) { // Inserção riou uma nova raiz
                raiz = raiz->pai;
            }
        }
    } else {
        raiz = cria(d);
        raiz->s[0] = chave;
        raiz->m = 1;
    }
    return raiz;
}

/*
 * Particiona o nó P para adicionar a chave e o ponteiro pt
 * Após o final da execução dessa função, a chave terá sido inserida no local correto
 * e um novo nó Q terá sido criado como resultado do particionamento
 * Uma nova raiz W pode ser criada, se a raiz atual estiver sendo particionada
 */
void particiona(TNo *P, int d, int pos, int chave, TNo *pt) {
    // Prepara Q
    TNo *Q = cria(d);
    int i = d * 2 - 1;
    int j = d - 1;
    while (j >= 0) {
        if (j != pos - d - 1) { // Move chave de P para Q
            Q->s[j] = P->s[i];
            Q->p[j + 1] = P->p[i + 1];
            i--;
        } else { // Insere chave em Q
            Q->s[j] = chave;
            Q->p[j + 1] = pt;
        }
        if (Q->p[j + 1] != NULL) {
            Q->p[j + 1]->pai = Q;
        }
        j--;
    }
    Q->m = d;

    // Processa P
    if (pos <= d) {
        P->m = d;
        insere(P, d, pos, chave, pt); // inserção vai fazer o número de chaves aumentar para d+1, e isso é tratado no final dessa função
    }

    // Processa W
    if (P->pai == NULL) { // Caso o nó seja raiz, cria o nó superior
        TNo *W = cria(d);
        W->p[0] = P;
        P->pai = W;
    }
    // Chave d de P sobe para o pai W
    insere(P->pai, d, -1, P->s[d], Q);
    // Ajusta o ponteiro da esquerda de Q (recebe ponteiro da direita da chave que subiu para o pai W)
    Q->p[0] = P->p[d+1];
    // Se o ponteiro p[0] for diferente de NULL, ajusta o ponteiro do pai do nó apontado por p[0[
    if (Q->p[0] != NULL)
        Q->p[0]->pai = Q;
    // A inserção da chave d em W fez o número de chaves de P diminuir para D
    P->m = d;
}


///////////////////////////////////////// MANIPULAÇÕES COM ÁRQUIVO DE JOGADOR ///////////////////////////////////////////////////////////

// Função para criar a árvore B com base nos IDs dos jogadores do arquivo
TNo *cria_arvore_com_ids(FILE *out, int D) {
    TPlayer *jogador;
    TNo *raiz = cria(D);  // Cria a raiz da árvore uma vez

    fseek(out, 0, SEEK_SET);  // Volta ao início do arquivo

    while ((jogador = le(out)) != NULL) {
        printf("\n\n****** Inserindo %d ******\n\n", jogador->id);
        raiz = insere_folha(raiz, D, jogador->id);
        imprime_arvore(raiz, 0);  // Imprime a árvore completa após inserções
        free(jogador);
    }


    return raiz;
}

/*
 * Remove a chave de um nó específico
 * d é a ordem da árvore
 * Retorna ponteiro para a raiz da árvore após a remoção
 */
TNo *remove_chave(TNo *no, int d, int chave) {
    if (no == NULL) {
        return NULL; // Árvore vazia, não há o que remover
    }

    int pos = posicao(chave, no);

    if (pos < no->m && chave == no->s[pos]) { // Encontrou a chave no nó atual
        if (no->p[pos] == NULL) { // Caso 1: Chave está em um nó folha
            for (int i = pos; i < no->m - 1; i++) { // Remove a chave
                no->s[i] = no->s[i + 1];
                no->p[i + 1] = no->p[i + 2];
            }
            no->m--;
            return no;
        } else { // Caso 2: Chave está em um nó interno
            TNo *pred = no->p[pos];
            while (pred->p[pred->m] != NULL) {
                pred = pred->p[pred->m];
            }
            int predecessor = pred->s[pred->m - 1]; // Encontra o predecessor da chave
            no->s[pos] = predecessor; // Substitui a chave a ser removida pelo predecessor
            no->p[pos] = remove_chave(no->p[pos], d, predecessor); // Remove o predecessor do nó folha
            return no;
        }
    } else { // A chave não está neste nó, procura no nó filho apropriado
        no->p[pos] = remove_chave(no->p[pos], d, chave);
        return no;
    }
}

/*
 * Função para remover uma chave da árvore
 * raiz é ponteiro para a raiz da árvore
 * d é a ordem da árvore
 * Retorna ponteiro para a raiz da árvore após a remoção
 */
TNo *remove_arvore(TNo *raiz, int d, int chave) {
    if (raiz != NULL) {
        raiz = remove_chave(raiz, d, chave);
        if (raiz->m == 0 && raiz->p[0] != NULL) { // Caso especial: raiz ficou vazia
            TNo *nova_raiz = raiz->p[0];
            free(raiz);
            return nova_raiz;
        }
    }
    return raiz;
}


//Função para buscar chave e retornar os jogadores presentes nela.
void busca_e_imprime_jogador(TNo *raiz, int id) {
    TNo *noEncontrado = busca(raiz, id);

    if (noEncontrado != NULL) {
        int pos = posicao(id, noEncontrado);
        if (pos < noEncontrado->m && id == noEncontrado->s[pos]) {
            printf("Jogador com ID %d encontrado:\n", id);
            TPlayer *jogador = le_jogador_por_id(id); // Função para ler o jogador por ID
            imprime(jogador);
            free(jogador);
        } else {
            printf("Jogador com ID %d nao encontrado na arvore.\n", id);
        }
    } else {
        printf("Jogador com ID %d nao encontrado na arvore.\n", id);
    }
}
