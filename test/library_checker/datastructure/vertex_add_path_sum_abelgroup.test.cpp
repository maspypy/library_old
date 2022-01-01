#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include "my_template.hpp"

#include "graph/treeabelgroup.hpp"
#include "algebra/group_add.hpp"

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
  TreeAbelGroup<decltype(hld), Group_Add<ll>, false, true, false> TA(hld, A);

  FOR(_, Q) {
    LL(t);
    if (t == 0) {
      LL(v, x);
      TA.add(v, x);
    } else {
      LL(u, v);
      print(TA.sum_path(u, v));
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
