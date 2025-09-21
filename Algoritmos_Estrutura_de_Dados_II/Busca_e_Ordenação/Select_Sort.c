/* Para um vetor começando na posição 1
   Guardando a posição 0 para um possível sentinela */

void SelectSort(vetor [], int tam)
{
  int i, j, indiceMaior, aux;

  for (i=1; i<tam; i++)
  {
    indiceMaior = i;
    for (j=i+1; j<=tam; j++)
      if (vetor[j] > vetor[indiceMaior] )
        maiorNum = j;
    if (i != indiceMaior)
    {
      aux = vetor[i];
      vetor[i] = vetor[indiceMaior];
      vetor[indiceMaior] = aux;
    }
  }
}
