#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iss.h"

ListaISS* Cria_lista_iss(void) {
    ListaISS* lista = (ListaISS*)malloc(sizeof(ListaISS));
    if (lista != NULL)
        lista->fim = 0;
    return lista;
}

ListaISS* Libera_lista_iss(ListaISS* lista) {
    free(lista);
    return NULL;
}

int Insere_item_iss(ListaISS* lista, Item item) {
    if (lista == NULL || lista->fim == MAX)
        return 0;
    lista->dados[lista->fim] = item;
    lista->fim++;
    return 1;
}

int Remove_item_iss(ListaISS* lista, char* astronauta) {
    if (lista == NULL || lista->fim == 0)
        return 0;

    int i = 0;
    while (i < lista->fim && strcmp(lista->dados[i].astronauta, astronauta) != 0)
        i++;

    if (i == lista->fim)
        return 0;

    lista->dados[i] = lista->dados[lista->fim - 1];
    lista->fim--;
    return 1;
}

int Busca_item_iss(ListaISS* lista, char* astronauta, Item* item) {
    if (lista == NULL || lista->fim == 0)
        return 0;

    for (int i = 0; i < lista->fim; i++) {
        if (strcmp(lista->dados[i].astronauta, astronauta) == 0) {
            *item = lista->dados[i];
            return 1;
        }
    }
    return 0;
}

void Exibir_lista_iss(ListaISS* lista) {
    if (lista == NULL || lista->fim == 0) {
        printf("A lista está vazia.\n");
    } else {
        printf("Lista de Itens:\n");
        for (int i = 0; i < lista->fim; i++) {
            printf("Astronauta: %s, Missão: %s, Módulo: %s\n", lista->dados[i].astronauta, lista->dados[i].missao, lista->dados[i].modulo);
        }
    }
}

int Alterar_item_iss(ListaISS* lista, char* astronauta, Item novo_item) {
    if (lista == NULL || lista->fim == 0)
        return 0;

    for (int i = 0; i < lista->fim; i++) {
        if (strcmp(lista->dados[i].astronauta, astronauta) == 0) {
            lista->dados[i] = novo_item;
            return 1;
        }
    }
    return 0;
}

int Tamanho_lista_iss(ListaISS* lista) {
    if (lista == NULL)
        return -1;
    return lista->fim;
}

int E_cheia_iss(ListaISS* lista) {
    if (lista == NULL)
        return -1;
    return (lista->fim == MAX);
}

int E_vazia_iss(ListaISS* lista) {
    if (lista == NULL)
        return -1;
    return (lista->fim == 0);
}
