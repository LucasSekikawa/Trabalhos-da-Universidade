int media ( int vetor[], int tam, int soma, int n ) 
{
  if ( n == 0 )
    return soma / tam;
  return  media( vetor, tam, soma + vetor[n], n-1 );
} 
