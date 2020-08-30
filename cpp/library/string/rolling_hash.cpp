// ============how it works=================
// input:
  // string a, b
    //bを円環だとしたときa[i:i+b.size()] == b[0:b.size()]の場所を見つける
// output:
  //b[i]から始まる文字とaが一致するか
  //vector<bool> res[i];res[i] から始まる文字がaと一致
// ========================================

ll M, B;
bool init = false;
vector<pair<ll, ll>> MB = {{2147483647, 2147483634}, {2147483629, 2147483627}, {2147483587, 2147483583}, {2147483579, 2147483576}, {2147483563, 2147483550}, {2147483543, 2147483541}, {2147483497, 2147483492}, {2147483489, 2147483486}, {2147483477, 2147483475}};

//=============rolling_hash============================
vector<bool> rolling_hash(string a, string b) {
  if (!init) {
    init = true;
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<> rand9(0, 8);
    ll temp = rand9(mt);
    M = MB.at(temp).first;
    B = MB.at(temp).second;
  }
  ll al = a.size(), bl = b.size();
  vector<bool> res(al, false);
  ll t = 1;
  ll ah = 0, bh = 0;
  for (ll i = 0; i < bl; ++i) {
    ah = (ah * B + a.at(i)) % M;
    bh = (bh * B + b.at(i)) % M;
    t = (t * B) % M;
  }
  for (ll i = 0; i < al; ++i) {
    if (ah == bh) {
      res.at(i) = true;
    }
    ah = (ah * B + a.at((i + bl) % al)) % M;
    ah -= (a.at(i) * t) % M;
    if (ah < 0ll) {
      ah += M;
    }
    ah %= M;
  }
  return res;
}
//=================================================
