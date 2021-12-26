#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "my_template.hpp"

#include "ds/disjointsparse.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);
  // [ disjoint sparse table template
  using E = int;
  DisjointSparse<E> DS(Monoid_min<E>(1 << 30), A);
  // disjoint sparse table template ]

  FOR(_, Q) {
    LL(L, R);
    print(DS.fold(L, R));
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
