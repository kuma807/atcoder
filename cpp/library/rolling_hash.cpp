// ============how it works=================

現在動作確認ができていない！！！
// input:
  // string a, b
    //bの中にaが入っているか
// output:
  //bの中にaが入ってるときtrue
// ========================================

typedef unsigned long long ull;
const ull B = 1000000007;
//=============rolling_hash============================
bool rolling_hash(string a, string b) {
    ll al = a.size(), bl = b.size();
    if (al > bl) {
      return false;
    }
    ull t = 1;
    ull ah = 0, bh = 0;
    for (ll i = 0; i < al; ++i) {
      ah = ah * B + a[i];
      bh = bh * B + b[i];
      t *= B;
    }
    for (ll i = 0; i + al <= bl; ++i) {
      if (ah == bh) {
        return true;
      }
      if (i + al < bl) {
        bh = bh * B + b[i + al] - b[i] * t;
      }
    }
    return false;
}
//=================================================
