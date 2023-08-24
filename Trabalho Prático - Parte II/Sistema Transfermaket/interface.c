//
//  Created by Mateus Santos & Emanuelle Ferraz
//    Trabalho Pratico - AEDS II
//

#include <stdio.h>
#include <stdlib.h>

#include "interface.h"


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

    printf("\n");
    printf("  \n\t15. SAIR");
}

void MENU(FILE *out, FILE *club, FILE *olheiro){
	int controle = 0;
	int opcao;
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
    } while(controle != 15);
}

