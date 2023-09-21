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
const double PI = 3.141592653589793238462643383279;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll T;
  cin >> T;
  for (ll testcase = 0; testcase < T; ++testcase) {
    ll N;
    cin >> N;
    vector<ll> C(N);
    multiset<pll> st;// cost, -index
    for (ll i = 0; i < N; ++i) {
      cin >> C.at(i);
      st.insert({C.at(i), -(i)});
    }
    ll K;
    cin >> K;
    vector<ll> ans(N + 1, 0);
    for (ll i = 0; i < N; ++i) {
      pll a = *st.begin();
      ll cost = a.first, index = -a.second;
      ll time = K / cost;
      ans.at(i) = time;
      // K -= time * cost;
      // ans.at(0) += time;
      // ans.at(index + 1) -= time;
      st.erase(st.find({C.at(i), -i}));
    }
    // for (ll i = 0; i < N; ++i) {
    //   ans.at(i + 1) += ans.at(i);
    // }
    for (ll i = 0; i < N; ++i) {
      cout << ans.at(i) << " ";
    }
    cout << "\n";
  }
}
