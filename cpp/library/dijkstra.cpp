// ============how it works=================
// input:
  // int s: starting point
  // int V: number of node
  // vector<vector<edge>> G(V, vector<edge>(0));: info about edges
    // struct edge {int to, cost;};
    // 隣接リストで辺が格納されている

// output:
  // int d[MAX_V]: shortest path to each node

//注意:
  //vector<vector<edge>> G(V, vector<edge>(0));
    //Vは頂点数
// ========================================

#define INF 1000000000
struct edge {int to, cost;};

//=============dijkstra============================
vector<long long> dijkstra(int s, int V, vector<vector<edge>> G)
{
  vector<long long> d(V, INF);
  typedef pair<long long, int> P;// first は最短距離　second は頂点の番号
  priority_queue<P, vector<P>, greater<P>> que;
  d.at(s) = 0;
  que.push(P(0, s));
  while (!que.empty())
  {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d.at(v) < p.first) continue;
    for (int i = 0; i < G.at(v).size(); ++i)
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
