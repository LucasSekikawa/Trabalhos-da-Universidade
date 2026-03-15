#ifndef PRINTS
#define PRINTS
#include "estruturas.h"

#define LINHA_SEP "----------------------------------------\n"

/* Responsavel apenas por imprimir o cabecalho da saida de comparacoes */
void impressao_cabecalho(double capital_inicial, int ano_inicio, int ano_fim);

/* Responsavel por imprimir a linha de cada investimento, com seu nome e valor */
void imprimir_linha_comparacao(char *nome_arquivo, double valor_final);

/* Responsavel por fazer a impressao completa da comparacao por janelas temporais */
void impressao_janela(char **arquivos, int *vitorias, int num_arquivos, int tam_janela, int ano_i, int ano_f);

#endif