#include <bits/stdc++.h>
// #include <atcoder/modint>
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define INF 2000000000000000000
#define ll long long
#define ull unsigned long long
#define ld long double
#define pll pair<ll, ll>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const double PI = 3.141592653589793238462643383279;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll T;
  cin >> T;
  for (ll testcase = 0; testcase < T; ++testcase) {
    ll R, G, B;
    cin >> R >> G >> B;
    vector<ll> A = {R, G, B};
    sort(rng(A));
    R = A.at(0), G = A.at(1), B = A.at(2);
    ll ans = INF;
    if ((G - R) % 3 == 0) {
      ll temp = (G - R) / 3;
      ll n = (R + temp * 2);
      if (G - temp >= 0 && B - temp >= 0) {
        ans = min(ans, temp + n);
      }
    }
    if ((B - R) % 3 == 0) {
      ll temp = (B - R) / 3;
      ll n = (R + temp * 2);
      if (G - temp >= 0 && B - temp >= 0) {
        ans = min(ans, temp + n);
      }
    }
    if ((B - G) % 3 == 0) {
      ll time = (B - G) / 3;
      ll need = max(0ll, time - R);
      ll temp = (need + 1) / 2;
      R += temp * 2, G -= temp, B -= temp;
      if (G >= 0 && B >= 0) {
        ll ntemp = (B - G) / 3;
        ll n = G + ntemp * 2;
        ans = min(ans, temp + ntemp + n);
      }
    }
    if (ans == INF) {
      ans = -1;
    }
    cout << ans << "\n";
  }
}
