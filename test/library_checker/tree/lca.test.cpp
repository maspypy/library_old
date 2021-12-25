#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "my_template.hpp"

#include "graph/base.hpp"
#include "graph/hld.hpp"

void solve() {
  LL(N, Q);
  Graph<int> G(N);
  FOR3(v, 1, N) {
    LL(p);
    G.add(p, v);
  }
  HLD<Graph<int>> hld(G);

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
