// ============how it works=================
//mos_algorithm mos(A, query);
  //配列Aに対するクエリqueryを処理
  //mos.query(query)で答えを返す

//query_struct
  //クエリの構造 l, r, index(何番目のクエリか)は必須
  //l, r, indexは0-index

// response_struct
  //クエリに対するリスポンスの構造

// status_struct
  //現状の状態の構造体
    //init_status
      //状態の初期化
    //move_l_left
      //左端を左へ移動
    //update(nl, nr)
      //左端をnl、右端をnrに移動させる
    //get_status
      //今の状態の答え返す

//計算量がギリギリのときはmove_l_leftなどをできるだけO(1)にする
// ========================================

//=============mos_algorithm============================
//l, r, indexは必要
struct query_struct {ll l, r, index, block = -1;};//要変更
struct response_struct {ll ans;};//要変更

struct status_struct {//要変更
  ll l, r;
  ll num = 0;
  vector<ll> A;
  vector<ll> now_status;

  void init_status() {//要変更
    now_status.at(A.at(0) - 1) = 1;
    l = 0, r = 0;
  }

  status_struct(vector<ll> A_) {
    A = A_;
    now_status = vector<ll>(A.size(), 0);
    init_status();
  }

  void move_l_left() {//要変更
    //add
    l -= 1;
    ll a = A.at(l) - 1;
    now_status.at(a) += 1;
    if (now_status.at(a) % 2 == 1) {
      num += 1;
    }
    else {
      num -= 1;
    }
  }

  void move_l_right() {//要変更
    //erase
    ll a = A.at(l) - 1;
    now_status.at(a) += 1;
    if (now_status.at(a) % 2 == 1) {
      num += 1;
    }
    else {
      num -= 1;
    }
    l += 1;
  }

  void move_r_right() {//要変更
    //add
    r += 1;
    ll a = A.at(r) - 1;
    now_status.at(a) += 1;
    if (now_status.at(a) % 2 == 1) {
      num += 1;
    }
    else {
      num -= 1;
    }
  }

  void move_r_left() {//要変更
    //erase
    ll a = A.at(r) - 1;
    now_status.at(a) += 1;
    if (now_status.at(a) % 2 == 1) {
      num += 1;
    }
    else {
      num -= 1;
    }
    r -= 1;
  }

  void update(ll nl, ll nr) {
    while (nl < l) {
      move_l_left();
    }
    while (r < nr) {
      move_r_right();
    }
    while (l < nl) {
      move_l_right();
    }
    while (nr < r) {
      move_r_left();
    }
  }

  response_struct get_status() {
    return {((r - l + 1) - num) / 2};//要変更
  }
};

struct mos_algorithm {
  ll N, Q, q;
  vector<response_struct> response_vec;

  mos_algorithm(vector<ll> A, vector<query_struct> query_vec) {
    N = A.size(), Q = query_vec.size();
    response_vec = vector<response_struct>(Q);
    ll B = max(1ll, (ll)sqrt(N * N / Q));
    q = 1;
    while (q * q < Q) {
      q += 1;
    }
    for (ll i = 0; i < query_vec.size(); ++i) {
      query_vec.at(i).block = query_vec.at(i).l / B;
    }
    sort(rng(query_vec), [&](query_struct a, query_struct b) {
      //要変更
      //queryのソート方法
      ll ai = a.block, bi = b.block;
      if (ai == bi) {
        if (ai % 2 == 1) {
          return a.r > b.r;
        }
        return a.r < b.r;
      }
      return ai < bi;
    });
    status_struct now_status(A);
    for (ll i = 0; i < Q; ++i) {
      now_status.update(query_vec.at(i).l, query_vec.at(i).r);
      response_vec.at(query_vec.at(i).index) = now_status.get_status();
    }
  }

  response_struct query(query_struct que) {
    return response_vec.at(que.index);
  }
};
//=================================================
