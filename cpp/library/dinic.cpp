// ============how it works=================
// input:
  // ll MAX_V: 頂点数の最大値
// output:
  // max_flow(s,t): s,t間の最大流を求める

//点aから点bに容量cの有向辺があるとき
  //add_edge(a, b, c);
// ========================================


//=============dinic============================
ll MAX_V = 101;
struct edge {ll to, cap, rev;};
vector<vector<edge>> G(MAX_V);
vector<ll> level(MAX_V);
vector<ll> iter(MAX_V);

void add_edge(ll from, ll to, ll cap) {
  G.at(from).push_back((edge){to, cap, (ll)G.at(to).size()});
  G.at(to).push_back((edge){from, 0ll, (ll)G.at(from).size() - 1});
}

void bfs(ll s) {
  for (ll i = 0; i < MAX_V; ++i) {
    level.at(i) = -1;
  }
  queue<ll> q;
  level.at(s) = 0;
  q.push(s);
  while (!q.empty()) {
    ll v = q.front();
    q.pop();
    for (ll i = 0; i < G.at(v).size(); ++i) {
      edge &e = G.at(v).at(i);
      if (e.cap > 0 && level.at(e.to) < 0) {
        level.at(e.to) = level.at(v) + 1;
        q.push(e.to);
      }
    }
  }
}

ll dfs(ll v, ll t, ll f) {
  if (v == t) {
    return f;
  }
  for (ll &i = iter.at(v); i < G.at(v).size(); ++i) {
    edge &e = G.at(v).at(i);
    if (e.cap > 0 && level.at(v) < level.at(e.to)) {
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
    bfs(s);
    if (level.at(t) < 0) {
      return flow;
    }
    for (ll i = 0; i < MAX_V; ++i) {
      iter.at(i) = 0;
    }
    ll f;
    while ((f = dfs(s, t, INF)) > 0) {
      flow += f;
    }
  }
  return flow;
}
//=================================================
