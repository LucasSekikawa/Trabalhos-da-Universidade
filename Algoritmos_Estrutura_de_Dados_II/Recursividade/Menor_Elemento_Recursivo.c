int MenorElemento (vetor[], int i)
{
  int menorNum;
  if (i == 0)
    return vetor[i];
  menorNum = MenorElemento(vetor, i-1);
  if (vetor[i] < menorNum)
    return vetor[i];
  return menorNum;
}
