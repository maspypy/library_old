#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/fenwickraq.hpp"

void solve() {
  LL(N, Q);
  FenwickRAQ<Group_Add<ll>> bit(N);
  FOR(_, Q) {
    LL(t, L, R);
    --L;
    if (t == 0) {
      LL(x);
      bit.add(L, R, x);
    } else {
      print(bit.sum(L, R));
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
