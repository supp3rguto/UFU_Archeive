#define MAX_ASTRONAUTAS 10
#define MAX_MISSOES 5
#define MAX_MODULOS 5

typedef struct {
    char nome[50];
    int idade;
    char nacionalidade[30];
} Astronauta;

typedef struct {
    char nome[50];
    char objetivo[100];
    int duracao; // todo: alterar duração em dias (obs: perguntar?)
} Missao;

typedef struct {
    char nome[50];
    char tipo[50];
    int capacidade;
} Modulo;

typedef struct {
    Astronauta astronautas[MAX_ASTRONAUTAS];
    int num_astronautas;

    Missao missoes[MAX_MISSOES];
    int num_missoes;

    Modulo modulos[MAX_MODULOS];
    int num_modulos;
} EstacaoEspacial;

// Funções de inicialização
void inicializaEstacao(EstacaoEspacial *estacao);

// Funções para manipulação de astronautas
void adicionarAstronauta(EstacaoEspacial *estacao, char nome[], int idade, char nacionalidade[]);
void listarAstronautas(EstacaoEspacial *estacao);

// Funções para manipulação de missões
void adicionarMissao(EstacaoEspacial *estacao, char nome[], char objetivo[], int duracao);
void listarMissoes(EstacaoEspacial *estacao);

// Funções para manipulação de módulos
void adicionarModulo(EstacaoEspacial *estacao, char nome[], char tipo[], int capacidade);
void listarModulos(EstacaoEspacial *estacao);

// Nova função para listar toda a estação
void listarEstacao(EstacaoEspacial *estacao);