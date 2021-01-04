#include <bits/stdc++.h>
// #include <atcoder/modint>
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define INF 2000000000000000000
#define ll long long
#define ld long double
#define pll pair<ll, ll>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int main(){
  string S = "ruoYced_ehpigniriks_i_llrg_stae";
  string ans;
  ll N;
  cin >> N;
  ll last = 0;
  for (ll i = N - 1; i < S.size(); i += N) {
    for (ll j = i; j >= i - N + 1; --j) {
      ans += S.at(j);
      last = max(last, j);
    }
  }
  for (ll i = S.size() - 1; i > last; --i) {
    ans += S.at(i);
  }
  cout << ans << "\n";
}
