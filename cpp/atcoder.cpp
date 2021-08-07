#include <bits/stdc++.h>
// #include <atcoder/modint>
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define INF 2000000000000000000
#define ll long long
#define ull unsigned long long
#define ld long double
#define pll pair<ll, ll>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const double PI = 3.141592653589793;

ll power = 20;
//=============lowest_common_ancestor============================
vector<ll> depth_lca;
vector<vector<ll>> doubling;
bool called_init = false;
void init(vector<vector<ll>>& connection, ll root) {
  depth_lca = vector<ll>(connection.size(), -1);
  doubling = vector<vector<ll>>(power, vector<ll>(connection.size()));
  depth_lca.at(root) = 0;
  doubling.at(0).at(0) = -1;
  queue<ll> q;q.push(root);
  while (!q.empty()) {
    ll now = q.front();q.pop();
    ll now_d = depth_lca.at(now);
    for (ll i = 0; i < connection.at(now).size(); ++i) {
      if (depth_lca.at(connection.at(now).at(i)) != -1) {
        continue;
      }
      depth_lca.at(connection.at(now).at(i)) = now_d + 1;
      q.push(connection.at(now).at(i));
      doubling.at(0).at(connection.at(now).at(i)) = now;
    }
  }
  for (ll i = 0; i < power - 1; ++i) {
    for (ll j = 0; j < connection.size(); ++j) {
      ll temp = doubling.at(i).at(j);
      if (temp == -1) {
        doubling.at(i + 1).at(j) = -1;
      }
      else {
        doubling.at(i + 1).at(j) = doubling.at(i).at(temp);
      }
    }
  }
}

ll n_up(ll now, ll n)
{
  for (ll i = power; i >= 0; --i) {
    if (n & (1 << i)) {
      now = doubling.at(i).at(now);
    }
  }
  return now;
}

vector<ll> lowest_common_ancestor(vector<vector<ll>>& connection, ll a, ll b, ll root = 0) {
  if (!called_init) {
    called_init = true;
    init(connection, root);
  }
  ll ancestor, distance_between = 0;
  ll ad = depth_lca.at(a), bd = depth_lca.at(b);
  if (ad > bd) {
    swap(ad, bd);
    swap(a, b);
  }
  b = n_up(b, bd - ad);
  distance_between += bd - ad;
  bd = ad;
  ll l = -1, r = ad + 1;
  while (l + 1 != r) {
    ll m = (l + r) / 2;
    ll temp = n_up(a, m);
    if (temp == n_up(b, m)) {
      r = m;
      ancestor = temp;
    }
    else {
      l = m;
    }
  }
  distance_between += r * 2;
  return {ancestor, distance_between};
}
//=================================================

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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N;
  cin >> N;
  vector<vector<ll>> conn(N);
  for (ll i = 0; i < N - 1; ++i) {
    ll a, b;
    cin >> a >> b;
    a -= 1, b -= 1;
    connection.at(a).push_back(b);
    connection.at(b).push_back(a);
  }
  euler_tour et(connection, 0);
  init(connection, 0);
  // for (ll i = 0; i < N; ++i) {
  //   cout << "i" << i << "\n";
  //   for (ll j = 0; j < connection.at(i).size(); ++j) {
  //     cout << connection.at(i).at(j) << " ";
  //   }
  //   cout << "\n";
  // }
  // for (ll i = 0; i < N; ++i) {
  //   cout << depth_lca.at(i) << " ";
  // }
  // cout << "\n";
  // for (ll i = 0; i < N; ++i) {
  //   cout << in.at(i) << " " << out.at(i) << "\n";
  // }
  // cout << "\n";
  ll Q;
  cin >> Q;
  for (ll q = 0; q < Q; ++q) {
    ll K;
    cin >> K;
    vector<ll> V(K);
    for (ll i = 0; i < K; ++i) {
      cin >> V.at(i);
      V.at(i) -= 1;
    }
    ll lca = V.at(0);
    for (ll i = 1; i < K; ++i) {
      lca = lowest_common_ancestor(connection, lca, V.at(i)).at(0);
    }
    //a, node_index
    vector<pll> node;
    for (ll i = 0; i < K; ++i) {
      node.push_back({et.in.at(V.at(i)), V.at(i)});
    }
    sort(rrng(node));
    node.push_back({et.in.at(lca), lca});
    ll ans = 0;
    for (ll i = 0; i < node.size() - 1; ++i) {
      ll a = node.at(i).first, index = node.at(i).second, b = et.out.at(index);
      ll index2 = node.at(i + 1).second;
      // cout << a << ' ' << b << ' ' << index << "\n";
      ans += (depth_lca.at(index) - depth_lca.at(lowest_common_ancestor(connection, index, index2).at(0)));
    }
    // cout << lca << "\n";
    cout << ans << "\n";
  }
}
