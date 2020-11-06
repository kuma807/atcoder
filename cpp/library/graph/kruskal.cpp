#include <bits/stdc++.h>
using namespace std;
// ============need input=================
// MAX_N, MAX_E, V, E
// output:
  // ll ans: 最小全域木の辺の重みの総和
// ========================================


// ============union_find_tree===============
ll MAX_N = 10000;
vector<ll> par(MAX_N);//MAX_N == num of node
vector<ll> tree_rank(MAX_N);

void init(ll n)
{
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
// =======================================

// ==============kruskal==================

struct edge{ll u, v, cost;}; // 辺u, v をつなぐコストが cost
bool comp(const edge& e1, const edge& e2)
{
  return e1.cost < e2.cost;
}
const ll MAX_E = 100000;
edge es[MAX_E];
ll V, E; // V 頂点、E 辺　の数

ll kruskal()
{
  sort(es, es + E, comp);
  init(V);
  ll ans = 0;
  for (ll i = 0; i < E; ++i)
  {
    edge e = es[i];
    if (!same(e.u, e.v))
    {
      unite(e.u, e.v);
      ans += e.cost;
    }
  }
  return ans;
}
// =======================================
