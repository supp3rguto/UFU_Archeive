#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esq;
    struct No* dir;
} No;

No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

void imprimirNivel(No* raiz) {
    if (raiz == NULL) return;

    No* fila[500];
    int inicio = 0, fim = 0;
    fila[fim++] = raiz;

    int primeiro = 1;

    while (inicio < fim) {
        No* atual = fila[inicio++];
        if (primeiro) {
            printf("%d", atual->valor);
            primeiro = 0;
        } else {
            printf(" %d", atual->valor);
        }

        if (atual->esq != NULL) fila[fim++] = atual->esq;
        if (atual->dir != NULL) fila[fim++] = atual->dir;
    }
}

void liberarArvore(No* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
}

int main() {
    int casos, numElementos, valor;

    scanf("%d", &casos);
    for (int i = 1; i <= casos; i++) {
        No* raiz = NULL;

        scanf("%d", &numElementos);
        for (int j = 0; j < numElementos; j++) {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", i);
        imprimirNivel(raiz);

        if (i != casos) {
            printf("\n\n");
        } else {
            printf("\n");
        }

        liberarArvore(raiz);
    }

    return 0;
}
