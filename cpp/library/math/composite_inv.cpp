// ============how it works=================
// input:
  //composite_inv(a, mod)
    //aの逆元を求める, aとmodは互いに素でないといけない
// output:
  //aの逆元
// ========================================

//=============composite_inv============================
vector<ll> prime_factor(ll N)
{
  vector<ll> res;
  for (ll i = 2; i * i <= N; ++i) {
    if (N % i == 0) {
      ll cnt = 0;
      while (N % i == 0) {
        N /= i;
        cnt += 1;
      }
      res.push_back(i);
    }
  }
  if (N != 1) {
    res.push_back(N);
  }
  return res;
}

ll composite_inv(ll a, ll mod) {
  ll p = mod;
  vector<ll> fac = prime_factor(mod);
  for (ll i = 0; i < fac.size(); ++i) {
    p *= fac.at(i) - 1;
    p /= fac.at(i);
  }
  p -= 1;
  ll res = 1;
  while (p > 0)
  {
    if (p & 1) res = res * a % mod;
    a = a * a % mod;
    p >>= 1;
  }
  return res;
}
//=================================================
