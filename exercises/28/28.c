/*
Reescrevendo o código de forma mais clara, ele fica assim:
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node* link;
struct node
{
  int item;
  link next;
};

main(int argc, char * argv[])
{
  int i, N, M;
  N = atoi(argv[1]);
  M = atoi(argv[2]);
  link t = malloc(sizeof(*t));
  link x = t;
  t->item = 1;
  t->next = t;

  /*
  Este próximo 'for' é responsável pela criação da lista.
  Note que a cada execução do loop, um nó é criado, o nó anterior
  aponta para ele, e ele aponta para 't', o primeiro nó da lista.

  O problema é que a cada execução do laço, o 'next' do último nó
  deve ser modificado, pois não deve mais apontar para o início da
  lista, mas para o novo nó que será inserido.

  Um modo um pouco melhor de realizar a mesma operação é construir
  a lista de forma direta e, alocado o úlimo nó, fazer ele apontar para
  o início da lista. Para tal, basta remover a linha x -> next = t de dentro
  do laço.
  */

  for(i = 2; i <= N; i++)
  {
    x -> next = malloc(sizeof(*x));
    x = x->next;
    x -> item = i;
  }
  x -> next = t;
  while(x != x->next)
  {
    for(i = 1; i < M; i++)
    {
      x = x->next;
    }
    x -> next = x->next->next;
    N--;
  }
  printf("%d\n", x->item);
}
