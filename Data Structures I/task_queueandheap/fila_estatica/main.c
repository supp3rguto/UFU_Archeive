#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "filae.c"

int main() {
    FilaComandosTerraEstacao fila;
    inicializaFila(&fila);

    clock_t inicio, fim;
    double tempoa_decorrido;
    double tempob_decorrido;
    double tempoc_decorrido;

    inicio = clock();
    for (int i = 0; i < MAX; i++) {
        insereMensagem(&fila, i);
    }
    fim = clock();
    tempoa_decorrido = fim - inicio;

    inicio = clock();
    imprimeFilaMensagens(&fila);
    fim = clock();
    tempob_decorrido = fim - inicio;

    inicio = clock();
    for (int i = 0; i < MAX; i++) {
        removeMensagem(&fila);
    }
    fim = clock();
    tempoc_decorrido = fim - inicio;

    printf("Tempo de insercao na fila estatica: %ld clocks\n", (long)tempoa_decorrido);
    printf("Tempo de remocao na fila estatica: %ld clocks\n", (long)tempoc_decorrido);
    printf("Tempo de impressao na fila estatica: %ld clocks\n", (long)tempob_decorrido);

    return 0;
}
