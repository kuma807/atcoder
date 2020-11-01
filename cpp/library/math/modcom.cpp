// ============how it works=================
// input:
  //ll n
  //ll k
    //nCk
  //ll MAX
    //max(n, k)
  //ll mod
// output:
  //nCk
// ========================================

const ll MAX = 510010;
const ll mod = 1000000007;
vector<ll> fac(MAX), finv(MAX), inv(MAX);
bool init_called = false;
//=============modcom============================
void COMinit() {
  init_called = true;
  fac.at(0) = 1;
  fac.at(1) = 1;
  finv.at(0) = 1;
  finv.at(1) = 1;
  inv.at(1) = 1;
  for (ll i = 2; i < MAX; i++){
    fac.at(i) = fac.at(i - 1) * i % mod;
    inv.at(i) = mod - inv.at(mod % i) * (mod / i) % mod;
    finv.at(i) = finv.at(i - 1) * inv.at(i) % mod;
  }
}

ll COM(ll n, ll k){
  if (!init_called) {
    COMinit();
  }
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac.at(n) * (finv.at(k) * finv.at(n - k) % mod) % mod;
}
//=================================================
