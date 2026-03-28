#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estruturas.h"
#include "arquivos.h"
#include "calculos.h"
#include "prints.h"
#include "processamento.h"

#define ANO_PADRAO_INICIO 2000
#define ANO_PADRAO_FIM 2025
#define CAPITAL_PADRAO 1000.0
#define TAMANHO_PADRAO_JANELA 0
#define CAP_INICIAL_ARQUIVOS 4
#define TAXA_CRESCIMENTO 2

int main (int tam_arg, char *vetor_arg[]) {

    // Valores padroes de entrada
    int ano_inicio = ANO_PADRAO_INICIO; 
    int ano_fim = ANO_PADRAO_FIM;
    int tam_janela = TAMANHO_PADRAO_JANELA;
    double capital_inicial = CAPITAL_PADRAO;

    // Iniciar a capacidade do vetor de arquivos em 4
    int cap_arquivos = CAP_INICIAL_ARQUIVOS;
    int num_arquivos = 0;
    char **arquivos = malloc(cap_arquivos * sizeof(char *));

    // Ponteiro para funcao para decidir qual sera o modo do programa que sera executado
    void (*analise_funcao)(char **, int, int, int, int, double) = NULL;

    if (arquivos == NULL) 
    {
        printf("Erro na alocacao\n");
        return 1;
    }

    /* Checagem de flags e leitura de dados.
    Aqui os dados sao convertidos de string para seus tipos,
    para facilitar a manipulacao deles futuramente */
    for (int i=1; i<tam_arg; i++)
    {
        if (strcmp(vetor_arg[i], "-c") == 0)
        {
            i++;
            capital_inicial = atof(vetor_arg[i]);
        }
        else if (strcmp(vetor_arg[i], "-i") == 0)
        {
            i++;
            ano_inicio = atoi(vetor_arg[i]);
        }
        else if (strcmp(vetor_arg[i], "-f") == 0)
        {
            i++;
            ano_fim = atoi(vetor_arg[i]);
        }
        else if (strcmp(vetor_arg[i], "-w") == 0)
        {
            i++;
            tam_janela = atoi(vetor_arg[i]);
        }
        // Se chegar nesse else é porque a string lida é um arquivo 
        else
        {
            // Testa se a capacidade maxima de arquivos foi atingida
            if (num_arquivos == cap_arquivos)
            {
                // Dobra a capacidade do vetor dinamicamente
                cap_arquivos *= TAXA_CRESCIMENTO;
                char **temp = realloc(arquivos, cap_arquivos * sizeof(char*));
                if (temp == NULL)
                {
                    free(arquivos); 
                    return 1;
                }
                arquivos = temp;
            }
            // Adiciona o arquivo lido para um vetor apenas de strings de arquivos
            arquivos[num_arquivos] = vetor_arg[i];
            num_arquivos++;
        }
        
    }
    // Checa se a entrada pede a comparacao por janela temporal ou nao
    if (tam_janela > 0) 
        analise_funcao = modo_janela;
    else 
        analise_funcao = modo_comparacao;
    

    if (analise_funcao != NULL) 
        analise_funcao(arquivos, num_arquivos, ano_inicio, ano_fim, tam_janela, capital_inicial);

    // Limpeza final do vetor de strings de nomes de arquivos
    free(arquivos); 

    return 0;
}