#pragma once
#include "graph/base.hpp"

template<typename T>
pair<vc<T>, vc<int>> bfs01(Graph<T>& G, ll v) {
  assert(G.is_prepared());
  int N = G.N;
  vc<T> dist(N, -1);
  vc<int> par(N, -1);
  deque<int> que;

  dist[v] = 0;
  que.push_front(v);
  while (!que.empty()) {
    auto v = que.front();
    que.pop_front();
    for (auto&& e : G[v]) {
      if (dist[e.to] == -1 || dist[e.to] > dist[e.frm] + e.cost) {
        dist[e.to] = dist[e.frm] + e.cost;
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