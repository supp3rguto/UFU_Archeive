#include <stdio.h>
#include <stdlib.h>
#include "lladaec.h"

struct no {
              int info;
              struct no* prox;
           };
           

Lista* Cria_lista(void)
{
    return NULL;
}




Lista* Libera_lista(Lista* Ptl)
{
  Lista  *pt, *aux;
  
  if (Ptl == NULL)
     return NULL;
     
   
  pt = Ptl->prox;
  while (pt != Ptl)
    {
      aux = pt;
      pt = pt->prox;
      free(aux);
    }
    free(pt);
    return NULL;
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

// insere o inicio da lista
Lista* Insere_elem(Lista* Ptl, int elem)
 
{
    Lista *Ptnodo, *aux;
    Ptnodo = (Lista*)malloc(sizeof(struct no));
    if (Ptnodo == NULL)
       return Ptl;

    Ptnodo->info = elem;

    if (Ptl == NULL) // lista vazia
    {
        Ptl = Ptnodo;
        Ptnodo->prox = Ptl;
    }
    else //lista nao esta vazia,insere no final
     {
        Ptnodo->prox = Ptl->prox;
        Ptl->prox = Ptnodo;
        Ptl = Ptnodo;
     }
    return Ptl;
}


/*
Lista* Remove_elem_v1(Lista* Ptl, int elem)
{
  Lista *ant,*atual,*Ptaux;
  if (Ptl == NULL) //lista vazia
    return Ptl;

  atual = Ptl;
  // verifica se elemento esta no primeiro no
  if( elem == atual->info){
      if (atual->prox == Ptl)// lista com um no
     //remove o unico no da lista
      {
         Ptl = NULL;
         free(atual);
         return Ptl;
      }
     else {

            Ptaux = atual;
            while(Ptaux->prox != Ptl)
               Ptaux = Ptaux->prox;
            Ptaux->prox = atual->prox;
            Ptl = atual->prox;
            free(atual);
            return Ptl;
         }
   }
  ant = atual;
  atual = atual->prox;
  while (atual != Ptl && atual->info !=elem)
  {
     ant = atual;
     atual = atual->prox;
  }
  if (atual == Ptl)//nao achou elemento
     return Ptl;
  else {
         ant->prox = atual->prox;
         free(atual);
         return Ptl;
       }
}
*/

//----------------------
Lista* Remove_elem(Lista* Ptl, int elem)
{
  Lista *ant,*atual,*aux;
  
  if (Ptl == NULL) //lista vazia
    return Ptl;

  atual = Ptl->prox;
  ant = Ptl;
  
  while (atual!= Ptl && atual->info != elem)
  {
     ant = atual;
     atual = atual->prox;
  }
  
  if (atual->info == elem)
  { 
     if (atual == ant)
            Ptl = NULL;
     else {
           ant->prox = atual->prox;
           if (atual == Ptl) //ultimo nodo a ser removido
             Ptl = ant;
          }
     
    free(atual);
  }
  
  return Ptl;  
}   



int Tamanho_lista(Lista* Ptl)
{
  Lista *pt;
  int cont;

  if (Ptl == NULL)
     return 0;

  pt = Ptl->prox;
  cont = 1;
  while (pt != Ptl)
  {
     pt = pt->prox;
     cont++;
  }
   
  return cont;
}

int Consulta_nodo(Lista* Ptl, int pos, int *elem)
{
       int cont;
       Lista *pt;
       if( Ptl == NULL || pos <= 0)
         return 0;


       cont = 1;
       pt = Ptl->prox;
       while(pt != Ptl && cont < pos)
       {
           pt=pt->prox;
           cont++;
       }
       if (cont == pos)
       {
         *elem = pt->info;
         return 1;
       }
       else return 0;
}

