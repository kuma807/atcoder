#include <bits/stdc++.h>
#include <atcoder/maxflow>
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N;
  cin >> N;
  mf_graph<ll> graph(600010);
  ll s = 600000, t = 600001;
  for (ll i = 0; i < N; ++i) {
    ll a, b;
    cin >> a >> b;
    a += 199999, b += 199999;
    graph.add_edge(s, i, 1);
    graph.add_edge(i, a, 1);
    graph.add_edge(i, b, 1);
  }
  for (ll i = 200000; i < 600000; ++i) {
    graph.add_edge(i, t, 1);
  }
  cout << graph.flow(s, t) << "\n";
}
