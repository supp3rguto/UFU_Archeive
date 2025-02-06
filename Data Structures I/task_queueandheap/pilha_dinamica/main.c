#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pilhad.c"

int main() {
    PilhaEstoqueHardware pilha;
    inicializaPilha(&pilha);

    clock_t inicio, fim;
    double tempoa_decorrido;
    double tempob_decorrido;
    double tempoc_decorrido;

    inicio = clock();
    for (int i = 0; i < 25000; i++) {
        insereComponente(&pilha, i);
    }
    fim = clock();
    tempoa_decorrido = fim - inicio;

    inicio = clock();
    imprimeEstoqueHardware(&pilha);
    fim = clock();
    tempob_decorrido = fim - inicio;

    inicio = clock();
    for (int i = 0; i < 25000; i++) {
        removeComponente(&pilha);
    }
    fim = clock();
    tempoc_decorrido = fim - inicio;

    printf("Tempo de insercao na pilha dinamica: %ld clocks\n", (long)tempoa_decorrido);
    printf("Tempo de remocao na pilha dinamica: %ld clocks\n", (long)tempoc_decorrido);
    printf("Tempo de impressao na pilha dinamica: %ld clocks\n", (long)tempob_decorrido);

    return 0;
}
