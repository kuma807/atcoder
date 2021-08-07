#include <bits/stdc++.h>
// #include <atcoder/modint>
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define INF 2000000000000000000
#define ll long long
#define ld long double
#define pll pair<ll, ll>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const double PI = 3.141592653589793;

ll mod = pow(10, 9) + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll H, W;
  cin >> H >> W;
  string w;
  string b;
  for (ll i = 0; i < W; ++i) {
    w += '.';
    b += '#';
  }
  vector<string> C(H + 1, w);
  for (ll i = 0; i < H; ++i) {
    cin >> C.at(i);
  }
  map<string, ll> mp;
  mp[C.at(0)] = 1;
  for (ll i = 0; i < H; ++i) {
    map<string, ll> temp;
    // temp[C.at(i + 1)] = 1;
    for (const auto& [key, value] : mp){
      string s = key;
      set<string> from = {C.at(i + 1)};
      temp[C.at(i + 1)] += value;
      temp[C.at(i + 1)] %= mod;
      queue<pair<ll, string>> storage;
      for (ll j = 0; j < W; ++j) {
        while (true) {
          pair<ll, string> p = storage.front();
          if (j - p.first <= 1) {
            break;
          }
          storage.pop();
          from.insert(storage.at(j % 2).at(k));
        }
        storage.at(j % 2) = {};
        if (s.at(j) == '.') {
          for(auto itr = from.begin(); itr != from.end(); ++itr) {
            string now = *itr;
            for (ll k = -1; k <= 1; ++k) {
              if ((0 <= k + j) && (k + j < W)) {
                now.at(k + j) = '#';
              }
            }
            if (temp.find(now) == temp.end()) {
              temp[now] = 0;
            }
            storage.at(j % 2).push_back(now);
            // cout << j << ' ' << now << "\n";
            temp[now] += value;
            temp[now] %= mod;
          }
        }
      }
    }
    // for (const auto& [key, value] : mp){
    //   cout << key << ' ' << value << "\n";
    // }
    // cout << "\n";
    mp = temp;
  }
  ll ans = 0;
  for (const auto& [key, value] : mp){
    cout << key << ' ' << value << "\n";
    ans += value;
    ans %= mod;
  }
  cout << ans << "\n";
}
