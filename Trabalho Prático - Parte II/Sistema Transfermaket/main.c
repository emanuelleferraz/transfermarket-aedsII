#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    FILE *out;
    FILE *club;
    FILE *olheiro;

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
    } else {
        MENU(out, club, olheiro);
        fclose(out);
        fclose(club);
        fclose(olheiro);
    }
}

