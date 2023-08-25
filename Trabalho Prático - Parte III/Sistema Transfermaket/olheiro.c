#include "olheiro.h"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <time.h>

//IMPRIME OLHEIRO
void imprimeOlheiro(TScout *olheiro) {
    printf("\n***********************OLHEIRO*******************************");
    printf("\nCODIGO: ");
    printf("%d", olheiro->id);
    printf("\nNOME: ");
    printf("%s", olheiro->nome);
    printf("\nCPF: ");
    printf("%d", olheiro->cpf);
    printf("\nEMAIL: ");
    printf("%s", olheiro->email);
    printf("\n*************************************************************\n");
}

// CRIAR OLHEIRO
TScout *criarOlheiro(int id, int cpf, char *nome, char *email){
    TScout *olheiro = (TScout *) malloc(sizeof(TScout));
    if (olheiro) memset(olheiro, 0, sizeof(TScout));
    olheiro->id = id;
    olheiro->cpf = cpf;
    strcpy(olheiro->nome, nome);
    strcpy(olheiro->email, email);
    return olheiro;
}

//SALVA OLHEIRO
void salvaOlheiro(TScout *olheiro, FILE *out){
    fwrite(&olheiro->id, sizeof(int), 1, out);
    fwrite(&olheiro->cpf, sizeof(int), 1, out);
    fwrite(olheiro->nome, sizeof(char), sizeof(olheiro->nome), out);
    fwrite(olheiro->email, sizeof(char), sizeof(olheiro->email), out);
}

//LE OLHEIRO
void *leOlheiro(FILE *out){
    TScout *olheiro = (TScout *) malloc(sizeof(TScout));
    if (0 >= fread(&olheiro->id, sizeof(int), 1, out)) {
        free(olheiro);
        return NULL;
    }
    fread(&olheiro->cpf, sizeof(int), 1, out);
    fread(olheiro->nome, sizeof(char), sizeof(olheiro->nome), out);
    fread(olheiro->email, sizeof(char), sizeof(olheiro->email), out);
    return olheiro;
}

//INSERE MULTIPLOS OLHEIROS
int insere_multiplos_olheiros(FILE *out) {
    int contador = 0;
    printf("Informe quantos olheiros deseja cadastrar: ");
    scanf("%d", &contador);

    srand(time(NULL));

    int *numeros = malloc(contador * sizeof(int));

    for (int i = 0; i < contador; i++) {
        numeros[i] = i + 1;
    }

    for (int i = contador - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = temp;
    }

    int x = 0;
    for (int i = 0; i < contador; i = i + 2) {
        TScout *o1 = criarOlheiro(numeros[x], 123410, "Pepa", "pepa@cruzeiro.com");
        x++;

        TScout *o2 = criarOlheiro(numeros[x], 456789, "Sampaoli", "sampaoli@flamengo.com");
        x++;

        salvaOlheiro(o1, out);
        salvaOlheiro(o2, out);
        free(o1);
        free(o2);
    }
    free(numeros);
    return contador;
}
//LE OLHEIRO
void *le_olheiros(FILE *in) {
    printf("\n\nLendo olheiros do arquivo...\n\n");
    rewind(in);
    TScout *f;
    while ((f = leOlheiro(in)) != NULL) {
        imprimeOlheiro(f);
        free(f);
    }
}

// BUSCA SEQUENCIAL
void busca_sequencial_olheiro(FILE *in){
    int c;
    rewind(in);
    TScout *s;
    int found = 0;
    int cont = 0;

    printf("\n\nInforme o codigo do olheiro: ");
    scanf("%d", &c);

    clock_t inicio = clock();
    while((s = leOlheiro(in)) != NULL){
        cont++;
        if (s->id == c){
            printf("Olheiro Encontrado!\n");
            imprimeOlheiro(s);
            found = 1;
            break;
        }
        free(s);
    }
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    if(found){
        printf("\nTempo de execucao da busca: %.2f segundos\n", tempo);
        printf("Numero de comparacoes: %d\n", cont);
    } else {
        printf("Olheiro nao pertence a base de dados!...");
        printf("\nNumero de comparacoes: %d\n", cont);
    }
}

