//
//  Created by Mateus Santos & Emanuelle Ferraz
//    Trabalho Pratico - AEDS II
//

#include "jogador.h"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <time.h>
#include <limits.h>


//IMPRIMIR
void imprime(TPlayer *jogador) {
	printf("\n***********************JOGADOR*******************************");
	//JOGADOR
   printf("\nCODIGO: ");
    printf("%d", jogador->id);
    printf("\nNOME: ");
    printf("%s", jogador->nome);
    printf("\nPOSICAO: ");
    printf("%s", jogador->posicao);
    printf("\nIDADE: ");
    printf("%d", jogador->idade);
    printf("\nSALARIO R$: ");
    printf("%4.2f", jogador->salario);
	printf("\nVALOR DE MERCADO R$: ");
    printf("%4.2f", jogador->valorMercado);
	printf("\nSCORE: ");
    printf("%4.2f", jogador->score);
	printf("\nCONTRATO: ");
    printf("%s", jogador->contrato);

	//CLUBE
	printf("\n************************CLUBE********************************");
	printf("\nCODIGO DO CLUBE: ");
    printf("%d", jogador->clube.id);
	printf("\nNOME DO CLUBE: ");
    printf("%s", jogador->clube.nome);
    printf("\n*************************************************************\n");
}

// CRIAR JOGADOR
TPlayer *criarJogador(int id, char *nome, char *posicao, int idade, double salario,
                      double valorMercado, float score, char *contrato, TClub *clube) {
    TPlayer *jogador = (TPlayer *) malloc(sizeof(TPlayer));
    if (jogador) memset(jogador, 0, sizeof(TPlayer));
    jogador->id = id;
    strcpy(jogador->nome, nome);
    strcpy(jogador->posicao, posicao);
	jogador->idade = idade;
	jogador->salario = salario;
	jogador->valorMercado = valorMercado;
	jogador->score = score;
    strcpy(jogador->contrato, contrato);

	jogador->clube.id = clube->id;
	strcpy(jogador->clube.nome, clube->nome);
    return jogador;
}

// SALVA JOGADOR
void salva(TPlayer *jogador, FILE *out) {
    fwrite(&jogador->id, sizeof(int), 1, out);
    fwrite(jogador->nome, sizeof(char), sizeof(jogador->nome), out);
    fwrite(jogador->posicao, sizeof(char), sizeof(jogador->posicao), out);
    fwrite(&jogador->idade, sizeof(int), 1, out);
    fwrite(&jogador->salario, sizeof(double), 1, out);
	fwrite(&jogador->valorMercado, sizeof(double), 1, out);
	fwrite(&jogador->score, sizeof(float), 1, out);
	fwrite(jogador->contrato, sizeof(char), sizeof(jogador->contrato), out);

	fwrite(&jogador->clube.id, sizeof(int), 1, out);
	fwrite(jogador->clube.nome, sizeof(char), sizeof(jogador->clube.nome), out);
}

// SALVA JOGADOR
void salva_arvore(TPlayer *jogador, FILE *out) {
    fseek(out, 0, SEEK_END);
    fwrite(&jogador->id, sizeof(int), 1, out);
    fwrite(jogador->nome, sizeof(char), sizeof(jogador->nome), out);
    fwrite(jogador->posicao, sizeof(char), sizeof(jogador->posicao), out);
    fwrite(&jogador->idade, sizeof(int), 1, out);
    fwrite(&jogador->salario, sizeof(double), 1, out);
	fwrite(&jogador->valorMercado, sizeof(double), 1, out);
	fwrite(&jogador->score, sizeof(float), 1, out);
	fwrite(jogador->contrato, sizeof(char), sizeof(jogador->contrato), out);

	fwrite(&jogador->clube.id, sizeof(int), 1, out);
	fwrite(jogador->clube.nome, sizeof(char), sizeof(jogador->clube.nome), out);
}

//LE JOGADOR
TPlayer *le(FILE *out) {
    TPlayer *jogador = (TPlayer *) malloc(sizeof(TPlayer));
    if (0 >= fread(&jogador->id, sizeof(int), 1, out)) {
        free(jogador);
        return NULL;
    }
    fread(jogador->nome, sizeof(char), sizeof(jogador->nome), out);
    fread(jogador->posicao, sizeof(char), sizeof(jogador->posicao), out);
    fread(&jogador->idade, sizeof(int), 1, out);
    fread(&jogador->salario, sizeof(double), 1, out);
	fread(&jogador->valorMercado, sizeof(double), 1, out);
	fread(&jogador->score, sizeof(float), 1, out);
	fread(jogador->contrato, sizeof(char), sizeof(jogador->contrato), out);

	fread(&jogador->clube.id, sizeof(int), 1, out);
	fread(jogador->clube.nome, sizeof(char), sizeof(jogador->clube.nome), out);
    return jogador;
}

