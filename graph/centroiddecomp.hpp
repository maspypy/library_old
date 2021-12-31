#include "graph/base.hpp"
template <typename Graph>
vector<int> centroid_decomposition(Graph& G) {
  // 重心分解木における depth 配列を返す。
  assert(G.is_prepared());
  assert(!G.is_directed());
  int N = G.N;
  vc<int> dep(N, -1);
  vc<int> sz(N);
  vc<int> par(N, -1);

  auto find = [&](int v) -> int {
    vc<int> V = {v};
    par[v] = -1;
    int p = 0;
    while (p < len(V)) {
      int v = V[p++];
      sz[v] = 0;
      for (auto&& [frm, to, cost, id]: G[v]) {
        if (to == par[v] || dep[to] != -1) continue;
        par[to] = v;
        V.eb(to);
      }
    }
    while (len(V)) {
      int v = V.back();
      V.pop_back();
      sz[v] += 1;
      if (p - sz[v] <= p / 2) return v;
      sz[par[v]] += sz[v];
    }
    return -1;
  };

  vc<pair<int, int>> st = {{0, 0}};
  while (len(st)) {
    auto [lv, v] = st.back();
    st.pop_back();
    auto c = find(v);
    dep[c] = lv;
    for (auto&& [frm, to, cost, id]: G[c]) {
      if (dep[to] == -1) st.eb(lv + 1, to);
    }
  }
  return dep;
}