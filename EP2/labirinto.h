typedef struct item Item;
struct item{
int id;
Item* next;
};

typedef struct room Room;
struct room{
Item* adj;
};

void adiciona_item_fim(Item *, int);
void inicializa_sala(Room *);
void inicializa_lista(Item * i);
void imprime_tabela(Room **, int);
void imprime_relatorio(int, int, int**);
