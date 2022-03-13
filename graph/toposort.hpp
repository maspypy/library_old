#include "graph/base.hpp"
#include "graph/degree.hpp"

template <typename Graph>
vc<int> toposort(Graph& G) {
  // DAG じゃなかったら空配列
  assert(G.is_prepared());
  assert(G.is_directed());
  auto [indeg, outdeg] = degree_inout(G);
  vc<int> V;
  ll N = G.N;
  FOR(v, N) if (indeg[v] == 0) V.eb(v);
  ll p = 0;
  while (p < len(V)) {
    auto v = V[p++];
    for (auto&& e: G[v]) {
      if (--indeg[e.to] == 0) V.eb(e.to);
    }
  }
  if(len(V) < N) {
    V.clear();
  }
  return V;
}
