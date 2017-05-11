#!/bin/bash

echo "(i)   ./cliente E*A*S*Y* retorna $(./cliente E*A*S*Y*)" 2>&1 | tee -a saida.txt
echo "(ii)  ./cliente EASY**** retorna $(./cliente EASY****)" 2>&1 | tee -a saida.txt 
echo "(iii) ./cliente EA*S*Y** retorna $(./cliente EA*S*Y**)" 2>&1 | tee -a saida.txt
echo "(iv)  é impossível desempilhar esta sequencia porque a sequencia E A S Y impossibilita desempilhar o E antes do S." 2>&1 | tee -a saida.txt
