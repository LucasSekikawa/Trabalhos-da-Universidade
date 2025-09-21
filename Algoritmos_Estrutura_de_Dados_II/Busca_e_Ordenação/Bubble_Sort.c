/* Vetor de [1..tam]
   Guardando a posição 0 para um possível sentinela */

void BubbleSort (vetor[], int tam)
{
  int i, j, aux;
  for (i=1; i<tam; i++)
  {
    for (j=tam; j>i; j--)
      if (vetor[j] > vetor[j-1])
      {
        aux = vetor[j-1];
        vetor[j-1] = vetor[j];
        vetor[j] = aux;
      }
  }
}
