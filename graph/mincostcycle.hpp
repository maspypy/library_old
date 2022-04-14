#include "graph/dijkstra.hpp"
#include "graph/bfs01.hpp"

template <typename T, T INF, typename Graph>
typename Graph::cost_type MinCostCycle(Graph& G) {
  using T = typename Graph::cost_type;
  int M = G.M;
  int N = G.N;
  T mx = 0;
  T INF = 1;
  for (auto&& e: G.edges) chmax(mx, e.cost), INF += e.cost;
  T res = INF;

  FOR(i, M) {
    auto& e = G.edges[i];
    T cost = e.cost;
    int frm = e.to, to = e.frm;
    Graph Gi(N);
    FOR(j, M) if (i != j) {
      auto& e = G.edges[j];
      Gi.add(e.frm, e.to, e.cost);
    }
    Gi.build();

    T x = (mx <= 1 ? bfs01(Gi, frm).fi[to] : dijkstra<T, INF>(Gi, frm).fi[to]);
    if (x == -1) x = INF;
    chmin(res, cost + x);
  }
  if (res == INF) res = -1;
  return res;
}