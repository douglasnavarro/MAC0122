#include "labirinto.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  FILE * arq;
  int m; /*corredores*/
  int n; /*salas*/
  int i; /*para iterar*/

  if(argc != 2) /* não especificou o arquivo na chamada */
  {
    printf("%s <arquivo.txt>\n", argv[0]);
    return 0;
  }

  arq = fopen(argv[1], "r");

  if(arq == NULL) /* problema ao abrir arquivo*/
  {
    printf("\nFalha ao abrir arquivo!\n");
    return 0;
  }

  fscanf(arq, "%d", &n); /*lê numero de salas da primeira linha do arquivo*/
  fscanf(arq, "%d", &m); /*lê numero de corredores da segunda linha do arquivo*/

  /*declara matriz e aloca linhas*/
  int ** corredores;
  corredores = malloc( n*sizeof( int * ) );

  /*aloca colunas*/
  for(i = 0; i< n; i++)
  {
    corredores[i] = malloc(2*sizeof(int));
  }

  /*le corredores do arquivo e armazena na matriz*/
  for(i = 0; i < n-1; i++)
  {
    fscanf(arq, "%d %d", &corredores[i][0], &corredores[i][1]);
  }

  imprime_relatorio(n, m, corredores);

  /*declara vetor de ponteiros para Room e aloca memoria para vetor*/
  Room ** salas;
  salas = malloc( n*sizeof(Room *) );

  /*aloca memoria para cada sala e as inicializa*/
  for(i = 0; i< n; i++)
  {
    salas[i] = (Room *) malloc(sizeof(Room));
    inicializa_sala(salas[i]);
  }
  
  /*percorre corredores e salva na lista de cada sala*/
  for(i = 0; i < n-1; i++)
  {
    adiciona_item_fim(salas[corredores[i][0]]->adj, corredores[i][1]);
    adiciona_item_fim(salas[corredores[i][1]]->adj, corredores[i][0]);
  }

  printf("Tabela de adjacencias:\n");
  imprime_tabela(salas, n);

}
