#define MAX 10

typedef struct {
    char astronauta[50];
    char missao[50];
    char modulo[50];
} Item;

typedef struct no {
    Item dado;
    struct no* prox;
} No;

typedef struct {
    No* inicio;
} ListaISS;

ListaISS* Cria_lista_iss(void);
ListaISS* Libera_lista_iss(ListaISS* lista);
int Insere_item_iss(ListaISS** lista, Item item);
int Remove_item_iss(ListaISS** lista, char* astronauta);
int Busca_item_iss(ListaISS* lista, char* astronauta, Item* item);
void Exibir_lista_iss(ListaISS* lista);
int Alterar_item_iss(ListaISS* lista, char* astronauta, Item novo_item);
int Tamanho_lista_iss(ListaISS* lista);
int E_cheia_iss(ListaISS* lista);
int E_vazia_iss(ListaISS* lista);
int Verifica_duplicata_iss(ListaISS* lista, char* astronauta);
void Salva_lista_iss_em_arquivo(ListaISS* lista, const char* nome_arquivo);
ListaISS* Mesclar_listas_iss(ListaISS* lista1, ListaISS* lista2);
int Comparar_items(Item a, Item b);
void Ordenar_lista_iss(ListaISS* lista);