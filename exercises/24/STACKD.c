#include "STACK.h"
#include <stdlib.h>

void STACKinit(int N)
{
  _tam_vetor = N;
  _topo[1] = N - 1;
  _topo[0] = 0;
  _Pilha = malloc ( N * sizeof(int));
}

void STACKpush( int x, int pilha)
{
  if(pilha == 0) _Pilha[_topo[pilha]++] = x;
  else _Pilha[_topo[pilha]--] = x;
}

int STACKpop(int pilha)
{
  if(pilha == 0)
  {
    return _Pilha[--_topo[pilha]];
  }
  else
  {
    return _Pilha[++_topo[pilha]];
  }
}

int STACKempty(int pilha)
{
  if(pilha == 0)
  {
    return _topo[pilha] == 0;
  }
  else
  {
    return _topo[pilha] == _tam_vetor -1;
  }
}

int STACKtop(int pilha)
{
  return _Pilha[_topo[pilha] + (2*pilha -1)];
}
