// ============how it works=================
// input:
  //string A, B
// output:
  //vector<ll> Z
    //Z[i] = AとB[i:]の先頭なん文字が一致しているか
// ========================================

//=============z_algorithm============================
vector<ll> z_algorithm(string &A, string &B)
{
  char not_in_AB = '$';//要変更
  string S = A + not_in_AB + B;
  vector<ll> Z(S.size(), 0);
  ll i = 1, j = 0;
  while (i < S.size())
  {
    while (i+j < S.size() && S[j] == S[i+j]) ++j;
    Z.at(i) = j;
    if (j == 0) { ++i; continue;}
    ll k = 1;
    while (i+k < S.size() && k+Z.at(k) < j) Z.at(i + k) = Z.at(k), ++k;
    i += k; j -= k;
  }
  vector<ll> res;
  for (ll i = A.size() + 1; i < S.size(); ++i) {
    res.push_back(Z.at(i));
  }
  return res;
}
//=================================================
