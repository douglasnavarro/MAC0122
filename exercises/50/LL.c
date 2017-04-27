#include <stdlib.h>
#include "LL.h"

/*Como nas declarações certas funções são do tipo void, não podemos retornar
  o ponteiro para o primeiro nó e portanto devemos utilizar esta variavel
  global.*/
link lista;

/*
Cria nó cujo 'next' é NULL porque está sozinho e
seu conteúdo (item) é x.
*/
link newNode(int x)
{
  link p;
  p = (link) malloc(sizeof(*p));
  p -> next = NULL;
  p -> item = x;
  return p;
}

/*
Inicializa uma lista ligada com N nós,
sem especificar os valores dos itens, apenas os ponteiros next.
*/
void initNodes(int N)
{
  int i;
  lista = (link) malloc (N * (sizeof (*lista))); /* lista aponta para inicio do vetor |node|node|node|node|node| ... */

  for(i = 0; i < N-1; i++)
  {
    lista[i] -> next = &lista[i+1];
  }

  lista[N-1] -> next = NULL;
}
