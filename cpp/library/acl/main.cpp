#include <bits/stdc++.h>
#include <atcoder/maxflow>
#define ll long long
using namespace std;
using namespace atcoder;

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
