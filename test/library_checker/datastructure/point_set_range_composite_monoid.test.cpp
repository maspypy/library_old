#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "my_template.hpp"

#include "ds/segtree.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N, Q);
  using E = pair<mint, mint>;
  SegTree<E> seg(
    [&](E x, E y) {
      return E({x.fi * y.fi, x.se * y.fi + y.se});
    },
    E({1, 0}));
  seg.init(N);
  vc<E> seg_raw(N);
  FOR(i, N) {
    LL(a, b);
    seg_raw[i] = {a, b};
  }
  seg.build(seg_raw);

  FOR(q, Q) {
    LL(t);
    if (t == 0) {
      LL(i, a, b);
      seg.set(i, E({a, b}));
    } else {
      LL(L, R, x);
      auto [a, b] = seg.fold(L, R);
      print(a * mint(x) + b);
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
