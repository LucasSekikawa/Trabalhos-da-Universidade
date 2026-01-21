/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 09/09/2025 para a disciplina CI1001 - Programação 1.
*/


#include <stdio.h>
#include <stdlib.h>
#include "racional.h"


void leVetor(struct racional **vetor, int tam)
{
    int num;
    int den;
    int i;

    for (i=0; i<tam; i++)
    {
        scanf("%d %d", &num, &den);
        vetor[i] = cria_r(num, den);
    }
}



void imprimeVetor(struct racional **vetor, int tam)
{
    int i;    
    
    printf("VETOR = ");

    // Checa se o vetor nao esta vazio
    if (tam > 0)
    {
        for (i=0; i<tam-1; i++)
        {
	    imprime_r(vetor[i]);
        printf(" ");
        }
        imprime_r(vetor[tam-1]);
    }

    printf("\n");
        
}



/* A ideia da funcao e utilizar de duas variaveis,
   uma começando pelo inicio, outra pelo fim do vetor.
   Com isso, a variavel da esquerda percorre o vetor ate achar um invalido,
   quando ele é encontrado, a variavel da direita, busca um elemento valido
   para fazer a substituicao com o valor invalido */

void eliminaInvalidos(struct racional **vetor, int *tam)
{
    int i = 0; 
    int j = *tam - 1; 

    // Loop roda enquanto i estiver a esquerda de j    
    while (i <= j)
    {
        // Caso seja válido, i apenas avanca uma posicao
        if (valido_r(vetor[i]))
        {
            i++;
        }
        else
        {
            // Caso contrario, comeca a busca por um valido em vetor[j]
            
            // Se o elemento for invalido, ele é destruido, e j avança uma posicao a esquerda 
            if (!valido_r(vetor[j]))
            {
                destroi_r(&vetor[j]);
                j--;
            }
            // Se o elemento for valido, ocorre uma troca de vetor[j] pelo invalido de vetor[i]
            else
            {
                // Destroi o elemento invalido vetor[i]
                destroi_r(&vetor[i]); 
                
                // A posicao i recebo o valor de vetor[j]
                vetor[i] = vetor[j];
                vetor[j] = NULL; 

                i++;
                j--;
            }
        }
    }

    // Por fim atualiza o tamanho do vetor com apenas os elementos validos
    *tam = j + 1;
} 
	


// Algoritmo usado no QuickSort para colocar o pivo na posicao central do vetor
void particao (struct racional **vetor, int esq, int dir, int *pos_pivo) 
{ 
        int i; 
        int j; 
        struct racional *pivo; 
        struct racional *aux; 
 
        // Comeca assumindo o pivo como o primeiro elemento do vetor
        pivo = vetor[esq]; 
        i = esq; 
        j = dir; 
 
        // Enquanto a variavel da esquerda for menor que a da direita
        while (i < j) 
        {  
                // Mantem somando i enquanto i for menor ou igual que o pivo, e i for menor que a direita 
                while ( ( compara_r(vetor[i], pivo) <= 0 ) && (i < dir) ) 
                        i++; 

                // Mantem subtraindo j enquanto j for maior ou igual que o pivo, e j for maior que esquerda
                while ( (compara_r(vetor[j], pivo) >= 0) && (j > esq) ) 
                        j--; 

                /* Apos ambos loops, caso i esteja a esquerda de j, ou seja, eles nao forem iguais,
                   ocorrera uma troca de ambos os valores, pois vetor[i] > pivo e vetor[j] < pivo */
                if ( i < j ) 
                { 
                        aux = vetor[j]; 
                        vetor[j] = vetor[i]; 
                        vetor[i] = aux; 
                } 
        } 
 

        // Por fim, ocorre a troca do pivo com vetor[j], sendo j a ultima posicao dos elementos menores que pivo
        aux = vetor[esq]; 
        vetor[esq] = vetor[j]; 
        vetor[j] = aux;

        // A posicao do pivo e alterada para seu local
        *pos_pivo = j; 
}



// Foi usado o algoritmo de QuickSort de forma recursiva
void ordenaVetor (struct racional **vetor, int esq, int dir)
{
	int pos_pivo;

	if (esq < dir)
	{
		particao(vetor, esq, dir, &pos_pivo);
		ordenaVetor(vetor, esq, pos_pivo-1);
		ordenaVetor(vetor, pos_pivo+1, dir);
	}
}



// A funcao retorna um ponteiro para o resultado da soma total dos valores do vetor
struct racional *somaVetor (  struct racional **vetor, int tam )
{
    struct racional *soma = cria_r (0, 1);
    struct racional *aux = cria_r (0, 1);

    // Caso um dos ponteiros temporarios estejam vazios, destroi ambos e retorna NULL
    if ( (soma == NULL) || (aux == NULL) )
    {
        destroi_r(&soma);
        destroi_r(&aux);
        return NULL;
    }

    /* Percorre o vetor usando aux como variavel auxiliar da operacao
       aux guarda o resultado da soma, e a soma pega o valor de aux para a proxima operacao */
    for (int i = 0; i < tam; i++)
    {
        soma_r (soma, vetor[i], aux);

        // Ponteiro de racional temporario criado para troca de soma com aux
        struct racional *troca = soma;
        soma = aux;
        aux = troca;
    }

    // Destroi o ponteiro auxiliar e retorna o ponteiro da soma final
    destroi_r(&aux);
    return soma;
    
    
}



void liberaElementosVetor(struct racional **vetor, int tam)
{
    int i;
    
    // Caso o vetor nao esteja apontando para nada, destroi os ponteiros que estao nele
        for(i=0; i<tam; i++)
            destroi_r(&vetor[i]);
}



/* programa principal */
int main ()
{
    int n;
    struct racional **vetor;
    struct racional *resultado_soma_ptr;

    scanf("%d", &n);

    // Checa se n esta nos limites determinados
    if ( (n <= 0) || (n >= 100) )
	return 0;

    /* Alocacao de memoria para os N ponteiros dentro do vetor
       Caso o vetor nao aponte para nada, retorna 1 */ 
    vetor = malloc(sizeof(struct racional *) * n);
    if (vetor == NULL)
        return 0;

    leVetor(vetor, n);
    imprimeVetor(vetor, n);

    eliminaInvalidos(vetor, &n);
    imprimeVetor(vetor, n);

    ordenaVetor(vetor, 0, n-1 );
    imprimeVetor(vetor, n);
    
    // Criacao do ponteiro para o valor da soma dos elementos do vetor e sua impressao
    resultado_soma_ptr = somaVetor(vetor, n);
    printf("SOMA = ");
    imprime_r(resultado_soma_ptr);    
    printf("\n");

    // Libera o espaco de todos os ponteiros que estao dentro do vetor    
    liberaElementosVetor(vetor, n);
    imprimeVetor(vetor, n);

    // Libera o espaco do ponteiro usado para armazenar a soma e o aponta para NULL
    destroi_r(&resultado_soma_ptr);

    // Libera o espaco do ponteiro do vetor
    free(vetor);
    vetor = NULL;

    return 0;
}

