#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include "my_template.hpp"

#include "graph/base.hpp"
#include "graph/hld.hpp"
#include "graph/treemonoid.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  Graph<int> G(N);
  FOR3(v, 1, N) {
    LL(p);
    G.add(p, v);
  }
  HLD<Graph<int>> hld(G);

  TreeMonoid<Graph<int>, ll, false> TM(hld, Monoid_add<ll>());
  TM.init(A);

  FOR(_, Q) {
    LL(t);
    if (t == 0) {
      LL(v, x);
      A[v] += x;
      TM.set(v, A[v]);
    } else {
      LL(u);
      print(TM.prod_subtree(u));
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
