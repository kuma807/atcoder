// ============how it works=================
//suffix_array(string& s, char first = 'a', char last = 'z');
  //文字列sの接頭辞配列を求める、使われてる文字の最小がfirstで最大がlast
  //計算量 O(sの長さ)

//LCP(const string& s, const vector<ll>& sa)
  //sのLCP(longest common prefix array)を求める、saは文字列sのsuffix array
  //計算量 O(sの長さ)

//接尾辞配列とは、文字列の接尾辞の文字列中の開始位置を要素とする配列を、接尾辞に関して辞書順に並べ替えて得られる配列である。
//abcbcbaの接頭辞配列は
//6 0 5 3 1 4 2

//LCPは、直前の接尾辞と、接尾辞の先頭から何文字か共通する文字がある場合の最大文字数。
//あり本p339参照
// ========================================

//=============suffix_array============================
void induced_sort(const vector<ll>& vec, ll val_range, vector<ll>& SA, const vector<bool>& sl, const vector<ll>& lms_idx) {
  vector<ll> l(val_range, 0), r(val_range, 0);
  for (ll c : vec) {
    if (c + 1 < val_range) ++l[c + 1];
    ++r[c];
  }
  partial_sum(l.begin(), l.end(), l.begin());
  partial_sum(r.begin(), r.end(), r.begin());
  fill(SA.begin(), SA.end(), -1);
  for (ll i = (ll)lms_idx.size() - 1; i >= 0; --i)
    SA[--r[vec[lms_idx[i]]]] = lms_idx[i];
  for (ll i : SA)
    if (i >= 1 && sl[i - 1]) SA[l[vec[i - 1]]++] = i - 1;
  fill(r.begin(), r.end(), 0);
  for (ll c : vec) ++r[c];
  partial_sum(r.begin(), r.end(), r.begin());
  for (ll k = (ll)SA.size() - 1, i = SA[k]; k >= 1; --k, i = SA[k])
    if (i >= 1 && !sl[i - 1]) {
      SA[--r[vec[i - 1]]] = i - 1;
    }
}

vector<ll> SA_IS(const vector<ll>& vec, ll val_range) {
  const ll n = vec.size();
  vector<ll> SA(n), lms_idx;
  vector<bool> sl(n);
  sl[n - 1] = false;
  for (ll i = n - 2; i >= 0; --i) {
    sl[i] = (vec[i] > vec[i + 1] || (vec[i] == vec[i + 1] && sl[i + 1]));
    if (sl[i] && !sl[i + 1]) lms_idx.push_back(i + 1);
  }
  reverse(lms_idx.begin(), lms_idx.end());
  induced_sort(vec, val_range, SA, sl, lms_idx);
  vector<ll> new_lms_idx(lms_idx.size()), lms_vec(lms_idx.size());
  for (ll i = 0, k = 0; i < n; ++i)
    if (!sl[SA[i]] && SA[i] >= 1 && sl[SA[i] - 1]) {
      new_lms_idx[k++] = SA[i];
    }
  ll cur = 0;
  SA[n - 1] = cur;
  for (size_t k = 1; k < new_lms_idx.size(); ++k) {
    ll i = new_lms_idx[k - 1], j = new_lms_idx[k];
    if (vec[i] != vec[j]) {
      SA[j] = ++cur;
      continue;
    }
    bool flag = false;
    for (ll a = i + 1, b = j + 1;; ++a, ++b) {
      if (vec[a] != vec[b]) {
        flag = true;
        break;
      }
      if ((!sl[a] && sl[a - 1]) || (!sl[b] && sl[b - 1])) {
        flag = !((!sl[a] && sl[a - 1]) && (!sl[b] && sl[b - 1]));
        break;
      }
    }
    SA[j] = (flag ? ++cur : cur);
  }
  for (size_t i = 0; i < lms_idx.size(); ++i) lms_vec[i] = SA[lms_idx[i]];
  if (cur + 1 < (ll)lms_idx.size()) {
    auto lms_SA = SA_IS(lms_vec, cur + 1);
    for (size_t i = 0; i < lms_idx.size(); ++i) {
      new_lms_idx[i] = lms_idx[lms_SA[i]];
    }
  }
  induced_sort(vec, val_range, SA, sl, new_lms_idx);
  return SA;
}

vector<ll> suffix_array(const string& s, const char first = 'a', const char last = 'z') {
  vector<ll> vec(s.size() + 1);
  copy(begin(s), end(s), begin(vec));
  for (auto& x : vec) x -= (ll)first - 1;
  vec.back() = 0;
  auto ret = SA_IS(vec, (ll)last - (ll)first + 2);
  ret.erase(ret.begin());
  return ret;
}

vector<ll> LCP(const string& s, const vector<ll>& sa) {
  ll n = s.size(), k = 0;
  vector<ll> lcp(n), rank(n);
  for (ll i = 0; i < n; i++) rank[sa[i]] = i;
  for (ll i = 0; i < n; i++, k ? k-- : 0) {
    if (rank[i] == n - 1) {
      k = 0;
      continue;
    }
    ll j = sa[rank[i] + 1];
    while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
    lcp[rank[i]] = k;
  }
  lcp[n - 1] = 0;
  return lcp;
}
//=================================================
