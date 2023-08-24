#include "clube.h"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <time.h>

//IMPRIMIR CLUBE
void imprimeClube(TClub *clube){
    printf("\n************************CLUBE********************************");
	printf("\nCODIGO DO CLUBE: ");
    printf("%d", clube->id);
	printf("\nNOME DO CLUBE: ");
    printf("%s", clube->nome);
    printf("\n*************************************************************\n");
}

// CRIAR CLUBE
TClub *criarClube(int id, char *nome){
    TClub *clube = (TClub *) malloc(sizeof(TClub));
    if (clube) memset(clube, 0, sizeof(TClub));
    clube->id = id;
    strcpy(clube->nome, nome);
    return clube;
}

// SALVA CLUBE
void salvaClube(TClub *clube, FILE *out){
    fwrite(&clube->id, sizeof(int), 1, out);
    fwrite(clube->nome, sizeof(char), sizeof(clube->nome), out);
}

//LE CLUBE
void *leClube(FILE *out){
    TClub *clube = (TClub *) malloc(sizeof(TClub));
    if (0 >= fread(&clube->id, sizeof(int), 1, out)) {
        free(clube);
        return NULL;
    }
    fread(clube->nome, sizeof(char), sizeof(clube->nome), out);
    return clube;
}

//INSERE CLUBES
void insereClubes(FILE *out){
    TClub *c1 = criarClube(2, "Cruzeiro");
    salvaClube(c1, out);
    free(c1);
    fflush(out);

    TClub *c2 = criarClube(5, "Atletico-MG");
    salvaClube(c2, out);
    free(c2);
    fflush(out);

    TClub *c3 = criarClube(3, "Vasco");
    salvaClube(c3, out);
    free(c3);
    fflush(out);

    TClub *c4 = criarClube(18, "Flamengo");
    salvaClube(c4, out);
    free(c4);
    fflush(out);

    TClub *c5 = criarClube(10, "Botafogo");
    salvaClube(c5, out);
    free(c5);
    fflush(out);

    TClub *c6 = criarClube(1, "Fluminense");
    salvaClube(c6, out);
    free(c6);
    fflush(out);

    TClub *c7 = criarClube(4, "America-MG");
    salvaClube(c7, out);
    free(c7);
    fflush(out);

    TClub *c8 = criarClube(20, "Sao Paulo");
    salvaClube(c8, out);
    free(c8);
    fflush(out);

    TClub *c9 = criarClube(6, "Palmeiras");
    salvaClube(c9, out);
    free(c9);
    fflush(out);

    TClub *c10 = criarClube(16, "Santos");
    salvaClube(c10, out);
    free(c10);
    fflush(out);

    TClub *c11 = criarClube(7, "Corinthians");
    salvaClube(c11, out);
    free(c11);
    fflush(out);

    TClub *c12 = criarClube(15, "Bragantino");
    salvaClube(c12, out);
    free(c12);
    fflush(out);

    TClub *c13 = criarClube(17, "Gremio");
    salvaClube(c13, out);
    free(c13);
    fflush(out);

    TClub *c14 = criarClube(11, "Internacional");
    salvaClube(c14, out);
    free(c14);
    fflush(out);

    TClub *c15 = criarClube(9, "Athletico-PR");
    salvaClube(c15, out);
    free(c15);
    fflush(out);

    TClub *c16 = criarClube(12, "Coritiba");
    salvaClube(c16, out);
    free(c16);
    fflush(out);

    TClub *c17 = criarClube(8, "Cuiaba");
    salvaClube(c17, out);
    free(c17);
    fflush(out);

    TClub *c18 = criarClube(14, "Goias");
    salvaClube(c18, out);
    free(c18);
    fflush(out);

    TClub *c19 = criarClube(19, "Fortaleza");
    salvaClube(c19, out);
    free(c19);
    fflush(out);

    TClub *c20 = criarClube(13, "Bahia");
    salvaClube(c20, out);
    free(c20);
    fflush(out);
}

