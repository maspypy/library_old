#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "my_template.hpp"

#include "ds/segtree.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);
  using E = int;
  SegTree<E> seg(
    [&](E x, E y) -> E {
      return min(x,y);
    },
    E(1<<30));
  seg.init(N);
  seg.build(A);

  FOR(_, Q) {
    LL(L, R);
    print(seg.fold(L, R));
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
