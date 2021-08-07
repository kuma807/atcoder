// ============how it works=================
//lowest_common_ancestor(connection, a, b, root)
// input:
  // vector<vector<ll>> connection
    //木のつながりの隣接リスト
  //ll a, b
    //a,b間の距離や共通の親を求める
  //ll root
    //木の根を指定
  //power ダブリングの深さを指定

// output:vector<ll>
  //{共通の親、　2点間の距離}
// ========================================

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
