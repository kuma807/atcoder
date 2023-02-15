// ============how it works=================
//convex_hull_trick cht(get_big);
  //初期化 get_big = trueで最大、get_big = falseで最小値を取得

// add(ll a, ll b)
  //直線y=ax+bを追加

// query(const ll x)
  //指定したx座標で一番大きい/小さい値を取る直線のy座標を返す

//計算量 直線の数 N、クエリ数 Qとすると
//O((N + Q)logN)
// ========================================

//=============convex_hull_trick============================
ll floor_div(const ll x, const ll y) { return x / y - ((x ^ y) < 0 && x % y != 0); }

class convex_hull_trick {
  struct line {
    ll a, b;
    //一番この直線が大きい区間を表す[start, end]ならp = end
    mutable ll p;
    //線どおしの比較演算子
    bool operator<(const line& l) const { return a < l.a; }
    //線と数値の比較演算子、query(x)のとき今一番多き直線を2分探索するために使う
    bool operator<(const ll x) const { return p < x; }
  };

  using container = multiset<line, std::less<>>;
  using iter = container::iterator;
  bool get_big;

  static constexpr ll inf = numeric_limits<ll>::max();

  container set;

  bool remove(const iter& x, const iter& y) {
    if (y == set.end()) {
      x->p = inf;
      return false;
    }
    if (x->a == y->a) {
      x->p = (x->b > y->b) ? inf : -inf;
    } else {
      x->p = floor_div(x->b - y->b, y->a - x->a);
    }
    return !(x->p < y->p);
  }

  public:
  convex_hull_trick(bool get_big_) : set(), get_big(get_big_) {}

  void add(ll a, ll b) {
    if (!get_big) {
      a = -a, b = -b;
    }
    auto z = set.insert({a, b, 0});
    auto y = z++;
    auto x = y;
    while (remove(y, z)) {
      z = set.erase(z);
    }
    if (x != set.begin() && remove(--x, y)) {
      remove(x, y = set.erase(y));
      return;
    }
    while ((y = x) != set.begin() && !((--x)->p < y->p)) {
      remove(x, set.erase(y));
    }
  }

  ll query(const ll x) const {
    const auto it = set.lower_bound(x);
    ll res = (it->a) * x + (it->b);
    if (!get_big) {
      res = -res;
    }
    return res;
  }
};
//=================================================
