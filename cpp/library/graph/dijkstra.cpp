// ============how it works=================
// input:
  // ll s: starting poll
  // ll V: number of node
  // vector<vector<edge>> G(V, vector<edge>(0));: info about edges
    // struct edge {ll to, cost;};
    // 隣接リストで辺が格納されている

// output:
  // ll d[MAX_V]: shortest path to each node

//注意:
  //vector<vector<edge>> G(V);
    //Vは頂点数
// ========================================

struct edge {ll to, cost;};
//=============dijkstra============================
vector<ll> dijkstra(ll s, vector<vector<edge>>& G)
{
  ll V = G.size();
  vector<ll> d(V, INF);
  typedef pair<ll, ll> P;// first は最短距離　second は頂点の番号
  priority_queue<P, vector<P>, greater<P>> que;
  d.at(s) = 0;
  que.push(P(0, s));
  while (!que.empty())
  {
    P p = que.top();
    que.pop();
    ll v = p.second;
    if (d.at(v) < p.first) continue;
    for (ll i = 0; i < G.at(v).size(); ++i)
    {
      edge e = G.at(v).at(i);
      if (d.at(e.to) > d.at(v) + e.cost)
      {
        d.at(e.to) = d.at(v) + e.cost;
        que.push(P(d.at(e.to), e.to));
      }
    }
  }
  return d;
}
//=================================================
