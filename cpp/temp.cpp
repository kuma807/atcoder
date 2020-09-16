#include <bits/stdc++.h>
#define INF 2000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll T;
  cin >> T;
  for (ll testcase = 0; testcase < T; ++testcase) {
    ll x, y, k;
    cin >> x >> y >> k;
    ll need = (k * (1 + y) - 1);
    ll ans = (need + x - 2) / (x - 1);
    ne
    cout << ans << "\n";
  }
}