//INSERE MULTIPLOS JOGADORES
int insere_multiplos_jogadores(FILE *out) {
    int contador = 0;
    printf("Informe quantos jogadores deseja cadastrar: ");
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
    for (int i = 0; i < contador; i = i + 10) {
    TClub *c1 = criarClube(2, "Cruzeiro");
    TClub *c2 = criarClube(5, "Atletico-MG");
    TClub *c3 = criarClube(3, "Vasco");
    TClub *c4 = criarClube(18, "Flamengo");
    TClub *c5 = criarClube(10, "Botafogo");
    TClub *c6 = criarClube(1, "Fluminense");
    TClub *c7 = criarClube(4, "America-MG");
    TClub *c8 = criarClube(20, "Sao Paulo");
    TClub *c9 = criarClube(6, "Palmeiras");
    TClub *c10 = criarClube(16, "Santos");
    TClub *c11 = criarClube(7, "Corinthians");
    TClub *c12 = criarClube(15, "Bragantino");
    TClub *c13 = criarClube(17, "Gremio");
    TClub *c14 = criarClube(11, "Internacional");
    TClub *c15 = criarClube(9, "Athletico-PR");
    TClub *c16 = criarClube(12, "Coritiba");
    TClub *c17 = criarClube(8, "Cuiaba");
    TClub *c18 = criarClube(14, "Goias");
    TClub *c19 = criarClube(19, "Fortaleza");
    TClub *c20 = criarClube(13, "Bahia");
    TClub *c21 = criarClube(0, "");

        TPlayer *j1 = criarJogador(numeros[x], "Joao", "Atacante", 28, 35500, 222200, 4.8, "Contrato ate 2024", c1);
        x++;
        salva(j1, out);
        free(j1);

        TPlayer *j2 = criarJogador(numeros[x], "Alexandre", "Meio Campo", 30, 48500, 388200, 4.7, "Contrato ate 2026 ", c2);
        x++;
        salva(j2, out);
        free(j2);

        TPlayer *j3 = criarJogador(numeros[x], "Davi", "Lateral-Direito", 22, 58500, 499200, 4.8, "Fim de 2023", c3);
        x++;
        salva(j3, out);
        free(j3);

        TPlayer *j4 = criarJogador(numeros[x], "Jonas", "Zagueiro", 25, 58500, 455200, 4.8, "Livre no mercado", c4);
        x++;
        salva(j4, out);
        free(j4);

        TPlayer *j5 = criarJogador(numeros[x], "Abel", "Lateral-Esquerdo", 23, 58500, 598200, 6.8, "Contrato ate 2025", c5);
        x++;
        salva(j5, out);
        free(j5);

        TPlayer *j6 = criarJogador(numeros[x], "Rafael", "Goleiro", 27, 56500, 423200, 8.8, "Fim de 2023", c6);
        x++;
        salva(j6, out);
        free(j6);

        TPlayer *j7 = criarJogador(numeros[x], "Lucas", "Atacante", 27, 59500, 467200, 7.8, "Livre no mercado", c21);
        x++;
        salva(j7, out);
        free(j7);

        TPlayer *j8 = criarJogador(numeros[x], "Leandro", "Meio-Campo", 26, 89500, 423200, 8.9, "Fim de 2023", c8);
        x++;
        salva(j8, out);
        free(j8);

        TPlayer *j9 = criarJogador(numeros[x], "Bruno", "Zagueiro", 27, 55500, 412200, 4.8, "Fim de 2025", c9);
        x++;
        salva(j9, out);
        free(j9);

        TPlayer *j10 = criarJogador(numeros[x], "Mateus", "Volante", 29, 55000, 482200, 7.8, "Contrato ate 2027", c10);
        x++;
        salva(j10, out);
        free(j10);
    }
    free(numeros);
    return contador;
}

// LE JOGADORES
void le_jogadores(FILE *in) {
    printf("\n\nLendo jogadores do arquivo...\n\n");
    rewind(in);
    TPlayer *f;
    while ((f = le(in)) != NULL) {
        imprime(f);
        free(f);
    }
}

