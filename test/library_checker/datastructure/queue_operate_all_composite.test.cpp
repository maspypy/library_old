#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include "my_template.hpp"

#include "ds/swag.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(Q);
  using E = pair<mint, mint>;
  vc<E> dat;
  dat.reserve(Q);

  SWAG<E> swag(
    [&](E x, E y) -> E {
      return E({x.fi * y.fi, x.se * y.fi + y.se});
    },
    E({mint(1), mint(0)}), dat);

  ll L = 0, R = 0;

  FOR(_, Q) {
    LL(t);
    if (t == 0) {
      LL(a, b);
      dat.eb(E({mint(a), mint(b)}));
      ++R;
    }
    elif (t == 1) { ++L; }
    elif (t == 2) {
      LL(x);
      auto e = swag.fold(L, R);
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
