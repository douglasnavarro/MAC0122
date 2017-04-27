void STACKinit(int);
int STACKempty();
void STACKpush(int);
int STACKpop();
int *_Pilha;
int _topo;

typedef struct node * Link;

struct node
{
  int info;
  Link prox;
};

Link _topo;
