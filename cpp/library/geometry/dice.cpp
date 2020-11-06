// ============how it works=================
// DICE dice;
  //DICEクラスを作成
// get_stat(front, top)
  // dice.back, dice.leftなどを更新する

//roll(ll front, ll top, vector<ll> w)
  //前面, 上面, w = {dx, dy}
  //wの方向に転がしたときのfront, topを更新する
// ========================================

//=============dice============================
vector<vector<ll>> way_to_roll = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class DICE {
public:
  //first == front
  ll right;
  ll left;
  ll top;
  ll front;
  ll back;
  ll bottom;
  map<pll, ll> right_side;//{front, top}
  DICE() {
    right_side[{1, 2}] = 3;right_side[{1, 3}] = 5;right_side[{1, 5}] = 4;right_side[{1, 4}] = 2;
    right_side[{2, 1}] = 4;right_side[{2, 4}] = 6;right_side[{2, 6}] = 3;right_side[{2, 3}] = 1;
    right_side[{3, 1}] = 2;right_side[{3, 2}] = 6;right_side[{3, 6}] = 5;right_side[{3, 5}] = 1;
    right_side[{4, 1}] = 5;right_side[{4, 5}] = 6;right_side[{4, 6}] = 2;right_side[{4, 2}] = 1;
    right_side[{5, 1}] = 3;right_side[{5, 3}] = 6;right_side[{5, 6}] = 4;right_side[{5, 4}] = 1;
    right_side[{6, 2}] = 4;right_side[{6, 4}] = 5;right_side[{6, 5}] = 3;right_side[{6, 3}] = 2;
  }

  void get_stat(ll f, ll t) {
    back = 7 - f, bottom = 7 - t, right = right_side[{f, t}], left = 7 - right, front = f, top = t;
  }

  void roll(ll& f, ll& t, vector<ll> w) {
    if (w == way_to_roll.at(0)) {
      ll temp1 = 7 - f;
      f = t;
      t = temp1;
    }
    else if (w == way_to_roll.at(1)) {
      t = 7 - right_side[{f, t}];
    }
    else if (w == way_to_roll.at(2)) {
      ll temp1 = 7 - t;
      t = f;
      f = temp1;
    }
    else {
      t = right_side[{f, t}];
    }
  }
};
//=================================================
