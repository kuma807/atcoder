// ============how it works=================
// input:
  // int N: number to check
// output:
  // bool: is prime or not
// ========================================

//=============is_prime============================
bool is_prime(int N)
{
  if (N == 1)
  {
    return false;
  }
  for (int i = 2; i * i <= N; ++i)
  {
    if (N % i == 0)
    {
      return false;
    }
  }
  return true;
}
//=================================================
