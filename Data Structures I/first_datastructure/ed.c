#include <stdio.h>
#include <stdlib.h>
#include "ed.h"

#define MAX 100

void Insere(int valor, int par[], int *par_tamanho, int impar[], int *impar_tamanho) {
    if(valor % 2 == 0) {
        par[*par_tamanho] = valor;
        (*par_tamanho)++;
    } else {
        impar[*impar_tamanho] = valor;
        (*impar_tamanho)++;
    }
}

void Remove(int valor, int vetor[], int *tamanho) {
    int i, encontrado = 0;

    for(i = 0; i < *tamanho; i++) {
        if(vetor[i] == valor) {
            encontrado = 1;
            break;
        }
    }

    if(encontrado) {
        for(; i < *tamanho - 1; i++) {
            vetor[i] = vetor[i + 1];
        }
        (*tamanho)--;
        printf("Elemento removido com sucesso.\n");
    } else {
        printf("Elemento nao encontrado.\n");
    }
}

int Consulta(int vetor[], int tamanho, int posicao) {
    if(posicao < 0 || posicao >= tamanho) {
        printf("Posicao invalida!\n");
        return -1;
    }
    return vetor[posicao];
}

void Exiba(int vetor[], int tamanho) {
    if(tamanho == 0) {
        printf("Vetor vazio.\n");
        return;
    }

    for(int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void Grave(char nome_arquivo[], int vetor[], int tamanho) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for(int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", vetor[i]);
    }

    fclose(arquivo);
    printf("Vetor gravado com sucesso em %s\n", nome_arquivo);
}
