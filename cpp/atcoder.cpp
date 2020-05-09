#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

vector<vector<ll>> modmatmul(vector<vector<ll>>& a, vector<vector<ll>>& b, ll mod)
{
  vector<vector<ll>> res(a.size(), vector<ll>(b.at(0).size()));
  for (ll row = 0; row < a.size(); ++row) {
    for (ll colom = 0; colom < b.at(0).size(); ++colom) {
      ll sum = 0;
      for (ll i = 0; i < b.size(); ++i) {
        sum = (sum  + a.at(row).at(i) * b.at(i).at(colom) % mod) % mod;
      }
      res.at(row).at(colom) = sum;
    }
  }
  return res;
}

vector<vector<ll>> modmatpow(vector<vector<ll>> a, ll power, ll mod)
{
  vector<vector<ll>> res(a.size(), vector<ll>(a.size(), 0));
  for (ll i = 0; i < a.size(); ++i) {
    res.at(i).at(i) = 1;
  }
  while (power) {
    if (power & 1) {
      res = modmatmul(a, res, mod);
    }
    a = modmatmul(a, a, mod);
    power = (power >> 1);
  }
  return res;
}

int main()
{
  ll N, mod;
  cin >> N >> mod;
  vector<vector<ll>> matrix = {{0, 1}, {1, 1}};
  vector<vector<ll>> F = {{0}, {1}};
  matrix = modmatpow(matrix, N - 2, mod);
  vector<vector<ll>> ans = modmatmul(matrix, F, mod);
  cout << ans.at(1).at(0) << "\n";
}
