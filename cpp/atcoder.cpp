#include <bits/stdc++.h>
#define INF 2000000000000000000
#define ll long long
using namespace std;

ll temp = pow(2, 32) - 1;
//=============matpow============================
vector<vector<ll>> matmul(vector<vector<ll>>& a, vector<vector<ll>>& b)
{
  vector<vector<ll>> res(a.size(), vector<ll>(b.at(0).size()));
  for (ll row = 0; row < a.size(); ++row) {
    for (ll colom = 0; colom < b.at(0).size(); ++colom) {
      ll sum = 0;
      for (ll i = 0; i < b.size(); ++i) {
        sum = (sum ^ (a.at(row).at(i) & b.at(i).at(colom)));
      }
      res.at(row).at(colom) = sum;
    }
  }
  return res;
}

vector<vector<ll>> matpow(vector<vector<ll>> a, ll power)
{
  vector<vector<ll>> res(a.size(), vector<ll>(a.size(), 0));
  for (ll i = 0; i < a.size(); ++i) {
    res.at(i).at(i) = temp;
  }
  while (power) {
    if (power & 1) {
      res = matmul(a, res);
    }
    a = matmul(a, a);
    power = (power >> 1);
  }
  return res;
}
//=================================================

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll K, M;
  cin >> K >> M;
  vector<vector<ll>> A(K, vector<ll>(1));
  for (ll i = 0; i < K; ++i) {
    cin >> A.at(i).at(0);
  }
  vector<vector<ll>> C(K, vector<ll>(K, 0));
  for (ll i = 0; i < K - 1; ++i) {
    C.at(i).at(i + 1) = temp;
  }
  for (ll i = 0; i < K; ++i) {
    cin >> C.at(K - 1).at(K - 1 - i);
  }
  // for (ll i = 0; i < C.size(); ++i) {
  //   for (ll j = 0; j < C.at(0).size(); ++j) {
  //     cout << C.at(i).at(j) << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";
  C = matpow(C, M - 1);
  // for (ll i = 0; i < C.size(); ++i) {
  //   for (ll j = 0; j < C.at(0).size(); ++j) {
  //     cout << C.at(i).at(j) << " ";
  //   }
  //   cout << "\n";
  // }
  A = matmul(C, A);
  cout << A.at(0).at(0) << "\n";
}
