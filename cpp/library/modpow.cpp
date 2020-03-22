// ============how it works=================
// input:
  // long long a:
  // long long n:
  // long long mod:

// output: a ^ n (mod = mod)　を返す
// ========================================

//=============modpow============================
long long modpow(long long a, long long n, long long mod)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
//=================================================
