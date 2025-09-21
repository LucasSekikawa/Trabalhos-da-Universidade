int MaiorElemento(vetor[], int i)
{
  int maiorNum;
  if (i == 0)
    return vetor[i];
  maiorNum = MaiorElemento(vetor, i-1);
  if (vetor[i] > MaiorElemento)
    return vetor[i];
  return maiorNum;
}
