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

typedef struct {
unsigned long num;
unsigned long den;
} Rational;

Rational RATinit(unsigned long numerator, unsigned long denominator);

void RATshow(Rational r);
Rational RATadd(Rational r1, Rational r2);
Rational RATmul(Rational r1, Rational r2);
Rational RATdiv(Rational r1, Rational r2);
