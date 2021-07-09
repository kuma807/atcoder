// ============need input=================
// cumulative_sum cs(vector<vector<ll>> vec);
//cs.get_sum(x1, y1, x2, y2)
  //(x1, y1), (x2, y2)で作られる四角形の合計
  //!!!zero index!!!!
// ========================================

// ============cumulative_sum===============
struct cumulative_sum {
  vector<vector<ll>> sum;
  ll N, M;

  cumulative_sum(vector<vector<ll>> &original)
  {
    N = original.size();
    M = original.at(0).size();
    if (N == 0 || M == 0) {
      cout << "cumulative_sum error: data size zero" << "\n";
    }
    sum = vector<vector<ll>>(N + 1, vector<ll>(M + 1));
    for (ll i = 0; i < N; ++i) {
      for (ll j = 0; j < M; ++j) {
        sum.at(i + 1).at(j + 1) = original.at(i).at(j);
      }
    }
    for (ll i = 0; i <= N; ++i) {
      for (ll j = 0; j < M; ++j) {
        sum.at(i).at(j + 1) += sum.at(i).at(j);
      }
    }
    for (ll i = 0; i <= M; ++i) {
      for (ll j = 0; j < N; ++j) {
        sum.at(j + 1).at(i) += sum.at(j).at(i);
      }
    }
  }

  //!!!!zero index!!!!!
  ll get_sum(ll x1, ll y1, ll x2, ll y2) {
    return sum.at(x2 + 1).at(y2 + 1) - sum.at(x1).at(y2 + 1) - sum.at(x2 + 1).at(y1) + sum.at(x1).at(y1);
  }
};
// =======================================
