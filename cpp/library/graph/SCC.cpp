// ============need input=================
// SCC scc(connection);
//scc.cmp.at(i)
  //iがどの強連結成分に属するか
//O(V + E)

//原理
//1. dfsで深さ優先探索を行い，その際各頂点 vに対して頂点 v から進めなくなった順番を vsに格納する
//2. グラフの矢印の向きをすべて逆向きにし(rG)、dfsをする(rdfs)その際 vs が大きい頂点からスタートする。行けるところまでを一つの連結成分とする。
// ========================================

//=============SCC============================
struct SCC {
  vector<vector<ll>> G;
  vector<vector<ll>> rG;
  vector<ll> vs;
  vector<bool> used;
  vector<ll> cmp;
  SCC(vector<vector<ll>> &connection) {
    G = connection;
    rG = vector<vector<ll>>(connection.size());
    used = vector<bool>(connection.size(), false);
    cmp = vector<ll>(connection.size());
    for (ll i = 0; i < connection.size(); ++i) {
      for (ll j = 0; j < connection.at(i).size(); ++j) {
        rG.at(connection.at(i).at(j)).push_back(i);
      }
    }
    for (ll i = 0; i < connection.size(); ++i) {
      if (!used.at(i)) {
        dfs(i);
      }
    }
    used = vector<bool>(connection.size(), false);
    ll k = 0;
    for (ll i = vs.size() - 1; i >= 0; --i) {
      if (!used.at(vs.at(i))) {
        rdfs(vs.at(i), k++);
      }
    }
  }
  void dfs(ll v) {
    used.at(v) = true;
    for (ll i = 0; i < G.at(v).size(); ++i) {
      if (!used.at(G.at(v).at(i))) {
        dfs(G.at(v).at(i));
      }
    }
    vs.push_back(v);
  }
  void rdfs(ll v, ll k) {
    used.at(v) = true;
    cmp.at(v) = k;
    for (ll i = 0; i < rG.at(v).size(); ++i) {
      if (!used.at(rG.at(v).at(i))) {
        rdfs(rG.at(v).at(i), k);
      }
    }
  }
};
//=================================================
