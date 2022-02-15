#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/toposort.hpp"

void solve() {
  LL(N, M);
  Graph<int, 1> G(N);
  G.read_graph(M, false, 0);
  auto I = toposort(G);
  for (auto&& x: I) print(x);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
