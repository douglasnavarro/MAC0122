#include "labirinto.h"
#include <stdlib.h>
#include <stdio.h>

void imprime_relatorio(int n, int m, int ** corredores)
{
  printf("\nO valor lido de n foi: %d\n", n);
  printf("O valor lido de m foi: %d\n", m);
  printf("Corredores:\n");
  int i;
  for(i = 0; i < n - 1; i++)
  {
    printf("%d %d\n", corredores[i][0], corredores[i][1]);
  }
  printf("\n");
}

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
  sala->visitada = 0;
  sala->adj = malloc(sizeof(Item));
  inicializa_lista(sala->adj);
}

void inicializa_lista(Item * i)
{
  i->next = NULL;
  i->id = 0;
}

void imprime_tabela(Room ** salas, int n)
{
  int i;
  for(i = 0; i < n; i++)
  {
    printf("(%d)->", i);
    Item * topo = salas[i]->adj->next;
    while (topo != NULL) {
      printf("%d->", topo->id);
      topo = topo->next;
    }
    printf("(NULL)\r\n");
  }
}

void STACKinit(int N)
{
  _Pilha = malloc(N*sizeof(int));
  _topo = 0;
}

int STACKempty()
{
  return(_topo == 0);
}

void STACKpush(int x)
{
  _Pilha[_topo] = x;
  _topo++;
}

int STACKpop()
{
  int x = _Pilha[_topo-1];
  _topo--;
  return x;
}
