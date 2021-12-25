#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "my_template.hpp"

#include "ds/lazysegtree.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N, Q);

  using E = pair<mint, mint>;  // cnt, sum
  using OP = pair<mint, mint>; // (a,b) of ax + b
  const bool OP_commute = false;
  LazySegTree<E, OP, OP_commute> seg(
    [&](E x, E y) -> E {
      return E({x.fi + y.fi, x.se + y.se});
    },
    [&](E x, OP y) -> E {
      return E({x.fi, x.se * y.fi + x.fi * y.se});
    },
    [&](OP x, OP y) -> OP {
      return OP({x.fi * y.fi, x.se * y.fi + y.se});
    },
    E({mint(0), mint(0)}), OP({mint(1), mint(0)}));
  seg.init(N);
  vc<E> A(N);
  FOR(i, N) {
    LL(x);
    A[i] = {1, x};
  }
  seg.build(A);

  FOR(_, Q) {
    LL(t, L, R);
    if (t == 0) {
      LL(a, b);
      seg.operate_range(L, R, OP({mint(a), mint(b)}));
    }

    if (t == 1) {
      auto [cnt, sum] = seg.fold(L, R);
      print(sum);
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
