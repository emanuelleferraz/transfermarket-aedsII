//
//  Created by Mateus Santos & Emanuelle Ferraz
//    Trabalho Pratico - AEDS II
//

#include <stdio.h>
#include <stdlib.h>

#include "interface.h"
#include "jogador.h"
#include "arvore-b.h"

void MSG_MENU( )
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> SEJA BEM VINDO AO MERCADO DE TRANSFERENCIAS TRANSFERMARKET <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. CRIAR MULTIPLOS JOGADORES");
    printf("  \n\t2. IMPRIMIR JOGADORES");
    printf("  \n\t3. CRIAR CLUBES");
    printf("  \n\t4. IMPRIMIR CLUBES");
    printf("  \n\t5. CRIAR OLHEIROS");
    printf("  \n\t6. IMPRIMIR OLHEIROS");
    printf("  \n\t7. BUSCA SEQUENCIAL");
    printf("  \n\t8. ORDENAR ARQUIVOS");
    printf("  \n\t9. BUSCA BINARIA");
    printf("\n");
    printf("  \n\t12. SOBRE");

    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> PARA OLHEIROS <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("  \n\t10. PESQUISAR JOGADOR POR CLUBE");
    printf("  \n\t11. REALIZAR TRANSFERENCIA");

    printf("\n\n\t>>>>>>> GERACAO DE PARTICOES E METODOS DE INTERCALACAO <<<<<<<");
    printf("  \n\t13. GERAR PARTICOES - SELECAO POR SUBSTITUICAO");
    printf("  \n\t14. INTERCALAR PARTICOES - INTERCALACAO OTIMA");

    printf("\n\n\t>>>>>>>>>>>>>> ARVORE B <<<<<<<<<<<<<<");
    printf("  \n\t15. CONSTRUIR ARVORE");
    printf("  \n\t16. BUSCAR");
    printf("  \n\t17. INSERIR");
    printf("  \n\t18. REMOVER");

    printf("\n");
    printf("  \n\t19. SAIR");
}

