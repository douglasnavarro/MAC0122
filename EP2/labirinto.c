#include "labirinto.h"
#include <stdlib.h>

void adiciona_item_fim(Item * topo, int x)
{
  Item * atual = topo;
  while( atual->next != NULL)
  {
    atual = atual->next;
  }
  /*atual aponta para o ultimo nó da lista*/
  atual->next = malloc(sizeof(Item));
  atual->next->id   = x;
  atual->next->next = NULL;
}

void inicializa_sala(Room sala)
{
  sala.adj = NULL;
}
