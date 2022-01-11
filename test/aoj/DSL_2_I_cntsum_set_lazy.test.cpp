#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"

#include "my_template.hpp"
#include "alg/lazy_cntsum_set.hpp"
#include "ds/lazysegtree.hpp"

void solve() {
  LL(N, Q);
  using Lazy = Lazy_CntSum_Set<ll, 12345>;
  vc<pi> seg_raw(N);
  FOR(i, N) seg_raw[i] = {1, 0};
  LazySegTree<Lazy> seg(seg_raw);
  FOR(_, Q) {
    LL(t, L, R);
    ++R;
    if (t == 0) {
      LL(x);
      seg.apply(L, R, x);
    } else {
      print(seg.prod(L, R).se);
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
