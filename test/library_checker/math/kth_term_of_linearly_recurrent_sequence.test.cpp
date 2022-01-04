#define PROBLEM \
  "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"
#include "my_template.hpp"

#include "mod/modint.hpp"
#include "sequence/linearrecurrence.hpp"

using mint = modint998;
void solve() {
  LL(N, K);
  VEC(mint, A, N);
  VEC(mint, g, N);
  for (auto&& x : g) x = -x;
  g.insert(g.begin(), 1);
  auto f = convolution(A, g);
  f.resize(N);
  print(coef_of_rational(f, g, K));
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
