/*
  *
  * AO PREENCHER ESSE CABEÇALHO COM O MEU NOME E O MEU NÚMERO USP,
  * DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESSE PROGRAMA.
  * TODAS AS PARTES ORIGINAIS DESSE EXERCÍCIO PROGRAMA (EP) FORAM
  * DESENVOLVIDAS E IMPLEMENTADAS POR MIM SEGUINDO AS INSTRUÇÕES DESSE EP
  * E QUE PORTANTO NÃO CONSTITUEM PLÁGIO. DECLARO TAMBÉM QUE SOU RESPONSÁVEL
  * POR TODAS AS CÓPIAS DESSE PROGRAMA E QUE EU NÃO DISTRIBUI OU FACILITEI A
  * SUA DISTRIBUIÇÃO. ESTOU CIENTE QUE OS CASOS DE PLÁGIO SÃO PUNIDOS COM
  * REPROVAÇÃO DIRETA NA DISCIPLINA.
  *
  * Nome: Douglas Navarro
  * NUSP: 8586760
  *
  * e.c, rat.c, RAT.h
  *
  * Referências:
  * https://www.khanacademy.org/math/algebra/rational-and-irrational-numbers/sums-and-products-of-rational-and-irrational-numbers/v/sum-and-product-of-rational-numbers
  */

#include "RAT.h"
#include <stdio.h>

void main(int argc, char *argv[])
{
  int n; int i;
  Rational e = RATinit(1,1);
  printf("\nEste programa realiza uma aproximacao racional para 'e' (numero de Euler) utilizando a expansao da serie de Taylor.\n");
  printf("\nInsira o numero de aproximacoes n: ");
  scanf("%d", &n);

  for(i = 1; i <= n; i++)
  {
    RATshow(e);
    e =  RATadd(e, RATinit(1, factorial(i)));
  }

  printf("\n");

}
