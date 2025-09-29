void inverteVetor(int vetor[], int i, int j)
{
  int aux;
  
  if (i < j)
  {
    aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
    inverteVetor (vetor, i+1, j-1);
  }
}
