Instruções de compilação e uso:

Compilando o rat.o:
$ gcc -c rat.c -o rat.o -Wall -ansi -pedantic -O2

Compilando o ratbetter.o:
$ gcc -c ratbetter.c -o ratbetter.o -Wall -ansi -pedantic -O2

Compilando euler_better, que utiliza ratbetter.o:
$ gcc e.c ratbetter.o -o euler_better -Wall -ansi -pedantic -O2

Exemplo de execução de euler_better:
$./euler_better
Este programa realiza uma aproximacao racional para 'e' (numero de Euler) utilizando a expansao da serie de Taylor.

Insira o numero de aproximacoes n: 6
 1/1 2/1 5/2 8/3 65/24 163/60

Compilando euler, que utiliza rat.o:
$ gcc e.c rat.o -o euler -Wall -ansi -pedantic -O2

Exemplo de execução de euler:
$./euler
Este programa realiza uma aproximacao racional para 'e' (numero de Euler) utilizando a expansao da serie de Taylor.

Insira o numero de aproximacoes n: 6
 1/1 2/1 5/2 32/12 780/288 93888/34560

Compilando sqrt, que utiliza rat.o:
$ gcc sqrt.c rat.o -o sqrt -Wall -ansi -pedantic -O2

Executando sqrt:
$./sqrt

Este programa calcula uma aproximacao racional da raiz quadrada de um numero S utilizando o metodo babilonico. Insira o numero S cuja raiz sera aproximada:25

Insira agora o valor inteiro n>0: 4
Insira agora o numerador do racional x0: 1
Insira agora o denominador do racional x0: 1

O resultado da aproximacao eh:  1412702437376/281681494016

Compilando sqrt_better, que utiliza rat_better.o:
$ gcc sqrt.c ratbetter.o -o sqrt_better -Wall -ansi -pedantic -O2

Executando sqrt_better:
$./sqrt_better
Este programa calcula uma aproximacao racional da raiz quadrada de um numero S utilizando o metodo babilonico. Insira o numero S cuja raiz sera aproximada:25

Insira agora o valor inteiro n>0: 4
Insira agora o numerador do racional x0: 1
Insira agora o denominador do racional x0: 1

O resultado da aproximacao eh:  43112257/8596237

Melhorias obtidas de rat.c para ratbetter.c:

- Melhor legibilidade dos resultados
- Possibilidade de aproximações melhores entre euler e euler_better. Por exemplo, para 20 aproximações a saída de euler é problematica a partir de n = 10:

Este programa realiza uma aproximacao racional para 'e' (numero de Euler) utilizando a expansao da serie de Taylor.

Insira o numero de aproximacoes n: 10
 1/1 2/1 5/2 32/12 780/288 93888/34560 67633920/24883200 340899840000/125411328000 13745206960128000/5056584744960000 = 2,7182787698412698412698412698413

Enquanto euler_better calcula aproximações até n = 14

 8463398743/3113510400 = 2,7182818284467590023145578701134

Isso ocorre porque em determinado momento a representação dos numeros fica impossível, e, apesar de utilizar o printf com a opção %lu, são impressos 0/0 na tela devido ao overflow.