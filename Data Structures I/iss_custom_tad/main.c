#include <stdio.h>
#include "iss.h"

int main() {
    EstacaoEspacial estacao;
    inicializaEstacao(&estacao);

    int opcao;
    do {
        printf("\n--- Menu Estação Espacial ---\n");
        printf("1. Adicionar Astronauta\n");
        printf("2. Listar Astronautas\n");
        printf("3. Adicionar Missão\n");
        printf("4. Listar Missões\n");
        printf("5. Adicionar Módulo\n");
        printf("6. Listar Módulos\n");
        printf("7. Listar Estação Completa\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        char nome[50], nacionalidade[30], objetivo[100], tipo[50];
        int idade, duracao, capacidade;

        switch(opcao) {
            case 1:
                printf("Nome do astronauta: ");
                scanf("%s", nome);
                printf("Idade: ");
                scanf("%d", &idade);
                printf("Nacionalidade: ");
                scanf("%s", nacionalidade);
                adicionarAstronauta(&estacao, nome, idade, nacionalidade);
                break;
            case 2:
                listarAstronautas(&estacao);
                break;
            case 3:
                printf("Nome da missão: ");
                scanf("%s", nome);
                printf("Objetivo: ");
                scanf("%s", objetivo);
                printf("Duração (em dias): ");
                scanf("%d", &duracao);
                adicionarMissao(&estacao, nome, objetivo, duracao);
                break;
            case 4:
                listarMissoes(&estacao);
                break;
            case 5:
                printf("Nome do módulo: ");
                scanf("%s", nome);
                printf("Tipo: ");
                scanf("%s", tipo);
                printf("Capacidade: ");
                scanf("%d", &capacidade);
                adicionarModulo(&estacao, nome, tipo, capacidade);
                break;
            case 6:
                listarModulos(&estacao);
                break;
            case 7:
                listarEstacao(&estacao);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}