// BUSCA SEQUENCIAL JOGADOR
void busca_sequencial_jogador(FILE *in){
    int c;
    rewind(in);
    TPlayer *j;
    int found = 0;
    int cont = 0;

    FILE *log_file = fopen("Log_jogadores.txt", "a"); // Modo de adição ao invés de escrita
    if (log_file == NULL) {
        printf("Erro ao abrir o arquivo de log.\n");
        return;
    }

    printf("\n\nInforme o codigo do jogador: ");
    scanf("%d", &c);

    clock_t inicio = clock();
    while((j = le(in)) != NULL){
        cont++;
        if (j->id == c){
            printf("Jogador Encontrado!\n");
            imprime(j);
            found = 1;
            break;
        }
        free(j);
    }
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    if(found){
        fprintf(log_file, "\nBUSCA SEQUENCIAL");
        fprintf(log_file, "\nTempo de execucao da busca: %.2f segundos\n", tempo);
        fprintf(log_file, "Numero de comparacoes: %d\n", cont);

        printf("\nTempo de execucao da busca: %.2f segundos\n", tempo);
        printf("Numero de comparacoes: %d\n", cont);
    } else {
        fprintf(log_file, "\nBUSCA SEQUENCIAL");
        fprintf(log_file, "jogador nao pertence a base de dados!...");
        fprintf(log_file, "\nNumero de comparacoes: %d\n", cont);

        printf("Jogador nao pertence a base de dados!...");
        printf("\nNumero de comparacoes: %d\n", cont);
    }

    fclose(log_file);
}


//TAMANHO DO REGISTRO DE JOGADOR
int tamanho_registro() {
    return sizeof(int) + sizeof(char) * 100 + sizeof(char) * 50 + sizeof(int)
    + sizeof(double) * 2 + sizeof(float) + sizeof(char) * 100 + sizeof(TClub);
}

//TAMANHO DO ARQUIVO JOGADOR
int tamanho_arquivo(FILE *arq) {
  fseek(arq, 0, SEEK_END);
  int tam = trunc(ftell(arq) / tamanho_registro());
  return tam;
}

//TAMANHO DO ARQUIVO PARA FUNÇÃO DE SELEÇÃO COM SUBSTITUIÇÃO
int tamanhoArquivoParticao(FILE *file) {
    int contSizeFile = 0;
    int bytesAUX = 0;

    while (1) {
        fseek(file, bytesAUX * sizeof(TPlayer), SEEK_SET);
        TPlayer *aux = le(file);
        if (aux == NULL) {
            break;
        }
        free(aux);
        contSizeFile++;
        bytesAUX++;
    }

    return contSizeFile;
}

//ORDENA JOGADORES
void insertion_sort_disco(FILE *arq) {
    int i;
    int tam = tamanho_arquivo(arq);
    //faz o insertion sort
    for (int j = 2; j <= tam; j++) {
        //posiciona o arquivo no registro j
        fseek(arq, (j-1) * tamanho_registro(), SEEK_SET);
        TPlayer *jogj = le(arq);
        printf("\n********* Jogador atual: %d\n", jogj->id);
        i = j - 1;
        //posiciona o cursor no registro i
        fseek(arq, (i-1) * tamanho_registro(), SEEK_SET);
        TPlayer *jogi = le(arq);
        printf("jogi = %d\n", jogi->id);
        while ((i > 0) && (jogi->id > jogj->id)) {
            //posiciona o cursor no registro i+1
            fseek(arq, i * tamanho_registro(), SEEK_SET);
            printf("Salvando jogador %d na posicao %d\n", jogi->id, i+1);
            salva(jogi, arq);
            i = i - 1;
            //posiciona o cursor no registro i
            fseek(arq, (i-1) * tamanho_registro(), SEEK_SET);
            jogi = le(arq);
            printf("jogi = %d; i = %d\n", jogi->id, i);
        }
        //posiciona cursor no registro i + 1
        fseek(arq, (i) * tamanho_registro(), SEEK_SET);
        printf("*** Salvando jogador %d na posicao %d\n", jogj->id, i+1);
        //salva registro j na posicao i
        salva(jogj, arq);
    }
    //descarrega o buffer para ter certeza que dados foram gravados
    fflush(arq);
}

