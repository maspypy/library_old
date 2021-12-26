#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include "my_template.hpp"

#include "ds/swag.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(Q);
  using E = pair<mint, mint>;
  SWAG<E> swag(Monoid_affine<mint>());

  FOR(_, Q) {
    LL(t);
    if (t == 0) {
      LL(a, b);
      swag.push(E({a, b}));
    }
    elif (t == 1) { swag.pop(); }
    elif (t == 2) {
      LL(x);
      auto e = swag.prod();
      print(e.fi * mint(x) + e.se);
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
