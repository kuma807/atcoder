// ============how it works=================
// input:
  //ll cnt = count_inversion(A);
  //vector<ll> A; 順列じゃなくて良い
// output:
  //cnt = 転倒数
// ========================================

//=============count_inversion============================
struct segment_tree {
  int MAX_N;
  int nn;
  vector<ll> dat;
  segment_tree(ll n_) {
    nn = 1;
    while (nn < n_) {
      nn *= 2;
    }
    MAX_N = nn;
    dat = vector<ll>(2 * MAX_N - 1, 0);
  }

  void update(ll k, ll a) {
    k += nn - 1;
    dat.at(k) += a;//要変更
    while (k > 0) {
      k = (k - 1) / 2;
      dat.at(k) = (dat.at(k * 2 + 1) + dat.at(k * 2 + 2));//要変更
    }
  }

  ll query(ll a, ll b, ll k = -1, ll l = -1, ll r = -1) {
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
      return (vl + vr);//要変更
    }
  }
};

void erase_continuous(vector<ll> &A) {
  sort(rng(A));
  A.erase(unique(rng(A)), A.end());
}

ll count_inversion(vector<ll> A) {
  vector<ll> temp = A;
  erase_continuous(temp);
  ll N = temp.size();
  for (ll i = 0; i < A.size(); ++i) {
    A.at(i) = lower_bound(rng(temp), A.at(i)) - temp.begin();
  }
  segment_tree seg(N);
  ll res = 0;
  for (ll i = 0; i < A.size(); ++i) {
    res += seg.query(A.at(i) + 1, N);
    seg.update(A.at(i), 1);
  }
  return res;
}
//=================================================
