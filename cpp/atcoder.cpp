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
const double PI = 3.141592653589793;

// ============union_find_tree===============
struct union_find {
  vector<ll> par;
  vector<ll> tree_rank;

  union_find(ll n)
  {
    par = vector<ll>(n);
    tree_rank = vector<ll>(n);
    for (ll i = 0; i < n; ++i)
    {
      par.at(i) = i;
      tree_rank.at(i) = 0;
    }
  }

  ll find(ll x)
  {
    if (par.at(x) == x)
    {
      return x;
    }
    else
    {
      return par.at(x) = find(par.at(x));
    }
  }

  void unite(ll x, ll y)
  {
    x = find(x);
    y = find(y);
    if (x == y)
    {
      return;
    }
    if (tree_rank.at(x) < tree_rank.at(y))
    {
      par.at(x) = y;
    }
    else
    {
      par.at(y) = x;
      if (tree_rank.at(x) == tree_rank.at(y))
      {
        tree_rank.at(x)++;
      }
    }
  }

  bool same(ll x, ll y)
  {
    return find(x) == find(y);
  }
};
// =======================================

// ==============kruskal==================

struct edge{ll u, v, cost;}; // 辺u, v をつなぐコストが cost
bool comp(const edge& e1, const edge& e2)
{
  return e1.cost < e2.cost;
}

ll kruskal(vector<edge> &edges, ll V, ll E) {
  //V 頂点、E 辺　の数
  sort(rng(edges), comp);
  union_find uf(V);
  ll ans = 0;
  for (ll i = 0; i < E; ++i)
  {
    edge e = edges.at(i);
    if (!uf.same(e.u, e.v))
    {
      uf.unite(e.u, e.v);
      ans += e.cost;
    }
  }
  map<ll, bool> mp;
  for (ll i = 0; i < V; ++i) {
    mp[uf.find(i)] = true;
  }
  if (mp.size() != 1) {
    return -1;
  }
  return ans;
}
// =======================================

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N, M;
  cin >> N >> M;
  vector<edge> connection;
  for (ll i = 0; i < M; ++i) {
    ll C, L, R;
    cin >> C >> L >> R;
    connection.push_back({L - 1, R, C});
  }
  cout << kruskal(connection, N + 1, M) << "\n";
}
