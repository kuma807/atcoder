#include <bits/stdc++.h>
#include <atcoder/math>
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
using namespace atcoder;
// pll p = crt({remain1, remain2, ...}, {mod1, mod2, ...});
//1 <= remain && lcm(all(remain))がllの範囲
//(ans, mod)
//答えがない場合は(0, 0)を返す

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N;
  cin >> N;
  pll p = crt({0, 0}, {2, N});
  cout << p.first << ' ' << p.second << "\n";
}
