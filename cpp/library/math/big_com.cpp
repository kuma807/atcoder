// ============how it works=================
// input:
  // ll n, r
// output:
  // nCr
//nCrがllの範囲に収まるときに使える
//計算量はO(nlog(n))
// ========================================


//=============big_com============================
ll big_com(ll n, ll r) {
  vector<ll> prime(n + 1, 0);
  for (ll i = n; i > n - r; --i) {
    ll now = i;
    for (ll j = 2; j * j <= i; ++j) {
      while (now % j == 0) {
        prime.at(j) += 1;
        now /= j;
      }
      if (now == 1) {
        break;
      }
    }
    if (now != 1) {
      prime.at(now) += 1;
    }
  }
  for (ll i = r; i >= 2; --i) {
    ll now = i;
    for (ll j = 2; j * j <= i; ++j) {
      while (now % j == 0) {
        prime.at(j) -= 1;
        now /= j;
      }
      if (now == 1) {
        break;
      }
    }
    if (now != 1) {
      prime.at(now) -= 1;
    }
  }
  ll res = 1;
  for (ll i = 1; i <= n; ++i) {
    res *= pow(i, prime.at(i));
  }
  return res;
}
//=================================================
