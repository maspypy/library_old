#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include "my_template.hpp"

#include "mod/modint.hpp"
#include "setfunc/and_convolution.hpp"

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
  auto ANS = and_convolution(A, B);
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
