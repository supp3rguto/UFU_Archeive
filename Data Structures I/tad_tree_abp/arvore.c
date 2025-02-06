#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int inserir(struct no** raiz, int valor) {
    if (*raiz == NULL) {
        *raiz = criarNo(valor);
        return 1;
    }

    if (valor < (*raiz)->info) {
        return inserir(&((*raiz)->esquerda), valor);
    } else if (valor > (*raiz)->info) {
        return inserir(&((*raiz)->direita), valor);
    }

    return 1; // valor já existe na árvore
}

void remover(struct no** raiz, int valor) {
    if (*raiz == NULL) {
        return;
    }

    if (valor < (*raiz)->info) {
        remover(&((*raiz)->esquerda), valor);
    } else if (valor > (*raiz)->info) {
        remover(&((*raiz)->direita), valor);
    } else {
        struct no* temp;
        
        if ((*raiz)->esquerda == NULL && (*raiz)->direita == NULL) { // nó folha
            free(*raiz);
            *raiz = NULL;
        } else if ((*raiz)->esquerda == NULL) { // um filho à direita
            temp = *raiz;
            *raiz = (*raiz)->direita;
            free(temp);
        } else if ((*raiz)->direita == NULL) { // um filho à esquerda
            temp = *raiz;
            *raiz = (*raiz)->esquerda;
            free(temp);
        } else { // nó com dois filhos
            struct no* aux = (*raiz)->direita;
            struct no* paiMenor = *raiz;

            while (aux->esquerda != NULL) {
                paiMenor = aux;
                aux = aux->esquerda;
            }

            (*raiz)->info = aux->info;
            if (paiMenor != *raiz) {
                paiMenor->esquerda = aux->direita;
            } else {
                (*raiz)->direita = aux->direita;
            }
            free(aux);
        }
    }
}

int contarNos(struct no* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

int contarNosNaoFolha(struct no* raiz) {
    if (raiz == NULL || (raiz->esquerda == NULL && raiz->direita == NULL)) return 0;
    return 1 + contarNosNaoFolha(raiz->esquerda) + contarNosNaoFolha(raiz->direita);
}

int contarNosFolha(struct no* raiz) {
    if (raiz == NULL) return 0;
    if (raiz->esquerda == NULL && raiz->direita == NULL) return 1;
    return contarNosFolha(raiz->esquerda) + contarNosFolha(raiz->direita);
}

int calcularAltura(struct no* raiz) {
    if (raiz == NULL) return -1;
    int alturaEsquerda = calcularAltura(raiz->esquerda);
    int alturaDireita = calcularAltura(raiz->direita);
    return (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1;
}

int acharMaior(struct no* raiz) {
    if (raiz == NULL) return -1;
    while (raiz->direita != NULL) {
        raiz = raiz->direita;
    }
    return raiz->info;
}

void espelharArvore(struct no* raiz) {
    if (raiz == NULL) return;
    struct no* temp = raiz->esquerda;
    raiz->esquerda = raiz->direita;
    raiz->direita = temp;
    espelharArvore(raiz->esquerda);
    espelharArvore(raiz->direita);
}

void imprimirEmOrdem(struct no* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->info);
        imprimirEmOrdem(raiz->direita);
    }
}