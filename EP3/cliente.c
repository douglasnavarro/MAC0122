#include <stdio.h>
#include "sistema.h"
#define MAX 100
/* TODO: inclua seus arquivos .h*/

void imprimeDiretorioAtual(char nome[]){
  printf("\n====================================================\n");
  printf("\n  Diretorio atual: %s\n", nome); /* TODO: nome do diretorio atual*/
}

void imprimeOperacoes(int imprimir){
  if(imprimir){
    printf("\n  (1) Criar um diretorio\n");
    printf("  (2) Criar um arquivo\n");
    printf("  (3) Mudar diretorio atual\n");
    printf("  (4) Voltar para o diretorio raiz\n");
    printf("  (5) Imprimir os elementos no diretorio atual\n");
    printf("  (6) Imprimir hierarquia do diretorio atual\n");
    printf("  (7) Calcular o tamanho do diretorio atual\n");
    printf("  (8) Apagar todos os elementos do diretório atual\n");
    printf("  (9) Imprimir/nao imprimir estas instrucoes\n");
    printf("  (0) Sair do programa\n");
    printf("\n  Digite uma operacao: ");
  }
}

void imprimeNomeDiretorio(int imprimir){
  if(imprimir){
    printf("\n  Digite o nome do diretorio: ");
  }
}

void imprimeNomeArquivo(int imprimir){
  if(imprimir){
    printf("\n  Digite o nome do arquivo: ");
  }
}

void imprimeTamanho(int imprimir){
  if(imprimir){
    printf("\n  Digite o tamanho do arquivo: ");
  }
}

void imprimeMudaDiretorio(int imprimir){
  if(imprimir){
    printf("\n  Digite o indice do diretório: ");
  }
}

void leInt(int *v){
    if(scanf("%d", v) != 1){
        printf("Erro de leitura de inteiro\n");
    }
}

void leString(char nome[]){
    if(scanf("%s", nome) != 1){
        printf("Erro de leitura de string\n");
    }
}

void prompt(){

  int operacao;
  int tamanho;
  int imprimir;
  char nome[MAX];
  Node * atual;
  Node * temp;
  imprimir = 1;
  atual = cria_diretorio("ROOT");

  do{

    imprimeDiretorioAtual(atual->nome);
    imprimeOperacoes(imprimir);
    leInt(&operacao);

    switch (operacao){
      case 1:
        imprimeNomeDiretorio(imprimir);
        leString(nome);

        /*o diretorio esta vazio*/
        if (atual->filho == NULL) {
          printf("criado diretorio filho!\n");
          atual->filho = cria_diretorio(nome);
        }

        /*o diretorio ja tem subdiretorios*/

        printf("\n  Diretorio %s criado!\n", nome);
        break;
      case 2:
        imprimeNomeArquivo(imprimir);
        leString(nome);
        imprimeTamanho(imprimir);
        leInt(&tamanho);

        /*o diretorio esta vazio*/
        if (atual->filho == NULL) {
          atual->filho = cria_arquivo(nome, tamanho);
        }

        /*o diretorio ja tem subdiretorios*/
        else{
          temp = atual->filho;
          while (temp->irmao != NULL) {
            temp = temp->irmao;
          }
          temp->irmao = cria_arquivo(nome, tamanho);
        }

        printf("\n  Arquivo %s criado! (%d KB)\n", nome, tamanho);
        break;
      case 3:
        /* TODO: chame aqui sua função de imprimir todos os filhos (operacao 5)*/
        imprimeMudaDiretorio(imprimir);
        leInt(&tamanho);
        /* TODO: chame aqui sua função de atualizar o diretorio atual*/
        printf("\n  Mudou para o diretorio %s!\n", "diretorio atual"); /* TODO: nome do diretorio atual*/
        break;
      case 4:
        /* TODO: atualize o diretorio atual para a raiz*/
        printf("\n  Mudou para o diretorio raiz!\n");
        break;
      case 5:
        imprime_filhos(atual);
        break;
      case 6:
        printf("\n  Hierarquia do diretorio atual:\n\n");
        /* TODO: chame aqui sua função de imprimir todos os descendentes*/
        break;
      case 7:
        /* TODO: chame aqui sua função de calcular o tamanho do diretorio atual*/
        break;
      case 8:
        /* TODO: chame aqui sua funcao que apaga os elementos na subarvore do diretorio atual*/
        printf("\n  Todos os itens do diretorio atual foram removidos!\n");
        break;
      case 9:
        imprimir = !imprimir;
        printf("\n  Variavel imprimir modificada para %d!\n", imprimir);
        break;
      case 0:
        /* TODO: nao faz nada. Apenas espera sair do programa*/
        break;
      default:
        printf("\n  Operacao invalida (%d)!\n", operacao);
        break;
    }
  } while(operacao != 0);
  /* TODO: desaloque aqui os nos restantes antes de encerrar o programa*/
}

int main(){
  prompt();

  return 0;
}
