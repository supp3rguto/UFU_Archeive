#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct Fila {
    No* frente;
    No* tras;
} Fila;

void inicializarFila(Fila* fila) {
    fila->frente = NULL;
    fila->tras = NULL;
}

int filaVazia(Fila* fila) {
    return (fila->frente == NULL);
}

void enfileirar(Fila* fila, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->proximo = NULL;

    if (filaVazia(fila)) {
        fila->frente = novoNo;
    } else {
        fila->tras->proximo = novoNo;
    }
    fila->tras = novoNo;
}

void exibirFila(Fila* fila) {
    No* atual = fila->frente;
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    Fila F, F2, F3, F4;
    int valor;

    inicializarFila(&F);
    inicializarFila(&F2);
    inicializarFila(&F3);
    inicializarFila(&F4);

    printf("Digite numeros inteiros para a fila F (digite -1 para encerrar):\n");
    while (1) {
        scanf("%d", &valor);
        if (valor == -1) break;
        enfileirar(&F, valor);

        if (valor % 3 == 0) {
            enfileirar(&F3, valor);
        }
        if (valor % 2 == 0) {
            enfileirar(&F2, valor);
        }
        if (valor % 2 != 0 && valor % 3 != 0) {
            enfileirar(&F4, valor);
        }
    }

    printf("Fila F: ");
    exibirFila(&F);

    printf("Fila F2 (multiplos de 2): ");
    exibirFila(&F2);

    printf("Fila F3 (multiplos de 3): ");
    exibirFila(&F3);

    printf("Fila F4 (nao multiplos de 2 nem de 3): ");
    exibirFila(&F4);

    return 0;
}
