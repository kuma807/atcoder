// ============how it works=================
// input:
  //ll s
    // starting point
  //ll E
    // num of edges
  // ll V
    // num of nodes
  // vector<edge> es
    // edge info

// output:
// vector<ll> d
  // shortest distance to nodes
  // if d == {}  負の閉路が存在する
// ========================================

#define INF 100000000
//=============belman_ford============================
struct edge{ll from, to, cost;};
vector<ll> belman_ford(ll s, ll E, ll V, vector<edge>& es)
{
  vector<ll> d(V, INF);
  ll cnt = 0;
  d.at(s) = 0;
  while (true)
  {
    bool update = false;
    for (ll i = 0; i < E; ++i)
    {
      edge e = es.at(i);
      if (d.at(e.from) != INF && d.at(e.to) > d.at(e.from) + e.cost)
      {
        d.at(e.to) = d.at(e.from) + e.cost;
        update = true;
      }
    }
    if (!update)
    {
      break;
    }
    cnt += 1;
    if (cnt == V)
    {
      return {};
    }
  }
  return d;
}
//=================================================
