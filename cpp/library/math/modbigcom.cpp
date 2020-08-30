// ============how it works=================
// input:
  //ll n
  //ll k
    //nCk
  //ll mod
// output:
  //nCk
//nが大きすぎてmodcomが使えないときよう
// ========================================

//=============mobigcom============================
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

ll COM(ll n, ll k, ll mod){
  ll up = 1, down = 1;
  for (ll i = 0; i < k; ++i) {
    up *= (n - i);
    up %= mod;
  }
  for (ll i = 1; i <= k; ++i) {
    down *= modinv(i, mod);
    down %= mod;
  }
  return (up * down % mod);
}
//=================================================
