// ============how it works=================
//imos imos1(N);
  //ノード数Nの初期化

// update(ll a, ll b, ll plus)
  //[a, b)の値をplusで更新する
  //update(a, b, plus)

// query(ll a)
  //aの値を求めるとき
    //query(a)とする
//a,b, k, l, r  はすべて0indexである
// ========================================


//=============imos================
struct imos {
  vector<ll> dat;
  ll N;
  bool calc_sum = false;
  imos(ll n_) {
    N = n_;
    dat = vector<ll>(N + 2, 0);//要変更
  }

  void sum() {
    for (ll i = 0; i < N + 1; ++i) {
      dat.at(i + 1) += dat.at(i);//要変更
    }
    calc_sum = true;
  }

  void update(ll a, ll b, ll plus) {
    if (calc_sum) {
      cout << "update cant be done after query" << "\n";
    }
    dat.at(a) += plus;//要変更
    dat.at(b) -= plus;//要変更
  }

  ll query(ll a) {
    if (!calc_sum) {
      sum();
    }
    return dat.at(a);
  }
};
//=================================================
