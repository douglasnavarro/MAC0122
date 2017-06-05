/*
Solução:

Devemos receber uma string do tipo 32+5* (pos fixa) e processar o resultado.
Utilizando a pilha simpes, devemos empilhar os numeros até encontrarmos uma operação.
Quando é encontada a operação, desempilhar 2 números, realizar a operação
e empilhar o resultado de volta.
*/

#include <stdio.h>
#include "STACK.h"
#include <string.h>

int main(int argc, char * argv[])
{
  char *a = argv[1];
  int x, y, i;
  int N = strlen(a);
  STACKinit(N);
  for(i = 0; i < N; i++)
  {
    switch (a[i])
    {
      case '+':
        x = STACKpop();
        y = STACKpop();
        STACKpush(x+y);
        break;

      case '*':
        x = STACKpop();
        y = STACKpop();
        STACKpush(x*y);
        break;

      default:
        STACKpush(a[i] - '0');
    }
  }
  while(STACKempty() == 0)
  {
    printf("%d\n", STACKpop());
  }
  return 0;
}
