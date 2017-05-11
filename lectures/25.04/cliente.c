#include <stdio.h>
#include "STACK.h"
#include <string.h>

// Expressão abre-fecha parênteses
//
// ((()())) <- bem-formada
// (()))    <- mal-formada
// ()(      <- mal-formada
//
// Problema:
// Dada uma expressão abre-fecha parênteses, verificar se ela é bem ou mal formada

// Percorrer a expressão:
// '(' -> empilha
// ')' -> se pilha vazia => mal formada
//       caso contrario => desempilha
//
// No final verificar
//   se pilha-vazia => bem-formada
//   caso contrario => mal-formada

int main (int argc, char * argv[])
{
  if (argc != 2)
  {
    printf("%s <expr>\n", argv[0]);
    return 0;
  }

  if (bem-formada(argv[1])) printf("Seq. bem-formada");
  else printf("Seq. mal-formada");
  return 0;
}

int bem-formada(char * s)
{
  STACKinit(strlen(s));
  while (*s != 0)
  {
    if (*s == '(')
    {
      STACKpush('(');
    }
    else
    {
      if (STACKempty()) return 0;
      else STACKpop();
    }
    s++;
    if (STACKempty()) return 1;
    return 0;
  }
}
