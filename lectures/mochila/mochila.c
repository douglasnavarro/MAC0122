#include "mochila.h"

/*M é a capacidade de peso da mochila*/
/*N é o numero de objetos*/

int mochila(int M)
{
  int valormax;
  valormax = 0;
  for(i = 0; i < N; i++)
  {
    restante = M - objeto[i].peso;
    if(restante > 0)
    {
      valor = mochila(restante);
      valortotal = valor + objeto[i].valor;
      if(valortotal > valormax) valormax = valortotal;
    }
  }
  return valormax;
}

/*memorization
valorcalculado[M] = valor da mochila c capacidade maxima M
objetoescolhido[M] =
*/
int mochila(int M)
{
  if(valorcalculado[M] != -1) return valorcalculado[M];
  valormaximo = 0;
  for(i=0; i< N; i++)
  {
    restante = M-objeto[i].peso;
    if(restante > 0)
    {
      if(valorcalculado[restante] == -1) valorcalculado[restante] = mochila(restante);
      valor = valorcalculado[restante];
      valortotal = valor + objeto[i].valor;
      if(valortotal>valormax)
      {
        valormax = valortotal;
        objetoescolhido[M] = i;
        valorcalculado[M] = valormax;
      }
    }
    return valormax;
  }
}
