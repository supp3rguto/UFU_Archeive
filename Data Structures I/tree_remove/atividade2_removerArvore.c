Arvore* remover(Arvore* raiz, int elem) {
    if (raiz == NULL) {
        return raiz;
    }

    if (elem < raiz->info) {
        raiz->esq = remover(raiz->esq, elem);
    } else if (elem > raiz->info) {
        raiz->dir = remover(raiz->dir, elem);
    } else {
        // caso nó folha (sem filhos)
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            return NULL;
        }

        // caso nó com um filho
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