#include <stdio.h>
#include <stdlib.h>
#include "lladae.h"

struct no {
              int info;
              struct no* prox;
           };

Lista* Cria_lista(void)
{
    
    return NULL;
}
  


Lista* Libera_lista(Lista *Ptl)
{
  Lista*   aux;

  while (Ptl!= NULL)
  {
    aux = Ptl;
    Ptl = Ptl->prox;
    free(aux);
  }
  
  return Ptl;
}


int E_vazia(Lista* Ptl)
{
   if (Ptl == NULL)
     return 1;
   else return 0;
}

int E_cheia(Lista* Ptl)
{
   return 0;
}  

Lista* Insere_elem(Lista *Ptl, int elem)
{
    Lista* Ptnodo;
    Ptnodo = (Lista*)malloc(sizeof(Lista));
    if (Ptnodo == NULL)
       return Ptl;
    Ptnodo->info = elem;
    Ptnodo->prox = Ptl;
    Ptl = Ptnodo;
    return Ptl;
}



Lista* Remove_elem(Lista *Ptl, int elem)
{
  Lista *ant,*atual;
  if (Ptl == NULL)
    return Ptl;
  
   
  atual = Ptl;
  while (atual != NULL && elem != atual->info)
  {
     ant = atual;
     atual = atual->prox;
  }
  if (atual == NULL)
    return Ptl;
  
  if (atual == Ptl)// primeiro nodo a ser removido
     Ptl = atual->prox;
  else 
       ant->prox = atual->prox;
  
  free(atual);
  return Ptl;
       
}

int Tamanho_lista(Lista* Ptl)
{
  Lista* pt;
  int cont;
  pt = Ptl;
  cont = 0;
  while (pt != NULL)
  {
     cont++;
     pt = pt->prox;
  }
  return cont;
}


  
int Consulta_nodo(Lista* Ptl, int pos,int *elem)
{
       int cont = 1;
       Lista* pt;
       pt = Ptl;
       if (pos <= 0 || pt == NULL)
         return 0;
       while(pt != NULL && cont < pos)
       {
           pt=pt->prox;
           cont++;
       }       
       if (pt == NULL)
         return 0;
       else {
               *elem = pt->info;  
               return 1;
            }                  
}




void Exibe_lista(Lista* Ptl) {
    if (E_vazia(Ptl)) {
        printf("A lista está vazia.\n");
        return;
    }
    Lista* ptr = Ptl;
    printf("Elementos da lista: ");
    while (ptr != NULL) {
        printf("%d ", ptr->info);
        ptr = ptr->prox;
    }
    printf("\n");
}

void Salva_lista_em_arquivo(Lista* Ptl, const char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    Lista* ptr = Ptl;
    while (ptr != NULL) {
        fprintf(arquivo, "%d\n", ptr->info);
        ptr = ptr->prox;
    }

    fclose(arquivo);
    printf("Lista salva no arquivo %s\n", nome_arquivo);
}