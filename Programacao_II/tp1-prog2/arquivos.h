#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "estruturas.h"

#define PASTA_DADOS "Documentos/"   
#define EXTENSAO_PADRAO ".txt"       
#define TAM_MAX_CAMINHO 150          
#define TAM_VALOR 50          
#define FATOR_CRESCIMENTO 2            

/* Inverte a ordem dos dados, visto que nos arquivos estao em ordem decrescente,
ou seja, do mais recente para o mais antigo, a inversao e feita para facilitar os calculos e a manipulacao dos dados */
void inverter_historico(Historico *h);

/* Recebe o nome do arquivo a ser lido e depois completa o caminho do documento. Depois, atribui todos os valores para a struct Historico que sera retornada */
Historico* carregar_arquivo(char *nome_arq);

/* Faz a leitura de cada linha do documento, separando em strings diferentes, uma para a data do mes/ano, e outra para o valor. Apos isso, e feita a conversao do valor para float, para facilitar a manipulacao dos numeros e para futuros calculos.
Tambem e responsavel por aumentar a capacidade maxima de elementos dentro da estrutura Historico recebida, fazendo isso com realacocao de memoria */
void leitura_linhas(FILE *arquivo, Historico* h);

/* Encontra o indice para o primeiro mes do ano recebido pelo parametro, retorna o indice caso tenha encontrado, e -1 caso o ano nao esteja dentro do documento */
int encontrar_indice_ano(Historico *h, int ano_alvo);


#endif