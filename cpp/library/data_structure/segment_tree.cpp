// ============how it works=================
//segment_tree<ll, marge, replaceNode> seg(N, identity);
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

ll marge(ll a, ll b) {
  return a + b;
}

ll replaceNode(ll a, ll b) {
  return b;
}

//=============segment_tree============================
template <class T, T (*Marge)(T, T), T (*ReplaceNode)(T, T)>
struct segment_tree {
  int MAX_N;
  int nn;
  vector<ll> dat;
  T Identity;
  segment_tree(ll n_, T identity) {
    Identity = identity;
    nn = 1;
    while (nn < n_) {
      nn *= 2;
    }
    MAX_N = nn;
    dat = vector<ll>(2 * MAX_N - 1, Identity);
  }

  void update(ll k, ll a) {
    k += nn - 1;
    dat.at(k) = ReplaceNode(dat.at(k), a);//要変更
    while (k > 0) {
      k = (k - 1) / 2;
      dat.at(k) = ReplaceNode(dat.at(k), Marge(dat.at(k * 2 + 1), dat.at(k * 2 + 2)));//要変更
    }
  }

  ll query(ll a, ll b, ll k = -1, ll l = -1, ll r = -1) {
    if (k == -1 && l == -1 && r == -1) {
      k = 0, l = 0, r = nn;
    }
    if (r <= a || b <= l) {
      return Identity;//要変更
    }
    if (a <= l && r <= b) {
      return dat.at(k);
    }
    else {
      ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return Marge(vl, vr);//要変更
    }
  }
};
//=================================================
