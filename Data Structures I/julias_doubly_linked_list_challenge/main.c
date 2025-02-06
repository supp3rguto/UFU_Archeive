#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "julia.c"

int main() {
    Filme* listaFilmes = NULL;
    ListaIngressos listaIngressos;
    listaIngressos.inicio = NULL;
    listaIngressos.fim = NULL;

    Filme* filme1 = criarFilme("Filme 1", 10);
    Filme* filme2 = criarFilme("Filme 2", 10);
    adicionarFilme(&listaFilmes, filme1);
    adicionarFilme(&listaFilmes, filme2);

    int opcao;
    while (1) {
        printf("\nMENU:\n");
        printf("1. Vender ingresso\n");
        printf("2. Cancelar ingresso\n");
        printf("3. Listar ingressos disponiveis\n");
        printf("4. Exibir ingressos vendidos\n");
        printf("5. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int filmeEscolha, assento;
                printf("Escolha um filme:\n1. Filme 1\n2. Filme 2\n");
                scanf("%d", &filmeEscolha);

                char* filme;
                if (filmeEscolha == 1) {
                    filme = "Filme 1";
                } else if (filmeEscolha == 2) {
                    filme = "Filme 2";
                } else {
                    printf("Escolha invalida.\n");
                    break;
                }

                printf("Insira o numero do assento (1 a 10):\n");
                scanf("%d", &assento);
                venderIngresso(&listaFilmes, &listaIngressos, filme, assento);
                break;
            }
            case 2: {
                int filmeEscolha, assento;
                printf("Escolha um filme para cancelar o ingresso:\n1. Filme 1\n2. Filme 2\n");
                scanf("%d", &filmeEscolha);

                char* filme;
                if (filmeEscolha == 1) {
                    filme = "Filme 1";
                } else if (filmeEscolha == 2) {
                    filme = "Filme 2";
                } else {
                    printf("Escolha invalida.\n");
                    break;
                }

                printf("Insira o numero do assento (1 a 10):\n");
                scanf("%d", &assento);
                cancelarIngresso(&listaFilmes, &listaIngressos, filme, assento);
                break;
            }
            case 3: {
                int filmeEscolha;
                printf("Escolha um filme para ver os ingressos disponiveis:\n1. Filme 1\n2. Filme 2\n");
                scanf("%d", &filmeEscolha);

                if (filmeEscolha == 1) {
                    exibirIngressosDisponiveis(filme1);
                } else if (filmeEscolha == 2) {
                    exibirIngressosDisponiveis(filme2);
                } else {
                    printf("Escolha invalida.\n");
                }
                break;
            }
            case 4:
                exibirIngressosVendidos(&listaIngressos);
                break;
            case 5:
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opcao invalida.\n");
        }
    }
    return 0;
}
