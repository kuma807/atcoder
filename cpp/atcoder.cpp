#include <bits/stdc++.h>
#define INF 2000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;
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
ll boundary_sum(ll n, ll m, ll a, ll b) {
  //上の境界線上の格子点の数を返す
  ll h = (a * (n - 1) + b + m) / m;
  ll all = n * h;
  ll up = floor_sum(n, m, a, m - (a * (n - 1) + b) % m);
  ll down = floor_sum(n, m, a, b + m);
  ll res = (up + down) - all;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m, a, b;
  cin >> n >> m >> a >> b;
  cout << floor_sum(n, m, a, b) << "\n";
  cout << boundary_sum(n, m, a, b) << "\n";
}
