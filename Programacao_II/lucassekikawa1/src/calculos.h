#ifndef CALCULOS
#define CALCULOS
#include "estruturas.h"

/* Retorna a aplicacao da formula usada para saber o rendimento mensal sob juros compostos */
double calcular_taxa_mensal(double taxa_anual);

/* Faz a distincao se o rendimento a ser calculado e taxa ou cotacao, sendo que a taxa é denotada pelo formato == 1, e a cotacao como formato == 2.
Apos isso, chama a funcao auxiliar (calcular_taxa_mensal) caso seja taxa, ou calcula diretamente o valor caso seja cotacao. Retorna o rendimento final */
double calcular_rendimento(Historico *h, int ini, int fim, double capital_inicial);

/* Faz o calculo geral de cada vez que cada investimento "ganhou" como melhor investimento dentro de cada janela de tempo possivel no periodo solicitado.
Sao criados dois vetores auxiliares para guardar os indices iniciais e finais de acordo com cada ano, isso e feito para caso os documentos comecem em anos diferentes.
Por fim, é alterado no vetor de vitorias quanto cada um ganhou por janelas temporais, levando em conta que a ordem dos elementos segue a mesma ordem dos arquivos lidos inicialmente */
void calculo_janela(Historico **lista_h, int num_arquivos, int tam_janela, double capital_inicial, int ano_inicio, int ano_fim, int *vitorias);


#endif