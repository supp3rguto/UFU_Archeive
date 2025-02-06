#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

typedef struct {
    int elementos[MAX];
    int topoAtual;
} EstruturaPilha;

typedef struct {
    int elementos[MAX];
    int primeiro, ultimo;
} EstruturaFila;

typedef struct {
    int elementos[MAX];
    int quantidade;
} EstruturaFilaPrioridade;

void configurarPilha(EstruturaPilha *pilha) {
    pilha->topoAtual = -1;
}

bool adicionarNaPilha(EstruturaPilha *pilha, int valor) {
    if (pilha->topoAtual >= MAX - 1) return false;
    pilha->elementos[++pilha->topoAtual] = valor;
    return true;
}

bool removerDaPilha(EstruturaPilha *pilha, int *valor) {
    if (pilha->topoAtual == -1) return false;
    *valor = pilha->elementos[pilha->topoAtual--];
    return true;
}

void configurarFila(EstruturaFila *fila) {
    fila->primeiro = fila->ultimo = -1;
}

bool inserirNaFila(EstruturaFila *fila, int valor) {
    if (fila->ultimo >= MAX - 1) return false;
    if (fila->primeiro == -1) fila->primeiro = 0;
    fila->elementos[++fila->ultimo] = valor;
    return true;
}

bool retirarDaFila(EstruturaFila *fila, int *valor) {
    if (fila->primeiro == -1 || fila->primeiro > fila->ultimo) return false;
    *valor = fila->elementos[fila->primeiro++];
    return true;
}

void configurarFilaPrioridade(EstruturaFilaPrioridade *filaPrioridade) {
    filaPrioridade->quantidade = 0;
}

bool colocarNaFilaPrioridade(EstruturaFilaPrioridade *filaPrioridade, int valor) {
    if (filaPrioridade->quantidade >= MAX) return false;
    filaPrioridade->elementos[filaPrioridade->quantidade++] = valor;
    return true;
}

bool extrairMaiorDaFila(EstruturaFilaPrioridade *filaPrioridade, int *valor) {
    if (filaPrioridade->quantidade == 0) return false;
    int indiceMaior = 0;
    for (int i = 1; i < filaPrioridade->quantidade; i++) {
        if (filaPrioridade->elementos[i] > filaPrioridade->elementos[indiceMaior]) {
            indiceMaior = i;
        }
    }
    *valor = filaPrioridade->elementos[indiceMaior];
    filaPrioridade->elementos[indiceMaior] = filaPrioridade->elementos[--filaPrioridade->quantidade];
    return true;
}

int main() {
    int n, comando, valor;

    while (scanf("%d", &n) != EOF) {
        EstruturaPilha pilha;
        EstruturaFila fila;
        EstruturaFilaPrioridade filaPrioridade;

        configurarPilha(&pilha);
        configurarFila(&fila);
        configurarFilaPrioridade(&filaPrioridade);

        bool comportamentoPilha = true;
        bool comportamentoFila = true;
        bool comportamentoFilaPrioridade = true;

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &comando, &valor);

            if (comando == 1) {
                if (comportamentoPilha) adicionarNaPilha(&pilha, valor);
                if (comportamentoFila) inserirNaFila(&fila, valor);
                if (comportamentoFilaPrioridade) colocarNaFilaPrioridade(&filaPrioridade, valor);
            } else if (comando == 2) {
                int resultado;

                if (comportamentoPilha && (!removerDaPilha(&pilha, &resultado) || resultado != valor)) {
                    comportamentoPilha = false;
                }
                if (comportamentoFila && (!retirarDaFila(&fila, &resultado) || resultado != valor)) {
                    comportamentoFila = false;
                }
                if (comportamentoFilaPrioridade && (!extrairMaiorDaFila(&filaPrioridade, &resultado) || resultado != valor)) {
                    comportamentoFilaPrioridade = false;
                }
            }
        }

        if (comportamentoPilha + comportamentoFila + comportamentoFilaPrioridade > 1) {
            printf("not sure\n");
        } else if (comportamentoPilha) {
            printf("stack\n");
        } else if (comportamentoFila) {
            printf("queue\n");
        } else if (comportamentoFilaPrioridade) {
            printf("priority queue\n");
        } else {
            printf("impossible\n");
        }
    }

    return 0;
}
