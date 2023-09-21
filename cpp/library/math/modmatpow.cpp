// ============how it works=================
// input:
  // vector<vector<ll>> a
    //正方行列
  // ll power
    //何乗にするか
  // ll mod
// output:
  // vector<vector<ll>> res
    //　正方行列aのn乗のmod


//行列の積について
//行列の積は数字・掛け算・足し算でなくても良い
//半環の性質を持っているとき行列の積は使える
// 半環は、以下の性質を満たす二つの二項演算、即ち加法（和）"+" と乗法（積）"·" とを備えた集合 R を言う[1]：
//
// (R, +) は単位元 0 を持つ可換モノイドを成す:
// (a + b) + c = a + (b + c),
// 0 + a = a + 0 = a,
// a + b = b + a.
// (R, ·) は単位元 1 を持つモノイドを成す:
// (a · b)· c = a ·(b · c),
// 1 · a = a · 1 = a.
// 乗法は加法の上に分配的である:
// a ·(b + c) = (a · b) + (a · c),
// (a + b)· c = (a · c) + (b · c).
// 0-倍は R を零化する:
// 0 · a = a · 0 = 0.

//計算量
//O(N^3 * log(pow))
// ========================================


//=============modmatpow============================
vector<vector<ll>> modmatmul(vector<vector<ll>>& a, vector<vector<ll>>& b, ll mod)
{
  vector<vector<ll>> res(a.size(), vector<ll>(b.at(0).size()));
  for (ll row = 0; row < a.size(); ++row) {
    for (ll colom = 0; colom < b.at(0).size(); ++colom) {
      ll sum = 0;
      for (ll i = 0; i < b.size(); ++i) {
        sum = (sum + a.at(row).at(i) * b.at(i).at(colom));
        if (sum >= mod) {
          sum %= mod;
        }
      }
      res.at(row).at(colom) = sum;
    }
  }
  return res;
}

vector<vector<ll>> modmatpow(vector<vector<ll>> a, ll power, ll mod)
{
  vector<vector<ll>> res(a.size(), vector<ll>(a.size(), 0));
  for (ll i = 0; i < a.size(); ++i) {
    res.at(i).at(i) = 1;
  }
  while (power) {
    if (power & 1) {
      res = modmatmul(a, res, mod);
    }
    a = modmatmul(a, a, mod);
    power = (power >> 1);
  }
  return res;
}
//=================================================
