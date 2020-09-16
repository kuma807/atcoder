// ============need input=================
//格子点の数(下の境界は含まれない)
//input
  //n, m, a, b
//output
  //(i = 0, n - 1)∑ floor((a×i+b) / m)を返す
// ========================================

// ===========floor_sum================
ll floor_sum(ll n, ll m, ll a, ll b) {
    ll ans = 0;
    if (a >= m) {
        ans += (n - 1) * n * (a / m) / 2;
        a %= m;
    }
    if (b >= m) {
        ans += n * (b / m);
        b %= m;
    }

    ll y_max = (a * n + b) / m, x_max = (y_max * m - b);
    if (y_max == 0) return ans;
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
    return ans;
}
// =======================================

//未確定
ll ceil_sum(ll n, ll m, ll a, ll b) {
  return floor_sum(n, m, a, b + m - 1);
}
ll floor_sum_with_out_boundary(ll n, ll m, ll a, ll b) {
  //floor_sumから上の境界線を除く
  ll h = (a * (n - 1) + b + m) / m;
  ll all = n * h;
  ll minus = floor_sum(n, m, a, m - (a * (n - 1) + b) % m);
  ll res = all - minus;
  if (b != 0) {
    res -= n;
  }
  else if (b == 0 && a != 0) {
    res -= n - 1;
  }
  return res;
}
ll boundary_sum(ll n, ll m, ll a, ll b) {
  //上の境界線上の格子点の数を返す
  ll h = (a * (n - 1) + b + m) / m;
  ll all = n * h;
  ll up = floor_sum(n, m, a, m - (a * (n - 1) + b) % m);
  ll down = floor_sum(n, m, a, b + m);
  ll res = (up + down) - all;
  return res;
}
