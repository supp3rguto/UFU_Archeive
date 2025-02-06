#include <stdio.h>
#define MAX 100

typedef struct {
    int dados[MAX];
    int inicio, fim, tamanho;
} Fila;

void inicializaFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

int filaCheia(Fila *f) {
    return f->tamanho == MAX;
}

int filaVazia(Fila *f) {
    return f->tamanho == 0;
}

int enfileirar(Fila *f, int valor) {
    if (filaCheia(f)) {
        return 0;
    }
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    f->tamanho++;
    return 1;
}

int desenfileirar(Fila *f, int *valor) {
    if (filaVazia(f)) {
        return 0;
    }
    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return 1;
}

void exibeFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia\n");
        return;
    }
    printf("Fila: ");
    for (int i = 0; i < f->tamanho; i++) {
        int index = (f->inicio + i) % MAX;
        printf("%d ", f->dados[index]);
    }
    printf("\n");
}

int main() {
    Fila F1, F2, F;
    inicializaFila(&F1);
    inicializaFila(&F2);
    inicializaFila(&F);

    int n1, n2, valor;

    printf("Quantos valores deseja inserir na F1? ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Insira o valor %d para F1: ", i + 1);
        scanf("%d", &valor);
        enfileirar(&F1, valor);
    }

    printf("Quantos valores deseja inserir na F2? ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Insira o valor %d para F2: ", i + 1);
        scanf("%d", &valor);
        enfileirar(&F2, valor);
    }

    printf("Fila F1 antes: ");
    exibeFila(&F1);
    printf("Fila F2 antes: ");
    exibeFila(&F2);

    int valorF1, valorF2;
    while (!filaVazia(&F1) && !filaVazia(&F2)) {
        desenfileirar(&F1, &valorF1);
        desenfileirar(&F2, &valorF2);

        if (valorF1 >= valorF2) {
            enfileirar(&F, valorF1);
            enfileirar(&F2, valorF2);
        } else {
            enfileirar(&F, valorF2);
            enfileirar(&F1, valorF1);
        }
    }

    while (!filaVazia(&F1)) {
        desenfileirar(&F1, &valorF1);
        enfileirar(&F, valorF1);
    }

    while (!filaVazia(&F2)) {
        desenfileirar(&F2, &valorF2);
        enfileirar(&F, valorF2);
    }

    printf("Fila F1 depois: ");
    exibeFila(&F1);
    printf("Fila F2 depois: ");
    exibeFila(&F2);
    printf("Fila F resultante: ");
    exibeFila(&F);

    return 0;
}
