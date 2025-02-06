#include <stdio.h>
#include <stdlib.h>

struct no {
    int info;
    struct no* esquerda;
    struct no* direita;
};

int inserir(struct no** raiz, int valor) {
    if (*raiz == NULL) {
        *raiz = (struct no*)malloc(sizeof(struct no));
        if (*raiz == NULL) return 0;
        (*raiz)->info = valor;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
        return 1;
    }

    if (valor < (*raiz)->info) {
        return inserir(&((*raiz)->esquerda), valor);
    } else if (valor > (*raiz)->info) {
        return inserir(&((*raiz)->direita), valor);
    }

    return 1;
}

void emOrdem(struct no* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->info);
        emOrdem(raiz->direita);
    }
}

int main() {
    struct no* raiz = NULL;
    int numNo;

    numNo = inserir(&raiz, 90);
    numNo = inserir(&raiz, 32);
    numNo = inserir(&raiz, 21);
    numNo = inserir(&raiz, 40);
    numNo = inserir(&raiz, 75);
    numNo = inserir(&raiz, 60);
    numNo = inserir(&raiz, 84);

    printf("Valores da arvore em ordem: ");
    emOrdem(raiz);

    return 0;
}
