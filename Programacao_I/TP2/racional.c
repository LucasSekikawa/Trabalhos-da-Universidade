/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo de implementação para TAD racional.
 * Feito em 20/09/2024 para a disciplina CI1001 - Programação 1.
 *
 * Este arquivo deve conter as implementações das funções cujos protótipos
 * foram definidos em racional.h. Neste arquivo também podem ser definidas
 * funções auxiliares para facilitar a implementação daquelas funções.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

/*
 * Implemente aqui as funcoes definidas no racionais.h; caso precise,
 * pode definir aqui funcoes auxiliares adicionais, que devem ser usadas
 * somente neste arquivo.
*/

/* retorna um número aleatório entre min e max, inclusive. */
long aleat (long min, long max)
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

    if (valido_r(r) == 0)
        return (r);

    valor_mdc = mdc(r.num, r.den);
    if (valor_mdc < 0)
        valor_mdc *= (-1);


    r.num /= valor_mdc;
    r.den /= valor_mdc;    

    if ( r.den < 0 )
    {
       r.num *= -1;
       r.den *= -1;

    }
    return (r);
}


long numerador_r (struct racional r)
{
    return r.num;
}


long denominador_r (struct racional r)
{
    return r.den;
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
    if ( r.den == 0 )
        return 0;
    return 1;
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
        printf(" NaN");
        return;
    }

    if ( r.num == 0 )
    {
        printf(" 0");
        return;
    }

    r = simplifica_r(r);

    if ( r.den == 1)
    {
        printf(" %ld", r.num);
        return;
    }

    if ( r.num == r.den )
    {
        printf(" 1");
        return;
    }


    printf(" %ld/%ld", r.num, r.den);
}

   
int compara_r (struct racional r1, struct racional r2)
{
    long num1;
    long num2; 

    if ( (valido_r(r1) == 0) || (valido_r(r2) == 0) )
        return -2;
    
    r1 = simplifica_r(r1);
    r2 = simplifica_r(r2);

    num1 = r1.num * r2.den;
    num2 = r2.num * r1.den;

    if ( num1 < num2 )
        return -1;

    if ( num1 == num2 )
        return 0;

    return 1;
}


int soma_r (struct racional r1, struct racional r2, struct racional *r3)
{
    if ( (valido_r(r1) == 0) || (valido_r(r2) == 0) )
        return 0;

    
    int valor_mmc;

    if (r1.den != r2.den)
    {
        valor_mmc = mmc(r1.den, r2.den);
        r3 -> den  = valor_mmc;
        r3 -> num  = (valor_mmc / r1.den * r1.num) + (valor_mmc / r2.den * r2.num);
    }
    else
    {
        r3 -> num = r1.num + r2.num;
        r3 -> den = r1.den;
    }

    if ( valido_r(*r3) == 0 )
        return 0;

    *r3 = simplifica_r(*r3);

    return 1;
}


int subtrai_r (struct racional r1, struct racional r2, struct racional *r3)
{
    if ( (valido_r(r1) == 0) || (valido_r(r2) == 0) )
        return 0;


    long valor_mmc;

    if (r1.den != r2.den)
    {
        valor_mmc = mmc(r1.den, r2.den);
        r3 -> den  = valor_mmc;
        r3 -> num  = (valor_mmc / r1.den * r1.num) - (valor_mmc / r2.den * r2.num);
    }
    else
    {
        r3 -> num = r1.num - r2.num;
        r3 -> den = r1.den;
    }

    if ( valido_r(*r3) == 0 )
        return 0;

    *r3 = simplifica_r(*r3);

    return 1;
}

int multiplica_r (struct racional r1, struct racional r2, struct racional *r3)
{
    if ( (valido_r(r1) == 0) || (valido_r(r2) == 0) )
        return 0;

    r3 -> num = r1.num * r2.num;
    r3 -> den = r1.den * r2.den;

    if ((valido_r(*r3) == 0) || ( r3->num == 0))
        return 0;

    *r3 = simplifica_r(*r3);

    return 1;
}


int divide_r (struct racional r1, struct racional r2, struct racional *r3)
{
    if ( (valido_r(r1) == 0) || (valido_r(r2) == 0) )
        return 0;

    r3 -> num = r1.num * r2.den;
    r3 -> den = r1.den * r2.num;

    if ((valido_r(*r3) == 0) || ( (r3->num) == 0))
        return 0;

    *r3 = simplifica_r(*r3);

    return 1;
}






































































