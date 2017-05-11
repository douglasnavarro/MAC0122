#include <stdlib.h>
#include "STACKL.h"

void STACkinit (int N)
{
  _topo = NULL;
}

int STACKempty()
{
  return (_topo == NULL);
}

void STACKpush(int x)
{
  Link aux;
  aux = malloc(sizeof(*aux));
  aux -> info = x;
  aux -> prox = _topo;
  _topo = aux;
}

int STACKpop()
{
  Link aux = _topo;
  _topo = _topo -> prox;
  int x = aux -> info;
  free(aux);
  return x;
}
