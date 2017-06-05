$ lsb_release -a

No LSB modules are available.
Distributor ID: Ubuntu
Description:    Ubuntu 14.04.5 LTS
Release:        14.04
Codename:       trusty

$ gcc -c labirinto.c
$ gcc cliente.c labirinto.o -o cliente
$ ./cliente labirinto.txt
0 1 4 7 4 1 2 5 8 9