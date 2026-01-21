#include "lista.h"
#include <stdlib.h>
/* coloque demais includes aqui */

/* ------------------- Nao altere estas structs ------------------------- */
struct nodo {
    int chave;
    struct nodo *prox;
};

struct lista {
    struct nodo *ini;
    struct nodo *ptr; /* ponteiro para algum nodo da lista (iterador) */
    int tamanho;

};
/* ---------------------------------------------------------------------- */

struct lista *lista_cria ()
{
    struct lista *ptr_lista = malloc(sizeof(struct lista));
    if (ptr_lista == NULL)
        return NULL;

    ptr_lista->ini = NULL;
    ptr_lista->ptr = NULL;
    ptr_lista->tamanho = 0;

    return ptr_lista;
}


void lista_destroi (struct lista **lista)
{
    struct nodo *atual;
    struct nodo *proximo;

    
    if ( (*lista)->tamanho != 0 )
    {    
        /* Inicia o nodo atual como o primeiro da lista */
        atual = (*lista)->ini;
    
        /* Percorre todos os nodos da lista */
        while (atual != NULL)
        {
            /* Guarda o endereco do proximo nodo
               antes de liberar o nodo atual */
            proximo = atual->prox;
            free(atual);
            atual = proximo;
        }   
    }

    free(*lista);

    *lista = NULL;
} 

int lista_insere_inicio (struct lista *lista, int chave)
{
    struct nodo *ptr_novo = malloc(sizeof(struct nodo));

    if (ptr_novo == NULL)
        return 0;

    ptr_novo->chave = chave;
    ptr_novo->prox = lista->ini;

    lista->ini = ptr_novo;
    lista->tamanho += 1;
    
    return 1;   
}

int lista_insere_fim (struct lista *lista, int chave)
{
    struct nodo *ptr_novo = malloc(sizeof(struct nodo));
    struct nodo *atual = lista->ini;
   
    if (ptr_novo == NULL)
        return 0;

    /* Atualiza os valores do novo elemento da lista */
    ptr_novo->chave = chave;
    ptr_novo->prox = NULL;

    /* Checa se a lista esta vazia, caso ela esteja,
       o valor inserido sera o primeiro, caso contrario,
       ele é colocado para a ultima posicao da lista */ 
    if (lista->tamanho == 0)
        lista->ini = ptr_novo;       
    else
    {
        while (atual->prox != NULL)
            atual = atual->prox;    

        atual->prox = ptr_novo;
    }

    lista->tamanho += 1;

    return 1;
}


int lista_insere_ordenado (struct lista *lista, int chave)
{
    struct nodo *atual;

    /* Inicializa o ponteiro anterior como NULL, visto que o anterior
       ao primeiro da lista nao existe */
    struct nodo *anterior = NULL;
    struct nodo *novo = malloc(sizeof(struct nodo));
    if ( novo == NULL)
        return 0;   
    
    novo->chave = chave;

    /* Checa se o elemento a ser inserido e o primeiro */
    if ( lista->tamanho == 0)
    {
        lista->ini = novo;
        novo->prox = NULL;
    }
    /* Se a lista possui mais de um nodo */
    else
    {
        /* Inicializa o ponteiro atual como sendo o primeiro da lista */
        atual = lista->ini;

        /* Mantem no looping enquanto ainda houver nodos a serem comparados,
           ou, enquanto a chave atual é maior ou igual a ser inserida */
        while ( (atual != NULL) && ( atual->chave < novo->chave ) )
        {
            anterior = atual;
            atual = atual->prox;
        }

        /* Caso a chave a ser inserida e menor que a do primeiro nodo,
           atualiza o novo nodo para a primeira posicao, e o que estava
           em primeiro para a segunda posicao */
        if (anterior == NULL)
        {
            novo->prox = lista->ini;
            lista->ini = novo;
        }         
        /* Caso o looping tenha rodado, a insercao sera feita,
           o novo nodo sera inserido entre anterior e atual,
           dessa maneira o novo nodo aponta para atual, enquanto que,
           o nodo anterior aponta para o novo nodo */
        else
        {
            novo->prox = atual;
            anterior->prox = novo;
            
        }
    }

    lista->tamanho += 1;
    

    return 1;
}



