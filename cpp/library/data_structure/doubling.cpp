// ============how it works=================
//call
  // doubling D(temp);
    //temp[log][N]←temp[i][j]はjの2^i先
      //temp[0]は埋めておく
//use
  //D.dest(now, dist)
    //nowからdist先の場所がわかる
// ========================================

//=============doubling============================
struct doubling {
  vector<ll> power;
  vector<vector<ll>> d;
  ll N, log;
  doubling(vector<vector<ll>> temp) {
    d = temp;
    log = d.size(), N = d.at(0).size();
    power = vector<ll>(log, 1);
    for (ll i = 0; i < log - 1; ++i) {
      power.at(i + 1) = power.at(i) * 2;
    }
    for (ll i = 0; i < log - 1; ++i) {
      for (ll j = 0; j < N; ++j) {
        d.at(i + 1).at(j) = d.at(i).at(d.at(i).at(j));
      }
    }
  }
  ll dest(ll now, ll dist) {
    for (ll i = 0; i < log; ++i) {
      if ((dist & power.at(i)) != 0) {
        now = d.at(i).at(now);
      }
    }
    return now;
  }
};
//=================================================
