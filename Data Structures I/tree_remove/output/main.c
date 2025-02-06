#include <stdio.h>
#include <stdlib.h>

struct no {
    int info;
    struct no* esq;
    struct no* dir;
};

typedef struct no Arvore;

void inserir(Arvore** a, int elem) {
    Arvore* n = (Arvore*) malloc(sizeof(Arvore));
    n->info = elem;
    n->dir = NULL;
    n->esq = NULL;

    if (*a == NULL) {
        *a = n;
    } else {
        Arvore* aux = *a;

        while (aux != NULL) {
            if (elem < aux->info) {
                if (aux->esq == NULL) {
                    aux->esq = n;
                    return;
                }
                aux = aux->esq;
            } else {
                if (aux->dir == NULL) {
                    aux->dir = n;
                    return;
                }
                aux = aux->dir;
            }
        }
    }
}



Arvore* remover(Arvore* raiz, int elem) {
    if (raiz == NULL) {
        return raiz;
    }

    if (elem < raiz->info) {
        raiz->esq = remover(raiz->esq, elem);
    } else if (elem > raiz->info) {
        raiz->dir = remover(raiz->dir, elem);
    } else {
        // caso de nó folha (sem filhos)
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            return NULL;
        }

        // caso de nó com um filho
        if (raiz->esq == NULL) {
            Arvore* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            Arvore* temp = raiz->esq;
            free(raiz);
            return temp;
        }

        // caso nó com dois filhos
        Arvore* aux = raiz->dir;

        if (aux->esq == NULL) {
            raiz->info = aux->info;
            raiz->dir = aux->dir;
            free(aux);
        } else {
            Arvore* paiMenor = aux;
            while (aux->esq != NULL) {
                paiMenor = aux;
                aux = aux->esq;
            }
            raiz->info = aux->info;
            paiMenor->esq = aux->dir;
            free(aux);
        }
    }

    return raiz;

}

void imprimirArvore(Arvore* raiz) {
    if (raiz != NULL) {
        imprimirArvore(raiz->esq);
        printf("%d ", raiz->info);
        imprimirArvore(raiz->dir);
    }
}

int main() {
    Arvore* raiz = NULL;

    inserir(&raiz, 50);
    inserir(&raiz, 30);
    inserir(&raiz, 70);
    inserir(&raiz, 20);
    inserir(&raiz, 40);
    inserir(&raiz, 60);
    inserir(&raiz, 80);

    printf("arvore em ordem antes da remocao: ");
    imprimirArvore(raiz);
    printf("\n");

    raiz = remover(raiz, 20);
    printf("arvore em ordem apos remover 20: ");
    imprimirArvore(raiz);
    printf("\n");

    raiz = remover(raiz, 30);
    printf("arvore em ordem apos remover 30: ");
    imprimirArvore(raiz);
    printf("\n");

    raiz = remover(raiz, 50);
    printf("arvore em ordem apos remover 50: ");
    imprimirArvore(raiz);
    printf("\n");

    return 0;
}
