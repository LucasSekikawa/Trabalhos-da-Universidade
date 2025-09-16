int somaRec(int a, int b)
{
  if (b == 0)
      return a;
  return 1 + somaRec(a, b-1);
}
