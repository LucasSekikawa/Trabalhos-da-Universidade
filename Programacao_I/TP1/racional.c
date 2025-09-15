/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo de implementação para TAD racional.
 * Feito em 16/09/2024 para a disciplina CI1001 - Programação 1.
 *
 * Este arquivo deve conter as implementações das funções cujos protótipos
 * foram definidos em racional.h. Neste arquivo também podem ser definidas
 * funções auxiliares para facilitar a implementação daquelas funções.
*/


#include <stdio.h>
#include <stdlib.h>
#include "racional.h"



/* retorna um número aleatório entre min e max, inclusive. */
int aleat (long min, long max)
{
    int resultado;
    resultado = (rand() % (max * 2 + 1)) + min;
    return (resultado);
}

/* Máximo Divisor Comum entre a e b      */
/* calcula o MDC pelo método de Euclides */
long mdc (long a, long b)
{
    if (b == 0)
        return a;
    else
        return mdc(b, a % b);
}

/* Mínimo Múltiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
long mmc (long a, long b)
{
    long resultado;
    resultado = ( ( a * b ) / mdc (a, b) );
    return (resultado);
}

/* Recebe um número racional e o simplifica.
 * Por exemplo, ao receber 10/8 deve retornar 5/4.
 * Se ambos numerador e denominador forem negativos, deve retornar um positivo.
 * Se o denominador for negativo, o sinal deve migrar para o numerador.
 * Se r for inválido, devolve-o sem simplificar. */
struct racional simplifica_r (struct racional r)
{
    int valor_mdc;
    valor_mdc = mdc(r.num, r.den);

    if (valor_mdc < 0)
        valor_mdc *= (-1);

    if (valido_r(r) == 0)
        return (r);

    else
    {
        r.num /= valor_mdc;
        r.den /= valor_mdc;
    }

    if ( r.den < 0 )
    {
       r.num *= -1;
       r.den *= -1;

    }
    return (r);
}


struct racional cria_r (long numerador, long denominador)

{
    struct racional r;

    r.num = numerador;
    r.den = denominador;
    return (r);
}

int valido_r (struct racional r)
{
    if (r.den == 0)
        return (0);
    else
        return(1);
}

struct racional sorteia_r (long min, long max)
{
    long numerador;
    long denominador;

    numerador = aleat(min, max);
    denominador = aleat(min, max);


    return (cria_r(numerador, denominador));
}

void imprime_r (struct racional r)
{
    if ( valido_r(r) == 0 )
    {
        printf("INVALIDO ");
        return;
    }

    if ( r.num == 0 )
    {
        printf("0 ");
        return;
    }

    r = simplifica_r(r);

    if ( r.den == 1)
    {
        printf("%ld ", r.num);
        return;
    }

    if ( r.num == r.den )
    {
        printf("1 ");
        return;
    }


    printf("%ld/%ld ", r.num, r.den);
}

struct racional soma_r (struct racional r1, struct racional r2)
{
    struct racional r_temp;
    int valor_mmc;

    /* Checa se os denominadores sejam iguais,
       caso não seja, calcula o mmc entre eles */
    if (r1.den != r2.den)
    {
        valor_mmc = mmc(r1.den, r2.den);
        r_temp.den = valor_mmc;
        r_temp.num = (valor_mmc / r1.den * r1.num) + (valor_mmc / r2.den * r2.num);
        return (r_temp);
    }
    else
    {
        r_temp.num = r1.num + r2.num;
        r_temp.den = r1.den;
        return (r_temp);
    }

}


struct racional subtrai_r (struct racional r1, struct racional r2)
{
    struct racional r_temp;
    int valor_mmc;

    /* Checa se os denominadores sejam iguais
       caso não sejam, calcula o mmc entre eles */
    if (r1.den != r2.den)
    {
        valor_mmc = mmc(r1.den, r2.den);
        r_temp.den = valor_mmc;
        r_temp.num = (valor_mmc / r1.den * r1.num) - (valor_mmc / r2.den * r2.num);
        return (r_temp);
    }
    else
    {
        r_temp.num = r1.num - r2.num;
        r_temp.den = r1.den;
        return (r_temp);
    }

}
struct racional multiplica_r (struct racional r1, struct racional r2)
{
    struct racional  r_temp;
    r_temp.num = r1.num * r2.num;
    r_temp.den = r1.den * r2.den;
    return (r_temp);
}

struct racional divide_r (struct racional r1, struct racional r2)
{
    struct racional r_temp;
    r_temp.num = r1.num * r2.den;
    r_temp.den = r1.den * r2.num;
    return (r_temp);
}
