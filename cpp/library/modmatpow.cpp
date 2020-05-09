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
// ========================================


//=============modmatpow============================
vector<vector<ll>> modmatmul(vector<vector<ll>>& a, vector<vector<ll>>& b, ll mod)
{
  vector<vector<ll>> res(a.size(), vector<ll>(b.at(0).size()));
  for (ll row = 0; row < a.size(); ++row) {
    for (ll colom = 0; colom < b.at(0).size(); ++colom) {
      ll sum = 0;
      for (ll i = 0; i < b.size(); ++i) {
        sum = (sum  + a.at(row).at(i) * b.at(i).at(colom) % mod) % mod;
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
