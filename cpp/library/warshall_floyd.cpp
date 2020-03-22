// ============how it works=================
// input:
  // int V: 頂点数
  // vector<vector<int>> d(V, vector<int>(V, INF)): ある点からある点への最短経路
    // d[u][v]は u から v　への最短経路

// output:
  // vector<vector<int>> d(V, vector<int>(V, INF)): d[u][v] は u からvへの最短経路
// ========================================

#define INF 100000000
//=============warshall_floyd============================
vector<vector<int>>  warshall_floyd(int V, vector<vector<int>> d)
{
  for (int k = 0; k < V; ++k)
  {
    for (int i = 0; i < V; ++i)
    {
      for (int j = 0; j < V; ++j)
      {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  return d;
}
//=================================================