void MENU(FILE *out, FILE *club, FILE *olheiro, FILE *arvoreb){
	int controle = 0;
	int opcao, chave;
	int fleg;
	int numParticoes;
    do
    {
        MSG_MENU();
        printf("\n\nDIGITE UMA OPCAO: ");
        fflush(stdin);
        scanf("%d", &controle);
        switch(controle)
        {
            case 1:
                insere_multiplos_jogadores(out);
                system("PAUSE");
                break;
            case 2:
                le_jogadores(out);
                system("PAUSE");
                break;
            case 3:
                insereClubes(club);
                system("PAUSE");
                break;
            case 4:
                le_clubes(club);
                system("PAUSE");
                break;
            case 5:
                insere_multiplos_olheiros(olheiro);
                system("PAUSE");
                break;
             case 6:
                le_olheiros(olheiro);
                system("PAUSE");
                break;
            case 7:
                printf("\n\n\t>>>>>>>>>>>>>>>>>> OPCOES <<<<<<<<<<<<<<<<<<<<<<");
                printf("\n\n\t1. BUSCAR JOGADOR");
                printf("  \n\t2. BUSCAR CLUBE");
                printf("  \n\t3. BUSCAR OLHEIRO");

                printf("\n\nDIGITE UMA OPCAO: ");
                scanf("%d", &opcao);

                if(opcao == 1){
                    busca_sequencial_jogador(out);
                } else if(opcao == 2){
                    busca_sequencial_clube(club);
                } else if(opcao == 3){
                    busca_sequencial_olheiro(olheiro);
                }
                system("PAUSE");
                break;
            case 8:
                printf("\n\n\t>>>>>>>>>>>>>>>>>> OPCOES <<<<<<<<<<<<<<<<<<<<<<");
                printf("\n\n\t1. ORDENAR JOGADORES");
                printf("  \n\t2. ORDENAR CLUBES");
                printf("  \n\t3. ORDENAR OLHEIROS");

                printf("\n\nDIGITE UMA OPCAO: ");
                scanf("%d", &opcao);

                if(opcao == 1){
                    insertion_sort_disco(out);
                } else if(opcao == 2){
                    insertion_sort_disco_clube(club);
                } else if(opcao == 3){
                    insertion_sort_disco_olheiro(olheiro);
                }
                system("PAUSE");
                break;
            case 9:
                printf("\n\n\t>>>>>>>>>>>>>>>>>> OPCOES <<<<<<<<<<<<<<<<<<<<<<");
                printf("\n\n\t1. BUSCAR JOGADOR");
                printf("  \n\t2. BUSCAR CLUBE");
                printf("  \n\t3. BUSCAR OLHEIRO");

                printf("\n\nDIGITE UMA OPCAO: ");
                scanf("%d", &opcao);

                if(opcao == 1){
                    busca_binaria(out);
                } else if(opcao == 2){
                    busca_binaria_clube(club);
                } else if(opcao == 3){
                    busca_binaria_olheiro(olheiro);
                }
                system("PAUSE");
                break;
            case 10:
                pesquisar_jogadores_clube(out);

                system("PAUSE");
                break;
            case 11:
                fleg = validar_olheiro(olheiro);

                if(fleg == 0){
                    transferencia_jogador(out, club);
                }

                system("PAUSE");
                break;
            case 12:
                printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> SOBRE O TRANSFERMARKET <<<<<<<<<<<<<<<<<<<<<<<<\n");
                printf("\nO TRANSFERMARKET e um sistema desenvolvido para gestao e acompanhamento de jogadores tanto \nlivres no mercado quanto em todos os clubes da primeira divisao do campeonato brasileiro\na ferramenta comporta todos os olheiros onde os mesmos podem realizar transferencias em tempo real.");
                printf("\n\nDESENVOLVIDO POR:\nEmanuelle Ferraz & Mateus Santos\n");
                printf("INFORMACOES DE CONTATO: \nmanu.ferraz16@gmail.com\nmateus_saantos@outlook.com\n");
                system("PAUSE");
                break;
             case 13:
                numParticoes = selecaoSubstituicao(out, "particao");
                printf("\n\n");

                system("PAUSE");
                break;
            case 14:
                printf("\nExecutando Intercalacao Otima... \n\n");
                intercalacaoOtima(out, "particao", numParticoes + 1);
                unirParticoesOrdenadas("particao", numParticoes + 1);

                system("PAUSE");
                break;
            case 15:
                rewind(out);

                printf("\n...Construindo Arvore B\n");
                char resultado[1000];
                char delimitador[] = "-";
                int valor;
                TNo *raiz = NULL;
                int d = 2;
                TPlayer *f;
                int cont = 0;

                while ((f = le(out)) != NULL) {

                    int id = f->id;
                    cria_arvore_b(arvoreb, id);
                    char temp[20]; // Vetor temporário para armazenar o número convertido
                    snprintf(temp, sizeof(temp), "%d-", id);
                    strcat(resultado, temp); // Concatenando com o resultado existente
                    free(f);
                }
                printf("ID's  %s", resultado);

                raiz = cria_arvore_com_ids(out, d);

                system("PAUSE");
                break;
            case 16:
                printf("\nInforme o codigo do jogador que deseja buscar: ");
                scanf("%d", &opcao);

                busca_e_imprime_jogador(raiz, opcao);

                system("PAUSE");
                break;
            case 17:
                printf("\nInforme o codigo do jogador que deseja inserir na arvore: ");
                scanf("%d", &chave);

                //Inserção do novo jogador no arquivo e na árvore B
                TClub *c3 = criarClube(3, "Vasco");
                fseek(out, tamanho_registro() * 20, SEEK_SET);
                TPlayer *jog = criarJogador(chave, "Zico", "Atacante", 30, 43000, 500000, 7.10, "Fim de 2029", c3);
                salva(jog, out);
                free(jog);

                fseek(out, tamanho_registro() * 20, SEEK_SET);
                TPlayer *jog21 = le(out);

                printf("\n\n****** Inserindo %d ******\n\n", jog->id);
                raiz = insere_folha(raiz, d, jog->id);
                imprime_arvore(raiz, 0);

                system("PAUSE");
                break;
            case 18:
                printf("\nInforme o codigo do jogador que voce deseja excluir: ");
                scanf("%d", &chave);

                printf("\n\n****** Removendo %d *******\n\n", chave);
                remove_arvore(raiz, d, chave);
                exclui_jogador(out, chave);
                imprime_arvore(raiz, 0);

                printf("\nJogador com ID %d removido com sucesso.\n", chave);

                system("PAUSE");
                break;

            case 19:
                //SAIR
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                system("PAUSE");
            } // fim do bloco switch
    } while(controle != 19);
}

