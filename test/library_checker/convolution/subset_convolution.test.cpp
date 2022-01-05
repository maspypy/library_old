#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"
#include "my_template.hpp"

#include "mod/modint.hpp"
#include "setfunc/subset_convolution.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(mint, A, 1<<N);
  VEC(mint, B, 1<<N);
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
