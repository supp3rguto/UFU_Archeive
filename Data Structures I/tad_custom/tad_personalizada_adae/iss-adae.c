#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iss-adae.h"

ListaISS* Cria_lista_iss(void) {
    ListaISS* lista = (ListaISS*)malloc(sizeof(ListaISS));
    if (lista != NULL)
        lista->inicio = NULL;
    return lista;
}

ListaISS* Libera_lista_iss(ListaISS* lista) {
    No* atual = lista->inicio;
    No* aux;
    while (atual != NULL) {
        aux = atual;
        atual = atual->prox;
        free(aux);
    }
    free(lista);
    return NULL;
}

int Insere_item_iss(ListaISS** lista, Item item) {
    if (lista == NULL || Verifica_duplicata_iss(*lista, item.astronauta)) {
        return 0;
    }

    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        return 0;
    }
    novo->dado = item;
    novo->prox = (*lista)->inicio;
    (*lista)->inicio = novo;
    return 1;
}

int Remove_item_iss(ListaISS** lista, char* astronauta) {
    if (lista == NULL || *lista == NULL || (*lista)->inicio == NULL) {
        return 0;
    }

    No *atual = (*lista)->inicio, *anterior = NULL;

    while (atual != NULL && strcmp(atual->dado.astronauta, astronauta) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        return 0;
    }

    if (anterior == NULL) {
        (*lista)->inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    return 1;
}

int Busca_item_iss(ListaISS* lista, char* astronauta, Item* item) {
    if (lista == NULL || lista->inicio == NULL) {
        return 0;
    }

    No* atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->dado.astronauta, astronauta) == 0) {
            *item = atual->dado;
            return 1;
        }
        atual = atual->prox;
    }

    return 0;
}

void Exibir_lista_iss(ListaISS* lista) {
    if (lista == NULL || lista->inicio == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }

    No* atual = lista->inicio;
    printf("Lista de Itens:\n");
    while (atual != NULL) {
        printf("Astronauta: %s, Missao: %s, Modulo: %s\n", atual->dado.astronauta, atual->dado.missao, atual->dado.modulo);
        atual = atual->prox;
    }
}

int Alterar_item_iss(ListaISS* lista, char* astronauta, Item novo_item) {
    if (lista == NULL || lista->inicio == NULL) {
        return 0;
    }

    No* atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->dado.astronauta, astronauta) == 0) {
            atual->dado = novo_item;
            return 1;
        }
        atual = atual->prox;
    }

    return 0;
}

int Tamanho_lista_iss(ListaISS* lista) {
    if (lista == NULL) {
        return -1;
    }

    int cont = 0;
    No* atual = lista->inicio;
    while (atual != NULL) {
        cont++;
        atual = atual->prox;
    }

    return cont;
}

int E_cheia_iss(ListaISS* lista) {
    return 0;
}

int E_vazia_iss(ListaISS* lista) {
    return (lista == NULL || lista->inicio == NULL);
}

int Verifica_duplicata_iss(ListaISS* lista, char* astronauta) {
    if (lista == NULL || lista->inicio == NULL) {
        return 0;
    }

    No* atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->dado.astronauta, astronauta) == 0) {
            return 1;
        }
        atual = atual->prox;
    }

    return 0;
}

void Salva_lista_iss_em_arquivo(ListaISS* lista, const char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    No* atual = lista->inicio;
    while (atual != NULL) {
        fprintf(arquivo, "%s\n%s\n%s\n", atual->dado.astronauta, atual->dado.missao, atual->dado.modulo);
        atual = atual->prox;
    }

    fclose(arquivo);
    printf("Lista salva no arquivo %s\n", nome_arquivo);
}

ListaISS* Mesclar_listas_iss(ListaISS* lista1, ListaISS* lista2) {
    ListaISS* listaMesclada = Cria_lista_iss();
    if (lista1 == NULL || lista2 == NULL || listaMesclada == NULL) {
        return NULL;
    }

    No* atual1 = lista1->inicio;
    No* atual2 = lista2->inicio;

    while (atual1 != NULL) {
        Insere_item_iss(&listaMesclada, atual1->dado);
        atual1 = atual1->prox;
    }

    while (atual2 != NULL) {
        if (!Verifica_duplicata_iss(listaMesclada, atual2->dado.astronauta)) {
            Insere_item_iss(&listaMesclada, atual2->dado);
        }
        atual2 = atual2->prox;
    }

    return listaMesclada;
}

int Comparar_items(Item a, Item b) {
    return strcmp(a.astronauta, b.astronauta);
}

void Ordenar_lista_iss(ListaISS* lista) {
    if (lista == NULL || lista->inicio == NULL) return;

    int trocou;
    No* i;
    No* j = NULL;
    do {
        trocou = 0;
        i = lista->inicio;

        while (i->prox != j) {
            if (Comparar_items(i->dado, i->prox->dado) > 0) {
                Item temp = i->dado;
                i->dado = i->prox->dado;
                i->prox->dado = temp;
                trocou = 1;
            }
            i = i->prox;
        }
        j = i;
    } while (trocou);
}
