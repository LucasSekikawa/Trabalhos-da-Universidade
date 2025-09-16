void fibonacci(int num)
{
  if (num == 0)
    return 0;
  if (num == 1)
    return 1;
  return fibonacci(n-2) + fibonacci(n-1);
}
