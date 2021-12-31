#include "graph/base.hpp"
template <typename Graph, typename E = int>
struct CentroidDecomposition {
  using edge_type = typename Graph::edge_type;
  using F = function<E(E, edge_type)>;
  Graph& G;
  F f; // (E path value, edge e) -> E new_path_value
  int N;
  vector<int> cdep; // depth in centroid tree
  vc<int> sz;
  vc<int> par;

  CentroidDecomposition(
      Graph& G, F f = [](int x, edge_type e) { return x + e.cost; })
      : G(G), N(G.N), f(f), sz(G.N), par(G.N), cdep(G.N, -1) {
    build();
  }

  int find(int v) {
    vc<int> V = {v};
    par[v] = -1;
    int p = 0;
    while (p < len(V)) {
      int v = V[p++];
      sz[v] = 0;
      for (auto&& e: G[v]) {
        if (e.to == par[v] || cdep[e.to] != -1) continue;
        par[e.to] = v;
        V.eb(e.to);
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
  }

  void build() {
    assert(G.is_prepared());
    assert(!G.is_directed());
    int N = G.N;

    vc<pair<int, int>> st = {{0, 0}};
    while (len(st)) {
      auto [lv, v] = st.back();
      st.pop_back();
      auto c = find(v);
      cdep[c] = lv;
      for (auto&& [frm, to, cost, id]: G[c]) {
        if (cdep[to] == -1) st.eb(lv + 1, to);
      }
    }
  }

  vc<vc<pair<int, E>>> collect(int root, E root_val) {
    /*
    root を重心とする木において、(v, path data v) の vector を、方向ごとに集めて返す
    ・0 番目：root からのパスすべて（root を含む）
    ・i 番目：i 番目の方向
    */
    vc<vc<pair<int, E>>> res = {{{root, root_val}}};
    for (auto&& e: G[root]) {
      int nxt = e.to;
      if (cdep[nxt] < cdep[root]) continue;
      vc<pair<int, E>> dat;
      int p = 0;
      dat.eb(nxt, f(root_val, e));
      par[nxt] = root;
      while (p < len(dat)) {
        auto [v, val] = dat[p++];
        for (auto&& e: G[v]) {
          if (e.to == par[v]) continue;
          if (cdep[e.to] < cdep[root]) continue;
          par[e.to] = v;
          dat.eb(e.to, f(val, e));
        }
      }
      res.eb(dat);
      res[0].insert(res[0].end(), all(dat));
    }
    return res;
  }
};
