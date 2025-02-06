#include <stdio.h>
#include <stdlib.h>
#include "llaeas.h"
#define MAX 10

struct lista{
               int FL;
               int dados[MAX];
            };


Lista* Cria_lista(void)
{
   Lista* pt = (Lista*)malloc(sizeof(Lista));
   if(pt != NULL)
       pt->FL = 0;
   return pt;
}


Lista* Libera_lista(Lista* Ptl)
{
   free(Ptl);
   return NULL;
}

Lista* Insere_elem(Lista* Ptl, int elem)
{

   if (Ptl == NULL || Ptl->FL == MAX)
       return Ptl;

   // insere elemento no final da lista
   Ptl->dados[Ptl->FL] = elem;
   Ptl->FL++;
   return Ptl;
}

// remocao com movimentacao de dados - nao faz parte do TAD
Lista* Remove_elem_mov(Lista* Ptl, int elem)
{
   int i,k;
   if (Ptl == NULL || Ptl->FL == 0)
      return Ptl;

   // procura elemento na lista

   i=0;
   while(i<Ptl->FL && Ptl->dados[i]!=elem)
         i++;

   if (i == Ptl->FL) // elemento nao encontrado
       return Ptl;

   //elemento encontrado na posi�ao i. Remover elemento
   // com movimenta�ao de dados

   for (k=i; k<Ptl->FL-1;k++)
       Ptl->dados[k]=Ptl->dados[k+1];

   // atualiza fim de lista
   Ptl->FL--;
   return Ptl;
}


Lista* Remove_elem(Lista* Ptl, int elem)
{
   int i,k;

   if (Ptl != NULL)
   {
   // procura elemento na lista
     i=0;
     while(i<Ptl->FL && Ptl->dados[i]!=elem)
         i++;

     if (i == Ptl->FL)
       return Ptl;// lista vazia ou elemento nao encontrado
   //elemento encontrado na posi�ao i. Remover elemento
   //sem movimenta�ao de dados

     Ptl->dados[i] = Ptl->dados[Ptl->FL-1];
   // atualiza fim de lista
     Ptl->FL--;
   }
   return Ptl;
}


int Consulta_nodo(Lista* Ptl, int pos, int* info)
{
  if (Ptl == NULL)
      return 0;
  if (pos <= 0 ||  pos > Ptl->FL)
     return 0;

  *info = Ptl->dados[pos-1];
  return 1;
}


int Tamanho_lista(Lista* Ptl)
{
   if (Ptl == NULL)
      return -1;
   else return Ptl->FL;
}

int E_cheia(Lista* Ptl)
{
   if (Ptl == NULL)
      return -1;
   if (Ptl->FL == MAX)
      return 1;
   return 0;
}

int E_vazia(Lista* Ptl)
{
   if (Ptl == NULL)
     return -1;
   if (Ptl->FL == 0)
      return 1;
   return 0;
}




void Exibir_lista(Lista* Ptl) {
    if (E_vazia(Ptl)) {
        printf("A lista está vazia.\n");
    } else {
        printf("Elementos na lista:\n");
        for (int i = 0; i < Tamanho_lista(Ptl); i++) {
            int elem;
            Consulta_nodo(Ptl, i + 1, &elem);
            printf("%d ", elem);
        }
        printf("\n");
    }
}

void Salvar_lista_em_arquivo(Lista* Ptl, char* nome_arquivo) {
    FILE *file = fopen(nome_arquivo, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    for (int i = 0; i < Tamanho_lista(Ptl); i++) {
        int elem;
        Consulta_nodo(Ptl, i + 1, &elem);
        fprintf(file, "%d\n", elem);
    }

    fclose(file);
    printf("Lista salva com sucesso em %s\n", nome_arquivo);
}