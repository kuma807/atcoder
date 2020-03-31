// ============how it works=================
// input:
  // ll a:
  // ll n:
  // ll mod:

// output: a ^ n (mod = mod)　を返す
// ========================================

//=============modpow============================
ll modpow(ll a, ll n, ll mod)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
//=================================================
