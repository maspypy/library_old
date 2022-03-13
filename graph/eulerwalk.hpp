#include "graph/base.hpp"

template <typename T>
vc<int> euler_walk(Graph<T>& G, int s = -1) {
  /*
  頂点番号の列を返す。有向・無向両対応。
  存在しない場合には、空を返す。
  辺が 0 個の場合には {0} を返す。
  */
  assert(G.is_prepared());
  ll N = G.N, M = G.M;

  if (s == -1) {
    vc<int> deg(N);
    for (auto&& e: G.edges) {
      if (G.is_directed()) {
        deg[e.frm]++, deg[e.to]--;
      } else {
        deg[e.frm]++, deg[e.to]++;
      }
    }
    s = max_element(all(deg)) - deg.begin();
    if (deg[s] == 0) s = G.edges[0].frm;
  }

  if (M == 0) return {s};
  vc<int> D(N), its(N), eu(M), ret, st = {s};
  FOR(v, N) its[v] = G.indptr[v];
  ++D[s];
  while (!st.empty()) {
    int x = st.back(), y, e, &it = its[x], end = G.indptr[x + 1];
    if (it == end) {
      ret.eb(x);
      st.pop_back();
      continue;
    }
    auto& ee = G.csr_edges[it++];
    y = ee.to, e = ee.id;
    if (!eu[e]) {
      D[x]--, D[y]++;
      eu[e] = 1;
      st.eb(y);
    }
  }
  for (auto&& x: D)
    if (x < 0) return {};
  if (len(ret) != M + 1) return {};
  reverse(all(ret));
  return ret;
}
