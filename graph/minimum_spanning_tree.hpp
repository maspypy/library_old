#include "ds/unionfind.hpp"
#include "graph/base.hpp"
#include "graph/hld.hpp"
#include "graph/treemonoid.hpp"
#include "graph/dualtreemonoid.hpp"
#include "alg/monoid_min.hpp"
#include "alg/monoid_max.hpp"

// return : {T mst_cost, vc<bool> in_mst, Graph MST}
template <typename T>
tuple<T, vc<bool>, Graph<T>> minimum_spanning_tree(Graph<T>& G) {
  int N = G.N;
  int M = len(G.edges);
  vc<pair<T, int>> edges;
  FOR(i, M) {
    auto& e = G.edges[i];
    edges.eb(e.cost, i);
  }
  sort(all(edges));
  vc<bool> in_mst(M);
  UnionFind uf(N);
  T mst_cost = T(0);
  Graph<T> MST(N);
  for (auto&& [cost, i]: edges) {
    auto& e = G.edges[i];
    if (uf.merge(e.frm, e.to)) {
      in_mst[i] = 1;
      mst_cost += e.cost;
    }
  }
  FOR(i, M) if (in_mst[i]) {
    auto& e = G.edges[i];
    MST.add(e.frm, e.to, e.cost);
  }
  MST.prepare();
  return {mst_cost, in_mst, MST};
}

// https://codeforces.com/contest/828/problem/F
// return : {T mst_cost, vc<bool> in_mst, Graph MST, vc<T> dat}
// dat : 辺ごとに、他の辺を保ったときに MST 辺になる最大重み
template <typename T, T INF = (1LL << 60)>
tuple<T, vc<bool>, Graph<T>, vc<T>> minimum_spanning_tree_cycle_data(
    Graph<T>& G) {
  int N = G.N;
  int M = len(G.edges);
  auto [mst_cost, in_mst, MST] = minimum_spanning_tree(G);
  HLD hld(MST);
  vc<T> dat;
  FOR(i, M) if (in_mst[i]) dat.eb(G.edges[i].cost);
  TreeMonoid<decltype(hld), Monoid_Max<T, INF>, 1> TM1(hld, dat);
  DualTreeMonoid<decltype(hld), Monoid_Min<T, INF>, 1> TM2(hld);
  FOR(i, M) {
    if (!in_mst[i]) {
      auto& e = G.edges[i];
      TM2.apply_path(e.frm, e.to, e.cost);
    }
  }
  vc<T> ANS(M);
  int m = 0;
  FOR(i, M) {
    auto& e = G.edges[i];
    if (in_mst[i])
      ANS[i] = TM2.get(m++);
    else
      ANS[i] = TM1.prod_path(e.frm, e.to);
  }
  return {mst_cost, in_mst, MST, ANS};
}