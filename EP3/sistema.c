#include "sistema.h"
#include <stdlib.h>
#include <stdio.h>

Node * cria_diretorio(char* nome)
{
  Node * diretorio      = (Node*)malloc(sizeof(Node));
  diretorio->nome       = nome;
  diretorio->irmao      = NULL;
  diretorio->filho      = NULL;
  diretorio->tamanho    = 0;
  diretorio->eh_arquivo = 0;
  return diretorio;
}

Node * cria_arquivo(char* nome, int tamanho)
{
  Node * arquivo      = (Node*)malloc(sizeof(Node));
  arquivo->nome       = nome;
  arquivo->tamanho    = tamanho;
  arquivo->filho      = NULL;
  arquivo->irmao      = NULL;
  arquivo->eh_arquivo = 1;
  return arquivo;
}

void imprime_filhos(Node* atual){
  int i = 0;
  printf("\n  Arquivos em %s:\n", atual->nome);
  if(atual->filho == NULL)
    printf("\n O diretorio esta vazio!\n");
  else{
    printf("  (%d)  %s\n", i, atual->filho->nome);
  }
}