//ORDENAR COM QUICKSORT
void quicksort(TPlayer arr[], int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        quicksort(arr, left, pivot - 1);
        quicksort(arr, pivot + 1, right);
    }
}

int partition(TPlayer arr[], int left, int right) {
    TPlayer pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j].id <= pivot.id) {
            i++;
            TPlayer temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    TPlayer temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;
}

//BUSCA BINARIA
TPlayer* busca_binaria(FILE *arq) {
  int tam = tamanho_arquivo(arq);
  int cod;

  FILE *log_file = fopen("Log_jogadores.txt", "a"); // Modo de adição ao invés de escrita
    if (log_file == NULL) {
        printf("Erro ao abrir o arquivo de log.\n");
        return;
    }

  printf("\nInforme o codigo do jogador: ");
  scanf("%d", &cod);

  int left = 0, right = tam - 1;
  int cont = 0;

  clock_t inicio = clock();

  while (left <= right) {
    int middle = (left + right) / 2;
    fseek(arq, middle * tamanho_registro(), SEEK_SET);
    TPlayer* jog = le(arq);
    cont++;

    if (cod == jog->id) {
      printf("\nJogador Encontrado!\n");
      imprime(jog);
      clock_t fim = clock();
      double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

      fprintf(log_file, "\nBUSCA BINARIA");
      fprintf(log_file, "\nTempo de execucao: %.2f segundos\n", tempo);
      fprintf(log_file, "Numero de comparacoes: %d\n", cont);

      printf("\nTempo de execucao: %.2f segundos\n", tempo);
      printf("Numero de comparacoes: %d\n", cont);
      return jog;
    } else if (cod < jog->id) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }

    free(jog);
  }

  fprintf(log_file, "\nBUSCA BINARIA");
  fprintf(log_file, "Jogador nao pertence a base de dados!...\n");
  fprintf(log_file, "Numero de comparacoes: %d\n", cont);

  printf("Jogador nao pertence a base de dados!...\n");
  printf("Numero de comparacoes: %d\n", cont);

  fclose(log_file);
  return NULL;
}


//JOGADORES POR CLUBE
void pesquisar_jogadores_clube(FILE *out){
    int contador = 0;
    printf("Informe o codigo do clube que deseja visualizar os jogadores: ");
    scanf("%d", &contador);

    rewind(out);
    TPlayer *f;

    while ((f = le(out)) != NULL) {
        if(f->clube.id == contador){
            imprime(f);
            free(f);
        }
    }
}

// LER JOGADORES (IMPRIMIR)
TClub* pesquisar_clube_codigo(FILE *in, int codigoClube){
    int flag = 0;

    rewind(in);
    TClub *c;
    while ((c = leClube(in)) != NULL){
        if(c->id == codigoClube){
            imprimeClube(c);
            return c;
        }
    }
    c->id = -1;
    return c;
}

void transferencia_jogador(FILE *in, FILE * clube){
    int contador = 0;
    int flag = 0;
    int codigoClube;
    printf("Informe o codigo do jogador que deseja contratar: \n");
    scanf("%d", &contador);

    rewind(in);
    TPlayer *f;
    while ((f = le(in)) != NULL) {
        if(f->id == contador){
            imprime(f);

            printf("Deseja realizar a contratacao do jogador?: \n");
            printf("1 SIM\n");
            printf("2 NAO\n");
            scanf("%d", &flag);

            if(flag == 1){
                printf("Informe o codigo do clube para finalizar a contratacao do jogador: \n");
                scanf("%d", &codigoClube);

                TClub *clubeTransferencia = pesquisar_clube_codigo(clube, codigoClube);

                if(clubeTransferencia->id != -1){

                        //fseek(in, -sizeof(TPlayer), SEEK_CUR); // Move o ponteiro de volta para a posição do jogador
                        strcpy(f->clube.nome, clubeTransferencia->nome);
                        //fwrite(f, sizeof(TPlayer), 1, in); // Salva o jogador com o novo nome

                        //fseek(in, -sizeof(TPlayer), SEEK_CUR); // Move o ponteiro de volta para a posição do jogador
                        f->clube.id = clubeTransferencia->id;
                        //fwrite(f, sizeof(TPlayer), 1, in); // Salva o jogador com o novo nome

                        printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> JOGADOR TRANSFERIDO <<<<<<<<<<<<<<<<<<<<<<<<\n");
                        imprime(f);
                }

                } else {
                    printf("Clube nao encontrado, transacao cancelada! \n");
                }
                printf("Contratacao realizada com sucesso!\n");
                //fclose(in);


                return 0;
            } else if(flag == 2){
                printf("Contratacao cancelada!\n");
                return 0;
            }
        }
        printf("Jogador nao encontrado na base de dados\n");
    }

