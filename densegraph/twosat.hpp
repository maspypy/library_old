struct TwoSat {
  vc<int> values;

  Graph<int> G;
  TwoSat(ll n) {
    G = Graph<int>(2 * n, 1);
    values.assign(n, -1);
  }
  void add(int a, int b) {
    a = (a >= 0 ? 2 * a + 1 : 2 * (~a));
    b = (b >= 0 ? 2 * b + 1 : 2 * (~b));
    G.add(a ^ 1, b, 1, false);
    G.add(b ^ 1, a, 1, false);
  }
  void set(int a) {
    if (a >= 0)
      values[a] = 1;
    else
      values[~a] = 0;
    a = (a >= 0 ? 2 * a + 1 : 2 * (~a));
    G.add(a ^ 1, a, 1, false);
  }
  void implies(int a, int b) { add(~a, b); }

  bool calc() {
    ll n = len(values);
    SCC<Graph<int>> scc(G);
    FOR(i, n) {
      if (scc[2 * i] == scc[2 * i + 1]) return false;
      values[i] = scc[2 * i] < scc[2 * i + 1];
    }
    return true;
  }
};