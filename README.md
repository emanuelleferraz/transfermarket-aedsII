# ⚽ Sistema Transfermarket - Aplicação em Linguagem C

Este projeto consiste em um conjunto de algoritmos e estruturas de dados implementados através de um sistema voltado ao mercado do futebol para realizar operações de busca e ordenação de dados em memória secundária. O projeto destaca os seguintes métodos e estruturas:

## 🔍 Busca Sequencial

O algoritmo de busca sequencial percorre a lista de elementos um a um até encontrar o valor desejado. É uma abordagem simples, mas eficaz para listas não ordenadas.
```c
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
```
## 🔍 Busca Binária

A busca binária é uma técnica eficiente para buscar um elemento em uma lista ordenada. Ela divide a lista em metades e compara o valor alvo com o elemento no meio, reduzindo o espaço de busca pela metade a cada iteração.

```c
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
```
## Métodos de Ordenação

### ⚖️ Seleção com Substituição

O método de seleção por substituição é uma variação da ordenação por seleção. Neste método, os elementos são selecionados em um vetor e distribuídos em partições de acordo com o menor elemento selecionado. Quando todos os elementos do vetor estão "congelados", uma nova partição é criada e o processo é repetido.

### 🧾 Intercalação Ótima

A técnica de intercalação ótima é usada para unir listas ordenadas em uma única lista ordenada. Isso é útil para a ordenação de grandes conjuntos de dados.

### 🌳 Árvore B

A árvore B é uma estrutura de dados eficiente para armazenar e organizar grandes conjuntos de dados de forma balanceada. É útil para operações de busca e inserção.

O método oferece as seguintes funcionalidades:

- Inserção de jogadores na Árvore B.
- Remoção de jogadores da Árvore B.
- Busca e impressão de jogadores por ID.
- Impressão da Árvore B.

**Funções:**
- `cria` - Cria o nó da árvore
- `insere_folha` - Insere nó folha na árvore
- `busca` - Busca nó na árvore
- `remove_arvore` - Exclui nó da árvore

- Criação da árvore:
```c
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
``` 

## 📫 Autores
- Emanuelle Ferraz Lima
- Mateus Henrique Santos
- Contato: emanuelle.ferrazlm@gmail.com

