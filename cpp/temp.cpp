#include <bits/stdc++.h>
#define INF 2000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;
bool debug = true;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N, M;
  cin >> N >> M;
  vector<ll> a(N), b(M);
  for (ll i = 0; i < N; ++i) {
    cin >> a.at(i);
  }
  for (ll i = 0; i < M; ++i) {
    cin >> b.at(i);
  }
  vector<bool> ans(pow(2, 9), true);
  for (ll i = 0; i < N; ++i) {
    set<ll> pos;
    for (ll j = 0; j < M; ++j) {
      pos.insert((a.at(i) & b.at(j)));
    }
    for (ll j = 0; j < pow(2, 9); ++j) {
      if (!ans.at(j)) {
        continue;
      }
      if (pos.find(j) == pos.end()) {
        ans.at(j) = false;
      }
    }
  }
  for (ll i = 0; i < pow(2, 9); ++i) {
    if (ans.at(i)) {
      cout << i << "\n";
      return 0;
    }
  }
}
