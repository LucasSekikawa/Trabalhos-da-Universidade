#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estruturas.h"
#include "arquivos.h"
#include "calculos.h"
#include "prints.h"

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
    // Checa se a entrada pede a comparacao por janela temporal
    if (tam_janela > TAMANHO_PADRAO_JANELA)
    {
        // Cria um vetor do tipo Historico para os arquivos lidos
        Historico **lista_h = malloc(num_arquivos * sizeof(Historico *));

        // Vetor para armazenar a "vitoria" de cada investimento por janela
        int *vitorias = calloc(num_arquivos, sizeof(int));

        // Leitura dos arquivos
        for (int i=0; i<num_arquivos; i++)
            lista_h[i] = carregar_arquivo(arquivos[i]);
        
        // Calcula quantas janelas cada investimento "ganhou"
        calculo_janela(lista_h, num_arquivos, tam_janela, capital_inicial, ano_inicio, ano_fim, vitorias);

        impressao_janela(arquivos, vitorias, num_arquivos, tam_janela, ano_inicio, ano_fim);
        
        // Liberacao a memoria alocada
        for (int i = 0; i < num_arquivos; i++) 
        {
            free(lista_h[i]->nome_arquivo);
            free(lista_h[i]->registros);
            free(lista_h[i]);
        }
        free(lista_h);
        free(vitorias);
    }
    else
    {
        impressao_cabecalho(capital_inicial, ano_inicio, ano_fim);

        // Calcula e imprime o resultado de cada investimento 
        for (int i = 0; i < num_arquivos; i++) 
        {            
            Historico *h = carregar_arquivo(arquivos[i]);
            
            if (h != NULL) {
                // Localiza os índices baseados nas flags -i e -f
                int indice_ini = encontrar_indice_ano(h, ano_inicio);
                int indice_fim = encontrar_indice_ano(h, ano_fim);

                // Checa se o intervalo existe no arquivo
                if (indice_ini != -1 && indice_fim != -1) 
                {             
                    double valor_final = calcular_rendimento(h, indice_ini, indice_fim + 11, capital_inicial);

                    imprimir_linha_comparacao(arquivos[i], valor_final);               
                } 
                else 
                    printf("Intervalo de anos nao encontrado neste arquivo.\n");
                
                // Libera a memoria alocada
                free(h->nome_arquivo);
                free(h->registros);
                free(h);

            } 
            else 
                printf("Erro ao carregar o arquivo %s\n", arquivos[i]);
        }
        printf(LINHA_SEP);

    }
    // Limpeza final do vetor de strings de nomes de arquivos
    free(arquivos); 

    return 0;
}