int lista_remove_inicio (struct lista *lista, int *chave)
{
    struct nodo *removido;

    if (lista->tamanho == 0)
        return 0;    
    
    /* Usa um ponteiro auxiliar para guardar os valores
       que estao na struct que sera destruida, e armazena
       o valor da chave do elemento removido no parametro recebido */
    removido = lista->ini;
    *chave = removido->chave;
    
    /* Atualiza o valor de lista->ini,
       seja para NULL caso o tamanho seja 0,
       ou, caso nao seja, para o proximo elemento  */
    lista->ini = removido->prox;

    /* Atualiza o tamanho da lista com a remocao */
    lista->tamanho -= 1;
  
    free(removido);    
    
    return 1;            

}



int lista_remove_fim (struct lista *lista, int *chave)
{
    struct nodo *atual;
    struct nodo *anterior;

    if (lista->tamanho == 0)
        return 0;

    /* Comeca testando se a lista tem apenas um nodo */
    if (lista->ini->prox == NULL)
    {    
        *chave = lista->ini->chave;
        free(lista->ini);
        lista->ini = NULL;
    }
    /* Caso contrario, comeca a buscar o ultimo elemento*/
    else
    {
        /* Inicia o anterior como o primeiro nodo da lista,
           e o atual como o segundo nodo */
        anterior = lista->ini;
        atual = lista->ini->prox;
        
        /* Enquanto nao for encontrado o ultimo nodo da lista,
           atualiza os valores do elemento atual, e seu antecessor */
        while (atual->prox != NULL)
        {
            anterior = atual;
            atual = atual->prox;   
        }

        /* Aponta o ultimo nodo da lista para NULL */
        anterior->prox = NULL;

        /* Atualiza a chave e libera o nodo eliminado */
        *chave = atual->chave;
        free(atual);

    }

    lista->tamanho -= 1;

    return 1;
}

int lista_remove_ordenado (struct lista *lista, int chave)
{   
    struct nodo *atual;
    /* Inicializa como NULL, porque o elemento anterior
       ao primeiro nao existe */
    struct nodo *anterior = NULL; 

    if (lista->tamanho == 0)
        return 0;
    
    /* Inicializa atual como o primeiro elemento da lista */
    atual = lista->ini;

    /* Mantem o looping enquanto ainda houver nodos
       a serem conferidos, ou, enquanto a chave do 
       nodo analisado for menor que a chave fornecida */
    while ( (atual != NULL) && (atual->chave < chave) )
    {
        anterior = atual;        
        atual = atual->prox;
    }
    
    /* Se o primeiro elemento for o encontrado,
       atualiza para o proximo do nodo, seja o segundo
       nodo da lista, ou NULL */
    if ( anterior == NULL )
        lista->ini = atual->prox;

    /* Caso esteja no meio ou no fim da lista,
       o atual é "pulado" */
    else
        anterior->prox = atual->prox;

    free(atual);

    lista->tamanho -= 1;

    return 1;
}


int lista_vazia (struct lista *lista)
{
    if (lista->tamanho == 0)
        return 1;
    return 0;
}

int lista_tamanho (struct lista *lista)
{
    return lista->tamanho;
}

int lista_pertence (struct lista *lista, int chave)
{
    struct nodo *atual;    
    
    if ( lista->tamanho == 0 )
        return 0;
    
    atual = lista->ini;

    /* Executa o looping ate encontrar o elemento procurado
     * ou, ate percorrer todos os elementos da lista */
    while ( (atual != NULL) && (atual->chave != chave) )
        atual = atual->prox;

    /* Se o atual for igual a NULL, significa que  a lista
       inteira foi percorrida e a chave nao foi encontrada */
    if (atual == NULL)
        return 0;
    
    /* Caso contrario, a chave foi encontrada */
    return 1;

}

void lista_inicia_iterador (struct lista *lista)
{
    lista->ptr = lista->ini;  
}

int lista_incrementa_iterador (struct lista *lista, int *chave)
{
   /* Caso o ponteiro aponte para NULL, significa que
    * ele ultrapassou o ultimo elemento da lista */ 
   if ( lista->ptr == NULL )
        return 0;
   
   *chave = lista->ptr->chave;
        
   lista->ptr = lista->ptr->prox;

   return 1;

} 