//MEMÓRIA DE REGISTRO PARA FUNÇÃO SELEÇÃO COM SUBSTITUIÇÃO
int registroMemoria (int vet[6]) {

    int cont = 0;

    for (int i = 0; i < 6; ++i) {
        if (vet[i] == 1) {
            cont++;
        }
    }

    if (cont == 6) {
        return 1;
    } else {
        return 0;
    }
}

//IMPRIMIR ID JOGADOR
void imprimeParticoes(FILE *file, char nomeParticao[]) {
    printf("PARTICAO: %s \n\n", nomeParticao);

    int totalPlayers = tamanhoArquivoParticao(file);

    for (int i = 0; i < totalPlayers; ++i) {
        fseek(file, i * tamanho_registro(), SEEK_SET);
        TPlayer *aux = le(file);

        if (aux != NULL) {
            printf("%d ", aux->id);
            free(aux); // Liberar a memória alocada por le()
        }
    }

    printf("\n");
    printf("\n**********************************************************************************************\n");

}

// GERAR PARTIÇÕES
int selecaoSubstituicao(FILE *in, char nomeDaParticao[]) {
    int numeroDeParticoes = 0, contadorArquivo = 0, posicao = 6, posicaoMenorId = 0, menorId = 999999, AuxArquivo = 0, posicaoSelecionada = 0;
    int comparacao = 0;
    TPlayer player[6]; //Escolhemos 6 posições
    int auxVetPlayer[6] = {0, 0, 0, 0, 0, 0}; //Recebe os ID's de cada registro de TPlayer

    rewind(in);

    clock_t inicio = clock();

    // Obter o tamanho do arquivo de entrada
    AuxArquivo = tamanhoArquivoParticao(in);

    printf("\nGerando particoes por Selecao com Substituicao...\n\n");

    // Ler os primeiros 6 registros do arquivo e armazená-los na memória (vetor player)
    for (int i = 0; i < 6; ++i) {
        fseek(in, i * tamanho_registro(), SEEK_SET);
        TPlayer *aux = le(in);
        player[i] = *aux;
        free(aux); // Liberar a memória alocada por le()
    }

    // Preencher o vetor auxiliar 'auxVetPlayer' com os IDs dos registros do vetor 'player'
    for (int i = 0; i < 6; ++i) {
        auxVetPlayer[i] = player[i].id;
    }

    // Looping da geração de partições
    while (posicao != AuxArquivo) { //Enquanto AuxArquivo for diferente de (6 numero de posições)

        //Cria partições
        char nomeParticao[100];
        char str1[100];
        char str2[100] = ".dat";

        itoa(numeroDeParticoes, str1, 10);
        strcat(strcpy(nomeParticao, nomeDaParticao), str1);
        strcat(strcpy(nomeParticao, nomeParticao), str2);

        FILE *filePartition = fopen(nomeParticao, "wb+");

        // Vetor que irá fazer o controle das posições que serão cogeladas
        int vetCongelado[6] = {0, 0, 0, 0, 0, 0};

        // Loop interno para selecionar elementos para a partição
        while (posicao != AuxArquivo) {

            menorId = 9999999;

            // Encontrar o menor ID r dentre os IDs presentes no vetor auxiliar 'auxVetPlayer'
            for (int i = 0; i < 6; ++i) {
                if (menorId > auxVetPlayer[i] && vetCongelado[i] != 1) {
                    comparacao = comparacao + 1;
                    menorId = auxVetPlayer[i];
                    posicaoMenorId = i;
                }
            }

            // Salvar o registro com menor ID na partição
            salva(&player[posicaoMenorId], filePartition);

            // Ler próximo registro do arquivo de entrada
            fseek(in, posicao * tamanho_registro(), SEEK_SET);
            TPlayer *aux = le(in);

            //Atualiza a posição
            posicao++;

            // Atualizar vetor auxiliar 'auxVetPlayer' e vetor 'player' com o novo registro lido
            auxVetPlayer[posicaoMenorId] = aux->id;
            player[posicaoMenorId] = *aux;

            // Congelar o registro se o ID for menor que o recém gravado na partição de saída
            if (aux->id < menorId) {
                comparacao = comparacao + 1;
                vetCongelado[posicaoMenorId] = 1;
            }

            // Verificar se a memória da partição está cheia

            //Se for igual a 1 significa que vetor de congelos esta cheio.
            //Volta por passo 2 e descongela
            if (registroMemoria(vetCongelado) == 1) {
                comparacao = comparacao + 1;
                numeroDeParticoes++;
                break;
            }
        }

        // Fechar a partição criada
        fclose(filePartition);

        // Verificar se a última posição foi atingida
        if (posicao >= AuxArquivo) {
            break;
        }
    }

    // Nome da partição final a ser criada
    char nomeParticao[100];
    char str1[100];
    char str2[100] = ".dat";

    itoa(numeroDeParticoes, str1, 10);
    strcat(strcpy(nomeParticao, nomeDaParticao), str1);
    strcat(strcpy(nomeParticao, nomeParticao), str2);

    // Criar a partição final
    FILE *filePartitionFinal = fopen(nomeParticao, "ab+");

   // Criar uma lista dinâmica para armazenar os registros restantes
    TPlayer *remainingPlayers = malloc((AuxArquivo - posicao) * sizeof(TPlayer));
    int remainingCount = 0;

    // Armazenar os registros restantes na lista
    while (posicao < AuxArquivo) {
        fseek(in, posicao * tamanho_registro(), SEEK_SET);
        TPlayer *aux = le(in);
        remainingPlayers[remainingCount++] = *aux;
        free(aux);
        posicao++;
    }

    quicksort(remainingPlayers, 0, remainingCount - 1);

    for (int i = 0; i < remainingCount; ++i) {
        salva(&remainingPlayers[i], filePartitionFinal);
    }

    free(remainingPlayers);

    fclose(filePartitionFinal);

    // Looping para imprimir o conteúdo de cada partição gerada
    for (int i = 0; i <= numeroDeParticoes; ++i) {
        itoa(i, str1, 10);
        strcat(strcpy(nomeParticao, nomeDaParticao), str1);
        strcat(strcpy(nomeParticao, nomeParticao), str2);

        FILE *filePartition = fopen(nomeParticao, "rb+");

        imprimeParticoes(filePartition, nomeParticao);

        fclose(filePartition);
    }

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    FILE *log_file = fopen("Log_jogadores.txt", "a"); // Modo de adição ao invés de escrita
    if (log_file == NULL) {
        printf("Erro ao abrir o arquivo de log.\n");
        return;
    }

    printf("\nTempo de execucao do metodo de selecao: %.2f segundos\n", tempo);
    printf("Numero de comparacoes: %d\n", comparacao);

    fprintf(log_file, "SELECAO POR SUBSTITUICAO");
    fprintf(log_file, "\nTempo de execucao do metodo de selecao: %.2f segundos\n", tempo);
    fprintf(log_file, "Numero de comparacoes: %d\n", comparacao);

    fclose(log_file);

    return numeroDeParticoes;
}

