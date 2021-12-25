#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "my_template.hpp"

#include "graph/base.hpp"
#include "graph/hld.hpp"
#include "graph/treemonoid.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  Graph<int> G(N);
  FOR(_, N - 1) {
    LL(a, b);
    G.add(a, b);
  }

  HLD<Graph<int>> hld(G);
  using E = ll;
  const bool is_edge = false;
  const bool commute = true;
  TreeMonoid<HLD<Graph<int>>, E, is_edge, commute> TM(
    hld, [&](E x, E y) -> E { return x + y; }, E(0));

  TM.init(A);

  FOR(_, Q) {
    LL(t);
    if (t == 0) {
      LL(v, x);
      A[v] += x;
      TM.set(v, A[v]);
    } else {
      LL(u, v);
      print(TM.fold_path(u, v));
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
