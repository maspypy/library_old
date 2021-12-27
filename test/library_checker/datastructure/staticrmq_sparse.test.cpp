#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "my_template.hpp"

#include "algebraic_system/minmonoid.hpp"
#include "ds/disjointsparse.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);
  using Mono = MinMonoid<int, 1 << 30>;
  DisjointSparse<Mono> DS(A);

  FOR(_, Q) {
    LL(L, R);
    print(DS.prod(L, R));
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
