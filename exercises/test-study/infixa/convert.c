/*
Fazer um programa que converte uma expressao em notação pos-fixa para infixa:

23+5* -> 2+3*5

Solução:

Vamos empilhando os caracteres um a um até encontrar um operador. Quando encontramos um
operador, fazemos print(pop) print(operador) print(pop) e assim por diante. A implementação
com o uso de parenteses é mais complicada.

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
    if(a[i] == '+' || a[i] == '*')
    {
      x = STACKpop();
      y = STACKpop();
      printf("%d%c%d", y, a[i], x);
    }
    else
    {
      STACKpush(a[i]-'0');
    }
  }
  printf("\n");
  return 0;
}
