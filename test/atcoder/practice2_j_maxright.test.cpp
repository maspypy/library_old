#define PROBLEM "https://atcoder.jp/contests/practice2/tasks/practice2_j"
#include "my_template.hpp"
#include "ds/segtree.hpp"
#include "algebra/maxmonoid.hpp"

void solve() {
  using Mono = MaxMonoid<int, 1 << 30>;
  LL(N, Q);
  VEC(int, A, N);
  SegTree<Mono> seg(A);
  FOR(_, Q) {
    LL(t);
    if (t == 1) {
      LL(i, v);
      seg.set(--i, v);
    }
    elif (t == 2) {
      LL(L, R);
      print(seg.prod(--L, R));
    }
    elif (t == 3) {
      LL(L, v);
      --L;
      auto check = [&](ll x) -> bool { return x < v; };
      auto R = seg.max_right(check, L);
      print(R + 1);
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
