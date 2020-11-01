#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
#define INF 2000000000000000000
#define ll long long
#define ld long double
#define pll pair<ll, ll>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N = 6;
  vector<ll> A(N);
  for (ll i = 0; i < N; ++i) {
    cin >> A.at(i);
  }
  ll M;
  cin >> M;
  vector<ll> B(M);
  for (ll i = 0; i < M; ++i) {
    cin >> B.at(i);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  vector<vector<ll>> fret(M, vector<ll>(N));
  for (ll i = 0; i < M; ++i) {
    for (ll j = 0; j < N; ++j) {
      fret.at(i).at(j) = B.at(i) - A.at(j);
      cout << fret.at(i).at(j) << " ";
    }
    cout << "\n";
  }
}
