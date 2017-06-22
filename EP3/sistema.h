#ifndef _SISTEMAH_
#define _SISTEMAH_
#define MAX 100
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node Node;
struct node{
  Node* irmao;
  Node* filho;
  int tamanho;
  char* nome;
  int eh_arquivo;
};

Node * cria_diretorio(char*);
Node * cria_arquivo(char*, int);
void   imprime_filhos(Node*);
Node * muda_diretorio(int, Node*);
void imprime_descendentes(Node*, int);

#endif
