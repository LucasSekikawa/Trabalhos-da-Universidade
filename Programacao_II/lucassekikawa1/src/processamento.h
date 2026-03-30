#ifndef PROCESSAMENTO_H
#define PROCESSAMENTO_H

#include "estruturas.h"

void modo_comparacao(char **arquivos, int num_arqs, int ini, int fim, int jan, double cap);

/* Caso haja -w na entrada do programa, essa sera a funcao chamada, ela é a estrutura principal
   do caso de calculo de janelas temporais. 
   Recebe o vetor de arquivos, seu tamanho, os anos de inicio e fim, o tamanho da janela, e o capital inicial
   Fará todo o processo, desde chamada de funcoes auxiliares para realizar os calculos, quanto
   as impressoes e liberacao de memoria. */
void modo_janela(char **arquivos, int num_arqs, int ini, int fim, int jan, double cap);

#endif
