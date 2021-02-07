// ============how it works=================
// input:
  //string S
    //少数の文字列
  //ll mul
    //Sを何倍にして返すか
// output:
  //S * mul
// ========================================

//=============read_decimals============================
ll read_decimals(string S, ll mul) {
  ll N = S.size();
  ll div = 1;
  string remove_decimal = "";
  for (ll i = 0; i < N; ++i) {
    if (S.at(N - 1 - i) == '.') {
      div = pow(10, i);
    }
    if (S.at(i) != '.') {
      remove_decimal += S.at(i);
    }
  }
  return stoll(remove_decimal) * mul / div;
}
//=================================================
