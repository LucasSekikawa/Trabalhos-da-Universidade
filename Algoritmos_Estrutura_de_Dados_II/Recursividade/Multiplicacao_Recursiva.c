long multRec (int vetor[], int i)
{
    if (i == 0)
        return vetor[i];
    return (vetor[i] * multRec(vetor, i-1));
}

/* Multiplica todos os elementos de um vetor de maneira recursiva */
