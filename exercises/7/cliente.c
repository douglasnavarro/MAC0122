/*
Usando a convenção do Exercicio 6, escreva sequências por meio de inser-
ção de astericos na sequência E A S Y, tal que os valores retornados pela
operação desempilhamento sejam (i) E A S Y; (ii) Y S A E; (iii) A S Y E;
(iv) A Y E S; ou, prove que tal sequência não exista.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "STACK.h"

int main(int argc, char * argv[])
{
  char *a = argv[1];
  int i = 0;
  int N = strlen(a);
  STACKinit(N);
  while(i < N)
  {
    if(a[i] == '*') printf("%c", STACKpop());
    else STACKpush(a[i]);
    i++;
  }
  return 0;
}
