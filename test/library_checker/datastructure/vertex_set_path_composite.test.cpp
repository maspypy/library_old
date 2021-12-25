#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include "my_template.hpp"

#include "graph/base.hpp"
#include "graph/hld.hpp"
#include "graph/treemonoid.hpp"
#include "mod/modint.hpp"
using mint = modint998;

void solve() {
  LL(N, Q);
  using E = pair<mint, mint>;
  vc<E> A(N);
  FOR(i, N) {
    LL(a, b);
    A[i] = {mint(a), mint(b)};
  }
  Graph<int> G(N);
  FOR(_, N - 1) {
    LL(a, b);
    G.add(a, b);
  }

  HLD<Graph<int>> hld(G);

  // [ tree monoid template
  const bool is_edge = false;
  const bool commute = false;
  TreeMonoid<HLD<Graph<int>>, E, is_edge, commute> TM(
    hld, [&](E x, E y) -> E { return mp(x.fi * y.fi, x.se * y.fi + y.se); },
    E({mint(1), mint(0)}));
  TM.init(A);
  // tree monoid template]

  FOR(_, Q) {
    LL(t);
    if (t == 0) {
      LL(p, c, d);
      TM.set(p, E({mint(c), mint(d)}));

    } else {
      LL(u, v, x);
      auto e = TM.fold_path(u, v);
      print(e.fi * mint(x) + e.se);
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
