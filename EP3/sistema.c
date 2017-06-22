#include "sistema.h"

Node * cria_diretorio(char* nome)
{
  Node * diretorio      = (Node*)malloc(sizeof(Node));
  diretorio->nome       = (char*)malloc(MAX*sizeof(char));
  strcpy(diretorio->nome, nome);
  diretorio->irmao      = NULL;
  diretorio->filho      = NULL;
  diretorio->tamanho    = 0;
  diretorio->eh_arquivo = 0;
  return diretorio;
}

Node * cria_arquivo(char* nome, int tamanho)
{
  Node * arquivo      = (Node*)malloc(sizeof(Node));
  arquivo->nome       = (char*)malloc(MAX*sizeof(char));
  strcpy(arquivo->nome, nome);
  arquivo->tamanho    = tamanho;
  arquivo->filho      = NULL;
  arquivo->irmao      = NULL;
  arquivo->eh_arquivo = 1;
  return arquivo;
}

void imprime_filhos(Node* atual)
{
  int i = 0;
  Node* temp;

  if(atual->filho == NULL)
    printf("\n  Diretorio vazio!\n");
  else{
    temp = atual->filho;
    if(temp->eh_arquivo == 0)
      printf("  (%d)  %s\n", i, temp->nome);
    else
      printf("  (%d)  %s (%d KB)\n", i, temp->nome, temp->tamanho);
    i++;
    while (temp->irmao != NULL) {
      if(temp->irmao->eh_arquivo == 0)
        printf("  (%d)  %s\n", i, temp->irmao->nome);
      else
        printf("  (%d)  %s (%d KB)\n", i, temp->irmao->nome, temp->irmao->tamanho);
      temp = temp->irmao;
      i++;
    }
  }
}

Node * muda_diretorio(int indice, Node* atual)
{
  int i = 0;
  Node* temp;
  temp = atual->filho;
  if(i == indice)
    return temp;
  while (temp->irmao != NULL) {
    temp = temp->irmao;
    i++;
    if(i == indice)
      return temp;
  }
}

void imprime_descendentes(Node* atual, int espacos)
{
  if(atual == NULL)
    return;

  if(atual->eh_arquivo == 0)
  {
    printf("%*c", espacos, ' ');
    printf("%s\n", atual->nome);
  }

  else
  {
    printf("%*c", espacos, ' ');
    printf("%s (%d KB)\n", atual->nome, atual->tamanho);
  }

  if(atual->irmao != NULL)
  {
    imprime_descendentes(atual->filho, espacos + 2);
    imprime_descendentes(atual->irmao, espacos);
  }

  else
    imprime_descendentes(atual->filho, espacos + 2);
}
