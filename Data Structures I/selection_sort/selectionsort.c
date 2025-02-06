#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elemento Elemento;

struct elemento {
    int valor;
    Elemento *proximo;
    Elemento *anterior;
};

Elemento *inicio;
Elemento *fim;
int tamanho;

void criaLista() {
    inicio = NULL;
    fim = NULL;
    tamanho = 0;
}

Elemento *aloca(int valor) {
    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}

void insereFim(int valor) {
    Elemento *novo = aloca(valor);
    if (inicio == NULL) {
        inicio = novo;
        fim = novo;
    } else {
        fim->proximo = novo;
        novo->anterior = fim;
        fim = novo;
    }
    tamanho++;
}

void imprimeLista() {
    Elemento *atual = inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void swap(Elemento *a, Elemento *b) {
    int temp = a->valor;
    a->valor = b->valor;
    b->valor = temp;
}

void selectionSort() {
    if (inicio == NULL) return;

    Elemento *i, *j, *min;

    for (i = inicio; i != NULL; i = i->proximo) {
        min = i;
        for (j = i->proximo; j != NULL; j = j->proximo) {
            if (j->valor < min->valor) {
                min = j;
            }
        }
        if (min != i) {
            swap(i, min);
        }
    }
}

void medeTempo(void (*sortFunc)()) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    sortFunc();
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f segundos\n", cpu_time_used);
}

int main() {
    criaLista();
    for (int i = 0; i < 1000; i++) {
        insereFim(rand() % 10000);
    }

    printf("Lista original:\n");
    imprimeLista();

    printf("\nSelection Sort:\n");
    medeTempo(selectionSort);
    imprimeLista();

    return 0;
}
