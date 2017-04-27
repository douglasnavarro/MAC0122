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
  for(i = 2; i <= N; i++)
  {
    x -> next = malloc(sizeof(*x));
    x = x->next;
    x -> item = i;
    x -> next = t;
  }
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
