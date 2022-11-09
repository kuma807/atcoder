// ============how it works=================
//segment_tree_with_lazy_propagation lseg(N);
  //ノード数Nの初期化

//MAX_N
  //最大ノード数

// update(ll a, ll b, ll plus, ll k = 0, ll l = 0, ll r = n)
  //[a, b)の値をplusで更新する
  //update(a, b, plus)

// query(ll a, ll b, ll k, ll l, ll r)
  //[a, b)の最小値を求めるとき
    //query(a, b, 0, 0, N)とする
//a,b, k, l, r  はすべて0indexである

//子ノードはdat[n〜]
// ========================================

//=============Segment_Tree_with_Lazy_Propagation====
struct segment_tree_with_lazy_propagation {
  int MAX_N;
  int n;
  ll N;
  vector<ll> dat;
  vector<ll> lazy;

  segment_tree_with_lazy_propagation(ll n_) {
    N = n_;
    n = 1;
    while (n < n_) {
      n *= 2;
    }
    MAX_N = n;
    dat = vector<ll>(2 * MAX_N - 1, pow(2, 31) - 1);//要変更
    lazy = vector<ll>(2 * MAX_N - 1, INF);//要変更
  }

  void eval(ll k, ll l, ll r) {
    if (lazy.at(k) != INF) {
      dat.at(k) = lazy.at(k);//要変更
      if (r - l > 1) {
        lazy.at(k * 2 + 1) = lazy.at(k);//要変更
        lazy.at(k * 2 + 2) = lazy.at(k);//要変更
      }
      lazy.at(k) = INF;//要変更
    }
  }

  void update(ll a, ll b, ll plus, ll k = -1, ll l = -1, ll r = -1) {
    assert(0 <= a && a <= N && 0 <= b && b <= N);
    if (k == -1 && l == -1 && r == -1) {
      k = 0, l = 0, r = n;
    }
    if (r <= a || b <= l) {
      eval(k, l, r);//子供のlazyを更新する必要がある
      return;
    }
    if (a <= l && r <= b) {
      lazy.at(k) = plus;//要変更
      eval(k, l, r);//子供のlazyを更新する必要がある
    }
    else {
      eval(k, l, r);//updateで使う子供のlazeとdat.at(k)の更新
      update(a, b, plus, k * 2 + 1, l, (l + r) / 2);
      update(a, b, plus, k * 2 + 2, (l + r) / 2, r);
      dat.at(k) = min(dat.at(2 * k + 1), dat.at(2 * k + 2));//要変更
    }
  }

  ll query(ll a, ll b, ll k = -1, ll l = -1, ll r = -1) {
    assert(0 <= a && a <= N && 0 <= b && b <= N);
    if (k == -1 && l == -1 && r == -1) {
      k = 0, l = 0, r = n;
    }
    if (r <= a || b <= l) {
      return INF;//要変更
    }
    eval(k, l, r);//dat.at(k)と子供のlazy更新のためreturn datとqueryに必要
    if (a <= l && r <= b) {
      return dat.at(k);
    }
    else {
      ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return min(vl, vr);//要変更
    }
  }
};
//=================================================
