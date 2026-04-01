#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "arquivos.h"
#include "estruturas.h"
#include "prints.h"

void impressao_cabecalho(double capital_inicial, int ano_inicio, int ano_fim)
{
    printf(LINHA_SEP);
    printf("Período: Janeiro %d a Dezembro %d\n", ano_inicio, ano_fim);
    printf("Capital Inicial: R$ %.2f\n\n", capital_inicial);
}

void imprimir_linha_comparacao(char *nome_arquivo, double valor_final) {
    // String auxiliar para escrever o nome do investimento
    char nome[50];
    
    // Copia o nome do arquivo para uma string auxiliar
    strcpy(nome, nome_arquivo);

    // Procura a primeira aparicao de um '.' e substitui por '\0'
    char *ponto = strchr(nome, '.');
    if (ponto != NULL) 
        *ponto = '\0';

    // Converte a primeira letra para maiuscula
    nome[0] = toupper(nome[0]);

    // Imprime ate o '\0'
    printf("%s: R$ %.2f\n", nome, valor_final);
}

void impressao_janela(char **arquivos, int *vitorias, int num_arquivos, int tam_janela, int ano_ini, int ano_fim) {
    
    printf("----------------------------------------\n");
    printf("Período: Janeiro %d a Dezembro %d\n", ano_ini, ano_fim);
    printf("Tamanho da janela: %d meses\n\n", tam_janela);

    for (int i = 0; i < num_arquivos; i++) 
    {
        // String auxiliar para escrever o nome do investimento
        char nome[30];
    
        // Tratamento da string para escrever ate o primeiro '.'
        strcpy(nome, arquivos[i]);
        char *ponto = strchr(nome, '.');
        if (ponto != NULL) 
            *ponto = '\0'; 
        nome[0] = toupper(nome[0]);

        printf("%s: %d janelas\n", nome, vitorias[i]);
    }
    printf("----------------------------------------\n");
}