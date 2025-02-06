#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor;
    struct No *esq, *dir;
} No;

No* criarNo(char valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esq = novoNo->dir = NULL;
    return novoNo;
}

No* insercao(No* raiz, char valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    No **aux = (valor < raiz->valor) ? &raiz->esq : &raiz->dir;

    if (*aux == NULL) {
        *aux = criarNo(valor);
    } else {
        insercao(*aux, valor);
    }

    return raiz;
}

int busca(No* raiz, char valor) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->valor == valor) {
        return 1;
    } else if (valor < raiz->valor) {
        return busca(raiz->esq, valor);
    } else {
        return busca(raiz->dir, valor);
    }
}

void infixo(No* raiz, int *primeiro) {
    if (raiz != NULL) {
        infixo(raiz->esq, primeiro);
        if (*primeiro) {
            *primeiro = 0;
        } else {
            printf(" ");
        }
        printf("%c", raiz->valor);
        infixo(raiz->dir, primeiro);
    }
}

void prefixo(No* raiz, int *primeiro) {
    if (raiz != NULL) {
        if (*primeiro) {
            *primeiro = 0;
        } else {
            printf(" ");
        }
        printf("%c", raiz->valor);
        prefixo(raiz->esq, primeiro);
        prefixo(raiz->dir, primeiro);
    }
}

void posfixo(No* raiz, int *primeiro) {
    if (raiz != NULL) {
        posfixo(raiz->esq, primeiro);
        posfixo(raiz->dir, primeiro);
        if (*primeiro) {
            *primeiro = 0;
        } else {
            printf(" ");
        }
        printf("%c", raiz->valor);
    }
}

int main() {
    No* raiz = NULL;
    char comando[10];
    char elemento;

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &elemento);
            raiz = insercao(raiz, elemento);
        } else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &elemento);
            if (busca(raiz, elemento)) {
                printf("%c existe\n", elemento);
            } else {
                printf("%c nao existe\n", elemento);
            }
        } else if (strcmp(comando, "INFIXA") == 0) {
            int primeiro = 1;
            infixo(raiz, &primeiro);
            printf("\n");
        } else if (strcmp(comando, "PREFIXA") == 0) {
            int primeiro = 1;
            prefixo(raiz, &primeiro);
            printf("\n");
        } else if (strcmp(comando, "POSFIXA") == 0) {
            int primeiro = 1;
            posfixo(raiz, &primeiro);
            printf("\n");
        }
    }
    
    return 0;
}
