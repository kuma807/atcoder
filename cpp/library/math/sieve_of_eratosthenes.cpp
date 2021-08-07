// ============how it works=================
//MAX_N 素数判定する最大値
//is_prime.at(i) iが素数ならtrue
//init()を一回呼ぶ
//O(NloglogN)
// =======================================

//=============sieve_of_eratosthenes==========================
ll MAX_N = pow(10, 6) + 2;
bool init_called = false;
vector<bool> is_prime(MAX_N, true);
void init() {
  is_prime.at(0) = false;
  is_prime.at(1) = false;
  for (ll i = 2; i < MAX_N; ++i) {
    if (!is_prime.at(i)) {
      continue;
    }
    ll cnt = 2;
    while (i * cnt < MAX_N) {
      is_prime.at(i * cnt) = false;
      cnt += 1;
    }
  }
}
//=================================================
