// ============how it works=================
//euler_tour et(connection, root);

// output:
  //et.in.at(i)
    //頂点iに最初に訪れたタイミング
  //et.out.at(i)
    //頂点iを離れるタイミング
  //et.depth.at(i)
    //頂点iと根との距離
  //et.par.at(i)
    //頂点iの親、rootの親は-1
// ========================================

//=============euler_tour============================
struct euler_tour {
  vector<ll> in, out, depth, par;
  ll dist = 0;
  euler_tour(vector<vector<ll>> &connection, ll s) {
    in = out = depth = par = vector<ll>(connection.size(), -1);
    dfs(connection, s);
  }
  void dfs(vector<vector<ll>> &connection, ll now) {
    in.at(now) = dist;
    dist += 1;
    for (ll i = 0; i < connection.at(now).size(); ++i) {
      ll next = connection.at(now).at(i);
      if (next == par.at(now)) {
        continue;
      }
      depth.at(next) = depth.at(now) + 1;
      par.at(next) = now;
      dfs(connection, next);
    }
    out.at(now) = dist;
    dist += 1;
  }
};
// =======================================
