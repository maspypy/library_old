#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "my_template.hpp"

#include "ds/fenwick2d.hpp"

void solve() {
  LL(N, Q);
  vi X(N), Y(N), W(N);
  FOR(i, N) {
    LL(x, y, w);
    X[i] = x, Y[i] = y, W[i] = w;
  }
  Fenwick2D<Group_Add<ll>, false> bit(X, Y, W);
  FOR(_, Q) {
    LL(l, d, r, u);
    print(bit.sum(l, r, d, u));
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
