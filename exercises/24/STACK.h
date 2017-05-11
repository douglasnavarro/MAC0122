/*

| | | | | | | | | | | | | | |
pilha 0 ->       1 <- pilha 1

2 tipos
1 vetor

*/

int *_Pilha;
int _topo[2];
int _tam_vetor;
void STACKinit(int);
void STACKpush( int x, int pilha);
int STACKpop(int pilha);
int STACKempty(int pilha);
int STACKtop(int pilha);
