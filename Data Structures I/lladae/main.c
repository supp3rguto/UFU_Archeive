#include <stdio.h>
#include <stdlib.h>
#include "lladae.c"

int main() {
    Lista* lista = Cria_lista();
    int valor;

    printf("Insira os elementos na lista (digite -1 para encerrar):\n");
    while (1) {
        printf("Valor: ");
        scanf("%d", &valor);
        if (valor == -1)
            break;
        lista = Insere_elem(lista, valor);
    }

    Exibe_lista(lista);

    printf("Digite o valor do no que deseja remover: ");
    scanf("%d", &valor);
    lista = Remove_elem(lista, valor);

    Exibe_lista(lista);

    char nome_arquivo[100];
    printf("Digite o nome do arquivo para salvar a lista: ");
    scanf("%s", nome_arquivo);
    Salva_lista_em_arquivo(lista, nome_arquivo);

    lista = Libera_lista(lista);

    return 0;
}
