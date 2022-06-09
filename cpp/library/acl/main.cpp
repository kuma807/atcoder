#include <bits/stdc++.h>
#include <atcoder/mincostflow>
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define INF 2000000000000000000
#define ll long long
#define ld long double
#define pll pair<ll, ll>
using namespace std;
using namespace atcoder;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N;
  cin >> N;
  mcf_graph<int, ll> g(400);
  ll team_index = 1, category_index = 151;
  ll s = 0, t = 301;
  for (ll i = 0; i < 150; ++i) {
    g.add_edge(s, team_index + i, 1, 0);
  }
  for (ll i = 0; i < 150; ++i) {
    g.add_edge(category_index + i, t, 1, 0);
  }
  ll MC = 1000000000;
  for (ll i = 0; i < N; ++i) {
    ll a, b, c;
    cin >> a >> b >> c;
    a = a + team_index - 1, b = b + category_index - 1;
    g.add_edge(a, b, 1, MC - c);
  }
  vector<ll> ans;
  for (ll i = 1; i <= N; ++i) {
    mcf_graph<int, ll> temp_g = g;
    pll f = temp_g.flow(s, t, i);
    // cout << f.first << ' ' << f.second << "\n";
    if (f.first != i) {
      break;
    }
    ans.push_back(MC * i - f.second);
  }
  // for (ll i = 0; i < (ll)ans.size() - 1; ++i) {
  //   ans.at(i + 1) += ans.at(i);
  // }
  cout << ans.size() << "\n";
  for (ll i = 0; i < ans.size(); ++i) {
    cout << ans.at(i) << "\n";
  }
}
