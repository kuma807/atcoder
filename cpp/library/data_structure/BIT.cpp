// ============how it works=================
//すべて0ーindexである
//ll n:要素数
// input:
  // sum(i, j)
    //[i,j]の和を出力
  // add(i, x)
    // iにxを足す
//MAX_N
  //最大要素数
// ========================================

//=============BIT============================
const ll MAX_N = pow(10, 5) * 5 + 1;
ll n;
vector<ll> bit(MAX_N + 1, 0);

ll sum(ll i, ll j) {
  j += 1;
  ll si = 0, sj = 0;
  while (i > 0) {
    si += bit.at(i);
    i -= i & -i;
  }
  while (j > 0) {
    sj += bit.at(j);
    j -= j & -j;
  }
  return sj - si;
}

void add(ll i, ll x) {
  i += 1;
  while (i <= n) {
    bit.at(i) += x;
    i += i & -i;
  }
}
//=================================================
