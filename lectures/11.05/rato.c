#include <stdio.h>
#include "QUEUE.h"
#define MAX 500;

int main(int argc, char *argv[])
{
  int m, n, **L, i, j, x, lr, cl, lq, cq, y;
  FILE * arq;
  if(argc != 2) /*Chamou errado o programa */
  {
    printf("Insira o nome do arquivo na chamada!\n");
    return 0;
  }
  arq = fopen(argv[1], "r");
  if(arq == NULL) /*arquivo não existe*/
  {
    printf("Arquivo %s não existe!\n", argv[1]);
    return 0;
  }
  fscanf(arq, "%d", &m);
  fscanf(arq, "%d", &n);
  L = malloc(m*sizeof(int*)); /* aloca coluna de linhas */
  for(i = 0; i<m; i++) L[i] = malloc(n*sizeof(int)); /*aloca memoria de cada linha */
  for(i = 0; i<m; i++) /*preenche a matriz com os valores*/
  {
    for(j=0; j<n; j++)
    {
      fscanf(arq, "%d", &x);
      L[i][j] = x;
    }
  }
  fclose(arq);

  do {
    printf("Entre c/ a posição do ratinho: ");
    scanf("%d", &lr);
    scanf("%d", &cr);
  } while(L[lr][cr] == -1); /*Entrada do ratinho */

  do {
    printf("Entre c/ a posição do queijo: ");
    scanf("%d", &lq);
    scanf("%d", &cq);
  } while(L[lq][cq] == -1); /*Entrada do queijo */

  QUEUEinit(7);
  QUEUEput(lq);
  QUEUEput(cq);
  L[lq][cq] = 1;

  while(!QUEUEempty())
  {
    x = QUEUEget();
    y = QUEUEget();
    if( x == lr && y == cr) break; /* Encontrou o rato! */
    if( x-1 >= 0 && L[x-1][y] == 0)
    {
      L[x-1][y] = L[x][y] + 1;
      QUEUEput(x-1);
      QUEUEput(y);
    }
    if( y+1<n && L[x][y+1] == 0) L[x][y+1] = L[x][y] + 1;
    if( x+1 < m && L[x+1][y] == 0) L[x+1][y] = L[x][y] + 1;
    if( y-1 >= 0 && L[x][y-1] == 0) L[x][y-1] = L[x][y] + 1;
  }

  for(i = 0; i<m; i++) /*desaloca memoria*/
  {
    free(L[i]);
    L[i] = NULL;
  }
  free(L);
  L = NULL;
  return 1;
} /*main*/
