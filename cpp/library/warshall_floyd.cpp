// ============how it works=================
// input:
  // ll V: 頂点数
  // vector<vector<ll>> d(V, vector<ll>(V, INF)): ある点からある点への最短経路
    // d[u][v]は u から v　への最短経路

// output:
  // vector<vector<ll>> d(V, vector<ll>(V, INF)): d[u][v] は u からvへの最短経路
// ========================================

#define INF 100000000
//=============warshall_floyd============================
void  warshall_floyd(ll V, vector<vector<ll>>& d)
{
  for (ll k = 0; k < V; ++k)
  {
    for (ll i = 0; i < V; ++i)
    {
      for (ll j = 0; j < V; ++j)
      {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}
//=================================================
