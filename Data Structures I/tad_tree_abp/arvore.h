struct no {
    int info;
    struct no* esquerda;
    struct no* direita;
};

struct no* criarNo(int valor) {
    struct no* novoNo = (struct no*)malloc(sizeof(struct no));
    if (novoNo != NULL) {
        novoNo->info = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
    }
    return novoNo;
}

int inserir(struct no** raiz, int valor);
void remover(struct no** raiz, int valor);
int contarNos(struct no* raiz);
int contarNosNaoFolha(struct no* raiz);
int contarNosFolha(struct no* raiz);
int calcularAltura(struct no* raiz);
int acharMaior(struct no* raiz);
void espelharArvore(struct no* raiz);
void imprimirEmOrdem(struct no* raiz);