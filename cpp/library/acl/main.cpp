#include <bits/stdc++.h>
#include <atcoder/math>
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define INF 2000000000000000000
#define ll long long
#define ld long double
#define pll pair<ll, ll>
using namespace std;
using namespace atcoder;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

<<<<<<< HEAD
//=============is_prime============================
bool is_prime(ll N)
{
  if (N == 1)
  {
    return false;
  }
  for (ll i = 2; i * i <= N; ++i)
  {
    if (N % i == 0)
    {
      return false;
    }
  }
  return true;
}
//=================================================

int main(){
  vector<ll> P = {4, 5, 9};
  for (ll i = 6; i <= 28; ++i) {
    if (is_prime(i)) {
      P.push_back(i);
    }
  }
  // for (ll i = 0; i < P.size(); ++i) {
  //   cout << 338557213 % P.at(i) << "\n";
  // }
  ll M = 0;
  for (ll i = 0; i < P.size(); ++i) {
    M += P.at(i);
  }
  cout << M << endl;
  vector<ll> A;
  vector<ll> len;
  for (ll i = 0; i < P.size(); ++i) {
    ll p = P.at(i);
    ll s = A.size() + 1;
    for (ll j = 0; j < p; ++j) {
      A.push_back(s + (1 + j) % p);
      len.push_back(p);
    }
  }
  for (ll i = 0; i < A.size(); ++i) {
    cout << A.at(i) << " ";
  }
  cout << endl;
  vector<ll> B(M);
  for (ll i = 0; i < M; ++i) {
    cin >> B.at(i);
  }
  vector<pair<long long, long long>> v;
  vector<ll> r, m;
  for (ll i = 0; i < M; ++i) {
    ll b = B.at(i);
    ll l = len.at(i);
    // if (i != M - 1 && len.at(i) == len.at(i + 1)) {
    //   continue;
    // }
    if (b >= A.at(i)) {
      // v.push_back({b - A.at(i), l});
      r.push_back(b - A.at(i) + 1);
      m.push_back(l);
    }
    else {
      r.push_back(b + l - A.at(i) + 1);
      m.push_back(l);
      // v.push_back({b + l - A.at(i), l});
    }
  }

  pll ans = crt(r, m);
  if (ans.first == 0) {
    cout << ans.second << "\n";
  }
  else {
    cout << ans.first << endl;
=======
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N, M;
  cin >> N >> M;
  vector<ll> P(N);
  for (ll i = 0; i < N; ++i) {
    cin >> P.at(i);
  }
  sort(rng(P));
  vector<ll> L(M), D(M);
  for (ll i = 0; i < M; ++i) {
    cin >> L.at(i);
  }
  for (ll i = 0; i < M; ++i) {
    cin >> D.at(i);
  }
  mcf_graph<int, ll> g(N + M + 2);
  ll c = 1, p = c + M;
  ll s = 0, t = N + M + 1;
  for (ll i = 0; i < M; ++i) {
    g.add_edge(s, c + i, 1, 0);
  }
  for (ll i = 0; i < N; ++i) {
    g.add_edge(p + i, t, 1, 0);
  }
  for (ll i = 0; i < N - 1; ++i) {
    g.add_edge(p + i, p + i + 1, N - i, P.at(i + 1) - P.at(i));
  }
  for (ll i = 0; i < M; ++i) {
    ll index = lower_bound(rng(P), L.at(i)) - P.begin();
    if (index != P.size()) {
      g.add_edge(c + i, p + index, 1, P.at(index) - D.at(i));
    }
  }
  //そのまま買う
  for (ll i = 0; i < N; ++i) {
    g.add_edge(s, p + i, 1, P.at(i));
>>>>>>> df1de9738cdd8fae687ce3654ee73592aadaaef8
  }
  pll ans = g.flow(s, t);
  // cout << ans.first << "\n";
  cout << ans.second << "\n";
}

// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   ll N;
//   cin >> N;
//   mcf_graph<int, ll> g(400);
//   ll team_index = 1, category_index = 151;
//   ll s = 0, t = 301;
//   for (ll i = 0; i < 150; ++i) {
//     g.add_edge(s, team_index + i, 1, 0);
//   }
//   for (ll i = 0; i < 150; ++i) {
//     g.add_edge(category_index + i, t, 1, 0);
//   }
//   ll MC = 1000000000;
//   for (ll i = 0; i < N; ++i) {
//     ll a, b, c;
//     cin >> a >> b >> c;
//     a = a + team_index - 1, b = b + category_index - 1;
//     g.add_edge(a, b, 1, MC - c);
//   }
//   vector<ll> ans;
//   for (ll i = 1; i <= N; ++i) {
//     mcf_graph<int, ll> temp_g = g;
//     pll f = temp_g.flow(s, t, i);
//     // cout << f.first << ' ' << f.second << "\n";
//     if (f.first != i) {
//       break;
//     }
//     ans.push_back(MC * i - f.second);
//   }
//   // for (ll i = 0; i < (ll)ans.size() - 1; ++i) {
//   //   ans.at(i + 1) += ans.at(i);
//   // }
//   cout << ans.size() << "\n";
//   for (ll i = 0; i < ans.size(); ++i) {
//     cout << ans.at(i) << "\n";
//   }
// }
