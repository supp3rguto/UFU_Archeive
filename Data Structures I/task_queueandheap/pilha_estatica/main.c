#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pilhae.c"

int main() {
    PilhaEstoqueComponentes pilha;
    inicializaPilha(&pilha);

    clock_t inicio, fim;
    double tempoa_decorrido;
    double tempob_decorrido;
    double tempoc_decorrido;

    inicio = clock();
    for (int i = 0; i < MAX; i++) {
        insereComponente(&pilha, i);
    }
    fim = clock();
    tempoa_decorrido = fim - inicio;

    inicio = clock();
    imprimeEstoqueComponentes(&pilha);
    fim = clock();
    tempob_decorrido = fim - inicio;

    inicio = clock();
    for (int i = 0; i < MAX; i++) {
        removeComponente(&pilha);
    }
    fim = clock();
    tempoc_decorrido = fim - inicio;

    printf("Tempo de insercao na pilha estatica: %ld clocks\n", (long)tempoa_decorrido);
    printf("Tempo de remocao na pilha estatica: %ld clocks\n", (long)tempoc_decorrido);
    printf("Tempo de impressao na pilha estatica: %ld clocks\n", (long)tempob_decorrido);

    return 0;
}
