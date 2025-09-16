int subRec(int a, int b)
{
  if (b == 0)
    return a;
  return subRec(a, b-1) - 1;
}
