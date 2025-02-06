#define MAX 25000

typedef struct {
    int componentes[MAX];
    int topo;
} PilhaEstoqueComponentes;

void inicializaPilha(PilhaEstoqueComponentes* pilha);
void insereComponente(PilhaEstoqueComponentes* pilha, int numero_serie);
int removeComponente(PilhaEstoqueComponentes* pilha);
void imprimeEstoqueComponentes(PilhaEstoqueComponentes* pilha);