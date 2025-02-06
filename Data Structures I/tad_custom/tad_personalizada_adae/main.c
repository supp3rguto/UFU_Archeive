#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iss-adae.c"

void Menu() {
    printf("\nHUB - ISS MISSIONS\n");
    printf("1 - Cadastrar\n");
    printf("2 - Remover\n");
    printf("3 - Buscar\n");
    printf("4 - Alterar\n");
    printf("5 - Exibir\n");
    printf("6 - Salvar em arquivo\n");
    printf("7 - Mesclar listas\n");
    printf("8 - Ordenar\n");
    printf("9 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    ListaISS* lista1 = Cria_lista_iss();
    ListaISS* lista2 = Cria_lista_iss();
    int opcao, listaEscolhida;
    Item item;
    char astronauta[50];

    do {
        Menu();
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("Escolha a lista para inserir (1 ou 2): ");
                scanf("%d", &listaEscolhida);
                getchar();
                if (listaEscolhida != 1 && listaEscolhida != 2) {
                    printf("Opcao invalida!\n");
                    break;
                }

                printf("Digite o nome do astronauta: ");
                fgets(item.astronauta, sizeof(item.astronauta), stdin);
                item.astronauta[strcspn(item.astronauta, "\n")] = '\0';

                if (Verifica_duplicata_iss(listaEscolhida == 1 ? lista1 : lista2, item.astronauta)) {
                    printf("Astronauta ja existente na lista.\n");
                    break;
                }

                printf("Digite a missao: ");
                fgets(item.missao, sizeof(item.missao), stdin);
                item.missao[strcspn(item.missao, "\n")] = '\0';

                printf("Digite o modulo: ");
                fgets(item.modulo, sizeof(item.modulo), stdin);
                item.modulo[strcspn(item.modulo, "\n")] = '\0';

                if (Insere_item_iss(listaEscolhida == 1 ? &lista1 : &lista2, item)) {
                    printf("Item inserido com sucesso.\n");
                } else {
                    printf("Erro ao inserir o item.\n");
                }
                break;

            case 2:
                printf("Escolha a lista para remover (1 ou 2): ");
                scanf("%d", &listaEscolhida);
                getchar();
                if (listaEscolhida != 1 && listaEscolhida != 2) {
                    printf("Opcao invalida!\n");
                    break;
                }

                printf("Digite o nome do astronauta a ser removido: ");
                fgets(astronauta, sizeof(astronauta), stdin);
                astronauta[strcspn(astronauta, "\n")] = '\0';

                if (Remove_item_iss(listaEscolhida == 1 ? &lista1 : &lista2, astronauta)) {
                    printf("Item removido com sucesso.\n");
                } else {
                    printf("Erro ao remover o item ou item nao encontrado.\n");
                }
                break;

            case 3:
                printf("Escolha a lista para buscar (1 ou 2): ");
                scanf("%d", &listaEscolhida);
                getchar();
                if (listaEscolhida != 1 && listaEscolhida != 2) {
                    printf("Opcao invalida!\n");
                    break;
                }

                printf("Digite o nome do astronauta a ser buscado: ");
                fgets(astronauta, sizeof(astronauta), stdin);
                astronauta[strcspn(astronauta, "\n")] = '\0';

                if (Busca_item_iss(listaEscolhida == 1 ? lista1 : lista2, astronauta, &item)) {
                    printf("Astronauta: %s, Missao: %s, Modulo: %s\n", item.astronauta, item.missao, item.modulo);
                } else {
                    printf("Item nao encontrado.\n");
                }
                break;

            case 4:
                printf("Escolha a lista para alterar (1 ou 2): ");
                scanf("%d", &listaEscolhida);
                getchar();
                if (listaEscolhida != 1 && listaEscolhida != 2) {
                    printf("Opcao invalida!\n");
                    break;
                }

                printf("Digite o nome do astronauta a ser alterado: ");
                fgets(astronauta, sizeof(astronauta), stdin);
                astronauta[strcspn(astronauta, "\n")] = '\0';

                printf("Digite o novo nome do astronauta: ");
                fgets(item.astronauta, sizeof(item.astronauta), stdin);
                item.astronauta[strcspn(item.astronauta, "\n")] = '\0';

                printf("Digite a nova missao: ");
                fgets(item.missao, sizeof(item.missao), stdin);
                item.missao[strcspn(item.missao, "\n")] = '\0';

                printf("Digite o novo modulo: ");
                fgets(item.modulo, sizeof(item.modulo), stdin);
                item.modulo[strcspn(item.modulo, "\n")] = '\0';

                if (Alterar_item_iss(listaEscolhida == 1 ? lista1 : lista2, astronauta, item)) {
                    printf("Item alterado com sucesso.\n");
                } else {
                    printf("Erro ao alterar o item.\n");
                }
                break;

            case 5:
                printf("Escolha a lista para exibir (1 ou 2): ");
                scanf("%d", &listaEscolhida);
                getchar();
                if (listaEscolhida != 1 && listaEscolhida != 2) {
                    printf("Opcao invalida!\n");
                    break;
                }

                Exibir_lista_iss(listaEscolhida == 1 ? lista1 : lista2);
                break;

            case 6:
                printf("Escolha a lista para salvar (1 ou 2): ");
                scanf("%d", &listaEscolhida);
                getchar();
                if (listaEscolhida != 1 && listaEscolhida != 2) {
                    printf("Opcao invalida!\n");
                    break;
                }

                printf("Digite o nome do arquivo: ");
                char nome_arquivo[50];
                fgets(nome_arquivo, sizeof(nome_arquivo), stdin);
                nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0';

                Salva_lista_iss_em_arquivo(listaEscolhida == 1 ? lista1 : lista2, nome_arquivo);
                break;

            case 7:
                {
                    ListaISS* listaMesclada = Mesclar_listas_iss(lista1, lista2);
                    if (listaMesclada != NULL) {
                        Exibir_lista_iss(listaMesclada);
                        listaMesclada = Libera_lista_iss(listaMesclada);
                    } else {
                        printf("Erro ao mesclar as listas.\n");
                    }
                }
                break;

            case 8:
            printf("Escolha a lista para ordenar (1 ou 2): ");
            scanf("%d", &listaEscolhida);
            getchar();
            if (listaEscolhida != 1 && listaEscolhida != 2) {
                printf("Opcao invalida!\n");
                break;
            }

            Ordenar_lista_iss(listaEscolhida == 1 ? lista1 : lista2);
            printf("Lista ordenada com sucesso.\n");
            break;

            
            case 9:
                lista1 = Libera_lista_iss(lista1);
                lista2 = Libera_lista_iss(lista2);
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 9);

    return 0;
}
