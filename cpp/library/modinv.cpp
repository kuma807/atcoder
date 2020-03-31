// ============how it works=================
// input:
  // ll a: aの逆元を求める
  // ll m: mod
    // a　と m は互いに素でなければならない
// output:
  // ll u: a　の逆元
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

int main() {
    // mod. 13 での逆元を求めてみる
    for (int i = 1; i < 13; ++i) {
        cout << i << " 's inv: " << modinv(i, 13) << endl;
    }
}
//=================================================