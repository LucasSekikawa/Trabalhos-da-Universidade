/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo de implementação para TAD racional.
 * Feito em 20/09/2024 para a disciplina CI1001 - Programação 1.
 * Atualizado em 09/09/2025 para a disciplina CI1001 - Programação 1.
 *
 * Este arquivo deve conter as implementações das funções cujos protótipos
 * foram definidos em racional.h. Neste arquivo também podem ser definidas
 * funções auxiliares para facilitar a implementação daquelas funções.
*/


#include <stdio.h>
#include <stdlib.h>

/* aqui vem a struct racional propriamente dita, nao modifique! */
struct racional {
  long num;          /* numerador   */
  long den;          /* denominador */
};



/* Maximo Divisor Comum entre a e b      */
/* calcula o mdc pelo metodo de Euclides */
long mdc (long a, long b)
{
    if (b == 0)
        return a;
    return mdc(b, a % b);
}


/* Minimo Multiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
long mmc (long a, long b)
{
    long resultado;
    resultado = ( ( a * b ) / mdc (a, b) );
    return (resultado);

}


int valido_r(struct racional *r)
{
    if ( ( r == NULL ) || ( r->den == 0) )
    	return 0;
    return 1;
}

/* Simplifica o número racional indicado no parâmetro.
 * Por exemplo, se o número for 10/8 muda para 5/4.
 * Retorna 1 em sucesso e 0 se r for inválido ou o ponteiro for nulo.
 * Se ambos numerador e denominador forem negativos, o resultado é positivo.
 * Se o denominador for negativo, o sinal deve migrar para o numerador. */
int simplifica_r (struct racional *r)
{
    long valor_mdc;

    if ( !(valido_r(r)) || (r == NULL))
        return 0;

    valor_mdc = mdc(r->num, r->den);
    if (valor_mdc < 0)
        valor_mdc *= (-1);


    r->num /= valor_mdc;
    r->den /= valor_mdc;

    if ( r->den < 0 )
    {
       r->num *= -1;
       r->den *= -1;
    }

    return 1;

}


long numerador_r(struct racional *r)
{
    return r->num;
}

long denominador_r(struct racional *r)
{
    return r->den;
}


struct racional *cria_r (long numerador, long denominador)
{
    struct racional *ptr_r;

    ptr_r  = malloc(sizeof(struct racional));
    
    if(!ptr_r)
        return NULL;   

    ptr_r->num = numerador;
    ptr_r->den = denominador;

    return ptr_r;
}


void destroi_r(struct racional **r)
{
    if (r != NULL && *r != NULL)
    {
        free(*r);        
        *r = NULL;
    }
}



void imprime_r (struct racional *r)
{
    if ( r == NULL)
    {
        printf("NULL");
        return;
    }


    if ( valido_r(r) == 0 )
    {
        printf("NaN");
        return;
    }   

    if ( r->num == 0 )
    {
        printf("0");
        return;
    }

    simplifica_r(r);

    if ( r->den == 1)
    {
        printf("%ld", r->num);
        return;
    }

    if ( r->num == r->den )
    {
        printf("1");
        return;
    }

    printf("%ld/%ld", r->num, r->den);
}

int compara_r (struct racional *r1, struct racional *r2)
{
    long num1;
    long num2;

    // Verifica se algum dos racionais sao invalidos 
    if ( (valido_r(r1) == 0) || (valido_r(r2) == 0) || (r1 == NULL) || (r2 == NULL) )
        return -2;

    simplifica_r(r1);
    simplifica_r(r2);

    // Metodo para retirar o denominador do numero para efetuar a comparacao direta sem divisao
    num1 = r1->num * r2->den;
    num2 = r2->num * r1->den;

    if ( num1 < num2 )
        return -1;

    if ( num1 == num2 )
        return 0;

    return 1;


}


int soma_r (struct racional *r1, struct racional *r2, struct racional *r3)
{    
    if ( (valido_r(r1) == 0) || (valido_r(r2) == 0) || (r1 == NULL) || (r2 == NULL) || (r3 == NULL) )
        return 0;

    
    long valor_mmc;
    
    // Caso os denominadores sejam diferentes, faz o calculo com o mmc deles
    if (r1->den != r2->den)
    {
        valor_mmc = mmc(r1->den, r2->den);
        r3 -> den  = valor_mmc;
        r3 -> num  = (valor_mmc / r1->den * r1->num) + (valor_mmc / r2->den * r2->num);
    }
    else
    {
        r3 -> num = r1->num + r2->num;
        r3 -> den = r1->den;
    }

    simplifica_r(r3);

    return 1;

}

int subtrai_r (struct racional *r1, struct racional *r2, struct racional *r3)
{
    if ( (valido_r(r1) == 0) || (valido_r(r2) == 0) || (r1 == NULL) || (r2 == NULL) || (r3 == NULL) )
        return 0;


    long valor_mmc;
    
    // Caso os denominadores sejam diferentes, calcula o mmc entre eles
    if (r1->den != r2->den)
    {
        valor_mmc = mmc(r1->den, r2->den);
        r3 -> den  = valor_mmc;
        r3 -> num  = (valor_mmc / r1->den * r1->num) - (valor_mmc / r2->den * r2->num);
    }
    else
    {
        r3 -> num = r1->num - r2->num;
        r3 -> den = r1->den;
    }

    simplifica_r(r3);

    return 1;
}


int multiplica_r (struct racional *r1, struct racional *r2, struct racional *r3)
{
    if ( (valido_r(r1) == 0) || (valido_r(r2) == 0) || (r1 == NULL) || (r2 == NULL) || (r3 == NULL) )
        return 0;

    r3 -> num = r1->num * r2->num;
    r3 -> den = r1->den * r2->den;

    simplifica_r(r3);

    return 1;
}


int divide_r (struct racional *r1, struct racional *r2, struct racional *r3)
{
    if ( (valido_r(r1) == 0) || (valido_r(r2) == 0) || (r1 == NULL) || (r2 == NULL) || (r3 == NULL) )
        return 0;

    r3 -> num = r1->num * r2->den;
    r3 -> den = r1->den * r2->num;

    if (valido_r(r3) == 0)
        return 0;

    simplifica_r(r3);

    return 1;
}





























