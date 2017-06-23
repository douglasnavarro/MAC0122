### Descrição das suas ADTS:

1. A estrutura Node define um nó genérico da árvore. Cada nó contém um ponteiro para um nó filho,
na hierarquia inferior, e para um nó irmão, na mesma hierarquia.

Os nós que são arquivos tem seu atributo eh_arquivo igual a 1 e tamanho definido pelo usuário.
Diretórios tem tamanho 0.

2. Sistema operacional usado para compilar o programa:

  douglas@DESKTOP-8L4TJNI:/mnt/c/Users/dougl/Desktop/software/MAC0122$ lsb_release -a
  No LSB modules are available.
  Distributor ID: Ubuntu
  Description:    Ubuntu 14.04.5 LTS
  Release:        14.04
  Codename:       trusty

3. Programa utilizado para compilar: terminal

4.
  $ gcc -c sistema.c -Wall -ansi -pedantic -O2
  $ gcc -o simulador sistema.o cliente.c -Wall -ansi -pedantic -O2
  $ ./simulador
