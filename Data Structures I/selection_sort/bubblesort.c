#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elemento Elemento;

struct elemento {
    int valor;
    Elemento *proximo;
    Elemento *anterior;
};

// Variáveis globais da lista
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

void bubbleSort() {
    if (inicio == NULL) return;

    int trocou;
    Elemento *atual;
    Elemento *ultimo = NULL;

    do {
        trocou = 0;
        atual = inicio;

        while (atual->proximo != ultimo) {
            if (atual->valor > atual->proximo->valor) {
                swap(atual, atual->proximo);
                trocou = 1;
            }
            atual = atual->proximo;
        }
        ultimo = atual;
    } while (trocou);
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

    printf("\nBubble Sort:\n");
    medeTempo(bubbleSort);
    imprimeLista();

    return 0;
}
