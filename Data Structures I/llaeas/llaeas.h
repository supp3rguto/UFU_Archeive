typedef struct lista Lista;

Lista* Cria_lista(void);
Lista* Libera_lista(Lista* Ptl);
Lista* Insere_elem(Lista* Ptl, int elem);
Lista* Remove_elem(Lista* Ptl, int elem);
Lista* Remove_elem_mov(Lista* Ptl, int elem);
int Consulta_nodo(Lista* Ptl, int pos, int* info);

void Exibir_lista(Lista* Ptl);
void Salvar_lista_em_arquivo(Lista* Ptl, char* nome_arquivo);

int Tamanho_lista(Lista* Ptl);
int E_cheia(Lista* Ptl);
int E_vazia(Lista* Ptl);