#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"


// Inversao da ordem dos dados
void inverter_historico(Historico *h) {
    int inicio = 0;
    int fim = h->total_meses - 1;
    Registro temp;

    while (inicio < fim) {
        temp = h->registros[inicio];
        h->registros[inicio] = h->registros[fim];
        h->registros[fim] = temp;

        inicio++;
        fim--;
    }
}

Historico* carregar_arquivo(char *nome_arq)
{
    // Tratamento da string lida para o caminho que sera lido por fopen
    char pasta[] = PASTA_DADOS; 
    char sufixo[] = EXTENSAO_PADRAO;
    char caminho_arq[TAM_MAX_CAMINHO];
    
    strcpy(caminho_arq, pasta);
    strcat(caminho_arq, nome_arq);
    strcat(caminho_arq, sufixo);

    FILE *arquivo = fopen (caminho_arq, "r");

    if (arquivo == NULL)
    {
        printf("Não possível abrir o arquivo, verifique o caminho: ");
        return NULL;
    }

    // Atribuicao dos valores da struct historico para cada arquivo lido
    Historico *h = malloc(sizeof(Historico));
    h->nome_arquivo = strdup(caminho_arq);
    h->total_meses = 0;
    h->capacidade = CAPACIDADE_INICIAL;
    h->registros = malloc(h->capacidade * sizeof(Registro));

    if (strstr(caminho_arq, ".tax"))
        h->formato = FORMATO_TAX;
    else    
        h->formato = FORMATO_COT;

    // Le todas as linhas do documento
    leitura_linhas(arquivo, h);

    // Inverte a ordem dos valores
    inverter_historico(h);

    fclose(arquivo);
    return h;
}

void leitura_linhas(FILE *arquivo, Historico* h)
{
    char valor[TAM_VALOR];

    // Separa a linha em duas strings, uma para a data, outra o valor
    while (fscanf(arquivo, "%s %s", h->registros[h->total_meses].data, valor) == 2) {
        
        // A string do valor precisa ser tratada, vista o "." e a ","
        for (int i = 0; valor[i] != '\0'; i++) 
        {
            // Caso seja um ponto, sera feita a remocao dele
            if (valor[i] == '.') 
            {
                for (int k = i; valor[k] != '\0'; k++)
                    valor[k] = valor[k+1];
                i--;
            } 
            else if (valor[i] == ',') 
                // Se for virgula, vira ponto (para ser tratado como decimal)
                valor[i] = '.';
            
        }

        // Conversao do valor de string para float
        h->registros[h->total_meses].valor = atof(valor);

        // Cada linha é um mes, logo o valor deve ser atualizado
        h->total_meses++;

        // Checa se o tamanho maximo de meses foi atingido, caso tenha sido, dobra seu tamanho
        if (h->total_meses == h->capacidade) 
        {
            h->capacidade *= 2;
            Registro *temp = realloc(h->registros, h->capacidade * sizeof(Registro));
            if (temp == NULL) 
            {
                printf("Erro na alocacao de memoria");
                exit(1);
            }
            // Atribui o valor da variavel temporaria para o valor real
            h->registros = temp;
        }
    }
}



int encontrar_indice_ano(Historico *h, int ano_alvo) {
    // Separa os dois ultimos digitos do ano
    int ano = ano_alvo % 100; 

    for (int i = 0; i < h->total_meses; i++) 
    {
        // ptr_ano aponta para o primeiro dos dois ultimos digitos
        char *ptr_ano = h->registros[i].data + (strlen(h->registros[i].data) - 2);

        int ano_registro = atoi(ptr_ano);

        if (ano_registro == ano) 
            return i; 
    
    }
    // Retorna -1 caso o ano nao seja encontrado
    return -1; 
}