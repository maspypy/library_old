#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/base.hpp"
#include "graph/chromatic.hpp"

void solve() {
  LL(N, M);
  Graph<int> G(N);
  FOR_(M) {
    LL(a, b);
    G.add(a, b);
  }
  G.prepare();
  print(chromatic_number(G));
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
