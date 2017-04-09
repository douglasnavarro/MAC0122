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
  * https://en.wikipedia.org/wiki/Euclidean_algorithm#Implementations
  * https://www.khanacademy.org/math/algebra/rational-and-irrational-numbers/sums-and-products-of-rational-and-irrational-numbers/v/sum-and-product-of-rational-numbers
  */


#include "RAT.h"
#include <stdio.h>

/**
 * Calcula uma aproximacao racional da raiz quadrada de S atraves do metodo babilonico
 * (recursivo)
 * @param int S (numero cuja raiz quadrada se deseja), int n (numero de passos da aproximacao), Rational x0 (chute inicial)
 * @return Rational: numero racional que aproxima a raiz de S
 */
Rational sqrt_aprox( int S, int n, Rational x0)
{
  if ( n == 0 ) return x0;
  else
  {
    Rational RatS    = RATinit(S, 1);
    Rational x_n_ant = sqrt_aprox(S, n-1, x0);
    Rational soma    = RATadd(x_n_ant, RATdiv(RatS, x_n_ant));
    Rational prod    = RATmul(RATinit(1,2), soma);
    return prod;
  }
}

int main()
{
  int S, n;
  unsigned long num, den;

  printf("\nEste programa calcula uma aproximacao racional da raiz quadrada de um numero S utilizando o metodo babilonico. Insira o numero S cuja raiz sera aproximada:");
  if( scanf("%d", &S) != 1) return 0;
  printf("\nInsira agora o valor inteiro n>0: ");
  if( scanf("%d", &n)!= 1) return 0;
  printf("Insira agora o numerador do racional x0: ");
  if( scanf("%lu", &num) != 1) return 0;
  printf("Insira agora o denominador do racional x0: ");
  if( scanf("%lu", &den) != 1) return 0;
  printf("\nO resultado da aproximacao eh: ");
  RATshow(sqrt_aprox(S, n, RATinit(num, den)));
  printf("\n");
  return 1;
}
