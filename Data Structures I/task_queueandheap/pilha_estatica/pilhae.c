#include <stdio.h>
#include <time.h>
#include "pilhae.h"

void inicializaPilha(PilhaEstoqueComponentes* pilha) {
    pilha->topo = -1;
}

void insereComponente(PilhaEstoqueComponentes* pilha, int numero_serie) {
    if (pilha->topo == MAX - 1) {
        printf("Estoque de componentes cheio!\n");
        return;
    }
    pilha->componentes[++(pilha->topo)] = numero_serie;
}

int removeComponente(PilhaEstoqueComponentes* pilha) {
    if (pilha->topo == -1) {
        printf("Nenhum componente no estoque!\n");
        return -1;
    }
    return pilha->componentes[(pilha->topo)--];
}

void imprimeEstoqueComponentes(PilhaEstoqueComponentes* pilha) {
    for (int i = pilha->topo; i >= 0; i--) {
        printf(" %d ", pilha->componentes[i]);
    }
    printf("\n");
}