#define PROBLEM "https://yukicoder.me/problems/no/1320"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/mincostcycle.hpp"

void solve() {
  LL(T, N, M);
  if (T == 0) {
    Graph<ll, 0> G(N);
    G.read_graph(M, true);
    print(MinCostCycle(G));
  } else {
    Graph<ll, 1> G(N);
    G.read_graph(M, true);
    print(MinCostCycle(G));
  }
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