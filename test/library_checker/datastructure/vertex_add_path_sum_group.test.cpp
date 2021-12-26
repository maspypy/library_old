#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include "my_template.hpp"

#include "graph/treegroup.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);

  Graph<int> G(N);
  FOR(_, N - 1) {
    LL(a, b);
    G.add(a, b);
  }

  HLD<Graph<int>> hld(G);
  TreeGroup<Graph<int>, ll, false> TG(hld, Monoid_add<ll>(), true,
                                     false);
  TG.init(A);

  FOR(_, Q) {
    LL(t);
    if (t == 0) {
      LL(v, x);
      A[v] += x;
      TG.set(v, A[v]);
    } else {
      LL(u, v);
      print(TG.prod_path(u, v));
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
