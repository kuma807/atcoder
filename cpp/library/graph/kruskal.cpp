// ============need input=================
// kruskal(vector<edge> &edges, ll V, ll E)
  //edgesは辺をすべて収納
  //Vは頂点数
  //Eは辺の8数
// output:
  // ll ans: 最小全域木の辺の重みの総和
// ========================================

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
