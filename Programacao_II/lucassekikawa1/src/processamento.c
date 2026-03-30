#include <stdio.h>
#include "estruturas.h"
#include "prints.h"
#include "stdlib.h"
#include "calculos.h"
#include "arquivos.h"

void modo_comparacao(char **arquivos, int num_arquivos, int ano_inicio, int ano_fim, int 
tam_janela, double capital_inicial) 
{
    impressao_cabecalho(capital_inicial, ano_inicio, ano_fim);

        // Calcula e imprime o resultado de cada investimento 
        for (int i = 0; i < num_arquivos; i++) 
        {            
            Historico *h = carregar_arquivo(arquivos[i]);
            
            if (h != NULL) 
            {
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

void modo_janela(char **arquivos, int num_arquivos, int ano_inicio,
     int ano_fim, int tam_janela, double capital_inicial)
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
