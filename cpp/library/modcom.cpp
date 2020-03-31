// ============how it works=================
// input:
  //ll n
  //ll k
    //nCk
  //ll mod: mod
// output:
  //nCk
// ========================================

//=============modinv============================
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
//=================================================

//=============modcom============================
ll modcom(ll n, ll k, ll mod)
{
  k = min(k, n - k);
  ll up = 1;
  for (ll i = n - k + 1; i < n + 1; ++i)
  {
    up = (up * i) % mod;
  }
  ll down = 1;
  for (ll i = 2; i < k + 1; ++i)
  {
    down = (down * modinv(i, mod)) % mod;
  }
  return (up * down) % mod;
}
//=================================================
