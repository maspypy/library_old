#pragma once
#include "graph/base.hpp"

template <typename Graph>
pair<vector<typename Graph::cost_type>, vector<int>> dijkstra(Graph& G, int v) {
  auto N = G.N;
  using T = typename Graph::cost_type;
  vector<T> dist(N, -1);
  vector<int> par(N, -1);
  using P = pair<T, int>;

  priority_queue<P, vector<P>, greater<P>> que;

  dist[v] = 0;
  que.push(mp(T(0), v));
  while (!que.empty()) {
    auto [dv, v] = que.top();
    que.pop();
    if (dv > dist[v]) continue;
    for (auto&& e: G[v]) {
      if (dist[e.to] == -1 || dist[e.to] > dist[e.frm] + e.cost) {
        dist[e.to] = dist[e.frm] + e.cost;
        par[e.to] = e.frm;
        que.push(mp(dist[e.to], e.to));
      }
    }
  }
  return mp(dist, par);
}
