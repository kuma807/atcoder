// ============how it works=================
//segment_tree seg(N);
  //ノード数Nの初期化

//MAX_N
  //最大ノード数

// update(ll k, ll a)
  //k番目の値をaに更新

// query(ll a, ll b, ll k, ll l, ll r)
  //[a, b)の最小値を求めるとき
    //query(a, b)とする
//a,b, k, l, r  はすべて0indexである

//子ノードはdat[n〜]
// ========================================

//=============segment_tree============================
struct segment_tree {
  int MAX_N;
  int nn;
  vector<ll> dat;
  segment_tree(ll n_) {
    MAX_N = 1 << 17;//要変更(1 << 17 ≒ 10 ^ 5)
    dat = vector<ll>(2 * MAX_N - 1, 0);//要変更
    nn = 1;
    while (nn < n_) {
      nn *= 2;
    }
  }

  void update(ll k, ll a) {
    k += nn - 1;
    dat.at(k) += a;//要変更
    while (k > 0) {
      k = (k - 1) / 2;
      dat.at(k) = dat.at(k * 2 + 1) + dat.at(k * 2 + 2);//要変更
    }
  }

  ll query(ll a, ll b, ll k, ll l, ll r) {
    if (r <= a || b <= l) {
      return 0;//要変更
    }
    if (a <= l && r <= b) {
      return dat.at(k);
    }
    else {
      ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return vl + vr;//要変更
    }
  }

  ll query(ll a, ll b) {
    ll k = 0, l = 0, r = nn;
    if (r <= a || b <= l) {
      return 0;//要変更
    }
    if (a <= l && r <= b) {
      return dat.at(k);
    }
    else {
      ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return vl + vr;//要変更
    }
  }
};
//=================================================
