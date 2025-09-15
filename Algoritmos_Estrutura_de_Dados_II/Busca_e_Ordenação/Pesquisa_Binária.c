/* Retorna a posição do elemento caso ele esteja no vetor
   Caso contrário, retorna -1; */

int PesqBinaria (vetor[], int i, elementoProcurado)
{
  int ini, meio, fim;
  ini = 0;
  fim = i-1;

  while ( ini <= fim )
  {
    meio = (ini + fim) / 2;
    if (vetor[meio] == elementoProcurado)
      return meio;
    if (vetor[meio] > elementoProcurado)
      fim = meio - 1;
    else
      ini = meio + 1;
  }  
  return -1
}
