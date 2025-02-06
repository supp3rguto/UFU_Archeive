#include <stdio.h>
#include <stdlib.h>
#include "llaeas.h"

int main() {
    Lista *lista = Cria_lista();
    int elem;

    printf("Insira elementos na lista (digite -1 para finalizar):\n");
    while (1) {
        printf("Elemento: ");
        scanf("%d", &elem);
        if (elem == -1) break;
        lista = Insere_elem(lista, elem);
    }

    printf("Lista original:\n");
    Exibir_lista(lista);

    printf("Insira o elemento a ser removido: ");
    scanf("%d", &elem);
    lista = Remove_elem_mov(lista, elem);

    printf("Lista atualizada:\n");
    Exibir_lista(lista);

    char nome_arquivo[100];
    printf("Digite o nome do arquivo para salvar a lista: ");
    scanf("%s", nome_arquivo);
    Salvar_lista_em_arquivo(lista, nome_arquivo);

    lista = Libera_lista(lista);
    return 0;
}
