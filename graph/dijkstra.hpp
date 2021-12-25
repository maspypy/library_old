#pragma once
#include "graph/base.hpp"

template <typename T>
pair<vi, vi> dijkstra(Graph<T>& G, ll v) {
  const ll INF = 1LL << 60;
  auto N = G.N;
  vi dist(N, INF);
  vi par(N, -1);
  using P = pair<T, ll>;

  priority_queue<P, vector<P>, greater<P>> que;

  dist[v] = 0;
  que.push(mp(T(0), v));
  while (!que.empty()) {
    auto [dv, v] = que.top();
    que.pop();
    if(dv > dist[v]) continue;
    for (auto&& e : G[v]) {
      if (chmin(dist[e.to], dist[e.frm] + e.cost)) {
        par[e.to] = e.frm;
        que.push(mp(dist[e.to], e.to));
      }
    }
  }
  return mp(dist, par);
}
