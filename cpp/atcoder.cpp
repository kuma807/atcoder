#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

vector<vector<ll>> mk_block(string& S, vector<ll>& A) {
  vector<vector<ll>> res = {};
  bool start = false;
  char before = '1';
  vector<ll> temp = {};
  for (ll i = 0; i < S.size(); ++i) {
    if (!start && S[i] == '0') {
      continue;
    }
    else {
      start = true;
    }
    if (S[i] == before) {
      temp.push_back(A.at(i));
    }
    else {
      res.push_back(temp);
      temp = {};
      temp.push_back(A.at(i));
    }
    before = S[i];
  }
  if (start && (temp.size() != 0)) {
    res.push_back(temp);
  }
  return res;
}

int main() {
  ll T;
  cin >> T;
  for (ll testcase = 0; testcase < T; ++testcase) {
    bool zero = true;
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
      cin >> A.at(i);
    }
    string S;
    cin >> S;
    if (S[N - 1] == '1') {
      cout << 1 << "\n";
      continue;
    }
    vector<vector<ll>> block = mk_block(S, A);
    if (block.size() == 0) {
      cout << 0 << "\n";
      continue;
    }
    vector<ll> roof(block.size());
    for (ll i = 0; i < block.size(); ++i) {
      ll M = 0;
      for (ll j = 0; j < block.at(i).size(); ++j) {
        M = max(block.at(i).at(j), M);
      }
      ll roof_M = 1;
      while (roof_M <= M) {
        roof_M *= 2;
      }
      roof.at(i) = roof_M - 1;
    }
    ll check = roof.at(0);
    for (ll i = 0; i < block.size() / 2; ++i) {
      unordered_map<ll, bool> mp;
      for (ll j = 0; j < block.at(i * 2 + 1).size(); ++j) {
        mp[block.at(i * 2 + 1).at(j)] = true;
      }
      for (ll j = 0; j < block.at(i * 2).size(); ++j) {
        ll now = block.at(i * 2).at(j);
        if (mp[now] || mp[now ^ roof.at(i)]) {
          continue;
        }
        zero = false;
        break;
      }
      if (!zero) {
        break;
      }
    }
    if (zero) {
      cout << 0 << "\n";
    }
    else {
      cout << 1 << "\n";
    }
    // for (ll i = 0; i < roof.size(); ++i) {
    //   cout << roof.at(i) << "\n";
    // }
    // for (ll i = 0; i < block.size(); ++i) {
    //   for (ll j = 0; j < block.at(i).size(); ++j) {
    //     cout << block.at(i).at(j) << " ";
    //   }
    //   cout << "\n";
    // }
    // break;
  }
}
