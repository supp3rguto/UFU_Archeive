#include <stdio.h>
#include <stdlib.h>
#include "ed.h"

#define MAX 100

int main() {
    int par[MAX], impar[MAX];
    int par_tamanho = 0, impar_tamanho = 0;
    int opcao, valor, posicao;
    char nome_arquivo[50];

    do {
        printf("\nMenu:\n");
        printf("1. Insere Elemento\n");
        printf("2. Remova Elemento\n");
        printf("3. Consulta Posição\n");
        printf("4. Exiba Elementos\n");
        printf("5. Grave Elementos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
          case 1: {
              double temp;
              printf("Digite um numero inteiro: ");
              if(scanf("%lf", &temp) != 1 || (int)temp != temp) {
                  printf("Valor nao aceito. Por favor, insira um numero inteiro.\n");
                  while(getchar() != '\n');
              } else {
                  valor = (int)temp;
                  Insere(valor, par, &par_tamanho, impar, &impar_tamanho);
              }
              break;
          }

            case 2:
                printf("Digite um numero para remover: ");
                scanf("%d", &valor);
                printf("Remover de qual vetor? (1- Par, 2- Impar): ");
                scanf("%d", &opcao);
                if(opcao == 1)
                    Remove(valor, par, &par_tamanho);
                else if(opcao == 2)
                    Remove(valor, impar, &impar_tamanho);
                else
                    printf("Opcao invalida!\n");
                break;

            case 3:
                printf("Digite a posicao a consultar: ");
                scanf("%d", &posicao);
                printf("Consultar qual vetor? (1- Par, 2- Impar): ");
                scanf("%d", &opcao);
                if(opcao == 1) {
                    valor = Consulta(par, par_tamanho, posicao);
                    if (valor != -1)
                        printf("Elemento na posicao %d: %d\n", posicao, valor);
                }
                else if(opcao == 2) {
                    valor = Consulta(impar, impar_tamanho, posicao);
                    if (valor != -1)
                        printf("Elemento na posicao %d: %d\n", posicao, valor);
                }
                else
                    printf("Opcao invalida!\n");
                break;

            case 4:
                printf("Exibir qual vetor? (1- Par, 2- Impar): ");
                scanf("%d", &opcao);
                if(opcao == 1)
                    Exiba(par, par_tamanho);
                else if(opcao == 2)
                    Exiba(impar, impar_tamanho);
                else
                    printf("Opcao invalida!\n");
                break;

            case 5:
                printf("Gravar qual vetor? (1- Par, 2- Impar): ");
                scanf("%d", &opcao);
                printf("Digite o nome do arquivo: ");
                scanf("%s", nome_arquivo);
                if(opcao == 1)
                    Grave(nome_arquivo, par, par_tamanho);
                else if(opcao == 2)
                    Grave(nome_arquivo, impar, impar_tamanho);
                else
                    printf("Opcao invalida!\n");
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}
