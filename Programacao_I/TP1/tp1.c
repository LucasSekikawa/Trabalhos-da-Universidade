#include <stdlib.h>
#include "racional.h"

int main ()
{
    srand(0);

    int n;
    int max;
    int i;

    struct racional r1;
    struct racional r2;
    struct racional soma;
    struct racional subtracao;
    struct racional multiplicacao;
    struct racional divisao;

    scanf("%d", &n);
    scanf("%d", &max);

    /* Checa se os intervalos de leitura sao respeitados,
     * caso algum deles nao seja, o programa eh encerrado. */
    if ( ((n <= 0) || (n >= 100)) || ((max <= 0) || (max >= 30)) )
        return(1);


    for(i=1; i <= n; i++)
    {
        /* Imprime o numero da iteraçao */
        printf("%d: ", i);

        /* Sorteia os numeros racionais dentro do intervalo estabelecido */
        r1 = sorteia_r(-max, max);
        r2 = sorteia_r(-max, max);

        /* Imprime os dois valores sorteados */
        imprime_r(r1);
        imprime_r(r2);

        /* Checa se r1 ou r2 sao numeros invalidos, caso algum deles seja, encerra o loop */
        if ( (valido_r(r1) == 0) || (valido_r(r2) == 0) )
        {
            printf("NUMERO INVALIDO\n");
            return(1);
        }
        else
        {
            /* Calculo das operacoes */
            soma = soma_r(r1, r2);
            subtracao = subtrai_r(r1, r2);
            multiplicacao = multiplica_r(r1, r2);
            divisao = divide_r(r1, r2);

            /* Checa se a divisao eh invalida, caso seja, encerra o loop */
            if (valido_r(divisao) == 0)
            {
                printf("DIVISAO INVALIDA\n");
                return(1);
            }

            /* Impressao dos resultados */
            imprime_r( soma );
            imprime_r( subtracao );
            imprime_r( multiplicacao );
            imprime_r( divisao );
        }
        printf("\n");
    }

    return (0) ;
}