//INTERCALAÇÃO DE PARTIÇÕES ORDENADAS
void intercalacaoOtima(FILE *in, char nomeDaParticao[], int qtdParticoes) {

    //Cria um vetor de partições que recebe as partições do SELEÇÃO POR SUBSTITUIÇÃO
    FILE *particoes[qtdParticoes + 1];
    TPlayer *registros[qtdParticoes + 1];

    clock_t inicio = clock();
    int comparacao = 0;

    //Abre as partições para leitura
    for (int i = 0; i < qtdParticoes; i++) {
        char nomeArqParticao[20];
        snprintf(nomeArqParticao, sizeof(nomeArqParticao), "%s%d.dat", nomeDaParticao, i);
        particoes[i] = fopen(nomeArqParticao, "rb"); // Leitura dos arquivos de partição
        if (particoes[i] == NULL) {
            printf("Erro ao abrir o arquivo da partição %s\n", nomeArqParticao);
            exit(1);
        }

        //Leitura dos registros
        registros[i] = le(particoes[i]);
    }

    //Escolhemsos pegar de 4 em 4
    int grupoSize = 4; // Tamanho do grupo de partições a intercalar
    //Faz a conta das partições
    int numGrupos = qtdParticoes / grupoSize;

    // Looping para intercalar grupos de partições
    //Primeiro for para concatenar as partições
    for (int grupo = 0; grupo < qtdParticoes; grupo += 4) {
        TPlayer *grupoRegistros[4 * qtdParticoes];
        int idx = 0;

        // Carrega os registros do grupo de 4 partições
        for (int i = grupo; i < grupo + 4 && i < qtdParticoes; i++) {
            while (registros[i] != NULL) {
                comparacao = comparacao + 1;
                grupoRegistros[idx++] = registros[i];
                registros[i] = le(particoes[i]);

                if (idx >= 4 * qtdParticoes) {
                    break;
                }
            }
        }

        // Ordena o grupo de registros
        // Ordenação por Bubble sort
        for (int i = 0; i < idx - 1; i++) {
            for (int j = i + 1; j < idx; j++) {
                if (grupoRegistros[i]->id > grupoRegistros[j]->id) {
                    comparacao = comparacao + 1;
                    TPlayer *temp = grupoRegistros[i];
                    grupoRegistros[i] = grupoRegistros[j];
                    grupoRegistros[j] = temp;
                }
            }
        }

        // Cria o nome da partição de saída
        //Aqui é criado o 5 arquivo de saida com as partições ordenadas acima (baseado no mumero da ultima particao)
        char nomeParticao[100];
        char str1[100];
        char str2[100] = ".dat";

        int numeroParticao = qtdParticoes + 1 + grupo / 4; // Nomear a partir do número da última partição + 1
        itoa(numeroParticao, str1, 10);
        strcat(strcpy(nomeParticao, nomeDaParticao), str1);
        strcat(strcpy(nomeParticao, nomeParticao), str2);

        // Grava o grupo ordenado na partição
        FILE *filePartition = fopen(nomeParticao, "wb+");
        if (filePartition == NULL) {
            printf("Erro ao criar a partição %s\n", nomeParticao);
            exit(1);
        }

        for (int i = 0; i < idx; i++) {
            salva(grupoRegistros[i], filePartition);
        }

        fclose(filePartition);
    }

     // Looping para imprimir o conteúdo de cada partição gerada após a concatenação
    for (int grupo = 0; grupo < qtdParticoes; grupo += 4) {
        char nomeParticao[100];
        char str1[100];
        char str2[100] = ".dat";

        int numeroParticao = qtdParticoes + 1 + grupo / 4; // Nomear a partir do número da última partição + 1
        itoa(numeroParticao, str1, 10);
        strcat(strcpy(nomeParticao, nomeDaParticao), str1);
        strcat(strcpy(nomeParticao, nomeParticao), str2);

        FILE *filePartition = fopen(nomeParticao, "rb+");
        if (filePartition == NULL) {
            printf("Erro ao abrir a partição %s para impressão\n", nomeParticao);
            exit(1);
        }

        imprimeParticoes(filePartition, nomeParticao);

        fclose(filePartition);
    }


    // Fecha os arquivos e libera memória
    for (int i = 0; i < qtdParticoes; i++) {
        fclose(particoes[i]);
        free(registros[i]);
    }

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\nTempo de execucao do metodo de intercalacao otima: %.2f segundos\n", tempo);
    printf("Numero de comparacoes: %d\n\n\n", comparacao);

    FILE *log_file = fopen("Log_jogadores.txt", "a"); // Modo de adição ao invés de escrita
    if (log_file == NULL) {
        printf("Erro ao abrir o arquivo de log.\n");
        return;
    }

    fprintf(log_file, "INTERCALACAO OTIMA");
    fprintf(log_file, "\nTempo de execucao do metodo de selecao: %.2f segundos\n", tempo);
    fprintf(log_file, "Numero de comparacoes: %d\n", comparacao);

    fclose(log_file);


}

