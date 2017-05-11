#include <stdlib.h>
#include "STACK.h"

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
  int x = _Pilha[_topo -1];
  _topo--;
  return x;
}
