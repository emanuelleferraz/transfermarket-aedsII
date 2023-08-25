#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    FILE *out;
    FILE *club;
    FILE *olheiro;
    FILE *arvoreb;

    if ((out = fopen("jogador.dat", "w+b")) == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    if ((club = fopen("clubes.dat", "w+b")) == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    if ((olheiro = fopen("olheiro.dat", "w+b")) == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    if ((arvoreb = fopen("arvore_b.dat", "w+b")) == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    } else {
        MENU(out, club, olheiro, arvoreb);
        fclose(out);
        fclose(club);
        fclose(olheiro);
        fclose(arvoreb);
    }
}

