#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "my_template.hpp"

#include "algebra/cntsum_affine_lazy.hpp"
#include "ds/lazysegtree.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N, Q);
  using S = CntSum_Affine_Lazy<mint>;
  using E = pair<mint, mint>;
  vc<E> seg_raw(N);
  FOR(i, N) {
    LL(x);
    seg_raw[i] = E({mint(1), mint(x)});
  }
  LazySegTree<S> seg(seg_raw);

  FOR(_, Q) {
    LL(t);
    if (t == 0) {
      LL(l, r, a, b);
      seg.apply(l, r, E({a, b}));
    }
    elif (t == 1) {
      LL(l, r);
      auto cs = seg.prod(l, r);
      print(cs.se);
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
