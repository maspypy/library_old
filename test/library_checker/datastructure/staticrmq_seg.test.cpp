#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "my_template.hpp"

#include "ds/segtree.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);
  SegTree<int> seg(Monoid_min<int>(1<<30));
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
