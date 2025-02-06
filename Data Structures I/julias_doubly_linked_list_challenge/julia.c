#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "julia.h"

Filme* criarFilme(char* nome, int lotacao) {
    Filme* filme = (Filme*) malloc(sizeof(Filme));
    strcpy(filme->nome, nome);
    filme->lotacao = lotacao;
    for (int i = 0; i < lotacao; i++) {
        filme->assentosDisponiveis[i] = 1;
    }
    filme->proximo = NULL;
    return filme;
}

Ingresso* criarIngresso(char* filme, int assento) {
    Ingresso* ingresso = (Ingresso*) malloc(sizeof(Ingresso));
    strcpy(ingresso->filme, filme);
    ingresso->assento = assento;
    ingresso->proximo = NULL;
    ingresso->anterior = NULL;
    return ingresso;
}

void adicionarFilme(Filme** lista_filmes, Filme* filme) {
    if (*lista_filmes == NULL) {
        *lista_filmes = filme;
    } else {
        Filme* atual = *lista_filmes;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = filme;
    }
}

void adicionarIngressoVendido(ListaIngressos* listaIngressos, Ingresso* ingresso) {
    if (listaIngressos->inicio == NULL) {
        listaIngressos->inicio = ingresso;
        listaIngressos->fim = ingresso;
    } else {
        ingresso->anterior = listaIngressos->fim;
        listaIngressos->fim->proximo = ingresso;
        listaIngressos->fim = ingresso;
    }
}

void removerIngressoVendido(ListaIngressos* listaIngressos, Ingresso* ingresso) {
    if (ingresso == listaIngressos->inicio) {
        listaIngressos->inicio = ingresso->proximo;
        if (listaIngressos->inicio != NULL) {
            listaIngressos->inicio->anterior = NULL;
        } else {
            listaIngressos->fim = NULL;
        }
    } else if (ingresso == listaIngressos->fim) {
        listaIngressos->fim = ingresso->anterior;
        listaIngressos->fim->proximo = NULL;
    } else {
        ingresso->anterior->proximo = ingresso->proximo;
        ingresso->proximo->anterior = ingresso->anterior;
    }
    free(ingresso);
}

void exibirIngressosDisponiveis(Filme* filme) {
    printf("Ingressos disponiveis para o filme %s:\n", filme->nome);
    for (int i = 0; i < filme->lotacao; i++) {
        if (filme->assentosDisponiveis[i] == 1) {
            printf("Assento %d\n", i + 1);
        }
    }
}

void exibirIngressosVendidos(ListaIngressos* listaIngressos) {
    if (listaIngressos->inicio == NULL) {
        printf("Nenhum ingresso foi vendido.\n");
        return;
    }
    printf("Ingressos vendidos em ordem de compra:\n");
    Ingresso* atual = listaIngressos->inicio;
    while (atual != NULL) {
        printf("Filme: %s, Assento: %d\n", atual->filme, atual->assento);
        atual = atual->proximo;
    }
}

void venderIngresso(Filme** lista_filmes, ListaIngressos* listaIngressos, char* filme, int assento) {
    Filme* filmeAtual = *lista_filmes;
    while (filmeAtual != NULL) {
        if (strcmp(filmeAtual->nome, filme) == 0) {
            if (filmeAtual->assentosDisponiveis[assento - 1] == 1) {
                filmeAtual->assentosDisponiveis[assento - 1] = 0;
                Ingresso* ingresso = criarIngresso(filme, assento);
                adicionarIngressoVendido(listaIngressos, ingresso);
                printf("Ingresso vendido com sucesso!\n");
                return;
            } else {
                printf("Assento ja ocupado!\n");
                return;
            }
        }
        filmeAtual = filmeAtual->proximo;
    }
    printf("Filme nao encontrado.\n");
}

void cancelarIngresso(Filme** lista_filmes, ListaIngressos* listaIngressos, char* filme, int assento) {
    Filme* filmeAtual = *lista_filmes;
    while (filmeAtual != NULL) {
        if (strcmp(filmeAtual->nome, filme) == 0) {
            if (filmeAtual->assentosDisponiveis[assento - 1] == 0) {
                filmeAtual->assentosDisponiveis[assento - 1] = 1;
                Ingresso* ingressoAtual = listaIngressos->inicio;
                while (ingressoAtual != NULL) {
                    if (strcmp(ingressoAtual->filme, filme) == 0 && ingressoAtual->assento == assento) {
                        removerIngressoVendido(listaIngressos, ingressoAtual);
                        printf("Ingresso cancelado com sucesso!\n");
                        return;
                    }
                    ingressoAtual = ingressoAtual->proximo;
                }
            } else {
                printf("Esse assento ja está disponivel.\n");
            }
            return;
        }
        filmeAtual = filmeAtual->proximo;
    }
    printf("Filme nao encontrado.\n");
}
