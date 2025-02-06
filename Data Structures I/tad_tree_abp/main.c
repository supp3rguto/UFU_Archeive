#include <stdio.h>
#include <stdlib.h>
#include "arvore.c"

int main() {
    struct no* raiz = NULL;
    int opcao, valor;

    do {
        printf("\n---- MENU ----\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Imprimir arvore em ordem\n");
        printf("4. Contar numero de nos\n");
        printf("5. Contar numero de nos folha\n");
        printf("6. Contar numero de nos nao-folha\n");
        printf("7. Calcular altura da arvore\n");
        printf("8. Encontrar o maior valor da arvore\n");
        printf("9. Espelhar arvore\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserir(&raiz, valor);
                break;

            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                remover(&raiz, valor);
                break;

            case 3:
                printf("Arvore em ordem: ");
                imprimirEmOrdem(raiz);
                printf("\n");
                break;

            case 4:
                printf("Numero de nos: %d\n", contarNos(raiz));
                break;

            case 5:
                printf("Numero de nos folha: %d\n", contarNosFolha(raiz));
                break;

            case 6:
                printf("Numero de nos nao-folha: %d\n", contarNosNaoFolha(raiz));
                break;

            case 7:
                printf("Altura da arvore: %d\n", calcularAltura(raiz));
                break;

            case 8:
                printf("Maior valor da arvore: %d\n", acharMaior(raiz));
                break;

            case 9:
                espelharArvore(raiz);
                printf("Arvore espelhada com sucesso!\n");
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}