//BUSCA SEQUENCIAL CLUBE
void busca_sequencial_clube(FILE *in){
    int c;
    rewind(in);
    TClub *clube;
    int found = 0;
    int cont = 0;

    printf("\n\nInforme o codigo do clube: ");
    scanf("%d", &c);

    clock_t inicio = clock();
    while((clube = leClube(in)) != NULL){
        cont++;
        if (clube->id == c){
            printf("\nClube Encontrado!\n");
            imprimeClube(clube);
            found = 1;
            break;
        }
        free(clube);
    }
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    if(found){
        printf("\nTempo de execucao da busca: %.2f segundos\n", tempo);
        printf("Numero de comparacoes: %d\n", cont);
    } else {
        printf("Clube nao pertence a base de dados!...");
        printf("\nNumero de comparacoes: %d\n", cont);
    }
}

//TAMANHO REGISTRO DE CLUBE
int tamanho_registro_clube(){
    return sizeof(int)
    + sizeof(char) * 100;
}
//TAMANHO ARQUIVO CLUBE
int tamanho_arquivo_clube(FILE *arq){
  fseek(arq, 0, SEEK_END);
  int tam = trunc(ftell(arq) / tamanho_registro_clube());
  return tam;
}

//ORDENAR CLUBES
void insertion_sort_disco_clube(FILE *arq) {
    int i;
    int tam = tamanho_arquivo_clube(arq);
    //faz o insertion sort
    for (int j = 2; j <= tam; j++) {
        //posiciona o arquivo no registro j
        fseek(arq, (j-1) * tamanho_registro_clube(), SEEK_SET);
        TClub *clbj = leClube(arq);
        printf("\n********* Clube atual: %d\n", clbj->id);
        i = j - 1;
        //posiciona o cursor no registro i
        fseek(arq, (i-1) * tamanho_registro_clube(), SEEK_SET);
        TClub *clbi = leClube(arq);
        printf("clbi = %d\n", clbi->id);
        while ((i > 0) && (clbi->id > clbj->id)) {
            //posiciona o cursor no registro i+1
            fseek(arq, i * tamanho_registro_clube(), SEEK_SET);
            printf("Salvando clube %d na posicao %d\n", clbi->id, i+1);
            salvaClube(clbi, arq);
            i = i - 1;
            //posiciona o cursor no registro i
            fseek(arq, (i-1) * tamanho_registro_clube(), SEEK_SET);
            clbi = leClube(arq);
            printf("clbi = %d; i = %d\n", clbi->id, i);
        }
        //posiciona cursor no registro i + 1
        fseek(arq, (i) * tamanho_registro_clube(), SEEK_SET);
        printf("*** Salvando clube %d na posicao %d\n", clbj->id, i+1);
        //salva registro j na posicao i
        salvaClube(clbj, arq);
    }
    //descarrega o buffer para ter certeza que dados foram gravados
    fflush(arq);
}

//BUSCA BINARIA CLUBE
TClub* busca_binaria_clube(FILE *arq) {
  int tam = tamanho_arquivo_clube(arq);
  int cod;
  printf("\nInforme o codigo do clube: ");
  scanf("%d", &cod);

  int left = 0, right = tam - 1;
  int cont = 0;

  clock_t inicio = clock();

  while (left <= right) {
    int middle = (left + right) / 2;
    fseek(arq, middle * tamanho_registro_clube(), SEEK_SET);
    TClub* club = leClube(arq);
    cont++;

    if (cod == club->id) {
      printf("\nClube Encontrado!\n");
      imprimeClube(club);
      clock_t fim = clock();
      double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
      printf("\nTempo de execucao: %.2f segundos\n", tempo);
      printf("Numero de comparacoes: %d\n", cont);
      return club;
    } else if (cod < club->id) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }

    free(club);
  }

  printf("Clube nao pertence a base de dados!...\n");
  printf("Numero de comparacoes: %d\n", cont);

  return NULL;
}
