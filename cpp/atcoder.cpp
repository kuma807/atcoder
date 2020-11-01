#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define ld long double
#define pll pair<ll, ll>
using namespace std;

//=============dice============================
vector<vector<ll>> way = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//first == front
map<pll, ll> right_side;//{front, top}
bool called_init = false;

void init() {
  right_side[{1, 2}] = 3;right_side[{1, 3}] = 5;right_side[{1, 5}] = 4;right_side[{1, 4}] = 2;
  called_init = true;
  right_side[{2, 1}] = 4;right_side[{2, 4}] = 6;right_side[{2, 6}] = 3;right_side[{2, 3}] = 1;
  right_side[{3, 1}] = 2;right_side[{3, 2}] = 6;right_side[{3, 6}] = 5;right_side[{3, 5}] = 1;
  right_side[{4, 1}] = 5;right_side[{4, 5}] = 6;right_side[{4, 6}] = 2;right_side[{4, 2}] = 1;
  right_side[{5, 1}] = 3;right_side[{5, 3}] = 6;right_side[{5, 6}] = 4;right_side[{5, 4}] = 1;
  right_side[{6, 2}] = 4;right_side[{6, 4}] = 5;right_side[{6, 5}] = 3;right_side[{6, 3}] = 2;
}

void roll(pll& stat, vector<ll> w) {
  if (!called_init) {
    init();
  }
  if (w == way.at(0)) {
    ll temp1 = 7 - stat.first;
    stat.first = stat.second;
    stat.second = temp1;
  }
  else if (w == way.at(1)) {
    stat.second = 7 - right_side[stat];
  }
  else if (w == way.at(2)) {
    ll temp1 = 7 - stat.second;
    stat.second = stat.first;
    stat.first = temp1;
  }
  else {
    stat.second = right_side[stat];
  }
}
//=================================================


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while (true) {
    ll N;
    cin >> N;
    if (N == 0) {
      break;
    }
    vector<vector<pll>> board(2 * N + 1, vector<pll>(2 * N + 1, {0, 0}));//hight, top
    ll sx = N, sy = N;
    for (ll i = 0; i < N; ++i) {
      ll t, f;
      cin >> t >> f;
      while (true) {
        bool found = true;
      }
    }
  }
}
