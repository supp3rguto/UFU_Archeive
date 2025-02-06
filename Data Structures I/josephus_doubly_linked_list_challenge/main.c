#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "josephus.c"

typedef struct {
    char nome[50];
    int numero;
} Pessoa;

void grava_saida(FILE* arquivo, int posicao, Pessoa* pessoa) {
    fprintf(arquivo, "Posição: %d, Nome: %s, Número: %d saiu do círculo\n", posicao, pessoa->nome, pessoa->numero);
}

void grava_ultimo(FILE* arquivo, Pessoa* pessoa, const char* premio_castigo) {
    fprintf(arquivo, "Última pessoa: Nome: %s, Número: %d - %s\n", pessoa->nome, pessoa->numero, premio_castigo);
}

int sorteia_numero(int N) {
    return (rand() % N) + 1;
}

int main() {
    srand(time(NULL));
    int N, pos, elem, removido;
    FILE *arquivo = fopen("saida.txt", "w");

    if (!arquivo) {
        printf("Erro ao abrir o arquivo de saida.\n");
        return 1;
    }

    printf("Digite o numero de pessoas no circulo: ");
    scanf("%d", &N);

    Lista* circulo = Cria_lista();
    Pessoa pessoas[N];
    
    for (int i = 0; i < N; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].nome);
        pessoas[i].numero = i + 1;
        circulo = Insere_elem(circulo, pessoas[i].numero);
    }

    int tamanho_atual = N;
    while (tamanho_atual > 1) {
        int sorteado = sorteia_numero(tamanho_atual);
        Consulta_nodo(circulo, sorteado, &removido);
        grava_saida(arquivo, sorteado, &pessoas[removido - 1]);
        circulo = Remove_elem(circulo, removido);
        tamanho_atual--;
    }

    Consulta_nodo(circulo, 1, &removido);
    grava_ultimo(arquivo, &pessoas[removido - 1], "Recebe um prêmio!");
    circulo = Libera_lista(circulo);
    fclose(arquivo);

    printf("Jogo encerrado. Resultados gravados em 'saida.txt'.\n");
    return 0;
}
