#include "graph/base.hpp"

template <typename T>
vi euler_walk(Graph<T>& G) {
  /*
  頂点番号の列を返す。有向・無向両対応。
  存在しない場合には、空を返す。
  辺が 0 個の場合には {0} を返す。
  */
  ll N = G.N, M = G.M;
  if (M == 0) return {0};
  vi deg(N);
  for (auto&& e: G.edges) {
    if (G.directed) {
      deg[e.frm]++, deg[e.to]--;
    } else {
      deg[e.frm]++, deg[e.to]++;
    }
  }

  ll s = max_element(all(deg)) - deg.begin();
  if (deg[s] == 0) s = G.edges[0].frm;

  vi D(N), its(N), eu(M), ret, st = {s};
  ++D[s];
  while (!st.empty()) {
    ll x = st.back(), y, e, &it = its[x], end = len(G[x]);
    if (it == end) {
      ret.eb(x);
      st.pop_back();
      continue;
    }
    auto ee = G[x][it++];
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
