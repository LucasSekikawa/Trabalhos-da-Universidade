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
