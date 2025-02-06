#define MAX 10

typedef struct {
    char astronauta[50];
    char missao[50];
    char modulo[50];
} Item;

typedef struct {
    int fim;
    Item dados[MAX];
} ListaISS;

ListaISS* Cria_lista_iss(void);
ListaISS* Libera_lista_iss(ListaISS* lista);
int Insere_item_iss(ListaISS* lista, Item item);
int Remove_item_iss(ListaISS* lista, char* astronauta);
int Busca_item_iss(ListaISS* lista, char* astronauta, Item* item);
void Exibir_lista_iss(ListaISS* lista);
int Alterar_item_iss(ListaISS* lista, char* astronauta, Item novo_item);
int Tamanho_lista_iss(ListaISS* lista);
int E_cheia_iss(ListaISS* lista);
int E_vazia_iss(ListaISS* lista);