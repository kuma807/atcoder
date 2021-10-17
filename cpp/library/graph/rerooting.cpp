// ============how it works=================
//Rerooting<ll, marge, connect_with_par> rerooting(connection, identity);

//rerooting.get(par, root)
  //parを親、rootを根とした木の答えを求める(parは木に含まれない)
// ========================================

ll marge(ll a, ll b) {
  return max(a, b);
}

ll connect_with_par(ll a) {
  return a + 1;
}

ll identity = 0;

//=============Rerooting===========================
template <class T, T (*marge)(T, T), T (*connect_with_par)(T)>
struct Rerooting {
  vector<vector<ll>> connection;
  ll N;
  vector<ll> par, number;
  map<pll, T> mp;
  T identity;

  Rerooting(vector<vector<ll>> &Connetion, T Identity) {
    identity = Identity;
    connection = Connetion;
    N = Connetion.size();
    par = vector<ll>(N, -1);
    //0を根とした木のdfs順(num)を求める
    stack<ll> st;
    st.push(0);
    vector<bool> already(N, false);
    already.at(0) = true;
    number = {0};
    while (!st.empty()) {
      ll now = st.top();
      st.pop();
      for (ll i = 0; i < connection.at(now).size(); ++i) {
        ll next = connection.at(now).at(i);
        if (already.at(next)) {
          continue;
        }
        already.at(next) = true;
        par.at(next) = now;
        st.push(next);
        number.push_back(next);
      }
    }

    //0を頂点とした木の答えを求める
    for (ll i = N - 1; i >= 0; --i) {
      ll now = number.at(i);
      T M = identity;
      for (ll j = 0; j < connection.at(now).size(); ++j) {
        ll next = connection.at(now).at(j);
        if (next == par.at(now)) {
          continue;
        }
        M = marge(M, connect_with_par(mp[{now, next}]));
      }
      mp[{par.at(now), now}] = M;
    }

    //他の頂点を根とした木の答えを求める
    for (ll i = 0; i < N; ++i) {
      ll now = number.at(i);
      vector<T> rev_max(connection.at(now).size() + 1, identity);
      for (ll j = connection.at(now).size() - 1; j >= 0; --j) {
        ll next = connection.at(now).at(j);
        rev_max.at(j) = connect_with_par(mp[{now, next}]);
        rev_max.at(j) = marge(rev_max.at(j), rev_max.at(j + 1));
      }
      T M = identity;
      for (ll j = 0; j < connection.at(now).size(); ++j) {
        ll next = connection.at(now).at(j);
        mp[{next, now}] = marge(M, rev_max.at(j + 1));
        M = marge(M, connect_with_par(mp[{now, next}]));
      }
      mp[{-1, now}] = M;
    }
  }

  T get(ll par, ll root) {
    return mp[{par, root}];
  }
};
//=================================================
