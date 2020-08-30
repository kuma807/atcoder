#include <bits/stdc++.h>
using namespace std;
// ============need input=================
// MAX_N
// need to call init()
// ll n:
  //number of nodes
// ========================================

// ============union_find_tree===============
ll MAX_N = -1;
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
