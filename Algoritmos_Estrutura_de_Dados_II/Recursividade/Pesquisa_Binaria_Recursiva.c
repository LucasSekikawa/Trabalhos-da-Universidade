
int pesquisaBinaria (vetor[], int ini, int fim, int elementoProcurado)
{
  
  if (ini > fim)
    return -1;

  int meio = (ini + fim) / 2
  if (vetor[meio] == elementoProcurado)
    return meio;
  if (vetor[meio] > elementoProcurado)
    return pesquisaBinaria(vetor, ini, meio-1, elementoProcurado);
  else
    return pesquisaBinaria(vetor, meio+1, fim, elementoProcurado);
}
