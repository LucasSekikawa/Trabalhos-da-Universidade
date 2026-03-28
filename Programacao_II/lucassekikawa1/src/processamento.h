#ifndef PROCESSAMENTO_H
#define PROCESSAMENTO_H

#include "estruturas.h"

// Definimos o tipo do ponteiro de função aqui para ser usado globalmente
typedef void (*ModoAnaliseFn)(char **arquivos, int num_arqs, int ini, int fim, int jan, double cap);

// Protótipos das funções que o main poderá usar
void modo_comparacao(char **arquivos, int num_arqs, int ini, int fim, int jan, double cap);
void modo_janela(char **arquivos, int num_arqs, int ini, int fim, int jan, double cap);

#endif