void unirParticoesOrdenadas(char nomeDaParticao[], int numParticoes) {
    FILE *saidaFinal = fopen("saida_final_ordenada.dat", "wb+");
    if (saidaFinal == NULL) {
        printf("Erro ao criar o arquivo de saída final ordenada.\n");
        exit(1);
    }

    TPlayer *registros[numParticoes];
    FILE *particoes[numParticoes];

    // Abrir todas as partições
    for (int i = 0; i < numParticoes; i++) {
        char nomeArqParticao[20];
        snprintf(nomeArqParticao, sizeof(nomeArqParticao), "%s%d.dat", nomeDaParticao, i);
        particoes[i] = fopen(nomeArqParticao, "rb"); // Leitura dos arquivos de partição
        if (particoes[i] == NULL) {
            printf("Erro ao abrir o arquivo da partição %s\n", nomeArqParticao);
            exit(1);
        }

        registros[i] = le(particoes[i]);
    }

    // Merge sort para unir as partições ordenadas
    while (1) {
        int menorId = INT_MAX;
        int idxMenor = -1;

        // Encontrar o menor registro entre as partições
        for (int i = 0; i < numParticoes; i++) {
            if (registros[i] != NULL && registros[i]->id < menorId) {
                menorId = registros[i]->id;
                idxMenor = i;
            }
        }

        if (idxMenor == -1) {
            // Todos os registros foram unidos

            break;
        }

        // Salvar o registro no arquivo final
        salva(registros[idxMenor], saidaFinal);

        // Ler o próximo registro da partição correspondente
        registros[idxMenor] = le(particoes[idxMenor]);
    }

    // Fechar e remover as partições
    for (int i = 0; i < numParticoes; i++) {
        fclose(particoes[i]);
        char nomeArqParticao[20];
        snprintf(nomeArqParticao, sizeof(nomeArqParticao), "%s%d.dat", nomeDaParticao, i);
        remove(nomeArqParticao);
    }

    fclose(saidaFinal);

    // Abrir o arquivo final ordenado para impressão
    FILE *saidaFinalOrdenada = fopen("saida_final_ordenada.dat", "rb");
    if (saidaFinalOrdenada == NULL) {
        printf("Erro ao abrir o arquivo de saída final ordenada para impressão.\n");
        exit(1);
    }

    // Imprimir o conteúdo do arquivo final ordenado
    imprimeParticoesFinal(saidaFinalOrdenada, "saida_final_ordenada.dat");

    fclose(saidaFinalOrdenada);
}

