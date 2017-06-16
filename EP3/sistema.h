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
