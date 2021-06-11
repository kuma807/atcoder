//expander.py
  python3 expander.py main.cpp

//modint
  #include <atcoder/modint>
  using mint = atcoder::modint;
  //1.mod の設定
  //mint::set_mod(int m)
  //2.定義
  //mint x = 10;
  //3.xの値を返す
  //int x_val = x.val()
  //4.pow(x, n)を返す
  //mint x.pow(n)
  //5.inv　←　割り算使えるからいらない？
  //mint m.inv()

//crt(中国余弦定理)
  #include <atcoder/math>
  using namespace atcoder;
  pll p = crt({remain1, remain2, ...}, {mod1, mod2, ...});
  //1 <= remain && lcm(all(remain))がllの範囲
  //(ans, mod)
  //答えがない場合は(0, 0)を返す

//maxflow
  #include <atcoder/maxflow>
  using namespace atcoder;
  mf_graph<ll> graph(N);//Nは頂点数
  graph.add_edge(from, to, cap);
  graph.flow(from, to);#最大流量
