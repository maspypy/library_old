#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "my_template.hpp"

#include "graph/hld.hpp"

void solve() {
  LL(N, Q);
  Graph<int, 1> G(N);
  FOR3(v, 1, N) {
    LL(p);
    G.add(p, v);
  }
  G.prepare();
  HLD hld(G);

  FOR(_, Q) {
    LL(a, b);
    print(hld.LCA(a, b));
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();
  return 0;
}
