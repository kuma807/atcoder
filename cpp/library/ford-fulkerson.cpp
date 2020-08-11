// ============how it works=================
// input:
  // ll MAX_V: 頂点数の最大値
// output:
  // max_flow(s,t): s,t間の最大流を求める

//点aから点bに容量cの有向辺があるとき
  //add_edge(a, b, c);
// ========================================


//=============ford_fulkerson============================
ll MAX_V = 101;
struct edge {ll to, cap, rev;};
vector<vector<edge>> G(MAX_V);
vector<bool> used(MAX_V, false);

void add_edge(ll from, ll to, ll cap) {
  G.at(from).push_back((edge){to, cap, (ll)G.at(to).size()});
  G.at(to).push_back((edge){from, 0ll, (ll)G.at(from).size() - 1});
}

ll dfs(ll v, ll t, ll f) {
  if (v == t) {
    return f;
  }
  used.at(v) = true;
  for (ll i = 0; i < G.at(v).size(); ++i) {
    edge &e = G.at(v).at(i);
    if (!used.at(e.to) && e.cap > 0) {
      ll d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        G.at(e.to).at(e.rev).cap += d;
        return d;
      }
    }
  }
  return 0;
}

ll max_flow(ll s, ll t) {
  ll flow = 0;
  while (true) {
    used = vector<bool>(MAX_V, false);
    ll f = dfs(s, t, INF);
    if (f == 0) {
      return flow;
    }
    flow += f;
  }
}
//=================================================