//TAMANHO DO REGISTRO DE OLHEIRO
int tamanho_registro_olheiro() {
    return sizeof(int) + sizeof(int) + sizeof(char) * 100 + sizeof(char) * 200;
}

int tamanho_arquivo_olheiro(FILE *arq) {
  fseek(arq, 0, SEEK_END);
  int tam = trunc(ftell(arq) / tamanho_registro_olheiro());
  return tam;
}

//ORDENAR OLHEIROS
void insertion_sort_disco_olheiro(FILE *arq) {
    int i;
    int tam = tamanho_arquivo_olheiro(arq);
    //faz o insertion sort
    for (int j = 2; j <= tam; j++) {
        //posiciona o arquivo no registro j
        fseek(arq, (j-1) * tamanho_registro_olheiro(), SEEK_SET);
        TScout *olj = leOlheiro(arq);
        printf("\n********* Olheiro atual: %d\n", olj->id);
        i = j - 1;
        //posiciona o cursor no registro i
        fseek(arq, (i-1) * tamanho_registro_olheiro(), SEEK_SET);
        TScout *oli = leOlheiro(arq);
        printf("oli = %d\n", oli->id);
        while ((i > 0) && (oli->id > olj->id)) {
            //posiciona o cursor no registro i+1
            fseek(arq, i * tamanho_registro_olheiro(), SEEK_SET);
            printf("Salvando olheiro %d na posicao %d\n", oli->id, i+1);
            salvaOlheiro(oli, arq);
            i = i - 1;
            //posiciona o cursor no registro i
            fseek(arq, (i-1) * tamanho_registro_olheiro(), SEEK_SET);
            oli = leOlheiro(arq);
            printf("oli = %d; i = %d\n", oli->id, i);
        }
        //posiciona cursor no registro i + 1
        fseek(arq, (i) * tamanho_registro_olheiro(), SEEK_SET);
        printf("*** Salvando olheiro %d na posicao %d\n", olj->id, i+1);
        //salva registro j na posicao i
        salvaOlheiro(olj, arq);
    }
    //descarrega o buffer para ter certeza que dados foram gravados
    fflush(arq);
}

//BUSCA BINARIA OLHEIRIO
TScout* busca_binaria_olheiro(FILE *arq) {
  int tam = tamanho_arquivo_olheiro(arq);
  int cod;
  printf("\nInforme o codigo do olheiro: ");
  scanf("%d", &cod);

  int left = 0, right = tam - 1;
  int cont = 0;

  clock_t inicio = clock();

  while (left <= right) {
    int middle = (left + right) / 2;
    fseek(arq, middle * tamanho_registro_olheiro(), SEEK_SET);
    TScout* scout = leOlheiro(arq);
    cont++;

    if (cod == scout->id) {
      printf("\nOlheiro Encontrado!\n");
      imprimeOlheiro(scout);
      clock_t fim = clock();
      double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
      printf("\nTempo de execucao: %.2f segundos\n", tempo);
      printf("Numero de comparacoes: %d\n", cont);
      return scout;
    } else if (cod < scout->id) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }

    free(scout);
  }

  printf("Olheiro nao pertence a base de dados!...\n");
  printf("Numero de comparacoes: %d\n", cont);

  return NULL;
}

int validar_olheiro(FILE *in){
    int codigo = 0;
    printf("Informe seu codigo de olheiro: \n");
    scanf("%d", &codigo);

    rewind(in);
    TScout *f;
    while ((f = leOlheiro(in)) != NULL) {
        if(f->id == codigo){
            imprimeOlheiro(f);
            free(f);
            return 0;
        }
    }
    printf("Olheiro nao cadastrado ou incorreto!\n");
    return 1;
}
