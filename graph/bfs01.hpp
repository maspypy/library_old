#pragma once
#include "graph/base.hpp"

template<typename T>
pair<vi, vi> bfs01(Graph<T>& G, ll v) {
  const ll INF = 1LL << 60;
  auto N = G.N;
  vi dist(N, INF);
  vi par(N, -1);
  deque<ll> que;

  dist[v] = 0;
  que.push_front(v);
  while (!que.empty()) {
    auto v = que.front();
    que.pop_front();
    for (auto&& e : G[v]) {
      if (chmin(dist[e.to], dist[e.frm] + e.cost)) {
        par[e.to] = e.frm;
        if (e.cost == 0)
          que.push_front(e.to);
        else
          que.push_back(e.to);
      }
    }
  }
  return {dist, par};
}