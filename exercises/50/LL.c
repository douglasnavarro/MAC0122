#include <stdlib.h>
#include "LL.h"

/*Como nas declarações certas funções são do tipo void, não podemos retornar
  o ponteiro para o primeiro nó e portanto devemos utilizar esta variavel
  global.
  A ideia é que esta lista tenha o numero máximo de nós que o cliente
  possivelmente irá precisar.
  */
link lista;

/*
Inicializa uma lista ligada com N nós,
sem especificar os valores dos itens, apenas os ponteiros next.
*/
void initNodes(int N)
{
  int i;
  lista = (link)malloc (N * (sizeof (*lista))); /* lista aponta para inicio do vetor |node|node|node|node|node| ... */

  for(i = 0; i < N-1; i++)
  {
    lista[i].next = &lista[i+1];
  }

  lista[N-1].next = NULL;
}

/*
Insere nó "t" em uma lista, à frente do nó "x". Note que não é possível inserir
esse nó "t" no início de uma lista, apenas no final, se t-> next for NULL.
*/

void insertNext(link x, link t)
{
  t->next = x->next;
  x->next = t;
}

/*
Remove o nó x, retornando o endereço do nó que estava ligado a x.
*/

link deleteNext(link x)
{
  link t = x->next;
  x->next = t->next;
  return t;
}

/*
retorna um ponteiro para o nó que vem após x
*/
link Next(link x)
{
  return x->next;
}

/*
retorna o conteúdo do nó passado
*/
int Item(link x)
{
  return x-> item;
}


link newNode(int i)
{
  link x = deleteNext(lista);
  x->item = i;
  x-> next = x;
  return x;
}

void freeNode(link x)
{
  insertNext(lista, x);
  free(x);
}
