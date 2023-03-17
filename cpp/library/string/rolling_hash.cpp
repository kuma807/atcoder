// ============how it works=================
// init_rolling_hash(ll n)
  //modの数をn個でハッシュを計算、nはデフォルトで3
  // O(log(mod))

// calc_hash(string s)
  // sのハッシュを計算する
  // 計算量 O(Sの長さ)

// add_back(vector<pll> a, char c)
  //文字列sのハッシュがaのときaを s + c のハッシュに置き換える
  //計算量　O(1)

// add_front(vector<pll> a, char c)
  //文字列sのハッシュがaのときaを c + s のハッシュに置き換える
  //計算量　O(1)

// pop_back(vector<pll> a, char c)
  //文字列sの右の文字がcの時、sから一番右の文字であるc取り除きのaを新しい文字列のハッシュに置き換える
    // 例
    //vector<pll> a = "abc"のハッシュ;
    //pop_front(a, 'c')
    //aは"ab"のハッシュになる
  //計算量　O(1)

// pop_front(vector<pll> a, char c)
  //文字列sの左の文字がcの時、sから一番左の文字であるc取り除きのaを新しい文字列のハッシュに置き換える
    // 例
    //vector<pll> a = "abc"のハッシュ;
    //pop_front(a, 'a')
    //aは"bc"のハッシュになる
  //計算量　O(1)

//unite(vector<pll> a, vector<pll> b)
  // 文字列a + bのハッシュを返す
  //計算量 O(1)
// ========================================

//=============modinv============================
ll modinv(ll a, ll m) {
  ll b = m, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}
//=================================================

//=============rolling_hash============================
bool init_called = false;
vector<pair<ll, ll>> MB = {{2147483647, 2147483634}, {2147483629, 2147483627}, {2147483587, 2147483583}, {2147483579, 2147483576}, {2147483563, 2147483550}, {2147483543, 2147483541}, {2147483497, 2147483492}, {2147483489, 2147483486}, {2147483477, 2147483475}};
vector<ll> Ms, Bs, invs;

void init_rolling_hash(ll n = 3) {
  init_called = true;
  vector<ll> already;
  assert(n <= MB.size());
  random_device rnd;
  mt19937 mt(rnd());
  for (ll i = 0; i < n; ++i) {
    uniform_int_distribution<> rand9(0, (ll)MB.size() - i - 1);
    ll temp = rand9(mt);
    ll cnt = 0;
    for (ll j = 0; j < already.size(); ++j) {
      if (already.at(j) <= temp) {
        cnt += 1;
      }
    }
    temp += cnt;
    already.push_back(temp);
    Ms.push_back(MB.at(temp).first);
    Bs.push_back(MB.at(temp).second);
    invs.push_back(modinv(MB.at(temp).second, MB.at(temp).first));
  }
  assert(already.size() == n);
}

vector<pll> calc_hash(string a) {
  if (!init_called) {
    init_rolling_hash();
  }
  vector<pll> res;
  for (ll itr = 0; itr < Ms.size(); ++itr) {
    ll M = Ms.at(itr), B = Bs.at(itr);
    ll t = 1;
    ll ah = 0;
    for (ll i = 0; i < a.size(); ++i) {
      ah = (ah * B + a.at(i)) % M;
      t = (t * B) % M;
    }
    res.push_back({ah, t});
  }
  return res;
}

vector<pll> add_back(vector<pll> &a, char c) {
  for (ll itr = 0; itr < Ms.size(); ++itr) {
    ll M = Ms.at(itr), B = Bs.at(itr);
    a.at(itr).first = (a.at(itr).first * B + c) % M;
    a.at(itr).second = a.at(itr).second * B % M;
  }
  return a;
}

vector<pll> add_front(vector<pll> &a, char c) {
  for (ll itr = 0; itr < Ms.size(); ++itr) {
    ll M = Ms.at(itr), B = Bs.at(itr);
    a.at(itr).first = (a.at(itr).first + c * a.at(itr).second) % M;
    a.at(itr).second = a.at(itr).second * B % M;
  }
  return a;
}

vector<pll> pop_back(vector<pll> &a, char c) {
  for (ll itr = 0; itr < Ms.size(); ++itr) {
    ll M = Ms.at(itr), B = Bs.at(itr), inv = invs.at(itr);
    a.at(itr).first = ((a.at(itr).first - c + M) % M) * inv % M;
    a.at(itr).second = a.at(itr).second * inv % M;
  }
  return a;
}

vector<pll> pop_front(vector<pll> &a, char c) {
  for (ll itr = 0; itr < Ms.size(); ++itr) {
    ll M = Ms.at(itr), B = Bs.at(itr), inv = invs.at(itr);
    a.at(itr).first = (a.at(itr).first - (c * a.at(itr).second % M) * inv % M + M) % M;
    a.at(itr).second = a.at(itr).second * inv % M;
  }
  return a;
}

vector<pll> unite(vector<pll> a, vector<pll> b) {
  for (ll itr = 0; itr < Ms.size(); ++itr) {
    ll M = Ms.at(itr), B = Bs.at(itr), inv = invs.at(itr);
    a.at(itr).first *= b.at(itr).second;
    a.at(itr).first += b.at(itr).first;
    a.at(itr).second *= b.at(itr).second;
    a.at(itr).first %= M;
    a.at(itr).second %= M;
  }
  return a;
}
//=================================================
