#ifndef ESTRUTURAS
#define ESTRUTURAS

#define FORMATO_TAX 1
#define FORMATO_COT 2
#define TAM_DATA 10
#define CAPACIDADE_INICIAL 12

/* Essa struct e feita para armazenar tanto a data (mes e ano) quanto o valor, do que seria cada linha do arquivo */
typedef struct 
{
    char data[7];
    double valor;
} Registro;

/* Essa struct e feita para armazenar os dados gerais de cada arquivo, contendo o nome dele, uma sessao para a struct registro (armazenar a data e o valor), o total de meses, a capacidade maxima, e caso ele seja uma taxa ou cotacao */
typedef struct 
{
    char *nome_arquivo;
    Registro *registros; 
    int total_meses;
    int capacidade;
    int formato; // 1: Taxa; 2: Cotação
} Historico;

#endif