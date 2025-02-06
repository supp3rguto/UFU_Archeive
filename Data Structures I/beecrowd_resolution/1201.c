#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int valor;
    struct No *esq, *dir;
} No;

No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->esq = novoNo->dir = NULL;
    return novoNo;
}

No* insercao(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    
    if (valor < raiz->valor) {
        raiz->esq = insercao(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = insercao(raiz->dir, valor);
    }

    return raiz;
}

//nota: função para encontrar o maior valor do lado esquerdo (antecessor/pai no caso)
No* acharMax(No* raiz) {
    while (raiz->dir != NULL) {
        raiz = raiz->dir;
    }
    return raiz;
}

No* removerNo(No* raiz, int valor) {
    if (raiz == NULL) return raiz;

    if (valor < raiz->valor) {
        raiz->esq = removerNo(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = removerNo(raiz->dir, valor);
    } else {  //encontrou o nó a ser removido
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);  //nó folha
            return NULL;
        } else if (raiz->esq == NULL || raiz->dir == NULL) {
            No* temp = raiz->esq ? raiz->esq : raiz->dir;
            free(raiz);  //um filho
            return temp;
        } else {
            //dois filhos, pega o maior da subárvore à esquerda
            No* maxEsq = acharMax(raiz->esq);
            raiz->valor = maxEsq->valor;
            raiz->esq = removerNo(raiz->esq, maxEsq->valor);
        }
    }

    return raiz;
}

int buscar(No* raiz, int valor) {
    No* atual = raiz;
    while (atual != NULL) {
        if (valor == atual->valor) return 1;
        atual = (valor < atual->valor) ? atual->esq : atual->dir;
    }
    return 0;
}

void infixo(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        infixo(raiz->esq, primeiro);
        if (*primeiro) {
            *primeiro = 0;
        } else {
            printf(" ");
        }
        printf("%d", raiz->valor);
        infixo(raiz->dir, primeiro);
    }
}


void prefixo(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        if (*primeiro) {
            *primeiro = 0;
        } else {
            printf(" ");
        }
        printf("%d", raiz->valor);
        prefixo(raiz->esq, primeiro);
        prefixo(raiz->dir, primeiro);
    }
}


void posfixo(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        posfixo(raiz->esq, primeiro);
        posfixo(raiz->dir, primeiro);
        if (*primeiro) {
            *primeiro = 0;
        } else {
            printf(" ");
        }
        printf("%d", raiz->valor);
    }
}

int main() {
    No* raiz = NULL;
    char comando[10];
    int elemento;
    
    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "I") == 0) {
            scanf("%d", &elemento);
            raiz = insercao(raiz, elemento);
        } else if (strcmp(comando, "P") == 0) {
            scanf("%d", &elemento);
            if (buscar(raiz, elemento)) {
                printf("%d existe\n", elemento);
            } else {
                printf("%d nao existe\n", elemento);
            }
        } else if (strcmp(comando, "R") == 0) {
            scanf("%d", &elemento);
            raiz = removerNo(raiz, elemento);
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
