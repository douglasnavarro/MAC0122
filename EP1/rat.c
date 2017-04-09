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

/**
 * Inicializa variavel do tipo Rational.
 * @param unsigned long numerador, unsigned long denominador
 * @return Rational com num e den definidos
 */
 Rational RATinit(unsigned long numerator, unsigned long denominator)
 {
   Rational racional;
   racional.num = numerator;
   racional.den = denominator;
   return racional;
 }

 /**
  * Soma dois numeros racionais. Teoria mencionada no cabeçalho.
  * @param primeira parcela: Rational r1, segunda parcela:Rational r2
  * @return Rational: resultado da soma de r1 e r2
  */
Rational RATadd(Rational r1, Rational r2)
{
  Rational racional;
  unsigned long a, b, m, n;
  a = r1.num;  b = r1.den;
  m = r2.num;  n = r2.den;
  racional.num = a*n + b*m;
  racional.den = b*n;
  return racional;
}

/**
 * Multiplica dois numeros racionais.
 * @param primeiro fator: Rational r1, segundo fator:Rational r2
 * @return Rational: resultado do produto de r1 e r2
 */
Rational RATmul(Rational r1, Rational r2)
{
  Rational racional;
  racional.num = r1.num * r2.num;
  racional.den = r1.den * r2.den;
  return racional;
}

/**
 * Divide dois numeros racionais. Igual a multiplicação mas com o segundo fator invertido.
 * @param primeiro fator: Rational r1, segundo fator:Rational r2
 * @return Rational: resultado da divisao de r1 e r2
 */
Rational RATdiv(Rational r1, Rational r2)
{
  Rational racional;
  racional.num = r1.num * r2.den;
  racional.den = r1.den * r2.num;
  return racional;
}

/**
 * Imprime o racional de entrada na tela com um espaço antes. Exemplo: 3/5
 * @param Racional r
 * @return none
 */
void RATshow(Rational r)
{
  printf(" %lu/%lu", r.num, r.den);
}

/**
 * Calcula o fatorial de um unsigned long de forma recursiva
 * @param unsigned long
 * @return unsigned long
 */
unsigned long factorial(unsigned long number)
{
  if(number == 0) return 1;
  else return (number * factorial(number -1));
}
