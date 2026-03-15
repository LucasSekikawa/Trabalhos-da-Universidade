#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "arquivos.h"
#include "estruturas.h"

double calcular_taxa_mensal(double taxa_anual) {
    return pow(1.0 + taxa_anual, 1.0 / 12.0) - 1.0;
}

double calcular_rendimento(Historico *h, int ini, int fim, double capital_inicial) {
    double capital_atual = capital_inicial;

    // Caso seja taxa
    if (h->formato == FORMATO_TAX) 
    { 
        for (int i = ini; i < fim; i++)
        {
            double taxa_mensal = calcular_taxa_mensal(h->registros[i].valor);
            capital_atual *= (1.0 + taxa_mensal);
        }
    } 
    // Caso seja cotacao
    else 
    { 
        double cotacao_ini = h->registros[ini].valor;
        double M = capital_inicial / cotacao_ini;
        
        double cotacao_fim = h->registros[fim].valor;
        capital_atual = M * cotacao_fim;
    }

    return capital_atual;
}

void calculo_janela(Historico **lista_h, int num_arquivos, int tam_janela, double capital_inicial, int ano_inicio, int ano_fim, int *vitorias) {

    /* Sao criados dois vetores diferentes para armazenar o indice 
    inicial e final de cada arquivo */
    int *indices_ini = malloc(num_arquivos * sizeof(int));
    int *indices_fim = malloc(num_arquivos * sizeof(int));

    for (int j = 0; j < num_arquivos; j++) 
    {
        indices_ini[j] = encontrar_indice_ano(lista_h[j], ano_inicio);
        indices_fim[j] = encontrar_indice_ano(lista_h[j], ano_fim);
    }

    // Determinacao do tempo que sera analisado
    int periodo_meses = (indices_fim[0] + 12) - indices_ini[0];

    /* Loop para testar todas as janelas possiveis no periodo de tempo indicado,
    considerando tambem o tamanho da janela */
    for (int k = 0; k < periodo_meses - tam_janela; k++) 
    {
        // Comeca assumindo o primeiro arquivo da lista como "vencedor" para fazer as comparacoes depois
        int indice_vencedor = 0;
        double maior_valor = calcular_rendimento(lista_h[0], indices_ini[0] + k, indices_ini[0] + k + tam_janela, capital_inicial);
        double maior_retorno = (maior_valor / capital_inicial) - 1.0;

        // Percorre os outros arquivos da lista para encontrar o maior
        for (int j = 1; j < num_arquivos; j++) 
        {
            double valor_atual = calcular_rendimento(lista_h[j], indices_ini[j] + k, indices_ini[j] + k + tam_janela, capital_inicial);
            double retorno_atual = (valor_atual / capital_inicial) - 1.0;

            if (retorno_atual > maior_retorno) 
            {
                maior_retorno = retorno_atual;
                indice_vencedor = j;
            }
        }
        // Aumenta o numero de "vitorias" do investimento vencedor dessa janela
        vitorias[indice_vencedor]++;
    }

    // Liberacao de memoria dos vetores alocados para armazenamento de indices
    free(indices_ini);
    free(indices_fim);
}