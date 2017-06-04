#include "labirinto.h"
#include <stdio.h>

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

  int corredores[n][2]; /*para armazenar os pares {sala, sala}*/
  Room salas[n];
  for(i = 0; i< n-1; i++)
  {
    inicializa_sala(salas[i]);
  }

  for(i = 0; i < n-1; i++)
  {
    fscanf(arq, "%d %d", &corredores[i][0], &corredores[i][1]);
  }

  for(i = 0; i < n-1; i++) /*percorre corredores*/
  {
    printf("%d %d\n", corredores[i][0], corredores[i][1]);
    adiciona_item_fim(salas[corredores[i][0]].adj, corredores[i][1]);
    //adiciona_item_fim(salas[corredores[i][1]].adj, corredores[i][0]);
  }

}
