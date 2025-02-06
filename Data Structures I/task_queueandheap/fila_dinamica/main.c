#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "filad.c"

int main() {
    FilaComunicacaoEspacial fila;
    inicializaFila(&fila);

    clock_t inicio, fim;
    double tempoa_decorrido;
    double tempob_decorrido;
    double tempoc_decorrido;

    inicio = clock();
    for (int i = 0; i < 25000; i++) {
        insereComando(&fila, i);
    }
    fim = clock();
    tempoa_decorrido = fim - inicio;

    inicio = clock();
    imprimeFilaComunicacao(&fila);
    fim = clock();
    tempob_decorrido = fim - inicio;

    inicio = clock();
    for (int i = 0; i < 25000; i++) {
        removeComando(&fila);
    }
    fim = clock();
    tempoc_decorrido = fim - inicio;

    printf("Tempo de insercao na fila dinamica: %ld clocks\n", (long)tempoa_decorrido);
    printf("Tempo de remocao na fila dinamica: %ld clocks\n", (long)tempoc_decorrido);
    printf("Tempo de impressao na fila dinamica: %ld clocks\n", (long)tempob_decorrido);

    return 0;
}
