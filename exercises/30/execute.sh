#!/bin/bash
for M in 2 3 5 10;
do
	for N in 1000 10000 100000 1000000;
	do
		echo "Salvando a saida de Josephus($N, $M)"
		echo "Saida de Josephus($N, $M) = $(./28 $N $M)"$'\r'  >> saida.txt
	done
done
echo "Fim!"

