#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include "my_template.hpp"

#include "graph/base.hpp"
#include "graph/hld.hpp"
#include "graph/treemonoid.hpp"
#include "algebra/addgroup.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  Graph<int> G(N);
  FOR(_, N - 1) {
    LL(a, b);
    G.add(a, b);
  }
  G.prepare();

  HLD hld(G);
  const bool is_edge = false;
  using Mono = AddGroup<ll>;
  TreeMonoid<decltype(hld), Mono, is_edge> TM(hld, A);

  FOR(_, Q) {
    LL(t);
    if (t == 0) {
      LL(v, x);
      A[v] += x;
      TM.set(v, A[v]);
    } else {
      LL(u, v);
      print(TM.prod_path(u, v));
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
