// ============how it works=================
//quadratic_division qd(N);
  //ノード数Nの初期化

//MAX_N
  //最大ノード数

// update(ll a, ll b, ll k)
  //[a, b)の値をkで更新する
  //update(a, b, k)
  //計算量O(√N)

// query(ll a, ll b)
  //[a, b)の和を求める
  //計算量O(√N)
//a,bはすべて0indexである
// ========================================

//=============quadratic_division============================
struct quadratic_division {
  ll MAX_N;
  ll nn;
  vector<ll> dat;
  vector<ll> division;
  vector<ll> lazy;
  quadratic_division(ll n_) {
    nn = 1;
    while (nn * nn < n_) {
      nn += 1;
    }
    MAX_N = nn * nn;
    dat = vector<ll>(MAX_N, 0);//要変更
    division = vector<ll>(nn, 0);//要変更
    lazy = vector<ll>(nn, -1);//要変更
  }

  void eval(ll division_index) {
    if (nn <= division_index) {
      return;
    }
    ll k = lazy.at(division_index);
    if (lazy.at(division_index) == -1) {//要変更
      return;
    }
    for (ll i = division_index * nn; i < min(MAX_N, (division_index + 1) * nn); ++i) {
      dat.at(i) = k;
    }
    lazy.at(division_index) = -1;//要変更
  }

  void update(ll a, ll b, ll k) {
    ll da = a / nn, db = b / nn;
    for (ll i = da + 1; i < min(nn, db); ++i) {
      division.at(i) = k * nn;
      lazy.at(i) = k;
    }
    eval(da);
    for (ll i = a; i < min((da + 1) * nn, b); ++i) {
      division.at(da) += k - dat.at(i);
      dat.at(i) = k;
    }
    if (da != db) {
      eval(db);
      for (ll i = max(db * nn, a); i < min(MAX_N, b); ++i) {
        division.at(db) += k - dat.at(i);
        dat.at(i) = k;
      }
    }
  }

  ll query(ll a, ll b) {
    ll res = 0;//要変更
    ll da = a / nn, db = b / nn;
    for (ll i = da + 1; i < min(nn, db); ++i) {
      res += division.at(i);//要変更
    }
    eval(da);
    for (ll i = a; i < min((da + 1) * nn, b); ++i) {
      res += dat.at(i);//要変更
    }
    if (da != db) {
      eval(db);
      for (ll i = max(db * nn, a); i < min(MAX_N, b); ++i) {
        res += dat.at(i);//要変更
      }
    }
    return res;
  }
};
//=================================================
