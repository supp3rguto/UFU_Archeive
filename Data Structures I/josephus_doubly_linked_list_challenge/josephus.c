#include <stdio.h>
#include <stdlib.h>
#include "josephus.h"

struct no {
    int info;
    struct no* prox;
    struct no* ant;
};

Lista* Cria_lista(void) {
    return NULL;
}

Lista* Libera_lista(Lista* Ptl) {
    if (Ptl == NULL) return NULL;

    Lista *pt = Ptl->prox;
    while (pt != Ptl) {
        Lista *aux = pt;
        pt = pt->prox;
        free(aux);
    }
    free(pt);
    return NULL;
}

int E_vazia(Lista* Ptl) {
    return (Ptl == NULL);
}

Lista* Insere_elem(Lista* Ptl, int elem) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if (novo == NULL) return Ptl;

    novo->info = elem;
    if (Ptl == NULL) {
        novo->prox = novo;
        novo->ant = novo;
        return novo;
    }

    novo->prox = Ptl->prox;
    novo->ant = Ptl;
    Ptl->prox->ant = novo;
    Ptl->prox = novo;
    return novo;
}

Lista* Remove_elem(Lista* Ptl, int elem) {
    if (Ptl == NULL) return Ptl;

    Lista* atual = Ptl->prox;
    while (atual != Ptl && atual->info != elem) {
        atual = atual->prox;
    }

    if (atual->info == elem) {
        if (atual == Ptl && atual->prox == Ptl) {
            free(atual);
            return NULL;
        }

        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;
        if (atual == Ptl) Ptl = atual->ant;
        free(atual);
    }
    return Ptl;
}

int Tamanho_lista(Lista* Ptl) {
    if (Ptl == NULL) return 0;

    int tamanho = 1;
    Lista* pt = Ptl->prox;
    while (pt != Ptl) {
        tamanho++;
        pt = pt->prox;
    }
    return tamanho;
}

int Consulta_nodo(Lista* Ptl, int pos, int *elem) {
    if (Ptl == NULL || pos <= 0) return 0;

    Lista* pt = Ptl->prox;
    int cont = 1;
    while (pt != Ptl && cont < pos) {
        pt = pt->prox;
        cont++;
    }
    if (cont == pos) {
        *elem = pt->info;
        return 1;
    }
    return 0;
}
