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
  ll N;
  int nn;
  vector<ll> dat;
  segment_tree(ll n_) {
    N = n_;
    nn = 1;
    while (nn < n_) {
      nn *= 2;
    }
    MAX_N = nn;
    dat = vector<ll>(2 * MAX_N - 1, 0);
  }

  void update(ll k, ll a) {
    assert(0 <= k && k < N);
    k += nn - 1;
    dat.at(k) = a;//要変更
    while (k > 0) {
      k = (k - 1) / 2;
      dat.at(k) = __gcd(dat.at(k * 2 + 1), dat.at(k * 2 + 2));//要変更
    }
  }

  ll query(ll a, ll b, ll k = -1, ll l = -1, ll r = -1) {
    assert(0 <= a && a < N && 0 <= b && b <= N);
    if (k == -1 && l == -1 && r == -1) {
      k = 0, l = 0, r = nn;
    }
    if (r <= a || b <= l) {
      return 0;//要変更
    }
    if (a <= l && r <= b) {
      return dat.at(k);
    }
    else {
      ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return __gcd(vl, vr);//要変更
    }
  }
};
//=================================================
