// ============how it works=================
// input:
  // ll N:Nを素因数分解する
  // ll MAX_N:Nの最大値 + 1
// output:
  // vector<pll> res:pow(first, second)がNの約数
//Nの数が10^7より小さく大量に素因数分解するときに使える
// ========================================

//=============fast_prime_factor============================
ll MAX_N = pow(10, 6) + 1;
bool init_called = false;
vector<ll> smallest_prime(MAX_N, -1);
void init() {
  for (ll i = 2; i < MAX_N; ++i) {
    if (smallest_prime.at(i) == -1) {
      smallest_prime.at(i) == i;
      ll cnt = 2;
      while (cnt * i < MAX_N) {
        smallest_prime.at(cnt * i) = i;
        cnt += 1;
      }
    }
  }
}

vector<pll> prime_factor(ll N)
{
  if (!init_called) {
    init_called = true;
    init();
  }
  vector<pll> res;
  while (true) {
    ll cnt = 0;
    ll now = smallest_prime.at(N);
    if (now == -1) {
      break;
    }
    while (N % now == 0) {
      N /= now;
      cnt += 1;
    }
    res.push_back({now, cnt});
  }
  if (N != 1) {
    res.push_back({N, 1});
  }
  return res;
}
//=================================================
