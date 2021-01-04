// ============how it works=================
// input:
 //ax + by = c
 //solve(a, b, c, x, y)
// output:
  // 返り値: なし
  //ax+by=cを満たすx, yに変更される
//注意!!!!!!!　c % gcd(a, b) == 0のときのみ解を持つ
// ========================================

//=============ax+by=c============================
ll extGCD(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = extGCD(b, a%b, y, x);
  y -= a/b * x;
  return d;
}

void solve(ll a, ll b, ll c, ll &x, ll &y) {
  extGCD(a, b, x, y);
  ll gcd = __gcd(a, b);
  x *= c / gcd, y *= c / gcd;
}
//=================================================
