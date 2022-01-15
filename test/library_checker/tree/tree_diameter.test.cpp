#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include "my_template.hpp"
#include "graph/tree_diameter.hpp"

void solve() {
  LL(N);
  Graph<ll> G(N);
  FOR_(N - 1) {
    LL(a, b, c);
    G.add(a, b, c);
  }
  G.prepare();
  auto [diam, P] = tree_diameter(G);
  print(diam, len(P));
  print(P);
}

signed main() {
  solve();

  return 0;
}
