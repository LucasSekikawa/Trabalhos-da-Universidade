/* Busca por elemento em um vetor usando sentinela
   Retorna -1 caso o elemento procurado não esteja no vetor
   Caso contrário, retorna a posição do elemento */

int pesquisaSeqSentinela (vetor[], int i, elementoProcurado)
{
  vetor[0] = elementoProcurado;
  while (vetor[i] != elementoProcurado)
    i--;
  if (i == 0)
      return -1;
  return i;  
}

/* Busca por elemento em um vetor sem sentinela
   Retorna -1 caso o elemento procurado não esteja no vetor
   Caso contrário, retorna a posição do elemento */
int pesquisaSeq (vetor [], int i, elementoProcurado)
{
   while ( (i >= 0) && (vetor[i] != elementoProcurado) )
      i--;
   if (i < 0)
      return -1;
   return i
}