//IMPRIMIR SAIDA FINAL
void imprimeParticoesFinal(FILE *file, char nomeParticao[]) {
    printf("PARTICAO: %s \n\n", nomeParticao);

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    int totalPlayers = fileSize / tamanho_registro();

    fseek(file, 0, SEEK_SET);

    for (int i = 0; i < totalPlayers; ++i) {
        TPlayer *aux = le(file);

        if (aux != NULL) {
            printf("%d ", aux->id);
            free(aux); // Liberar a memória alocada por le()
        }
    }

    printf("\n");
    printf("\n********************************************************************************************\n");

}

//CRIA ARVORE B
void cria_arvore_b(FILE *out, int codigo) {
    TClub *c = criarClube(0, "");
    TPlayer *j = criarJogador(codigo, "", "", 0, 0, 0, 0, "", c);
    salva_arvore(j, out);
    free(j);
    free(c);
}

TPlayer *le_jogador_por_id(int id) {
    FILE *arquivo = fopen("jogador.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de jogadores.\n");
        return NULL;
    }

    TPlayer *jogador = NULL;

    while ((jogador = le(arquivo)) != NULL) {
        if (jogador->id == id) {
            fclose(arquivo);
            return jogador;
        }
        free(jogador); // Liberar memória se não for o jogador desejado
    }

    fclose(arquivo);
    printf("Jogador com ID %d nao encontrado.\n", id);
    return NULL;
}

//REMOVE JOGADOR
void exclui_jogador(FILE *arquivo, int id) {
    FILE *temp = fopen("temp.dat", "wb");  // Arquivo temporário para reescrita
    if (temp == NULL) {
        printf("Erro ao abrir arquivo temporario.\n");
        return;
    }

    TPlayer *jogador;
    int removido = 0;

    fseek(arquivo, 0, SEEK_SET);
    while ((jogador = le(arquivo)) != NULL) {
        if (jogador->id == id) {
            removido = 1;  // Indica que o jogador foi removido
            free(jogador);  // Libera a memória do jogador removido
            continue;  // Pula a escrita do jogador removido no arquivo temporário
        }

        // Escreve o jogador no arquivo temporário
        salva(jogador, temp);
        free(jogador);  // Libera a memória do jogador lido
    }

    fclose(arquivo);
    fclose(temp);

    if (removido) {
        remove("jogador.dat");  // Remove o arquivo original
        rename("temp.dat", "jogador.dat");  // Renomeia o arquivo temporário para o nome original
    } else {
        remove("temp.dat");  // Se nenhum jogador foi removido, remove o arquivo temporário
        printf("Jogador com ID %d nao encontrado.\n", id);
    }

    arquivo = fopen("jogador.dat", "rb+");  // Reabre o arquivo original em modo de leitura e escrita
}
