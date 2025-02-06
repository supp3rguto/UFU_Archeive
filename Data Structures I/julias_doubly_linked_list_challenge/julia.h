typedef struct Filme {
    char nome[50];
    int lotacao;
    int assentosDisponiveis[10];
    struct Filme* proximo;
} Filme;

typedef struct Ingresso {
    char filme[50];
    int assento;
    struct Ingresso* proximo;
    struct Ingresso* anterior;
} Ingresso;

typedef struct ListaIngressos {
    Ingresso* inicio;
    Ingresso* fim;
} ListaIngressos;

Filme* criarFilme(char* nome, int lotacao);
Ingresso* criarIngresso(char* filme, int assento);
void adicionarFilme(Filme** lista_filmes, Filme* filme);
void adicionarIngressoVendido(ListaIngressos* listaIngressos, Ingresso* ingresso);
void removerIngressoVendido(ListaIngressos* listaIngressos, Ingresso* ingresso);
void exibirIngressosDisponiveis(Filme* filme);
void exibirIngressosVendidos(ListaIngressos* listaIngressos);
void venderIngresso(Filme** lista_filmes, ListaIngressos* listaIngressos, char* filme, int assento);
void cancelarIngresso(Filme** lista_filmes, ListaIngressos* listaIngressos, char* filme, int assento);