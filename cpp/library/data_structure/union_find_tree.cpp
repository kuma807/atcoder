// ============need input=================
// union_find uf(NUM_NODE);
//uf.find(n)
  //find group
// ========================================

// ============union_find_tree===============
struct union_find {
  vector<ll> par;
  vector<ll> tree_rank;
  vector<ll> num;

  union_find(ll n)
  {
    par = vector<ll>(n);
    num = vector<ll>(n, 1);
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

  ll get_num(ll x) {
    return num.at(find(x));
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
      num.at(y) = num.at(x) + num.at(y);
    }
    else
    {
      par.at(y) = x;
      num.at(x) = num.at(x) + num.at(y);
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
