#include "labirinto.h"
#include <stdlib.h>
#include <stdio.h>

void adiciona_item_fim(Item * atual, int x)
{
  while( atual->next != NULL )
  {
    atual = atual->next;
  }
  /*atual aponta para o ultimo nó da lista*/
  Item * newI = malloc(sizeof(Item));
  atual->next = newI;
  newI->id   = x;
  newI->next = NULL;
}

void inicializa_sala(Room * sala)
{
  sala->adj = malloc(sizeof(Item));
  inicializa_lista(sala->adj);
}

void inicializa_lista(Item * i) {
  i->next = NULL;
  i->id = 0;
}
