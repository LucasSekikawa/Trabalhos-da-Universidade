/* Busca por elemento em um vetor usando sentinela
   Retorna 0 caso o elemento procurado não esteja no vetor
   Caso contrário, retorna a posição do elemento */

int pesquisaSeq (vetor[], int i, elementoProcurado)
{
  vetor[0] = elementoProcurado;
  while (vetor[i] != elementoProcurado)
    i--;
  if (i == 0)
      return 0;
  return i;  
}
