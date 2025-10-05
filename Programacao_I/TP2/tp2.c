/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 24/09/2024 para a disciplina CI1001 - Programação 1.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include "racional.h"


/* Funções auxiliares */


/* Le N valores de racionais e os insere no vetor */
void le_vetor(struct racional vetor[], int tam)
{
    int i;
    int num;
    int den;

    for(i=0; i<tam; i++)
    {
        scanf("%d %d", &num, &den);
        vetor[i] = cria_r(num, den);
    }
}

/* Imprime todos os N valores racionais do vetor */
/* Valores inválidos serão impressos como NaN */
void imprime_vetor(struct racional vetor[], int tam)
{
    int i;
    
    printf("VETOR =");
    for(i=0; i<tam; i++)
        imprime_r(vetor[i]);
    printf("\n");
}


void elimina_invalidos(struct racional vetor[], int *tam)
{
    int i;
    int j;

    j = 0;

    /* Faz um looping de verificação em todos valores do vetor 
     * São usados dois ponteiros, i percorre o vetor, j reescreve os racionais válidos
     * Ou seja, se vetor[i] for válido, é reescrito em vetor[j] e aumenta uma unidade em j
     * No final do looping valores inválidos não serão reescritos
     * E o valor de j será o tamanho final do vetor, com apenas valores válidos */
    for(i=0; i<*tam; i++)
    {
        if (valido_r(vetor[i]) == 1)
        {
            vetor[j] = vetor[i];
            j++;            
        }
    }
    
    *tam = j;   
}

void ordena_vetor(struct racional vetor[], int tam)
{
    int i;
    int j;
    int menor_valor;
    struct racional aux;
    
    /* É usado o algoritmo de Selection Sort
     * Percorre o vetor e procura o seu menor valor na parte desordenada
     * Troca o menor valor pela primeira posição dos racionais desordenados */
    for(i=0; i<tam-1; i++)
    {
        menor_valor = i;

        for (j=i+1; j<tam; j++)
        {
            if (compara_r(vetor[j], vetor[menor_valor]) == -1)
                menor_valor = j;
        }
        
        if (menor_valor != i)
        {
            aux = vetor[i];
            vetor[i] = vetor[menor_valor];
            vetor[menor_valor] = aux;
        }
    }
    

}

struct racional soma_vetor(struct racional vetor[], int tam)
{
    int i;
    struct racional soma_acumulada;
    
    /* Caso o vetor esteja zerado, retorna o racional 0/1 */
    if(tam == 0)
    {
        soma_acumulada.num = 0;
        soma_acumulada.den = 1;
        return soma_acumulada;
    }
    
    /* Define inicialmente a soma acumulada como o primeiro racional do vetor */
    soma_acumulada.num = vetor[0].num;
    soma_acumulada.den = vetor[0].den;

    /* Soma o valor atual de soma_acumulada com o elemento i do vetor */
    /* O resultado é armazenado no endereço de soma_acumulada */
    for (i=1; i < tam; i++)
    {
        soma_r(soma_acumulada, vetor[i], &soma_acumulada);
    }
    
    return soma_acumulada;
}

void imprime_soma(struct racional soma_total)
{
    printf("SOMA =");
    imprime_r(soma_total);
    printf("\n");
}






/* programa principal */
int main ()
{
    struct racional vetor[99];
    struct racional soma_total;
    int n;

    scanf("%d", &n);
    if ( (n <= 0) || (n >= 100) )
        return 0;

    le_vetor(vetor, n);
    imprime_vetor(vetor, n);

    elimina_invalidos(vetor, &n);
    imprime_vetor(vetor, n);

    ordena_vetor(vetor, n);
    imprime_vetor(vetor, n);

    soma_total = soma_vetor(vetor, n);
    imprime_soma(soma_total);


  return (0) ;
}
