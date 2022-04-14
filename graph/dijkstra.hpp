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

// 多点スタート。[dist, par, root]
template <typename Graph>
tuple<vector<typename Graph::cost_type>, vector<int>, vector<int>> dijkstra(
    Graph& G, vc<int> vs) {
  assert(G.is_prepared());
  int N = G.N;
  using T = typename Graph::cost_type;
  vc<ll> dist(N, -1);
  vc<int> par(N, -1);
  vc<int> root(N, -1);

  using P = pair<T, int>;

  priority_queue<P, vector<P>, greater<P>> que;

  for (auto&& v: vs) {
    dist[v] = 0;
    root[v] = v;
    que.emplace(T(0), v);
  }

  while (!que.empty()) {
    auto [dv, v] = que.top();
    que.pop();
    if (dv > dist[v]) continue;
    for (auto&& e: G[v]) {
      if (dist[e.to] == -1 || dist[e.to] > dist[e.frm] + e.cost) {
        dist[e.to] = dist[e.frm] + e.cost;
        root[e.to] = root[e.frm];
        par[e.to] = e.frm;
        que.push(mp(dist[e.to], e.to));
      }
    }
  }
  return {dist, par, root};
}
