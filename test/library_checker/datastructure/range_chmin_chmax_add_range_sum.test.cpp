#define PROBLEM \
  "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include "my_template.hpp"

#include "algebra/beats_sample.hpp"
#include "ds/lazysegtree_fail.hpp"

void solve() {
  LL(N, Q);
  LazySegTreeFail<Lazy> seg(N);
  FOR(i, N) {
    LL(a);
    seg.set(i, {1, a, a, a, 1, 1, a, a, 0});
  }
  FOR(_, Q) {
    LL(t, L, R);
    if (t == 0) {
      LL(x);
      seg.apply(L, R, {0, x, -INF});
    }
    elif (t == 1) {
      LL(x);
      seg.apply(L, R, {0, INF, x});
    }
    elif (t == 2) {
      LL(x);
      seg.apply(L, R, {x, INF, -INF});
    }
    elif (t == 3) {
      auto x = seg.prod(L, R);
      print(x.sum);
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
