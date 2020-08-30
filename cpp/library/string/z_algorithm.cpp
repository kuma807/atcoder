// ============how it works=================
// input:
  //string S
// output:
  //vector<ll> Z
    //Z[i] = SとS[i:]の先頭なん文字が一致しているか
// ========================================

//=============z_algorithm============================
vector<ll> z_algorithm(string S)
{
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
  return Z;
}
//=================================================
