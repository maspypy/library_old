#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "my_template.hpp"

#include "graph/dijkstra.hpp"
#include "graph/restore_path.hpp"

void solve() {
  LL(N, M, s, t);
  Graph<ll, true> G(N);
  FOR(_, M) {
    LL(a, b, c);
    G.add(a, b, c);
  }
  G.prepare();

  auto [dist, par] = dijkstra(G, s);
  if (dist[t] == -1) return print(-1);

  vector<int> pth = restore_path(par, t);
  print(dist[t], len(pth) - 1);
  FOR(i, len(pth) - 1) print(pth[i], pth[i + 1]);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
