#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"
#include "my_template.hpp"

#include "mod/modint.hpp"
#include "setfunc/subset_convolution.hpp"

using mint = modint998;

void solve() {
  LL(N);
  vc<mint> A(1 << N), B(1 << N);
  FOR(i, 1 << N) {
    LL(a);
    A[i] = a;
  }
  FOR(i, 1 << N) {
    LL(a);
    B[i] = a;
  }
  auto C = subset_convolution(A, B);
  print(C);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
