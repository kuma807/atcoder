// ============how it works=================
//すべて1ーindexである
//ll n:要素数
// input:
  // sum(i)
    //[1,i]の和を出力
  // add(i, x)
    // iにxを足す
//MAX_N
  //最大要素数
// ========================================

//=============BIT============================
const ll MAX_N = 1e5;
ll n;
vector<ll> bit(MAX_N + 1, 0);

ll sum(ll i) {
  ll s = 0;
  while (i > 0) {
    s += bit.at(i);
    i -= i & -i;
  }
  return s;
}

void add(ll i, ll x) {
  while (i <= n) {
    bit.at(i) += x;
    i += i & -i;
  }
}
//=================================================
