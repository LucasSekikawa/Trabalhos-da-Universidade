#ifndef PROCESSAMENTO_H
#define PROCESSAMENTO_H

#include "estruturas.h"

typedef void (*ModoAnaliseFn)(char **arquivos, int num_arqs, int ini, int fim, int jan, double cap);

void modo_comparacao(char **arquivos, int num_arqs, int ini, int fim, int jan, double cap);
void modo_janela(char **arquivos, int num_arqs, int ini, int fim, int jan, double cap);

#endif
