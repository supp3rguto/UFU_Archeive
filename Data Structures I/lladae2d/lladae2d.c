#include <stdio.h>
#include <stdlib.h>
#include "lladae2d.h"

struct no {
              struct no* ant;
              int info;
              struct no* prox;
           };

Lista* Cria_lista(void)
{
    
    return NULL;
}
  

 


//versao para libera - nao esta de acordo com TAD definido
Lista* Libera_lista(Lista *Ptl)
{
  Lista   *aux;
  while (Ptl!= NULL)
  {
    aux = Ptl;
    Ptl = Ptl->prox;
    free(aux);
  }
  
  return NULL;
}

int E_vazia(Lista *Ptl)
{
   if (Ptl == NULL)
     return 1;
   else return 0;
}

int E_cheia(Lista *Ptl)
{
   return 0;
}  


Lista* Insere_elem(Lista *Ptl, int elem)
{
    Lista *Ptnodo;
    Ptnodo = (Lista*)malloc(sizeof(Lista));
    if (Ptnodo == NULL)
       return Ptl;
    Ptnodo->info = elem;
    Ptnodo->prox = Ptl;
    Ptnodo->ant = NULL;
    if(Ptl != NULL)
       Ptl->ant = Ptnodo;
    Ptl = Ptnodo;
    return Ptl;
}



Lista* Remove_elem(Lista *Ptl, int elem)
{
  Lista *atual;
  if (Ptl == NULL)
    return Ptl;

  atual = Ptl;
  while (atual != NULL && elem != atual->info)
  {
     atual = atual->prox;
  }
  if (atual == NULL)// não achou
    return Ptl;
  
  if (atual == Ptl)// primeiro nodo a ser removido
      Ptl = atual->prox;   
  else // nodo removido do meio ou do final da lista
       atual->ant->prox = atual->prox;
       
  if (atual->prox != NULL)
           atual->prox->ant = atual->ant;
  free(atual);
  return Ptl;  
}


int Tamanho_lista(Lista *Ptl)
{
  Lista *pt;
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

  
int Consulta_nodo(Lista *Ptl, int pos, int *elem)
{
       int cont = 1;
       Lista *pt;
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
               *elem=pt->info;
               return 1;          
             }          
}
