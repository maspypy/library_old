#pragma once
#include "graph/base.hpp"

template <typename Graph, typename T>
vc<vc<typename Graph::cost_type>> warshall_floyd(Graph& G, T INF) {
  ll N = G.N;
  vv(T, dist, N, N, INF);
  FOR(v, N) {
    dist[v][v] = 0;
    for (auto&& e: G[v]) dist[v][e.to] = e.cost;
  }
  FOR(k, N) FOR(i, N) FOR(j, N) { chmin(dist[i][j], dist[i][k] + dist[k][j]); }
  return dist;
}