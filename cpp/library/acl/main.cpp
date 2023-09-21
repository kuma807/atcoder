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
  }
}
