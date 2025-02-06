#include <stdio.h>
#include <stdlib.h>
#include "iss.c"

void Menu() {
    printf("\nHUB - ISS MISSIONS\n");
    printf("1 - Cadastrar\n");
    printf("2 - Remover\n");
    printf("3 - Buscar=\n");
    printf("4 - Alterar\n");
    printf("5 - Exibir\n");
    printf("6 - Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    ListaISS* lista = Cria_lista_iss();
    int opcao;
    Item item;
    char astronauta[50];

    do {
        Menu();
        scanf("%d", &opcao);
        getchar(); 

        switch(opcao) {
            case 1:
                printf("Digite o nome do astronauta: ");
                fgets(item.astronauta, 50, stdin);
                item.astronauta[strcspn(item.astronauta, "\n")] = '\0';
                printf("Digite o nome da missão: ");
                fgets(item.missao, 50, stdin);
                item.missao[strcspn(item.missao, "\n")] = '\0';
                printf("Digite o nome do módulo: ");
                fgets(item.modulo, 50, stdin);
                item.modulo[strcspn(item.modulo, "\n")] = '\0';

                if (Insere_item_iss(lista, item)) {
                    printf("Item inserido com sucesso!\n");
                } else {
                    printf("Erro ao inserir item!\n");
                }
                break;

            case 2:
                printf("Digite o nome do astronauta a ser removido: ");
                fgets(astronauta, 50, stdin);
                astronauta[strcspn(astronauta, "\n")] = '\0';

                if (Remove_item_iss(lista, astronauta)) {
                    printf("Item removido com sucesso!\n");
                } else {
                    printf("Erro ao remover item!\n");
                }
                break;

            case 3:
                printf("Digite o nome do astronauta a ser buscado: ");
                fgets(astronauta, 50, stdin);
                astronauta[strcspn(astronauta, "\n")] = '\0';

                if (Busca_item_iss(lista, astronauta, &item)) {
                    printf("Item encontrado:\nAstronauta: %s\nMissão: %s\nMódulo: %s\n", item.astronauta, item.missao, item.modulo);
                } else {
                    printf("Item não encontrado!\n");
                }
                break;

            case 4:
                printf("Digite o nome do astronauta a ser alterado: ");
                fgets(astronauta, 50, stdin);
                astronauta[strcspn(astronauta, "\n")] = '\0';

                printf("Digite o novo nome do astronauta: ");
                fgets(item.astronauta, 50, stdin);
                item.astronauta[strcspn(item.astronauta, "\n")] = '\0';
                printf("Digite o novo nome da missão: ");
                fgets(item.missao, 50, stdin);
                item.missao[strcspn(item.missao, "\n")] = '\0';
                printf("Digite o novo nome do módulo: ");
                fgets(item.modulo, 50, stdin);
                item.modulo[strcspn(item.modulo, "\n")] = '\0';

                if (Alterar_item_iss(lista, astronauta, item)) {
                    printf("Item alterado com sucesso!\n");
                } else {
                    printf("Erro ao alterar item!\n");
                }
                break;

            case 5:
                Exibir_lista_iss(lista);
                break;

            case 6:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }
    } while(opcao != 6);

    lista = Libera_lista_iss(lista);
    return 0;
}
