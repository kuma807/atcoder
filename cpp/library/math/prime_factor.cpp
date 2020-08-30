// ============how it works=================
// input:
  // ll N:Nを素因数分解する
// output:
  // vector<pll> res:pow(first, second)がNの約数
//Nの値が大きくfast_prime_factorが使えないときに使う
// ========================================


//=============prime_factor============================
vector<pll> prime_factor(ll N)
{
  vector<pll> res;
  for (ll i = 2; i * i <= N; ++i) {
    if (N % i == 0) {
      ll cnt = 0;
      while (N % i == 0) {
        N /= i;
        cnt += 1;
      }
      res.push_back({i, cnt});
    }
  }
  if (N != 1) {
    res.push_back({N, 1});
  }
  return res;
}
//=================================================
