// ============how it works=================
// input:
  //ll n
  //ll k
    //nCk
  //ll MAX
    //max(n, k)
  //ll MOD
// output:
  //nCk
// ========================================

const ll MAX = 510010;
const ll MOD = 1000000007;
vector<ll> fac(MAX), finv(MAX), inv(MAX);
bool init_called = false;
//=============modinv============================
void COMinit() {
  init_called = true;
  fac.at(0) = 1;
  fac.at(1) = 1;
  finv.at(0) = 1;
  finv.at(1) = 1;
  inv.at(1) = 1;
  for (ll i = 2; i < MAX; i++){
    fac.at(i) = fac.at(i - 1) * i % MOD;
    inv.at(i) = MOD - inv.at(MOD % i) * (MOD / i) % MOD;
    finv.at(i) = finv.at(i - 1) * inv.at(i) % MOD;
  }
}

ll COM(ll n, ll k){
  if (!init_called) {
    COMinit();
  }
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac.at(n) * (finv.at(k) * finv.at(n - k) % MOD) % MOD;
}
//=================================================
