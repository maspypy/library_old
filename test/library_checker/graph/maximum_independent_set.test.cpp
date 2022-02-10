#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/mis.hpp"

void solve() {
  LL(N, M);
  Graph<int> G(N);
  FOR(_, M) {
    LL(a, b);
    G.add(a, b);
  }
  G.prepare();
  auto mis = maximum_independent_set(G);
  print(len(mis));
  print(mis);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
