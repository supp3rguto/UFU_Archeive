#include "iss.h"
#include <stdio.h>
#include <string.h>

void inicializaEstacao(EstacaoEspacial *estacao) {
    estacao->num_astronautas = 0;
    estacao->num_missoes = 0;
    estacao->num_modulos = 0;
}

void adicionarAstronauta(EstacaoEspacial *estacao, char nome[], int idade, char nacionalidade[]) {
    if (estacao->num_astronautas < MAX_ASTRONAUTAS) {
        Astronauta novo_astronauta;
        strcpy(novo_astronauta.nome, nome);
        novo_astronauta.idade = idade;
        strcpy(novo_astronauta.nacionalidade, nacionalidade);

        estacao->astronautas[estacao->num_astronautas++] = novo_astronauta;
    } else {
        printf("Limite de astronautas atingido.\n");
    }
}

void listarAstronautas(EstacaoEspacial *estacao) {
    printf("\n--- Lista de Astronautas ---\n");
    for (int i = 0; i < estacao->num_astronautas; i++) {
        printf("Nome: %s, Idade: %d, Nacionalidade: %s\n", estacao->astronautas[i].nome, estacao->astronautas[i].idade, estacao->astronautas[i].nacionalidade);
    }
}

void adicionarMissao(EstacaoEspacial *estacao, char nome[], char objetivo[], int duracao) {
    if (estacao->num_missoes < MAX_MISSOES) {
        Missao nova_missao;
        strcpy(nova_missao.nome, nome);
        strcpy(nova_missao.objetivo, objetivo);
        nova_missao.duracao = duracao;

        estacao->missoes[estacao->num_missoes++] = nova_missao;
    } else {
        printf("Limite de missões atingido.\n");
    }
}

void listarMissoes(EstacaoEspacial *estacao) {
    printf("\n--- Lista de Missões ---\n");
    for (int i = 0; i < estacao->num_missoes; i++) {
        printf("Nome: %s, Objetivo: %s, Duração: %d dias\n", estacao->missoes[i].nome, estacao->missoes[i].objetivo, estacao->missoes[i].duracao);
    }
}

void adicionarModulo(EstacaoEspacial *estacao, char nome[], char tipo[], int capacidade) {
    if (estacao->num_modulos < MAX_MODULOS) {
        Modulo novo_modulo;
        strcpy(novo_modulo.nome, nome);
        strcpy(novo_modulo.tipo, tipo);
        novo_modulo.capacidade = capacidade;

        estacao->modulos[estacao->num_modulos++] = novo_modulo;
    } else {
        printf("Limite de módulos atingido.\n");
    }
}

void listarModulos(EstacaoEspacial *estacao) {
    printf("\n--- Lista de Módulos ---\n");
    for (int i = 0; i < estacao->num_modulos; i++) {
        printf("Nome: %s, Tipo: %s, Capacidade: %d pessoas\n", estacao->modulos[i].nome, estacao->modulos[i].tipo, estacao->modulos[i].capacidade);
    }
}

void listarEstacao(EstacaoEspacial *estacao) {
    printf("\n--- Estação Espacial ---\n");

    printf("\n--- Astronautas ---\n");
    if (estacao->num_astronautas > 0) {
        for (int i = 0; i < estacao->num_astronautas; i++) {
            printf("Nome: %s, Idade: %d, Nacionalidade: %s\n", 
                estacao->astronautas[i].nome, 
                estacao->astronautas[i].idade, 
                estacao->astronautas[i].nacionalidade);
        }
    } else {
        printf("Nenhum astronauta na estação.\n");
    }

    printf("\n--- Missões ---\n");
    if (estacao->num_missoes > 0) {
        for (int i = 0; i < estacao->num_missoes; i++) {
            printf("Nome: %s, Objetivo: %s, Duração: %d dias\n", 
                estacao->missoes[i].nome, 
                estacao->missoes[i].objetivo, 
                estacao->missoes[i].duracao);
        }
    } else {
        printf("Nenhuma missão na estação.\n");
    }

    printf("\n--- Módulos ---\n");
    if (estacao->num_modulos > 0) {
        for (int i = 0; i < estacao->num_modulos; i++) {
            printf("Nome: %s, Tipo: %s, Capacidade: %d pessoas\n", 
                estacao->modulos[i].nome, 
                estacao->modulos[i].tipo, 
                estacao->modulos[i].capacidade);
        }
    } else {
        printf("Nenhum módulo na estação.\n");
    }
}
