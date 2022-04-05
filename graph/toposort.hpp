#include "graph/base.hpp"
#include "graph/degree.hpp"

// DAG じゃなかったら空配列
template <typename Graph>
vc<int> toposort(Graph& G) {
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


// https://codeforces.com/contest/798/problem/E
// toposort の候補をひとつ出力する。チェックはしない。
// 陽にグラフを作らず、何らかのデータ構造で未訪問の行き先を探す想定。
// set_used(v)：v を使用済に変更する
// find_unused(v)：v の行き先を探す。なければ -1 を返すこと。
template <typename F1, typename F2>
vc<int> toposort(int N, F1 set_used, F2 find_unused) {
  vc<int> V;
  vc<bool> done(N);
  auto dfs = [&](auto self, ll v) -> void {
    set_used(v);
    done[v] = 1;
    while (1) {
      int to = find_unused(v);
      if (to == -1) break;
      self(self, to);
    }
    V.eb(v);
  };
  FOR(v, N) if (!done[v]) dfs(dfs, v);
  return V;
}
