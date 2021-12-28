#include "graph/base.hpp"

template <typename Graph>
vector<int> degree(Graph& G) {
  vector<int> deg(N);
  FOR(v, N) deg[v] = len(G[v]);
  return deg;
}

template <typename Graph>
pair<vector<int>, vector<int>> degree_inout(Graph& G) {
  vector<int> indeg(N), outdeg(N);
  for (auto&& e: G.edges) { indeg[e.to]++, outdeg[e.frm]++; }
  return {indeg, outdeg};
}
